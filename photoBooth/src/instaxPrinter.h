//
//  instaxPrinter.h
//  photoBooth
//
//  Created by Martial on 18/09/2016.
//
//

#pragma once

#ifndef instaxPrinter_h
#define instaxPrinter_h

#include <ofMain.h>
#include <printer.h>

class InstaxPrinter : public Printer {
public:
    InstaxPrinter();
    virtual ~InstaxPrinter();
    
    virtual void print(ofImage &img);
    
};


#endif /* instaxPrinter_h */
