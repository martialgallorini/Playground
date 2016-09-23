//
//  printer.h
//  photoBooth
//
//  Created by Martial on 15/09/2016.
//

#pragma once

#ifndef printer_h
#define printer_h

#include "ofMain.h"
#include "defines.h"


class Printer
{
public:    
    Printer();
    virtual ~Printer();
    
    static Printer * create(int type);
    
    virtual void print(ofImage &img) = 0;
};

#endif /* printer_h */
