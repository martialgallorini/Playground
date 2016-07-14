#pragma once

#define MAP_SCALE 30

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
    void onWindingmodeChanged(int &val);
    void onPointSizeChanged(float &val);
		
    ofVboMesh mesh;
    
    ofImage image;
    ofImage scaledImage;
    
    ofEasyCam cam;
    
    ofLight light;
    
    ofxPanel gui;
    ofParameter<float> displacement;
    ofParameter<int> windingMode;
    ofParameter<float> pointSize;
    
    bool bSetup;
};
