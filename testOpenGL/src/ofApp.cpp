#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    cam.lookAt(ofVec3f(ofGetWidth() / 2, ofGetWidth() / 2, 500));
    
    ofColor color(255, 0, 0);
    
    float hue = 254.f;
    
    vel = ofVec3f(0);
    
    for(int i = 0; i <= 20; i++)
    {
        pos = ofVec3f(ofRandom(50, ofGetWidth() - 50), ofRandom(50, ofGetHeight() - 50), ofRandom(0, 500));
        obj.addVertex(pos);
        obj.addColor(color);
        color.setHue(hue);
        hue -= 20.f;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    vel = vel + acc;
//    pos = pos + vel;
//    
//    for(int i = 0; i <= 20; i++)
//    {
//        obj.getVertex(i);
//        pos = ofVec3f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0, 500));
//        obj.addVertex(pos);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofBackground(0, 0, 0);
    ofSetColor(0, 0, 255);
    ofLine(0, 0, 0, 0, 0, 100);
    ofSetColor(0, 255, 0);
    ofLine(0, 0, 0, 0, 100, 0);
    ofSetColor(255, 0, 0);
    ofLine(0, 0, 0, 100, 0, 0);
    ofPopMatrix();
//    cam.begin();
//    obj.drawFaces();
//    cam.end();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'n':
            for(int i = 0; i <= 20; i++)
            {
                vel = ofVec3f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0, 500));
                pos = pos + vel;
                obj.setVertex(i, pos);
            }
            break;
            
        default:
            break;
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
