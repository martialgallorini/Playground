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
    void updateContour();
    
    // is control point hovered ?
    int controlHovered(float x, float y);
    
    // shape path
    ofPath path;        // drawing shape
    ofPolyline contour; // processing shape
    
    // control points
    vector<ofPath::Command> controls;
    
    bool bCommands;         // edit mode
    float commandRadius;
    
};

#endif /* defined(__testSVGPolyline__Shape__) */
