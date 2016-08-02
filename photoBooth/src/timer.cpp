#include "timer.h"

Timer::~Timer() {
    ofRemoveListener(this->timerEnded, this, &Timer::onTimerEnd);
}

void Timer::setup(float t) {
    duration = t;
    countdownText.load("verdana.ttf", 300, true, true);
    countdownText.setLineHeight(300.0f);
    countdownText.setLetterSpacing(1.055);

    this->reset();

    ofAddListener(this->timerEnded, this, &Timer::onTimerEnd);

    fbo.allocate(1280, 800);
    fbo.begin();
    ofClear(0);
    fbo.end();
}

void Timer::onTimerEnd(const bool &val){
    bStopped = true;
    bFlash = true;
}

void Timer::update() {
    if(!bStopped){
        float elapsedTime = ofGetElapsedTimef();
        if (elapsedTime - newTime > 1) {
            newTime = ofGetElapsedTimef();
            countdown--;
        }
        if(countdown < 0) {
            bStopped = true;
            ofNotifyEvent(timerEnded, true);
        }
    }
}

void Timer::start() {
    newTime = ofGetElapsedTimef();
    bStopped = false;

}

void Timer::stop() {
    bStopped = true;
}

void Timer::reset() {
    countdown = duration;
    bStopped = true;
    bFlash = false;

    flashFade = 255.f;
}

void Timer::drawCountdown(int width, int height) {
    if(!bStopped && countdown >= 1) {
        string count = ofToString(countdown);
        ofRectangle contour = countdownText.getStringBoundingBox(count, 0, 0);
        int x = (width / 2) - (contour.getWidth() / 2);
        int y = (height / 2) - (contour.getHeight() / 2) + 200;
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
        }
    }
}

