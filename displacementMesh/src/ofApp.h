#pragma once

#define STEP 20
#define SCALE_METHOD

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

    void onDisplacementChanged(float &val);
    void onPointSizeChanged(float &val);
    void onShadeModelChange(bool &val);
		
    ofVboMesh mesh;
    ofVboMesh wireframe;
    
    ofImage image;
    
    ofEasyCam cam;
    
    ofLight light;
    
    ofxPanel gui;
    ofParameter<float> displacement;
    ofParameter<float> pointSize;
    ofParameter<bool> bFaces;
    ofParameter<bool> bLines;
    ofParameter<bool> bPoints;
    ofParameter<float> minAlpha;
    ofParameter<float> maxAlpha;
    ofParameter<float> distanceLimit;
    ofParameter<bool> bSmooth;
    
    
    
    bool bSetup;
};
