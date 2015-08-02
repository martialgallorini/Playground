#pragma once

#include "ofMain.h"
#include "ball.h"

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
		
    ofPoint dist;
    ofPoint attraction;
    
    vector<ball> balls;
    
    float k;
    float friction;

    float limit;
    
    float ballRadius;
};

