#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    image.load("image.jpg");
    ofSetWindowShape(image.getWidth(), image.getHeight());
    
    gui.setup();
    gui.add(displacement.set("displacement", 40., 1., 400.));
    gui.add(windingMode.set("winding mode", 4, 1, 7));
    gui.add(pointSize.set("point size", 3, 1, 10));
    gui.loadFromFile("settings.xml");
    
    bSetup = false;
    
    switch (windingMode) {
        case 1:
            mesh.setMode(OF_PRIMITIVE_TRIANGLES);
            break;
        case 2:
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            break;
        case 3:
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
            break;
        case 4:
            mesh.setMode(OF_PRIMITIVE_LINES);
            break;
        case 5:
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
            break;
        case 6:
            mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
            break;
        case 7:
            mesh.setMode(OF_PRIMITIVE_POINTS);
            break;
        default:
            mesh.setMode(OF_PRIMITIVE_POINTS);
            break;
    }
    mesh.enableColors();
    mesh.enableIndices();
    glPointSize(pointSize);
    //glDisable(GL_POINT_SMOOTH);
    //glHint(GL_POINT_SMOOTH_HINT,GL_FASTEST);

    //light.enable();
    //light.setAmbientColor(1.0);
    
    scaledImage = image;
    scaledImage.resize(image.getWidth() / MAP_SCALE, image.getHeight() / MAP_SCALE);
    
    int width = scaledImage.getWidth();
    int height = scaledImage.getHeight();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ofColor c = scaledImage.getColor(x, y);
            float brightness = ofMap(c.getBrightness(), 0, 1, -displacement, displacement);
            ofPoint p(x * MAP_SCALE, y * MAP_SCALE, brightness);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x * MAP_SCALE, y * MAP_SCALE));
        }
    }
    
    //add indices
    for (int y = 0; y < height - 1; y++){
        for (int x=0; x < width - 1; x++){
            mesh.addIndex(x+y*width);               // 0
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex(x+(y+1)*width);           // 10
            
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex((x+1)+(y+1)*width);       // 11
            mesh.addIndex(x+(y+1)*width);           // 10
        }
    }
    
    cam.setVFlip(true);
    
    displacement.addListener(this, &ofApp::onDisplacementChanged);
    windingMode.addListener(this, &ofApp::onWindingmodeChanged);
    pointSize.addListener(this, &ofApp::onPointSizeChanged);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    mesh.draw();
    ofPopMatrix();
    cam.end();
    
    if (bSetup) {
        gui.draw();
    }
}

void ofApp::exit(){
    displacement.removeListener(this, &ofApp::onDisplacementChanged);
    windingMode.removeListener(this, &ofApp::onWindingmodeChanged);
    pointSize.removeListener(this, &ofApp::onPointSizeChanged);
}

void ofApp::onDisplacementChanged(float &val){
    for (int i = 0 ; i < mesh.getNumVertices() ; i++) {
        
        ofColor color = mesh.getColor(i);
        float brightness = ofMap(color.getBrightness(), 0, 255, -val, val);
        cout << "brightness : " << brightness << endl;

        ofPoint oldPoint = mesh.getVertex(i);
        ofPoint newPoint(oldPoint.x, oldPoint.y, brightness);

        
        float distance = newPoint.distance(mesh.getVertex(i + 1));
        cout << "distance : " << distance << endl;
        float alpha = ofMap(distance, 1, 400, 10, 255);
        ofColor newColor(color.r, color.g, color.b, alpha);
        
        mesh.setVertex(i, newPoint);
        mesh.setColor(i, newColor);
    }
}

void ofApp::onWindingmodeChanged(int &val){
    switch (windingMode) {
        case 1:
            mesh.setMode(OF_PRIMITIVE_TRIANGLES);
            break;
        case 2:
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            break;
        case 3:
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
            break;
        case 4:
            mesh.setMode(OF_PRIMITIVE_LINES);
            break;
        case 5:
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
            break;
        case 6:
            mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
            break;
        case 7:
            mesh.setMode(OF_PRIMITIVE_POINTS);
            break;
        default:
            mesh.setMode(OF_PRIMITIVE_POINTS);
            break;
    }
}

void ofApp::onPointSizeChanged(float &val){
    glPointSize(val);
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
