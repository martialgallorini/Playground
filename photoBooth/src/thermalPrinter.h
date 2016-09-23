//
//  thermalPrinter.h
//  photoBooth
//
//  Created by Martial on 15/09/2016.
//
//

#pragma once

#ifndef thermalPrinter_h
#define thermalPrinter_h

#include <ofMain.h>
#include <printer.h>
#include <ofxThermalPrinter.h>

class ThermalPrinter : public Printer, public ofxThermalPrinter {
public:
    ThermalPrinter();
    virtual ~ThermalPrinter();
    
    virtual void print(ofImage &img);
    
};

#endif /* thermalPrinter_h */
