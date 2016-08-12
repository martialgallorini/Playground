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
    
    snapCount = 0;
    
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
    ofImage img;
    if (compose.bGrid) {
        snapCount++;
        if (snapCount <= 4) {
            img = preview.grabCroppedFrame();
            compose.add(img, text);
            if(snapCount == 4) {
                snapCount = 0;
                compose.create();
                compose.save();
            }
            else {
                timer.start();
            }
        }
    }
    else {
        img = preview.grabCroppedFrame();
        compose.add(img, text);
        compose.create();
        compose.save();
    }
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
    if(key == OF_KEY_TAB) {
        bSetup = !bSetup;
    }
    if(key == 'p') {
        system("lp /Users/Martial/Desktop/DEV/oF093/apps/playground/photoBooth/bin/data/test.png");
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
