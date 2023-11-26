
#include "DataLogger.cpp"

int main(){

    //ofstream File("Test.txt");
    //DataLogger data = DataLogger();

    const float BALL_DIAMETER = 1.2;
    const float GRAVITY_PULL = -5;
    
    float timestep = 1;
    float ballMass = 5;

    Ball ball = Ball(5, 1.2);
    ball.setWalls(20, -5, -20, 20);

    Force gravity = Force(0,-GRAVITY_PULL*ball.getMass());
    ball.applyForce(gravity);

    Force extraForce = Force(1, 2);

    for(int i = 0; i < 10; i++){
        ball.update(timestep);
        ball.applyForce(gravity);

        if(i == 1 || i == 2){

           // ball.applyForce(extraForce);
        }

        //File << i*timestep << ", " << ball.getX() << ", " << ball.getY() << ", " << 
          //  ball.getXVelocity() << ", " << ball.getYVelocity() << ", k" << endl;
    }

    //File.close();

    return 0;
}

