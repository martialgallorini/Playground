#pragma once

#ifndef VIDEOPREVIEW_H
#define VIDEOPREVIEW_H

#define CAM_WIDTH 1280
#define CAM_HEIGHT 720

#include "ofMain.h"

class VideoPreview
{
public:
    ~VideoPreview();
    void setup();
    void update();
    void draw();
//    ofTexture getTexture();
//    ofTexture getCroppedTexture();

    ofVideoGrabber cam;

    ofFbo view;
};

#endif // VIDEOPREVIEW_H
