#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    svg.load("1.svg");
    
    // grab individual shapes from SVG file
    for(int i = 0; i < svg.getNumPath(); i++) {
        Shape s;
        s.setup(svg.getPathAt(i));
        shapes.push_back(s);
    }
    
    bGrabControl = false;
    activeControl = -1;
    bShowControls = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(200);
    
    // draw shapes
    for(int i = 0; i < shapes.size(); i++) {
        shapes.at(i).draw();
    }
    
    // if a control point is grabbed, display control points and debug info
    if (bShowControls && bGrabControl) {
        ofDrawBitmapString("Command grabbed !", 200, 20);
        ofDrawBitmapString("Active Shape : ", 200, 35);
        ofDrawBitmapString(ofToString(activeShape), 400, 35);
        ofDrawBitmapString("Active Control point : ", 200, 50);
        ofDrawBitmapString(ofToString(activeControl), 400, 50);
        ofDrawBitmapString("position clicked : ", 200, 65);
        string coord = ofToString(mouseX) + " : " + ofToString(mouseY);
        ofDrawBitmapString(coord, 400, 65);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // toggle edit mode (shows control points)
    if (key == OF_KEY_TAB) {
        for(int i = 0; i < shapes.size(); i++) {
            shapes.at(i).bCommands = !shapes.at(i).bCommands;
        }
        bShowControls = !bShowControls;
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    // move grabbed control point
    if (bGrabControl) {
        shapes[activeShape].controls[activeControl].to.set(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // check if mouse if hovering a control point in edit mode
    for(int i = 0; i < shapes.size(); i++) {
        int cIndex = shapes[i].controlHovered(x, y);
        if (cIndex != -1) {
            bGrabControl = true;
            activeShape = i;
            activeControl = cIndex;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    bGrabControl = false;
    activeShape = -1;
    activeControl = -1;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
