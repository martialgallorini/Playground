//
//  Shape.cpp
//  testSVGPolyline
//
//  Created by Martial on 17/07/2015.
//
//

#include "Shape.h"

Shape::Shape(){

}

Shape::~Shape() {

}

void Shape::setup(ofPath p){
    path = p;
    //path.setMode(ofPath::COMMANDS);
    //path.setPolyWindingMode(OF_POLY_WINDING_ODD);
    path.close();
    path.setFilled(false);
    controls = p.getCommands();
    bCommands = false;
    bCommandGrab = false;
    commandRadius = 8;
}

void Shape::update(){
    
}

void Shape::draw(){
    ofNoFill();
    ofSetColor(200);
    ofPushMatrix();
    
    // draw shape
    path.draw();
    
    // display control points
    if(bCommands) {
        for (int i = 0; i < controls.size(); i++) {
            // draw control points
            ofCircle(controls[i].to, commandRadius);
            
            // draw shape contour
            vector<ofPolyline> outline = path.getOutline();
            for (int j = 0; j < outline.size(); j++)
            {
                outline[j].draw();
            }
        }
    }
    
    ofPopMatrix();
}

// is mouse hovering a control point ?
int Shape::controlHovered(float x, float y) {
    for (int i = 0; i < controls.size(); i++) {
        float dist = ofDist(x, y, controls[i].to.x, controls[i].to.y);
        if ( dist < commandRadius) {
            return i;
        }
    }
    return -1;
}
