#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowTitle("Arcs");
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    arcsGUI.setup();
    arcsGUI.add(drawNegative.setup("Draw Negative", true));
    arcsGUI.add(equalArcs.setup("Arc Negative = Arc", false));
    arcsGUI.add(arcClosed.setup("Close", true));
    arcsGUI.add(arcResolution.setup("Resolution", 60, 0, 100));
    arcsGUI.add(arcPolyWinding.setup("Poly Winding", 2, 0, 4));
    arcsGUI.add(arcStrokeWidth.setup("Stroke Width", 1, 0, 10));
    arcsGUI.add(arc.setup("Arc", " "));
    arcsGUI.add(arcRadiusX.setup("Radius X", 225, 0, 500));
    arcsGUI.add(arcRadiusY.setup("Radius Y", 225, 0, 500));
    arcsGUI.add(arcAngleBegin.setup("Angle Begin", 0, 0, 360));
    arcsGUI.add(arcAngleEnd.setup("Angle End", 270, 0, 360));
    arcsGUI.add(arcClock.setup("Clock Wise", true));
    arcsGUI.add(arcNegative.setup("Arc Negative", " "));
    arcsGUI.add(arcNegRadiusX.setup("Radius X", 200, 0, 500));
    arcsGUI.add(arcNegRadiusY.setup("Radius Y", 200, 0, 500));
    arcsGUI.add(arcNegAngleBegin.setup("Angle Begin", 270, 0, 360));
    arcsGUI.add(arcNegAngleEnd.setup("Angle End", 0, 0, 360));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint p(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    curve.arc(p, arcRadiusX, arcRadiusY, arcAngleBegin, arcAngleEnd, arcClock);
    if (drawNegative) {
        if (equalArcs) curve.arcNegative(p, arcNegRadiusX, arcNegRadiusY, arcAngleEnd, arcAngleBegin);
        else curve.arcNegative(p, arcNegRadiusX, arcNegRadiusY, arcNegAngleBegin, arcNegAngleEnd);
    }
    
    if (arcClosed) curve.close();
    
    switch (arcPolyWinding) {
        case 0:
            curve.setPolyWindingMode(OF_POLY_WINDING_ABS_GEQ_TWO);
            break;
        case 1:
            curve.setPolyWindingMode(OF_POLY_WINDING_NEGATIVE);
            break;
        case 2:
            curve.setPolyWindingMode(OF_POLY_WINDING_NONZERO);
            break;
        case 3:
            curve.setPolyWindingMode(OF_POLY_WINDING_ODD);
            break;
        case 4:
            curve.setPolyWindingMode(OF_POLY_WINDING_POSITIVE);
            
        default:
            break;
    }
    
    curve.setStrokeColor(MYORANGE);
    curve.setStrokeWidth(arcStrokeWidth);
    curve.setCircleResolution(arcResolution);
    curve.setCurveResolution(arcResolution);
    curve.setFillColor(MYGREEN);
    curve.setFilled(true);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(MYGRAY);
    
    curve.draw();
    curve.clear();
    
    arcsGUI.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
