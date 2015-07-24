#pragma once

#include "ofMain.h"
#include "ofxFaceTrackerThreaded.h"
#include "ofxCv.h"
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage img;
    ofVideoGrabber cam;
    ofxFaceTrackerThreaded tracker;
    
    ofxPanel gui;
    
    ofParameter<float> imgOffsetY;
    ofParameter<float> imgScale;
    
};
