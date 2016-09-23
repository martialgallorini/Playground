#pragma once

#include "ofMain.h"
#include "timer.h"
#include "textpicker.h"
#include "videopreview.h"
#include "composer.h"
#include "ofxGui.h"
#include "printer.h"
#include "thermalPrinter.h"
#include "defines.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

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
    
    void onTimerEnd(const bool &val);

    VideoPreview preview;
    Composer compose;
    ofFbo captionFbo;
    
    int snapCount;

    TextPicker word;
    ofTrueTypeFont verdana30;
    string text;

    Timer timer;

    ofxPanel gui;

    bool bSetup;
    
    Printer *printer;
};
