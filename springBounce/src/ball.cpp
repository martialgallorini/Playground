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
    
    //ofSetColor(ofMap(dist.length(), 0, 30, 100, 200, true));
    ofSetColor(ofMap(dist.x + dist.y, -10, 10, 40, 200, true));
    
    
    
    
    //boxes[index] = new SpringBox(x*width/columns, y*height/rows, height/rows);

    
//    SpringBox(float x, float y, float initBoxSize) {
//        xPos = x;
//        yPos = y;
//        boxSize = initBoxSize;
//        springPosX = boxSize/2;
//        springPosY = boxSize/2;
//        springVelX = 0;
//        springVelY = 0;
//        springAccX = 0;
//        springAccY = 0;
//        // set some defaults
//        stiffness = 0.5;
//        damping = 0.2;
//        mass = 5;
//        thickness = 30;
//        springColor = color(200,100,20);
//    }

    
    //color(255 - (springPosY/boxSize*128 + springPosX/boxSize*128))
    
    
    
    
    
    
    //ofSetColor(255 - (dist.x/200*128 + dist.y/200*128));

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