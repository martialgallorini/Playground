#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "Shape.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxSVG svg;
    
    vector<Shape> shapes;
    
    
    bool bGrabControl;  // is control point grabbed
    int activeControl;  // active control point index
    int activeShape;    // active shape index
    
    bool bShowControls; // show control points
    
};


/*

NOTES : 
 
mouseMove event -> transmettre coordonnŽes ˆ Shape.
 si controlHovered -> envoyer event ˆ ofApp avec index control hovered
 dans ofApp -> methode dŽclenchŽe par ŽvŽnement envoie Shape::control.move();
 
 
 
 if (activeShape == this)
 avec Shape* activeShape;
 ofApp::mousePressed() -> isHovered -> Shape::active = true;
 Shape::mouseDragged() -> if (activeShape == this) -> this.moveControl()
 
  
*/