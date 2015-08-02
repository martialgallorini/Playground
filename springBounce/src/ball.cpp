//
//  ball.cpp
//  testAttraction
//
//  Created by Martial on 01/08/2015.
//
//

#include "ball.h"

void ball::setup(float x, float y, float r) {
    pin = ofPoint(x, y);
    position = pin;
    radius = r;
    velocity = ofPoint(0, 0, 0);
    areaRadius = 70;
}

void ball::update() {
    
}

void ball::draw() {
    ofPushMatrix();
    ofCircle(pin, radius);
    ofPopMatrix();
}

bool ball::inArea(float x, float y) {
    if (ofDist(x, y, position.x, position.y) < areaRadius) {
        return true;
    }
    else {
        return false;
    }
}