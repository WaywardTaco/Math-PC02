
#include "Ball.cpp"

int main(){

    float timestep = 1;
    Ball ball = Ball(5, 1.2);

    Gravity gravity = Gravity(ball.getMass());


    ball.update(timestep);
    ball.applyForce(gravity);

    return 0;
}

