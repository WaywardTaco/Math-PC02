
#ifndef BALL
#define BALL

#include <cmath>
#include "Force.cpp"

#include <iostream>

using namespace std;

class Ball{

private:
    float   mass_kg,
            radius,
            k = 0,
            x = 0,
            y = 0,
            x_velocity = 0,
            y_velocity = 0,
            x_acceleration = 0,
            y_acceleration = 0;

    Force forceApplied = Force();

    float   upperWallBuffer = 99999999,
            lowerWallBuffer = -99999999,
            leftWallBuffer = -99999999,
            rightWallBuffer = 99999999;

public:
    Ball(float massKg, float diameter){
        this->mass_kg = massKg;
        this->radius = diameter / 2.0;
    }

    void setWalls(float upper_y, float lower_y, float left_x, float right_x){
        this->upperWallBuffer = upper_y - radius;
        this->lowerWallBuffer = lower_y + radius;
        this->leftWallBuffer = left_x + radius;
        this->rightWallBuffer = right_x - radius;
    }

    void teleportTo(float x, float y){
        this->x = x;
        this->y = y;
    }

    void applyForce(Force force){
        this->forceApplied.addForce(force);
    }

    void utilizeForces(){
        this->x_acceleration = forceApplied.getX() / mass_kg;
        this->y_acceleration = forceApplied.getY() / mass_kg;

        this->forceApplied = Force();
    }

    void updatePhysics(float timestep){

        float
            x_future = x + x_velocity*timestep + x_acceleration*timestep*timestep/2,
            y_future = y + y_velocity*timestep + y_acceleration*timestep*timestep/2;

        this->k = 0;

        do{

        bool    
            collideUp       = y_future >= upperWallBuffer, 
            collideLow      = y_future <= lowerWallBuffer, 
            collideRight    = x_future >= rightWallBuffer, 
            collideLeft     = x_future <= leftWallBuffer;

        if(!collideLeft && !collideLow && !collideRight && !collideUp){

            this->x_velocity += x_acceleration*timestep;
            this->y_velocity += y_acceleration*timestep;

            break;
        }

        float
            nowCoord = y,
            *futureCoord = &y_future,
            *velocity = &this->y_velocity,
            acceleration = y_acceleration,
            buffer = lowerWallBuffer;
        
        if(collideLow);
        else if(collideUp)
            buffer = upperWallBuffer;
        else if (collideLeft || collideRight){
            nowCoord = x;
            futureCoord = &x_future;
            velocity = &this->x_velocity;
            acceleration = x_acceleration;
            buffer = leftWallBuffer;

            if(collideRight)
                buffer = rightWallBuffer;
        }

        float D = sqrt( *velocity * *velocity - 2 * acceleration * (nowCoord - buffer) ) / acceleration;

        if(acceleration == 0){
            this->k = (buffer - nowCoord) / *velocity;
        } else if (collideLow)
            this->k = - *velocity / acceleration - D;
        else if (collideUp || collideRight)
            this->k = - *velocity / acceleration + D;
        else if (collideLeft)
            this->k = - *velocity / acceleration - D;

        float 
            dt = timestep - k,
            tempCoord = nowCoord + *velocity * k + acceleration * k * k / 2,
            tempVelocity = -(*velocity + acceleration*k);

        *futureCoord = tempCoord + tempVelocity * dt + acceleration * dt * dt /2;
        *velocity = tempVelocity + acceleration * dt;

        } while (true);

        this->x = x_future;
        this->y = y_future;

        utilizeForces();

    }

    float getK(){
        return k;
    }

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    float getXVelocity(){
        return x_velocity;
    }

    float getYVelocity(){
        return y_velocity;
    }

    float getMass(){
        return mass_kg;
    }
    
};

#endif