#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    gui.setup("Particle Parameters");
    
    gui.add(pRadius.set("radius", 2, 1, 10));
    gui.add(pSpeed.set("speed", 0, 0, 20));
    gui.add(pFriction.set("friction", 0, 0, 0.1));
    gui.add(pGravity.set("gravity", 0, 0, 1));
    
    bGuiVisible = true;

    for(int i = 0; i < 50; i++) {
        p.push_back(Particle());
        p[i].setup(ofGetWidth()/2, ofGetHeight()/2, ofRandomf() * PI * 2, ofRandomf() * 4 + 1);
    }
    
    syphonServer.setName("Particles Generator");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < p.size(); i++) {
        p[i].update(pSpeed, pFriction, pGravity);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
    for(int i = 0; i < p.size(); i++) {
        p[i].draw();
    }
    if (bGuiVisible) gui.draw();
    syphonServer.publishScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'h') {
        bGuiVisible = !bGuiVisible;
    }
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
