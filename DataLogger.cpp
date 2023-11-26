
#include <iostream>
#include <fstream>
#include <cmath>

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