#include "videopreview.h"


VideoPreview::~VideoPreview() {
    cam.close();
}


void VideoPreview::setup()
{
    params.setName("Video Parameters");
    params.add(camWidth.set("camera width", 1280, 320, 1920));
    params.add(camHeight.set("camera height", 720, 200, 1200));
    params.add(maskX.set("mask X position", 0, 0, 1920));
    params.add(maskY.set("mask Y position", 0, 0, 1200));
    params.add(maskW.set("mask Width", 320, 0, 1920));
    params.add(maskH.set("mask Height", 720, 0, 1200));
    params.add(aspectRatio.set("aspectRatio", 1.1111, 1, 2.35));

    cam.setDeviceID(0);
    cam.setDesiredFrameRate(30);
    cam.initGrabber(camWidth, camHeight);

    view.allocate(camWidth, camHeight);
    view.begin();
    ofClear(0);
    view.end();
}

void VideoPreview::update()
{
    cam.update();
}

void VideoPreview::draw()
{
    view.begin();
    ofBackground(0);
    ofSetColor(255);
    cam.draw(camWidth, 0, -camWidth, camHeight);
    ofSetColor(0, 50);
    ofFill();
    ofDrawRectangle(ofRectangle(maskX, maskY, maskW, maskH));
    ofDrawRectangle(ofRectangle(camWidth - maskW, maskY, maskW, maskH));
    view.end();
    view.draw(0, 0);
    //ofDrawBitmapString(ofGetFrameRate(), 20, 20);
}

ofImage VideoPreview::grabCroppedFrame()
{
    ofImage img = cam.getPixels();
    img.crop(maskW, 0, camWidth - (maskW * 2), maskH);
    return img;
}
