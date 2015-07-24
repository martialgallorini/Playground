#include "ofApp.h"

const int n = 100;		//Number of cloud points

//Offsets for Perlin noise calculation for points
float tx[n], ty[n];
ofPoint p[n];			//Cloud's points positions

float time0 = 0;		//Time value, used for dt computing



//--------------------------------------------------------------
void ofApp::setup(){

    time0 = 0;
    
    gui.setup();
    gui.add(Rad.set("radius", 500, 100, 800));
    gui.add(Vel.set("velocity", 0.1, 0.0, 1.0));
    
	//Initialize points offsets by random numbers
	for ( int j=0; j<n; j++ ) {
		tx[j] = ofRandom( 0, 1000 );	
		ty[j] = ofRandom( 0, 1000 );
	}
}

//--------------------------------------------------------------
void ofApp::update(){	

	//Computing dt as a time between the last
	//and the current calling of update() 	
	float time = ofGetElapsedTimef();
	float dt = time - time0;
	dt = ofClamp( dt, 0.0, 0.1 );	
	time0 = time; //Store the current time	

	//Update particles positions
	for (int j=0; j<n; j++) {
		tx[j] += Vel * dt;	//move offset
		ty[j] += Vel * dt;	//move offset
		//Calculate Perlin's noise in [-1, 1] and
		//multiply on Rad
		p[j].x = ofSignedNoise( tx[j] ) * Rad;		
		p[j].y = ofSignedNoise( ty[j] ) * Rad;	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set up the background
    
	//Draw cloud

	//Move center of coordinate system to the screen center
	ofPushMatrix();
	ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );

	//Draw points
	ofSetColor( 0, 0, 0 );
	ofFill();
	for (int i=0; i<n; i++) {
		ofCircle( p[i], 2 );
	}

	//Draw lines between near points
	float dist = 40;	//Threshold parameter of distance
	for (int j=0; j<n; j++) {
		for (int k=j+1; k<n; k++) {
			if ( ofDist( p[j].x, p[j].y, p[k].x, p[k].y )
				< dist ) {
					ofLine( p[j], p[k] );
			}
		}
	}

	//Restore coordinate system
	ofPopMatrix();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}