#include "ofApp.h"


///// TODO !
///// - on resolution change
///// - random interlignes


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    gui.setup("Parameters");
    
    meshGroup.setName("Mesh");
    meshGroup.add(resolution.set("mesh resolution", 4, 1, 30));
    meshGroup.add(zOffset.set("Z offset", 40., 1., 1000.));
    meshGroup.add(bInvertZOffset.set("invert Z offset", false));
    meshGroup.add(yOffset.set("Y offset", 15., 1., 50.));
    meshGroup.add(bInvertYOffset.set("invert Y offset", false));
    meshGroup.add(GLMode.set("GL display mode", 5, 1, 5));
    meshGroup.add(pointSize.set("point size", 3, 1, 10));
    meshGroup.add(minAlpha.set("minimum mesh alpha", 50, 0, 255));
    meshGroup.add(maxAlpha.set("maximum mesh alpha", 255, 0, 255));
    meshGroup.add(distanceLimit.set("vertices distance", 400, 1, 1000));
    meshGroup.add(bPoints.set("draw points", false));
    meshGroup.add(bTriangles.set("draw triangles", false));
    meshGroup.add(bFaces.set("draw faces", false));
    meshGroup.add(bSmooth.set("smooth shading", true));
    
    circlesGroup.setName("Circles");
    circlesGroup.add(bCircle.set("draw circles", false));
    circlesGroup.add(bCircleFill.set("fill shape", false));
    
    squaresGroup.setName("Squares");
    squaresGroup.add(bRect.set("draw rectangles", false));
    squaresGroup.add(bRectFill.set("fill shape", false));
    squaresGroup.add(bRotation.set("rotation", false));
    
    stripesGroup.setName("Stripes");
    stripesGroup.add(bStripes.set("draw stripes", false));
    stripesGroup.add(minStrokeWidth.set("min stroke width", .1, .05, 15.));
    stripesGroup.add(maxStrokeWidth.set("max stroke width", 2., .05, 15.));
    stripesGroup.add(bColor.set("color", true));
    stripesGroup.add(bGray.set("grayscale", false));
    stripesGroup.add(bWhite.set("white only", false));
    stripesGroup.add(bInvert.set("invert", false));
    
    gui.add(meshGroup);
    gui.add(circlesGroup);
    gui.add(squaresGroup);
    gui.add(stripesGroup);
    gui.loadFromFile("settings.xml");
    
    bSetup = false;
    
    img.load("salem.jpg");
    createMesh(img);
    
    minBright = 255;
    maxBright = 0;
    
    cam.setVFlip(true);
    
    zOffset.addListener(this, &ofApp::onZOffsetChanged);
    yOffset.addListener(this, &ofApp::onYOffsetChanged);
    pointSize.addListener(this, &ofApp::onPointSizeChanged);
    bSmooth.addListener(this, &ofApp::onShadeModelChange);
    GLMode.addListener(this, &ofApp::onGLModeChange);
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
    
    // Draw circles at mesh vertices position
    if (bCircle) {
        for (int i = 0; i < mesh.getVertices().size(); i++) {
            ofPoint p(mesh.getVertices().at(i).x, mesh.getVertices().at(i).y, mesh.getVertices().at(i).z);
            ofColor c = mesh.getColor(i);
            float r;
            r = ofMap(c.getBrightness(), 0, 255, 0.05, 2.f);
            ofSetColor(c);
            if (bCircleFill) {
                ofFill();
            }
            else {
                ofNoFill();
            }
            ofDrawCircle(p, r);
        }
    }
    
    // Draw rectangles at mesh vertices position
    if (bRect) {
        for (int i = 0; i < mesh.getVertices().size(); i++) {
            ofPoint p(mesh.getVertices().at(i).x, mesh.getVertices().at(i).y, mesh.getVertices().at(i).z);
            ofColor c = mesh.getColor(i);
            float size;
            size = ofMap(c.getBrightness(), 0, 255, 0.05, 30.f);
            ofSetColor(c);
            if (bRectFill) {
                ofFill();
            }
            else {
                ofNoFill();
            }
            ofSetLineWidth(ofMap(c.getBrightness(), maxBright, minBright, minStrokeWidth, maxStrokeWidth));
            if (bRotation) {
                ofPushMatrix();
                ofTranslate(p);
                ofRotateZ(ofMap(c.getBrightness(), maxBright, minBright, 0, 360));
                //ofRotate(ofMap(c.getBrightness(), maxBright, minBright, 0, 360), 0, 0, 1.);
                ofDrawRectangle(0, 0, 0, size, size);
                ofPopMatrix();
            }
            else {
//                ofBoxPrimitive box;
//                box.setPosition(p);
//                box.set(ofMap(c.getBrightness(), maxBright, minBright, 5, 50));
//                box.rotate(ofMap(c.getBrightness(), maxBright, minBright, 0, 360), 0, 1., 1.);
//                box.draw();
                ofDrawRectangle(p, size, size);
            }
        }
    }
    
    /****** TO CLEAN !!********************************************/
    
    if (bStripes) {
        for (int i = 0 ; i < mesh.getNumVertices() - 1; i++) {
            
            // if reached end of image line, don't draw the line
            if ( (i + 1) % (int)img.getWidth() == 0 ) { i += 1;}
            
            ofPoint p1(mesh.getVertices().at(i).x, mesh.getVertices().at(i).y, mesh.getVertices().at(i).z);
            ofPoint p2(mesh.getVertices().at(i+1).x, mesh.getVertices().at(i+1).y, mesh.getVertices().at(i+1).z);
            ofColor c = mesh.getColor(i);
            if (bGray) {
                ofSetColor(c.getBrightness());
                bWhite = false;
                bColor = false;
            }
            if (bWhite) {
                ofSetColor(255);
                bGray = false;
                bColor = false;
            }
            if (bColor) {
                ofSetColor(c);
                bGray = false;
                bWhite = false;
            }
//            if (bInvert) {
//                ofSetColor(ofColor(255) - c);
//                ofBackground(255);
//            }
//            else {
//                ofBackground(0);
//            }
            ofSetLineWidth(ofMap(c.getBrightness(), maxBright, minBright, minStrokeWidth, maxStrokeWidth));
            ofDrawLine(p1, p2);
        }
    }
    
    
    // Draw horizontal stripes
    //    if (bStripes) {
    //        int count = 0;
    //        for (int i = 0 ; i < mesh.getNumVertices() - 1 ; i++) {
    //            if(count < img.getWidth() - 1) {
    //                ofPoint p1(mesh.getVertices().at(i).x, mesh.getVertices().at(i).y, mesh.getVertices().at(i).z);
    //                ofPoint p2(mesh.getVertices().at(i+1).x, mesh.getVertices().at(i+1).y, mesh.getVertices().at(i+1).z);
    //                ofColor c = mesh.getColor(i);
    //                if (bGrey) {
    //                    ofSetColor(c.getBrightness());
    //                }
    //                else {
    //                    ofSetColor(c);
    //                }
    //                ofSetLineWidth(ofMap(c.getBrightness(), maxBright, minBright, minStrikeWidth, maxStrikeWidth));
    //                ofDrawLine(p1, p2);
    //                count++;
    //            }
    //            else {
    //                count = 0;
    //            }
    //        }
    //    }
    
    /*****************************************************/
    
    if (bPoints) {
        mesh.drawVertices();
    }
    if (bFaces) {
        mesh.drawFaces();
    }
    if (bTriangles) {
        mesh.disableColors();
        mesh.drawWireframe();
        mesh.enableColors();
    }
    ofDisableDepthTest();
    ofPopMatrix();
    cam.end();
    
    if (bSetup) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::exit(){
    zOffset.removeListener(this, &ofApp::onZOffsetChanged);
    yOffset.removeListener(this, &ofApp::onYOffsetChanged);
    pointSize.removeListener(this, &ofApp::onPointSizeChanged);
    bSmooth.removeListener(this, &ofApp::onShadeModelChange);
    GLMode.removeListener(this, &ofApp::onGLModeChange);
}

//--------------------------------------------------------------
void ofApp::onZOffsetChanged(float &val){
    for (int i = 0 ; i < mesh.getNumVertices() ; i++) {
        
        ofColor color = mesh.getColor(i);
        
        float brightness;
        if (bInvertZOffset) {
            brightness = ofMap(color.getBrightness(), 255, 0, -val, val);
        }
        else {
            brightness = ofMap(color.getBrightness(), 0, 255, -val, val);
        }
        
        ofPoint oldPoint = mesh.getVertex(i);
        ofPoint newPoint(oldPoint.x, oldPoint.y, brightness);
        
        float distance = newPoint.distance(mesh.getVertex(i + 3));
        float alpha = ofMap(distance, 1, distanceLimit, minAlpha, maxAlpha);
        ofColor newColor(color.r, color.g, color.b, alpha);
        
        mesh.setVertex(i, newPoint);
        mesh.setColor(i, newColor);
    }
}

//--------------------------------------------------------------
void ofApp::onYOffsetChanged(float &val){
    
    // TO DEBUG !!!!
    
    // ne pas enregistrer vertice + offset mais inclure offset uniquement à l'affichage
    // incompatible avec mesh ?
    
    for (int i = 0 ; i < mesh.getNumVertices() ; i++) {
        
        ofColor color = mesh.getColor(i);
        
        float brightness;
        if (bInvertYOffset) {
            brightness = ofMap(color.getBrightness(), 255, 0, 0, yOffset);
        }
        else {
            brightness = ofMap(color.getBrightness(), 0, 255, 0, yOffset);
        }
        if (brightness < minBright) {
            minBright = brightness;
        }
        else if (brightness > maxBright) {
            maxBright = brightness;
        }
        
        ofPoint oldPoint = mesh.getVertex(i);
        ofPoint newPoint(oldPoint.x, val, oldPoint.z);
        mesh.setVertex(i, newPoint);
    }
}

//--------------------------------------------------------------
void ofApp::onPointSizeChanged(float &val){
    glPointSize(val);
}

//--------------------------------------------------------------
void ofApp::onShadeModelChange(bool &val){
    if (val) {
        glShadeModel(GL_SMOOTH);
    }
    else {
        glShadeModel(GL_FLAT);
    }
}

//--------------------------------------------------------------
void ofApp::onGLModeChange(int &val) {
    switch (val) {
        case 1:
            mesh.setMode(OF_PRIMITIVE_LINES);
            break;
        case 2:
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
            break;
        case 3:
            mesh.setMode(OF_PRIMITIVE_PATCHES);
            break;
        case 4:
            mesh.setMode(OF_PRIMITIVE_POINTS);
            break;
        case 5:
            mesh.setMode(OF_PRIMITIVE_TRIANGLES);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::createMesh(ofImage &image) {
    
    // using scaled image to generate mesh
    
    ofSetWindowShape(image.getWidth(), image.getHeight());
    
    int scaledW = image.getWidth() / resolution;
    int scaledH = image.getHeight() / resolution;
    
    image.resize(scaledW, scaledH);
    
    mesh.clear();
    mesh.enableColors();
    mesh.enableIndices();
    glPointSize(pointSize);
    
    
    ///********* TESTING STUFF ! TO MAKE MORE GENERIC *********************/
    for (int y = 0; y < scaledH; y++) {
        for (int x = 0; x < scaledW; x++) {
            ofColor c = image.getColor(x, y);
            float brightness;
            if (bInvertYOffset) {
                brightness = ofMap(c.getBrightness(), 255, 0, 0, yOffset);
            }
            else {
                brightness = ofMap(c.getBrightness(), 0, 255, 0, yOffset);
            }
            if (brightness < minBright) {
                minBright = brightness;
            }
            else if (brightness > maxBright) {
                maxBright = brightness;
            }
            ofPoint p(x * resolution, (y * resolution) + brightness, 0);
            mesh.addVertex(p);
            mesh.addColor(image.getColor(x, y));
        }
    }
    ///*****************************************************************/
    
    //    for (int y = 0; y < scaledH; y++) {
    //        for (int x = 0; x < scaledW; x++) {
    //            ofColor c = image.getColor(x, y);
    //            float brightness;
    //            if (bInvertDisplacement) {
    //                brightness = ofMap(c.getBrightness(), 255, 0, -displacement, displacement);
    //            }
    //            else {
    //                brightness = ofMap(c.getBrightness(), 0, 255, -displacement, displacement);
    //            }
    //            ofPoint p(x * STEP, y * STEP, brightness);
    //            mesh.addVertex(p);
    //            mesh.addColor(image.getColor(x, y));
    //        }
    //    }
    //
    //add indices
    for (int y = 0; y <= scaledH - 1; y++){
        for (int x = 0; x <= scaledW - 1; x++){
            mesh.addIndex(x+y*scaledW);               // 0
            mesh.addIndex((x+1)+y*scaledW);           // 1
            mesh.addIndex(x+(y+1)*scaledW);           // 10
            
            mesh.addIndex((x+1)+y*scaledW);           // 1
            mesh.addIndex((x+1)+(y+1)*scaledW);       // 11
            mesh.addIndex(x+(y+1)*scaledW);           // 10
        }
    }
    
    if (bSmooth) {
        glShadeModel(GL_SMOOTH);
    }
    else {
        glShadeModel(GL_FLAT);
    }
    //glDisable(GL_POINT_SMOOTH);
    //glHint(GL_POINT_SMOOTH_HINT,GL_FASTEST);
    
    //    wireframe = mesh;
    
    //light.enable();
    //light.setAmbientColor(1.0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_TAB) {
        bSetup = !bSetup;
    }
    if(key==' ') {
        string fileName = "";
        fileName = ofSystemTextBoxDialog("Load image", fileName);
        ofImage newImage;
        newImage.load(fileName);
        createMesh(newImage);
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
