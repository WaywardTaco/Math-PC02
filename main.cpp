
#include "DataLogger.cpp"

const float 
    GRAVITY_PULL = -5,
    LEFT_WALL = -20,
    RIGHT_WALL = 20,
    FLOOR = -5,
    ROOF = 20,
    X_START = 0,
    Y_START = 0,
    BALL_DIAMETER = 1.2;
const bool
    APPLY_GRAVITY = true;

int main(){

    //ofstream File("Test.txt");
    //DataLogger data = DataLogger();
    float timestep = 1, ballMass = 2, appliedForceX = 15, appliedForceY = 25;

    cout << "Timestep per row (seconds): "; cin >> timestep; cin.ignore(); cin.clear();

    cout << "Mass of Ball: "; cin >> ballMass; cin.ignore(); cin.clear();
    Ball ball = Ball(ballMass, BALL_DIAMETER);
    ball.teleportTo(X_START, Y_START);
    ball.setWalls(ROOF, FLOOR, LEFT_WALL, RIGHT_WALL);

    const Force gravity = Force(0,GRAVITY_PULL*ball.getMass());

    cout << "Force to Apply in X: "; cin >> appliedForceX; cin.ignore(); cin.clear();
    cout << "Force to Apply in Y: "; cin >> appliedForceY; cin.ignore(); cin.clear();
    Force appliedForce = Force(appliedForceX, appliedForceY);
    ball.applyForce(appliedForce);

    if(APPLY_GRAVITY)
        ball.applyForce(gravity);

    float time = 0;

    while(time < 10){
        ball.updatePhysics(timestep);

        if(APPLY_GRAVITY)
            ball.applyForce(gravity);

        time += timestep;
    }

    //File.close();

    return 0;
}

