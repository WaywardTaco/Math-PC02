
#include <iostream>
#include <fstream>
#include "Ball.cpp"

using namespace std;

class DataLogger{

public:
    DataLogger(){
        
    }

    void writeLog(float timestep, Ball ball, ofstream File){
        File << timestep << ", " << ball.getX() << ", " << ball.getY() << ", " << 
            ball.getXVelocity() << ", " << ball.getYVelocity() << ", k" << endl;
    }


};