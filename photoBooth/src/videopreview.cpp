#include "videopreview.h"


VideoPreview::~VideoPreview() {
    cam.close();
}


void VideoPreview::setup()
{
    cam.setDeviceID(0);
    cam.setDesiredFrameRate(30);
    //cam.setup(CAM_WIDTH, CAM_HEIGHT);
    cam.initGrabber(CAM_WIDTH, CAM_HEIGHT);

    view.allocate(CAM_WIDTH, CAM_HEIGHT);
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
    cam.draw(CAM_WIDTH, 0, -CAM_WIDTH, CAM_HEIGHT);
    ofSetColor(0, 50);
    ofFill();
    ofDrawRectangle(0, 0, 240, 720);
    ofDrawRectangle(1040, 0, 240, 720);
    view.end();
    view.draw(0, 0);
    ofDrawBitmapString(ofGetFrameRate(), 20, 20);
}

//ofTexture VideoPreview::getTexture()
//{

//}

//ofTexture VideoPreview::getCroppedTexture()
//{

//}
