
#ifndef BALL
#define BALL

#include "Force.cpp"
#include "Wall.cpp"

class Ball{

private:
    float   ballMass,
            diameter = 1.2,
            x = 0,
            y = 0,
            x_future = 0,
            y_future = 0,
            x_velocity = 0,
            y_velocity = 0,
            x_acceleration = 0,
            y_acceleration = 0;

    Wall    wall1,
            wall2,
            wall3,
            wall4;

public:
    Ball(float mass){
        this->ballMass = mass;
    }

    void applyForce(Force force){
        x_acceleration += force.getX() / this->ballMass;
        y_acceleration += force.getY() / this->ballMass;
    }

    void update(float timestep_seconds){

        this->x = this->x_future;
        this->y = this->y_future;
        
        this->x_future = this->x + this->x_velocity*timestep_seconds + x_acceleration*timestep_seconds*timestep_seconds/2;
        this->y_future = this->y + this->y_velocity*timestep_seconds + y_acceleration*timestep_seconds*timestep_seconds/2;

        while(wall1.willCollide(this) || wall2.willCollide(this) || wall3.willCollide(this) || wall4.willCollide(this)){
            // Calculations that change future x and y as well as acceleration for that
        }

        this->x_velocity = this->x_velocity + this->x_acceleration*timestep_seconds;
        this->y_velocity = this->x_velocity + this->x_acceleration*timestep_seconds;

    }

    float getFutureX(){
        return x_future;
    }

    float getFutureY(){
        return y_future;
    }

    float getRadius(){
        return diameter / 2.0;
    }

    void initializeWalls(Wall wall_1, Wall wall_2, Wall wall_3, Wall wall_4){
        this->wall1 = wall_1;
        this->wall2 = wall_2;
        this->wall3 = wall_3;
        this->wall4 = wall_4;
    }
};

#endif