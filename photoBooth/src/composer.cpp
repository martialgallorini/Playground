// TODO
// - flip saved image
// - print over wifi
// -

#include "composer.h"

void Composer::setup() {
    params.setName("composer parameters");
    //    params.add(lines.set("lines", 1, 1, 3));
    //    params.add(cols.set("columns", 1, 1, 3));
    params.add(bGrid.set("2x2 photos", false));
    params.add(margin.set("margin", 20.f, 5.f, 50.f));
    params.add(fontSize.set("font size", 40, 10, 100));
    params.add(width.set("comp width", 860, 600, 1024));
    params.add(height.set("comp height", 920, 600, 1024));
    
    ofAddListener(this->compositingDone, this, &Composer::onCompositingDone);
}

void Composer::onCompositingDone(const bool &val) {
    images.clear();
    labels.clear();
}

void Composer::add(ofImage image, string label)
{
    images.push_back(image);
    labels.push_back(label);
}

void Composer::create() {
    if(bGrid) {
        
    }
    else {
        comp.allocate(width, height);
        comp.begin();
        ofClear(0);
        ofDrawRectangle(0, 0, width, height);
        images.at(0).draw(margin, margin);
        ofTrueTypeFont title;
        title.load("TrashHand.ttf", 40, true, true);
        //title.load("Crayon.ttf", 60, true, true);
        //title.load("ampersand.ttf", 60, true, true);
        //title.load("joe.ttf", 60, true, true);
        //title.load("hellogoodbye.otf", 50, true, true);
        //title.load("jd.ttf", 60, true, true);
        //title.load("Marker.otf", 40, true, true);
        //title.load("MoonFlowerB.ttf", 40, true, true);
        title.setLineHeight(fontSize);
        title.setLetterSpacing(1.055);
        ofRectangle bounds = title.getStringBoundingBox(labels.at(0), 0, 0);
        float x = (width / 2) - (bounds.getWidth() / 2);
        float y = height - 100;
        ofSetColor(0);
        title.drawString(labels.at(0), x, y);
        comp.end();
    }
    comp.readToPixels(bat); // save as pixel array for further processing
    ofNotifyEvent(compositingDone, true);
}

void Composer::save()
{
    ofSaveImage(bat, "test.png");
}

void Composer::print()
{
    ofSerial printer;
    printer.setup(0, 9600);
    if(printer.isInitialized() && printer.available()) {
        //unsigned char *buffer = bat.getPixels();
        unsigned char *buffer = bat.getData();
        printer.writeBytes(buffer, sizeof(buffer));
        printer.flush();
    }
}
