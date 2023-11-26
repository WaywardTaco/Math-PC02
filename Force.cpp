
#ifndef FORCE
#define FORCE

class Force{

protected:
    float   x = 0,
            y = 0;

public:
    Force(){
        
    }

    Force(float x_component, float y_component){
        this->x = x_component;
        this->y = y_component;
    }

    void addForce(Force force){
        this->x += force.getX();
        this->y += force.getY();
    }

    float getX(){
        return this->x;
    }
    
    float getY(){
        return this->y;
    }

};

#endif