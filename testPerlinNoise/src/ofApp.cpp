#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x0 = ofGetWidth() / 2;
    y0 = ofGetHeight()/2;
    line.addVertex(x, y);
    
    time0 = ofGetElapsedTimef();
    
    step = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    float dt = ofGetElapsedTimef() - time0;
    dt = ofClamp(dt, 0.0, 0.1);
    float tx = ofRandom(0, 1000) * 0.1 * dt;
    float ty = ofRandom(0, 1000) * 0.1 * dt;
    x = 5 * ofSignedNoise(tx);
    y = 20 * ofSignedNoise(ty);
    line.addVertex(x, y);
    //time0 = dt;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(200);
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    line.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
