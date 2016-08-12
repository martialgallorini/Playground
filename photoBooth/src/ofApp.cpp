#include "ofApp.h"


// TODO :
// - init layout values after defining comp size + border


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(30);
    
    captionFbo.allocate(ofGetWidth(), 50);
    captionFbo.begin();
    ofClear(0);
    captionFbo.end();
    
    verdana30.load("verdana.ttf", 30, true, true);
    verdana30.setLineHeight(30.0f);
    verdana30.setLetterSpacing(1.055);
    
    word.init();
    timer.setup();
    compose.setup();
    preview.setup();
    
    gui.setup("Global Parameters");
    gui.add(compose.params);
    gui.add(preview.params);
    gui.add(timer.params);
    gui.loadFromFile("settings.xml");
    
    bSetup = false;
    
    timer.reset();
    
    ofAddListener(timer.timerEnded, this, &ofApp::onTimerEnd);
}

//--------------------------------------------------------------
void ofApp::update(){
    preview.update();
    timer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    preview.draw();
    
    if(!timer.isTimedOut()) {
        captionFbo.begin();
        ofBackground(50);
        ofSetColor(200);
        ofRectangle bounds = verdana30.getStringBoundingBox(text, 0, 0);
        float w = (captionFbo.getWidth() / 2) - (bounds.getWidth() / 2);
        float h = verdana30.getLineHeight() + 5;
        verdana30.drawString(text, w, h);
        captionFbo.end();
        captionFbo.draw(0, ofGetHeight() - 50);
        timer.drawCountdown(ofGetWidth(), ofGetHeight());
    }
    
    if(bSetup) {
        gui.draw();
    }
}

void ofApp::exit() {
    ofRemoveListener(timer.timerEnded, this, &ofApp::onTimerEnd);
}

void ofApp::onTimerEnd(const bool &val) {
    ofImage img = preview.grabCroppedFrame();
    compose.add(img, text);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        if(compose.bGrid) {
        
        }
        else {
            text = word.getRandomText();
            timer.start();
        }
        //compose.create();
        //compose.save();
    }
    if(key == 'f') {
        ofToggleFullscreen();
    }
    if(key == OF_KEY_TAB) {
        bSetup = !bSetup;
    }
    if(key == 'c') {
        compose.create();
        compose.save();
    }
    if(key == 'q') {
        
        // 1 IMAGE :
        // image height = cam height
        // image width = ratio * image height
        // mask width = cam width - image width
        // if needed : scale image to fit compose - (margin * 2)
        
        // 4 IMAGES :
        
        ofImage img;
        text = word.getRandomText();
        for(int i = 0; i < 4; i++) {
            img = preview.grabCroppedFrame();
            compose.add(img, text);
        }
        compose.create();
        compose.save();
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
