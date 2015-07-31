//
//  Shape.h
//  testSVGPolyline
//
//  Created by Martial on 17/07/2015.
//
//

#ifndef __testSVGPolyline__Shape__
#define __testSVGPolyline__Shape__

#include <ofMain.h>

class Shape {

public:
    
    Shape();
    ~Shape();
    
    void setup(ofPath p);
    void update();
    void draw();
    
    void updatePath();
    void drawCommands();    // draw commands
    //void drawCp();          // draw control points attached to commands (bezier)
    
    // mouse clic inside shape
    bool inside(float x, float y);
    
    // is control point hovered ?
    int controlHovered(float x, float y);
    
    // shape path
    ofPath path;        // drawing shape
    ofPolyline contour; // processing shape
    
    // control points
    vector<ofPath::Command> controls;
    
    bool bCommands;         // edit mode
    //bool bShowCp;
    
    // Shape GUI
    ofParameterGroup groupGraphics;
    ofParameter<ofColor> strokeColor;
    ofParameter<float> strokeWidth;
    ofParameter<bool> fillShape;
    ofParameter<ofColor> fillColor;
    ofParameterGroup groupGeometry;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<float> rotation;
    ofParameter<float> scale;
    ofParameter<float> commandRadius;
};

#endif /* defined(__testSVGPolyline__Shape__) */
