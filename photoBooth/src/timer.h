#pragma once

#ifndef TIMER_H
#define TIMER_H

#include "ofMain.h"

class Timer
{
public:
    ~Timer();
    void setup();
    void update();
    void start();
    void reset();
    void drawCountdown(int width, int height);
    bool isTimedOut();

    ofEvent<const bool> timerEnded;

    float newTime;
    int countdown;
    bool bTimeout;

    bool bFlash;
    float flashFade;

    ofFbo fbo;

    ofTrueTypeFont countdownText;
    
    ofParameterGroup params;
    ofParameter<int> duration;
    ofParameter<int> fontSize;
    ofParameter<float> x;
    ofParameter<float> y;
};

#endif // TIMER_H
