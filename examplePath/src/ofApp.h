#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    // GUI
    ofxPanel arcsGUI;
    ofxLabel arc, arcNegative;
    ofxIntSlider arcRadiusX, arcRadiusY, arcAngleBegin, arcAngleEnd, arcNegRadiusX, arcNegRadiusY, arcNegAngleBegin, arcNegAngleEnd;
    ofxToggle arcClock, drawNegative, equalArcs, arcClosed;
    ofxIntSlider arcResolution, arcPolyWinding, arcStrokeWidth;
    
    // CURVE
    ofPath curve;
    
    // COLOR
    ofColor MYGRAY = ofColor(32);
    ofColor MYGREEN = ofColor(48, 204, 170);
    ofColor MYORANGE = ofColor(204, 79, 48);

		
};
