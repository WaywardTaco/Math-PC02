
class Ball{

private:
    float   ballMass,
            diameter = 1.2,
            x = 0,
            y = 0,
            x_velocity = 0,
            y_velocity = 0,
            x_acceleration = 0,
            y_acceleration = 0;

public:
    Ball(float mass){
        this->ballMass = mass;
    }

    void applyForce(float x_component, float y_component){
        x_acceleration += x_component / this->ballMass;
        y_acceleration += y_component / this->ballMass;
    }

    void applyGravity(float pull_of_gravity){
        y_acceleration -= pull_of_gravity;
    }

    void update(float timestep){
        // Apply Gravity


    }

};