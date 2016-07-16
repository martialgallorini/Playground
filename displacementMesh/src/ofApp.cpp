#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    image.load("image.jpg");
    ofSetWindowShape(image.getWidth(), image.getHeight());
    
    gui.setup();
    gui.add(displacement.set("displacement", 40., 1., 1000.));
    gui.add(pointSize.set("point size", 3, 1, 10));
    gui.add(minAlpha.set("minimum mesh alpha", 50, 0, 255));
    gui.add(maxAlpha.set("maximum mesh alpha", 255, 0, 255));
    gui.add(distanceLimit.set("vertices distance", 400, 1, 1000));
    gui.add(bPoints.set("draw points", false));
    gui.add(bLines.set("draw lines", false));
    gui.add(bFaces.set("draw faces", false));
    gui.add(bSmooth.set("smooth shading", true));
    gui.loadFromFile("settings.xml");
    
    bSetup = true;
    
#ifdef SCALE_METHOD
    
    // using scaled image to generate mesh
    
    int scaledW = image.getWidth() / STEP;
    int scaledH = image.getHeight() / STEP;
    
    image.resize(scaledW, scaledH);
    
    for (int y = 0; y < scaledH; y++) {
        for (int x = 0; x < scaledW; x++) {
            ofColor c = image.getColor(x, y);
            float brightness = ofMap(c.getBrightness(), 0, 255, 0, displacement);
            ofPoint p(x * STEP, y * STEP, brightness);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x, y));
        }
    }
    
    //add indices
    for (int y = 0; y < scaledH - 1; y++){
        for (int x = 0; x < scaledW -1; x++){
            mesh.addIndex(x+y*scaledW);               // 0
            mesh.addIndex((x+1)+y*scaledW);           // 1
            mesh.addIndex(x+(y+1)*scaledW);           // 10
            
            mesh.addIndex((x+1)+y*scaledW);           // 1
            mesh.addIndex((x+1)+(y+1)*scaledW);       // 11
            mesh.addIndex(x+(y+1)*scaledW);           // 10
        }
    }
    
#else
    
    // generating mesh directly from image
    
    for (int y = 0; y < image.getHeight(); y += STEP) {
        for (int x = 0; x < image.getWidth(); x += STEP) {
            ofColor c = image.getColor(x, y);
            float brightness = ofMap(c.getBrightness(), 0, 255, 0, displacement);
            ofPoint p(x, y, brightness);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x, y));
        }
    }
    
    //add indices
    int height = image.getHeight() / STEP;
    int width = image.getWidth() / STEP;
    for (int y = 0; y < height ; y++){
        for (int x = 0; x < width ; x++){
            mesh.addIndex(x+y*width);               // 0
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex(x+(y+1)*width);           // 10
            
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex((x+1)+(y+1)*width);       // 11
            mesh.addIndex(x+(y+1)*width);           // 10
        }
    }
    
#endif
    
    
    mesh.enableColors();
    mesh.enableIndices();
    glPointSize(pointSize);
    
    if (bSmooth) {
        glShadeModel(GL_SMOOTH);
    }
    else {
        glShadeModel(GL_FLAT);
    }
    //glDisable(GL_POINT_SMOOTH);
    //glHint(GL_POINT_SMOOTH_HINT,GL_FASTEST);
    
    wireframe = mesh;
    
    //light.enable();
    //light.setAmbientColor(1.0);
    
    cam.setVFlip(true);
    
    displacement.addListener(this, &ofApp::onDisplacementChanged);
    pointSize.addListener(this, &ofApp::onPointSizeChanged);
    bSmooth.addListener(this, &ofApp::onShadeModelChange);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    ofEnableDepthTest();
    if (bPoints) {
        mesh.drawVertices();
    }
    if (bFaces) {
        mesh.drawFaces();
    }
    if (bLines) {
        wireframe.drawWireframe();
    }
    ofDisableDepthTest();
    ofPopMatrix();
    cam.end();
    
    if (bSetup) {
        gui.draw();
    }
}

void ofApp::exit(){
    displacement.removeListener(this, &ofApp::onDisplacementChanged);
    pointSize.removeListener(this, &ofApp::onPointSizeChanged);
    bSmooth.removeListener(this, &ofApp::onShadeModelChange);
}

void ofApp::onDisplacementChanged(float &val){
    for (int i = 0 ; i < mesh.getNumVertices() ; i++) {
        
        ofColor color = mesh.getColor(i);
        float brightness = ofMap(color.getBrightness(), 0, 255, 0, val);
        
        ofPoint oldPoint = mesh.getVertex(i);
        ofPoint newPoint(oldPoint.x, oldPoint.y, brightness);
        
        float distance = newPoint.distance(mesh.getVertex(i + 3));
        float alpha = ofMap(distance, 1, distanceLimit, minAlpha, maxAlpha);
        ofColor newColor(color.r, color.g, color.b, alpha);
        
        mesh.setVertex(i, newPoint);
        mesh.setColor(i, newColor);
        
        wireframe.setVertex(i, newPoint);
        wireframe.setColor(i, ofColor(ofColor::gray));
    }
}

void ofApp::onPointSizeChanged(float &val){
    glPointSize(val);
}

void ofApp::onShadeModelChange(bool &val){
    if (val) {
        glShadeModel(GL_SMOOTH);
    }
    else {
        glShadeModel(GL_FLAT);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_TAB) {
        bSetup = !bSetup;
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
