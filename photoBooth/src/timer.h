#pragma once

#ifndef TIMER_H
#define TIMER_H

#include "ofMain.h"

class Timer
{
public:
    ~Timer();
    void setup(float t); // milliseconds
    void update();
    void start();
    void stop();
    void reset();
    void drawCountdown(int width, int height);

    ofEvent<const bool> timerEnded;
    void onTimerEnd(const bool &val);

    //float getElapsedTimeF();

    float duration;
    float newTime;
    int countdown;
    bool bStopped;

    bool bFlash;
    float flashFade;

    ofFbo fbo;

    ofTrueTypeFont countdownText;
};

#endif // TIMER_H
