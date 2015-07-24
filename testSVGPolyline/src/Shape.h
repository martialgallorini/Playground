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
    
    // is control point hovered ?
    int controlHovered(float x, float y);
    
    // shape path
    ofPath path;
    
    // control points
    vector<ofPath::Command> controls;
    
    bool bCommands;         // edit mode
    bool bCommandGrab;      // grab command point with mouse
    float commandRadius;
    
};

#endif /* defined(__testSVGPolyline__Shape__) */
