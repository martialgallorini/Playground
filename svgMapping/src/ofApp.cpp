#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    //    ofDisableAlphaBlending();
    //    ofDisableDepthTest();
    //    ofDisableLighting();
    
    svg.load("1.svg");
    
    // grab individual shapes from SVG file
    for(int i = 0; i < svg.getNumPath(); i++) {
        Shape s;
        s.setup(svg.getPathAt(i));
        shapes.push_back(s);
    }
    
    bGrabControl = false;
    activeControl = -1;
    activeShape = NULL;       // active shape
    //bShowControls = false;
    
    syphonServer.setName("SVG Mapping");
    
    // SCENE GUI
    sceneGui.setup();
    sceneGui.setName("SCENE SETTINGS");
    sceneGui.add(enableOsc.set("Enable OSC", false));
    sceneGui.add(enableSyphon.set("Enable Syphon", false));
    sceneGui.add(editMode.set("Edit mode", false));
    
    // SHAPE GUI - populated from a shape when single shape mode activated
    shapeGui.setup();
    shapeGui.setName("SHAPE SETTINGS");
    shapeGui.setPosition(sceneGui.getPosition().x, sceneGui.getPosition().y + sceneGui.getHeight() + 5);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //    // show control points
    //    if (editMode) {
    //        for(int i = 0; i < shapes.size(); i++) {
    //            shapes.at(i).bCommands = !shapes.at(i).bCommands;
    //        }
    //    }
    
    //    // edit shape moving control point
    //    if (editMode && bGrabControl) {
    //        shapes[activeShape].update();
    //    }
    
    // edit shape moving control point
    if (editMode) {
        
        if (bGrabControl){
            activeShape->update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(200);
    
    // draw shapes
    for(int i = 0; i < shapes.size(); i++) {
        shapes.at(i).draw();
    }
    
    // if a control point is grabbed, display debug info
    if (editMode && bGrabControl) {
        ofDrawBitmapString("Command grabbed !", 200, 20);
        ofDrawBitmapString("Active Shape : ", 200, 35);
        ofDrawBitmapString(ofToString(activeShape), 400, 35);
        ofDrawBitmapString("Active Control point : ", 200, 50);
        ofDrawBitmapString(ofToString(activeControl), 400, 50);
        ofDrawBitmapString("position clicked : ", 200, 65);
        string coord = ofToString(mouseX) + " : " + ofToString(mouseY);
        ofDrawBitmapString(coord, 400, 65);
        //        coord = ofToString(shapes[activeShape].contour.getCentroid2D().x) + " : " + ofToString(shapes[activeShape].contour.getCentroid2D().x);
        //        ofDrawBitmapString(coord, 400, 80);
    }
    
    // GUI
    if (bShowGui) {
        sceneGui.draw();
        if (editMode) {
            shapeGui.draw();
        }
    }
    syphonServer.publishScreen();
}

//--------------------------------------------------------------
void ofApp::populateShapeGui(){
    shapeGui.clear();
    shapeGui.add(activeShape->groupGeometry);
    shapeGui.add(activeShape->groupGraphics);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // toggle edit mode (shows control points)
    if (key == OF_KEY_TAB) {
        editMode = !editMode;
    }
    
    // toggle edit mode (shows control points)
    if (key == 'p') {
        bShowGui = !bShowGui;
    }
    
    // save scene to SVG file
    if (key == 's') {
        ofCairoRenderer save;   // save scene to an SVG file
        save.setup("mapping.svg", ofCairoRenderer::SVG);
        save.viewport();
        save.clear(0);
        save.background(0);
        for (int i = 0; i < shapes.size(); i++) {
            save.draw(shapes[i].path);
        }
        save.close();
        save.flush();
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    // move grabbed control point
    if (bGrabControl) {
        ofPoint m = ofPoint(x, y);
        activeShape->controls[activeControl].to.set(m);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // set active shape if shape selected
    if (editMode) {
        activeShape = NULL;
        for(int i = 0; i < shapes.size(); i++) {
            if (shapes[i].inside(x, y)) {
                activeShape = &shapes[i];
                activeShape->bCommands = true;
            }
            else {
                shapes[i].bCommands = false;
            }
        }
        
        // check if mouse if hovering a control point in edit mode
        if (activeShape != NULL) {
            int cIndex = activeShape->controlHovered(x, y);
            if (cIndex != -1) {
                bGrabControl = true;
                activeControl = cIndex;
            }
            populateShapeGui();
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    bGrabControl = false;
    activeControl = -1;
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
