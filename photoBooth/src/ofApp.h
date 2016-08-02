#pragma once

#include "ofMain.h"
#include "timer.h"
#include "textpicker.h"
#include "videopreview.h"

#define CAM_WIDTH 1280
#define CAM_HEIGHT 720

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    //ofVideoGrabber cam;
    VideoPreview preview;
    ofFbo photoFbo;
    ofFbo captionFbo;

    TextPicker word;
    ofTrueTypeFont verdana30;
    string text;

    Timer timer;

};
