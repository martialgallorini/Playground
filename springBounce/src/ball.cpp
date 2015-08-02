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
    velocity = ofPoint(0, 0);
    areaRadius = 20;
    dist = ofPoint(0,0);

}

void ball::update() {
    dist = pin - position;
}

void ball::draw() {
    
    ofPushMatrix();
    ofSetColor(ofMap(dist.length(), -30, 30, 30, 190, true));
    ofCircle(position, radius);
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