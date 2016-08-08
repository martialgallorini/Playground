#pragma once

#ifndef COMPOSER_H
#define COMPOSER_H

#include "ofMain.h"

class Composer
{
public:    

    void setup();
    void add(ofImage image, string label);
    void create();
    void save();
    void print();
    void clear();
    
    ofEvent<const bool> compositingDone;
    void onCompositingDone(const bool &val);

    ofFbo comp;
    ofPixels bat;

    vector<ofImage> images;
    vector<string> labels;

    ofParameterGroup params;
    ofParameter<bool> bGrid;
//    ofParameter<int> lines;
//    ofParameter<int> cols;
    ofParameter<float> margin;
    ofParameter<int> fontSize;
    ofParameter<int> width;
    ofParameter<int> height;
};

#endif // COMPOSER_H
