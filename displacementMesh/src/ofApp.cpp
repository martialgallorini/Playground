#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    image.load("image.jpg");
    
    grayMap = image;
    grayMap.setImageType(OF_IMAGE_GRAYSCALE);
    grayMap.resize(image.getWidth() / 4, image.getHeight() / 4);
    
    for (int x = 0; x < grayMap.getWidth(); x++) {
        for (int y = 0; y < grayMap.getHeight(); y++) {
            
            ofColor c = grayMap.getColor(x, y);
            float brightness = c.getBrightness();
            ofMap(brightness, 0, 1, -50, 50);
            
            ofPoint p(x * 4, y * 4, brightness);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x * 4, y * 4));
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    mesh.draw();
    ofPopMatrix();
    cam.end();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
