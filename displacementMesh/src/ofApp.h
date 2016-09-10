#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

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
    
    void onZOffsetChanged(float &val);
    void onYOffsetChanged(float &val);
    void onPointSizeChanged(float &val);
    void onShadeModelChange(bool &val);
    void onGLModeChange(int &val);
    
    ofImage img; // loaded image
    
    int maxBright; // image max brightness
    int minBright; // image min brightness
    
    void createMesh(ofImage &img);
    
    ofVboMesh mesh;
    
    ofEasyCam cam;
    
    bool bSetup;
    
    ofxPanel gui;
    ofParameterGroup meshGroup;
    ofParameter<int> resolution;
    ofParameter<int> GLMode;     // Change Mesh display mode
    ofParameter<float> zOffset;
    ofParameter<bool> bInvertZOffset;
    ofParameter<float> yOffset;
    ofParameter<bool> bInvertYOffset;
    ofParameter<float> pointSize;
    ofParameter<bool> bFaces;
    ofParameter<bool> bTriangles;
    ofParameter<bool> bPoints;
    ofParameter<float> minAlpha;
    ofParameter<float> maxAlpha;
    ofParameter<float> distanceLimit;
    ofParameter<bool> bSmooth;
    
    // display circles radius relative to brightness at mesh vertices position
    ofParameterGroup circlesGroup;
    ofParameter<bool> bCircle;
    ofParameter<bool> bCircleFill;
    
    // display circles radius relative to brightness at mesh vertices position
    ofParameterGroup squaresGroup;
    ofParameter<bool> bRect;
    ofParameter<bool> bRectFill;
    ofParameter<bool> bRotation;
    
    // display horizontal lines stroke width relative to brightness using mesh vertices position
    ofParameterGroup stripesGroup;
    ofParameter<bool> bStripes;
    ofParameter<float> minStrokeWidth;
    ofParameter<float> maxStrokeWidth;
    ofParameter<bool> bColor;
    ofParameter<bool> bGray;
    ofParameter<bool> bWhite;
    ofParameter<bool> bInvert;
};
