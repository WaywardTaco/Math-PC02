
#include "DataLogger.cpp"

int main(){

    ofstream File("Test.txt");
    DataLogger data = DataLogger();

    float timestep = 1;

    Ball ball = Ball(5, 1.2);
    ball.setWalls(20, -5, -20, 20);

    Force gravity = Force(30,-2*ball.getMass());
    ball.applyForce(gravity);

    Force extraForce = Force(1, 2);

    for(int i = 0; i < 10; i++){
        ball.update(timestep);
        ball.applyForce(gravity);

        if(i == 1 || i == 2){

           // ball.applyForce(extraForce);
        }

        File << i*timestep << ", " << ball.getX() << ", " << ball.getY() << ", " << 
            ball.getXVelocity() << ", " << ball.getYVelocity() << ", k" << endl;
    }

    File.close();

    return 0;
}

