#pragma once

#ifndef VIDEOPREVIEW_H
#define VIDEOPREVIEW_H

#include "ofMain.h"

class VideoPreview
{
public:
    ~VideoPreview();
    void setup();
    void update();
    void draw();
    ofImage grabCroppedFrame();

    ofVideoGrabber cam;

    ofFbo view;
    
    ofParameterGroup params;
    ofParameter<int> camWidth;
    ofParameter<int> camHeight;
    ofParameter<int> maskX;
    ofParameter<int> maskY;
    ofParameter<int> maskW;
    ofParameter<int> maskH;
    ofParameter<float> aspectRatio;
};

#endif // VIDEOPREVIEW_H
