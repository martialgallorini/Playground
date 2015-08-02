#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "Shape.h"
#include "ofxSyphon.h"
#include "ofxGui.h"

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
    
    void populateShapeGui();
    //Shape* getActiveShape();
    
    ofxSVG svg;
    
    vector<Shape> shapes;
    
    Shape* activeShape;     // active shape
    
    bool bGrabControl;      // is control point grabbed
    int activeControl;      // active control point index

    //bool bShowControls;     // show control points
    
    ofxSyphonServer syphonServer;

    // SCENE GUI
    ofxPanel sceneGui;
    bool bShowGui;
    
    //ofParameterGroup editModeGroup;
    ofParameter<bool> editMode;
    ofParameter<bool> enableSyphon;
    ofParameter<bool> enableOsc;
    //ofParameter<bool> singleShape;
    
    // SHAPE GUI (populated from Shape class parameters)
    ofxPanel shapeGui;
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