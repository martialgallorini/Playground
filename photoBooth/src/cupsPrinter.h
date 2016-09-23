//
//  cupsPrinter.h
//  photoBooth
//
//  Created by Martial on 18/09/2016.
//
//

#pragma once

#ifndef cupsPrinter_h
#define cupsPrinter_h

#include <ofMain.h>
#include <printer.h>

class CupsPrinter : public Printer {
public:
    CupsPrinter();
    virtual ~CupsPrinter();
    
    virtual void print(ofImage &img);
    
};

#endif /* cupsPrinter_h */
