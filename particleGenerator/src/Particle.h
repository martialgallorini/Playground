#include "ofMain.h"
#include "Force.h"

class Particle {
public:    
    float radius;
    float lifeSpan;
    Force position;
    Force velocity;
    Force friction;
    Force gravity;
    
    void setup(float x, float y, float direction, float speed, float frict = 0);
    void update(float speed, float frict = 0, float grav = 0);
    void draw();
    
    bool isDead();
    
};
