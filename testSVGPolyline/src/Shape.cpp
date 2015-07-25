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
    
    // convert to polyline for further processing
    vector<ofPolyline> outline = path.getOutline();
    for (int i = 0; i < outline.size(); i++) {
        contour.addVertices(outline[i].getVertices());
        if (outline[i].isClosed()) {
            contour.close();
        }
    }
    
    // TODO : don't close if shape not closed !
    path.close();
    path.setFilled(false);
    
    controls = p.getCommands();
    bCommands = false;
    commandRadius = 8;
}

void Shape::update(){
    
    
    
    // update shape with new control point positions
    
    ofPath newPath;
    newPath = path;     // save shape properties before editing path
    newPath.clear();    // clears path but keeps properties like color, stroke...
    
    // build new path according to actual path's control points properties
    for (int i = 0; i < controls.size(); i++) {
        switch (controls[i].type) {
            case ofPath::Command::moveTo:
                newPath.moveTo(controls[i].to);
                break;
            case ofPath::Command::lineTo:
                newPath.lineTo(controls[i].to);
                break;
            case ofPath::Command::curveTo:
                newPath.curveTo(controls[i].to);
                break;
            case ofPath::Command::bezierTo:
                newPath.bezierTo(controls[i].cp1, controls[i].cp2, controls[i].to);
                break;
            case ofPath::Command::quadBezierTo:
                newPath.quadBezierTo(controls[i].cp1, controls[i].cp2, controls[i].to);
                break;
            case ofPath::Command::arc:
                newPath.arc(controls[i].to, controls[i].radiusX, controls[i].radiusY, controls[i].angleBegin, controls[i].angleEnd, controls[i].arc);
                break;
            case ofPath::Command::arcNegative:
                newPath.arc(controls[i].to, controls[i].radiusX, controls[i].radiusY, controls[i].angleBegin, controls[i].angleEnd, controls[i].arcNegative);
                break;
            case ofPath::Command::close:
                newPath.close();
                break;
                
            default:
                break;
        }
        path.clear();
        path = newPath;
    }
}

void Shape::draw(){
    ofNoFill();
    ofSetColor(200);
    ofPushMatrix();
    
    // draw shape
    //path.draw();
    contour.draw();
    // display control points
    if(bCommands) {
        for (int i = 0; i < controls.size(); i++) {
            // draw control points
            ofCircle(controls[i].to, commandRadius);
            
            // draw shape contour
//            vector<ofPolyline> outline = path.getOutline();
//            for (int j = 0; j < outline.size(); j++)
//            {
//                outline[j].draw();
//            }
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
