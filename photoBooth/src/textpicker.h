#pragma once

#ifndef TEXTPICKER_H
#define TEXTPICKER_H

#include "ofMain.h"

class TextPicker
{
public:
    void init();
    string getRandomText();

    vector<string> list;
};

#endif // TEXTPICKER_H
