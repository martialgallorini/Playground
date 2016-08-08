#include "timer.h"


// TODO :
// - timer in center -> position rectangle = center plut™t que upper left corner
//
//Timer::Timer(float t) {
//    
//}

Timer::~Timer() {
    //ofRemoveListener(this->timerEnded, this, &Timer::onTimerEnd);
}

void Timer::setup() {
    
    params.setName("Timer Parameters");
    params.add(duration.set("duration", 5, 1, 60));
    params.add(fontSize.set("font size", 200, 20, 400));
    params.add(x.set("position X", 200, 0, 1920));
    params.add(y.set("position Y", 200, 0, 1200));

    countdownText.load("verdana.ttf", fontSize, true, true);
    countdownText.setLineHeight(fontSize);
    countdownText.setLetterSpacing(1.055);

    //ofAddListener(this->timerEnded, this, &Timer::onTimerEnd);
}

//void Timer::onTimerEnd(const bool &val){
//    //bTimeout = true;
//    //bFlash = true;
//}

bool Timer::isTimedOut() {
    return bTimeout;
}

void Timer::update() {
    if(!bTimeout){
        float elapsedTime = ofGetElapsedTimef();
        if (elapsedTime - newTime > 1) {
            newTime = ofGetElapsedTimef();
            countdown--;
        }
        if(countdown < 0) {
            bFlash = true;
            //ofNotifyEvent(timerEnded, true);
        }
    }
}

void Timer::start() {
    newTime = ofGetElapsedTimef();
    bTimeout = false;

}

void Timer::reset() {
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0);
    fbo.end();
    countdown = duration;
    bTimeout = true;
    bFlash = false;

    flashFade = 255.f;
}

void Timer::drawCountdown(int width, int height) {
    if(!bTimeout && countdown >= 1) {
        string count = ofToString(countdown);
        ofRectangle contour = countdownText.getStringBoundingBox(count, 0, 0);
        x = (width / 2) - (contour.getWidth() / 2);
        y = (height / 2) - (contour.getHeight() / 2) + 200;
        countdownText.drawString(count, x, y);
    }
    if(bFlash){
        if(flashFade > 0) {
            fbo.begin();
            ofSetColor(255 , flashFade);
            ofDrawRectangle(0, 0 ,1280, 800);
            fbo.end();
            fbo.draw(0, 0);
            flashFade-=30;
        }
        else {
            this->reset();
            ofNotifyEvent(timerEnded, true);
        }
    }
}

