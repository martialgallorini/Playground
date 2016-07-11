#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    image.load("image.jpg");
    ofSetWindowShape(image.getWidth(), image.getHeight());
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    mesh.enableIndices();
    glPointSize(3);
    
    //ofxCvGrayscaleImage grayMap;
    ofImage scaledImage;
    scaledImage = image;
    //grayMap.blur();
    //scaledImage.setImageType(OF_IMAGE_GRAYSCALE);
    scaledImage.resize(image.getWidth() / MAP_SCALE, image.getHeight() / MAP_SCALE);
    
    int width = scaledImage.getWidth();
    int height = scaledImage.getHeight();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            //ofColor c = grayMap.getPixels().getColor(x, y);
            ofColor c = scaledImage.getColor(x, y);
            float brightness = c.getBrightness();
            ofMap(brightness, 0, 1, -40, 40);
            ofPoint p(x * MAP_SCALE, y * MAP_SCALE, brightness);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x * MAP_SCALE, y * MAP_SCALE));
        }
    }
    
    //add indices
    for (int y = 0; y< height - 1; y++){
        for (int x=0; x < width - 1; x++){
            mesh.addIndex(x+y*width);               // 0
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex(x+(y+1)*width);           // 10
            
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex((x+1)+(y+1)*width);       // 11
            mesh.addIndex(x+(y+1)*width);           // 10
        }
    }
    
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
