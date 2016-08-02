#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetFrameRate(30);
    
//    photoFbo.allocate(CAM_WIDTH, CAM_HEIGHT);
//    photoFbo.begin();
//    ofClear(0);
//    photoFbo.end();

    preview.setup();
    
    captionFbo.allocate(CAM_WIDTH, 50);
    captionFbo.begin();
    ofClear(0);
    captionFbo.end();

    verdana30.load("verdana.ttf", 30, true, true);
    verdana30.setLineHeight(34.0f);
    verdana30.setLetterSpacing(1.055);

    word.init();

    timer.setup(5);
}

//--------------------------------------------------------------
void ofApp::update(){
    //cam.update();
    preview.update();
    timer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

//    photoFbo.begin();
//    ofBackground(0);
//    ofSetColor(255);
//    cam.draw(CAM_WIDTH, 0, -CAM_WIDTH, CAM_HEIGHT);
//    ofSetColor(0, 50);
//    ofFill();
//    ofDrawRectangle(0, 0, 240, 720);
//    ofDrawRectangle(1040, 0, 240, 720);
//    photoFbo.end();
    
    captionFbo.begin();
    ofBackground(50);
    ofSetColor(200);
    ofRectangle bounds = verdana30.getStringBoundingBox(text, 0, 0);
    float w = (captionFbo.getWidth() / 2) - (bounds.getWidth() / 2);
    float h = verdana30.getLineHeight() + 5;
    verdana30.drawString(text, w, h);
    captionFbo.end();

//    int cropX = (CAM_WIDTH / 4);
//    int cropY = 0;
//    int cropW = cropX * 2;
//    int cropH = 720;
//    photoFbo.getTexture().drawSubsection(cropX, 0, cropX * 2, 720, cropX, cropY, cropW, cropH);
//    photoFbo.draw(0, 0);
    preview.draw();
    captionFbo.draw(0, CAM_HEIGHT - 50);

    timer.drawCountdown(CAM_WIDTH, CAM_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        text = word.getRandomText();
        timer.start();
    }
    if(key == 'f') {
        ofToggleFullscreen();
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
