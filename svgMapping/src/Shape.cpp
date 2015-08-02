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
    }
    
    // TODO : don't close if shape not closed !
    if (contour.isClosed()) {
        path.close();
        path.setFilled(false);
    }
    
    
    controls = path.getCommands();
    bCommands = false;
    //bShowCp = false;
    
    // Shape Gui
    groupGeometry.setName("Geometry");
    groupGeometry.add(posX.set("Position X", 100, 0, ofGetWidth()));
    groupGeometry.add(posY.set("Position Y", 100, 0, ofGetHeight()));
    groupGeometry.add(rotation.set("Rotation", 0, 0, 360));
    groupGeometry.add(scale.set("Scale", 1, 0, 2));
    groupGeometry.add(commandRadius.set("Control radius", 8, 3, 12));
    
    groupGraphics.setName("Graphics");
    //groupGraphics.add(strokeColor.set("Stroke color", path.getStrokeColor()));
    groupGraphics.add(strokeWidth.set("Stroke width", path.getStrokeWidth(), 1, 20));
    groupGraphics.add(fillShape.set("Fill shape", false));
    //groupGraphics.add(fillColor.set("Fill color", path.getFillColor()));
    
}

void Shape::update(){
    //path.scale(scale, scale);
    updatePath();
    path.setColor(strokeColor);
    path.setFilled(fillShape);
    path.setStrokeWidth(strokeWidth);
}

void Shape::draw(){
    ofNoFill();
    ofSetColor(200);
    ofPushMatrix();
    
    // draw shape
    path.draw();
    
    if (bCommands) {
        drawCommands();
    }
    
    ofPopMatrix();
}





// TODO !!!!!!


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










void Shape::updatePath() {
    
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
        path.flagShapeChanged();
    }
}

bool Shape::inside(float x, float y) {
    contour.clear();
    vector<ofPolyline> outline;
    outline = path.getOutline();
    for (int i = 0; i < outline.size(); i++) {
        contour.addVertices(outline[i].getVertices());
    }
    return contour.inside(x, y);
}

void Shape::drawCommands() {
    if(bCommands) {
        for (int i = 0; i < controls.size(); i++) {
            int type = controls[i].type;
            if (i == 0) {
                ofCircle(controls[i].to, 8);
                if (type == ofPath::Command::bezierTo || type == ofPath::Command::quadBezierTo) {
                    ofCircle(controls[i+1].cp1, 5);
                    ofLine(controls[i].to , controls[i+1].cp1);
                }
            }
            else if (i == controls.size() - 1) {
                ofCircle(controls[i].to, 8);
                if (type == ofPath::Command::bezierTo || type == ofPath::Command::quadBezierTo) {
                    ofCircle(controls[i].cp2, 5);
                    ofLine(controls[i].to , controls[i].cp2);
                }
            }
            else {
                ofCircle(controls[i].to, 8);
                if (type == ofPath::Command::bezierTo || type == ofPath::Command::quadBezierTo) {
                    ofCircle(controls[i].cp2, 5);
                    ofCircle(controls[i+1].cp1, 5);
                    ofLine(controls[i].to , controls[i].cp2);
                    ofLine(controls[i].to , controls[i+1].cp1);
                }
            }
        }
    }
}
