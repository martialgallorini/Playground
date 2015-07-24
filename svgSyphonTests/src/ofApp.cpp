#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(0);
	ofSetColor(255);
	
	svg.load("abak.svg");
	for (int i = 0; i < svg.getNumPath(); i++){
		ofPath p = svg.getPathAt(i);
		// svg defaults to non zero winding which doesn't look so good as contours
		p.setPolyWindingMode(OF_POLY_WINDING_ODD);
		vector<ofPolyline>& lines = p.getOutline();
		for(int j=0;j<(int)lines.size();j++){
			outlines.push_back(lines[j].getResampledBySpacing(1));
		}
	}
    
    gui.setup();
    gui.add(speed.set("speed", 1, 1, 10));
    
    syphonServer.setName("oF Syphon");
}


//--------------------------------------------------------------
void ofApp::update(){
	step += 0.001;
	if (step > 1) {
		step = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofPushMatrix();
    ofNoFill();
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & line = outlines[i];
        
        int num = step * line.size();
        
        ofBeginShape();
        for (int j = 0; j < num; j++){
            ofVertex(line[j]);
        }
        ofEndShape();
        ofPopMatrix();
    }
    syphonServer.publishScreen();
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
