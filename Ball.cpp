
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
            x = 0,
            y = 0,
            x_future = 0,
            y_future = 0,
            x_velocity = 0,
            y_velocity = 0,
            x_futureVelocity = 0,
            y_futureVelocity = 0,
            x_acceleration = 0,
            y_acceleration = 0;

    float   upperWall_y = 99999999,
            lowerWall_y = -99999999,
            leftWall_x = -99999999,
            rightWall_x = 99999999;

public:
    Ball(float massKg, float diameter){
        this->mass_kg = massKg;
        this->radius = diameter / 2.0;
    }

    void setWalls(float upper_y, float lower_y, float left_x, float right_x){
        this->upperWall_y = upper_y;
        this->lowerWall_y = lower_y;
        this->leftWall_x = left_x;
        this->rightWall_x = right_x;
    }

    void applyForce(Force force){
        x_acceleration = force.getX() / this->mass_kg;
        y_acceleration = force.getY() / this->mass_kg;
    }

    void update(float timestep_seconds){

        this->x = this->x_future;
        this->y = this->y_future;

        this->x_velocity = this->x_futureVelocity;
        this->y_velocity = this->y_futureVelocity;
        
        cout << "Ball: (" << x << ", " << y << ") V: (" << x_velocity << ", " << y_velocity << ") A: (" << x_acceleration << ", " << y_acceleration << ")" << endl;

        this->x_future = this->x + this->x_velocity*timestep_seconds + x_acceleration*timestep_seconds*timestep_seconds/2;
        this->y_future = this->y + this->y_velocity*timestep_seconds + y_acceleration*timestep_seconds*timestep_seconds/2;

        this->x_futureVelocity = this->x_velocity + this->x_acceleration*timestep_seconds;
        this->y_futureVelocity = this->y_velocity + this->y_acceleration*timestep_seconds;

        processCollisions(timestep_seconds);

    }

    bool processCollisions(float in_timestep_seconds){
        bool    collidedUpper   = y_future + radius >= upperWall_y, 
                collidedLower   = y_future - radius <= lowerWall_y, 
                collidedRight   = x_future + radius >= rightWall_x, 
                collidedLeft    = x_future - radius <= leftWall_x;

        if(!collidedUpper && !collidedLower && !collidedLeft && !collidedRight)
            return false;

        float A, B, C, dt;

        if(collidedUpper){
            A = y_acceleration;
            B = y_velocity;
            C = y - (upperWall_y - radius);
            dt = (sqrt(B*B - 2*A*C) - B)/A;
        } else if (collidedLower){
            A = y_acceleration;
            B = y_velocity;
            C = y - (lowerWall_y + radius);
            dt = (- sqrt(B*B - 2*A*C) - B)/A;
        } else if (collidedLeft){
            A = x_acceleration;
            B = x_velocity;
            C = x - (leftWall_x + radius);
            dt = (- sqrt(B*B - 2*A*C) - B)/A;
        } else if (collidedRight){
            A = x_acceleration;
            B = x_velocity;
            C = x - (rightWall_x - radius);
            dt = (sqrt(B*B - 2*A*C) - B)/A;
        }

        float  remainingTime = in_timestep_seconds - dt;
        cout << dt << ", " << remainingTime << endl;;

        float temp_coord, temp_velocity;

        if(collidedUpper || collidedLower){
            temp_coord = y + y_velocity*dt + y_acceleration*dt*dt/2;
            temp_velocity = -(y_velocity + y_acceleration*dt);    
            this->y_future = temp_coord + temp_velocity*remainingTime + y_acceleration*remainingTime*remainingTime/2;
            this->y_futureVelocity = temp_velocity + y_acceleration*remainingTime;
        } else if (collidedLeft || collidedRight){
            temp_coord = x + x_velocity*dt + x_acceleration*dt*dt/2;
            temp_velocity = -(x_velocity + x_acceleration*dt);    
            this->x_future = temp_coord + temp_velocity*remainingTime + x_acceleration*remainingTime*remainingTime/2;
            this->x_futureVelocity = temp_velocity + x_acceleration*remainingTime;
        }

        cout << temp_coord << ", " << temp_velocity << endl;

        return true;
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

    float getRadius(){
        return radius;
    }

    float getMass(){
        return mass_kg;
    }
    
};

#endif