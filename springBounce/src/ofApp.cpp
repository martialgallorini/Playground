#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    ballRadius = 10;
    int nbX = ofGetWidth() / (ballRadius * 2) + 1;
    int nbY = ofGetHeight() / (ballRadius * 2) + 1;
    
    for (int x = 0; x < nbX; x++) {
        for (int y = 0; y < nbY; y++) {
            balls.push_back(ball());
            balls.back().setup(x * ballRadius * 2, y * ballRadius * 2, ballRadius);
        }
    }
    
    dist = ofPoint(0, 0);
    attraction = ofPoint(0, 0);
    k = 0.2;
    friction = 0.9;
    limit = 0.01;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < balls.size(); i++) {
        
        dist = balls[i].pin - balls[i].position;
        attraction = dist * k;
        balls[i].velocity = (balls[i].velocity + attraction) * friction;
        balls[i].position = balls[i].position + balls[i].velocity;
        
        if (dist.length() < limit) {
            balls[i].position = balls[i].pin;
        }
        
        balls[i].radius = ofMap(dist.length(), 0., 100., ballRadius, 1.);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(240);

    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
    
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
    for (int i = 0; i < balls.size(); i++) {
        if (balls[i].inArea(x, y)) {
            balls[i].position.set(x, y);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}
