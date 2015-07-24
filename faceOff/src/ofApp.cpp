#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    img.loadImage("fox.png");
    img.setAnchorPercent(0.5, 0.5);
    
    cam.initGrabber(1280, 720);
    
    tracker.setup();
    tracker.setIterations(25);
    
    gui.setup();
    gui.add(imgOffsetY.set("Image Y Offset", -28, -200, 200));
    gui.add(imgScale.set("Image Scale", 2.5, 1, 20));
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    cam.getPixelsRef().mirror(false, true);
    if(cam.isFrameNew()) {
        tracker.update(ofxCv::toCv(cam));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //cam.draw(0,0);
    cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    if(tracker.getFound())
    {
        ofPushMatrix();
        //glTranslatef();
        ofTranslate(tracker.getPosition());
        ofxCv::applyMatrix(tracker.getRotationMatrix());
        img.draw(0, imgOffsetY * tracker.getScale(), img.getWidth() * tracker.getScale() / imgScale, img.getHeight() * tracker.getScale() / imgScale);
        ofPopMatrix();
        //tracker.draw();
        //tracker.getImageMesh().draw();
    }
    gui.draw();
}

void ofApp::exit(){
    tracker.waitForThread();
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
