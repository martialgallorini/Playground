#include "ofMain.h"

class Force : public ofVec3f {
public:
    using ofVec3f::operator=;
    
    void setAngle(float angle);
    void setLength(float length);
};