
#ifndef WALL
#define WALL

#include "Ball.cpp"

enum wall_type{
    wall_default,
    wall_top,
    wall_bottom,
    wall_left,
    wall_right,
};

class Wall{

private:
    float coordinate = 0;
    wall_type wallType = wall_default;

public:
    Wall(float coord, wall_type type){
        this->coordinate = coord;
        this->wallType = type;
    }

    bool willCollide(Ball ball){
        switch(wallType){
            case wall_top:
                return ball.getFutureY() + ball.getRadius() > this->coordinate;
                
            case wall_bottom:
                return ball.getFutureY() - ball.getRadius() < this->coordinate;

            case wall_right:
                return ball.getFutureX() + ball.getRadius() > this->coordinate;

            case wall_left:
                return ball.getFutureX() - ball.getRadius() < this->coordinate;

            default:
                return false;
        }
    }
};

class TopWall : public Wall {

public: 
    TopWall(float coord) : Wall(coord, wall_top){}
};

class BottomWall : public Wall {

public: 
    BottomWall(float coord) : Wall(coord, wall_bottom){}
};

class LeftWall : public Wall {

public: 
    LeftWall(float coord) : Wall(coord, wall_left){}
};

class RightWall : public Wall {

public: 
    RightWall(float coord) : Wall(coord, wall_right){}
};

#endif