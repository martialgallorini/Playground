//
//  Force.cpp
//  testTrigo
//
//  Created by Martial on 28/04/2015.
//
//

#include "Force.h"

void Force::setAngle(float angle){
    float length = this->length();
    this->x = cos(angle) * length * 2 * PI;
    this->y = sin(angle) * length * 2 * PI;
}

void Force::setLength(float length){
    float angle = atan2(this->y, this->x);
    this->x = cos(angle) * length;
    this->y = sin(angle) * length;
}