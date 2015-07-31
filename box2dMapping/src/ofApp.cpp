#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    setupGui();
    
    bGui = false;
    g = 10.0;
    
    //fbo.allocate(ofGetWidth(), ofGetHeight());
    
    box2d.init();
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.setGravity(ofPoint(0, g, 0));
    
    svg.load("2.svg");
    
    // get every distinct shapes from the SVG file one by one
    for (int i = 0; i < svg.getNumPath(); i++) {
        
        // grab a shape
        ofPath shape = svg.getPathAt(i);
        
        // store its color and stroke width
        shapeColors.push_back(shape.getStrokeColor());
        strokeWidth.push_back(shape.getStrokeWidth());
        
        // grab the outline from the shape
        for(int j = 0; j < shape.getOutline().size(); j++) {
            ofPolyline line = shape.getOutline().at(j);
            
            // if this is a closed shape, join the first and last points
            // to close the contour
            if(line.isClosed()) {
                line.addVertex(line.getVertices()[0]);
            }
            
            // create a box2dEdge from the shape to make it interact with
            // other ojects into the box2d world
            shared_ptr <ofxBox2dEdge> edge = shared_ptr<ofxBox2dEdge>(new ofxBox2dEdge);
            edge->addVertexes(line);
            edge->setPhysics(0.0, 0.1, 0.7);
            edge->create(box2d.getWorld());
            edges.push_back(edge);
        }
    }
    
    syphonServer.setName("SVG Mapping Content");
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //fbo.begin();
    ofBackground(30);
    
    ofSetColor(250);
    ofDrawBitmapString("number of boxes : ", 10, 10);
    ofDrawBitmapString(ofToString(blocks.size()), 200, 10);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 20);
    
    // draw shapes
    for(int i = 0; i < edges.size(); i++) {
        ofSetColor(shapeColors[i]);
        ofSetLineWidth(strokeWidth[i]);
        edges[i]->draw();
    }

    // draw physics particles
    for(int i = 0; i < blocks.size(); i++){
        ofSetColor(12, 220, 50);
        blocks[i]->draw();
    }
    
    //fbo.end();
    
    //fbo.draw(0, 0);
    
    //syphonServer.publishTexture(&fbo.getTextureReference());
    
    if(bGui){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::setupGui(){
    gui.setup();
    
    gui.add(lineMode.set("Winding Mode", 2, 0, 5));
    gui.add(lifetime.set("Particle lifetime", 10, 1, 30));
    gui.add(bPhysics.set("Use physics", true));
    gui.add(bContact.set("Contact detection", false));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_TAB){
        g *= -1;
        box2d.setGravity(ofPoint(0, g, 0));
    }
    if(key == 'b'){
        bGui = !bGui;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    float w = ofRandom(10, 30);
    float h = ofRandom(10, 30);
    blocks.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
    blocks.back().get()->setPhysics(1.0, 0.4, 0.5);
    blocks.back().get()->setup(box2d.getWorld(), x, y, w, h);
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
