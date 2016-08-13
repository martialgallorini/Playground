// TODO
// - flip saved image
// - print over wifi
// - format impression : 600 x 800
// - add border

#include "composer.h"

void Composer::setup() {
    params.setName("composer parameters");
    params.add(bGrid.set("grid mode", false));
    params.add(bBorder.set("add border", false));
    params.add(outMargin.set("external margin", 20, 5, 50));
    params.add(inMargin.set("internal margin", 10, 5, 50));
    params.add(fontSize.set("font size", 40, 10, 100));
    params.add(width.set("comp width", 600, 600, 1024));
    params.add(height.set("comp height", 800, 600, 1024));
    
    footer = 0;
    
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
    // if use borders, height = 800 + margins + label zone
    if(bBorder) {
        footer = 140;
    }
    else {
        footer = 0;
    }
    
    comp.allocate(width, height + footer + 10, GL_RGB);
    bat.allocate(width, height + footer + 10, GL_RGB);
    comp.begin();
    ofClear(0);
    ofDrawRectangle(0, 0, width, height + footer + 10);
    if(bGrid) {
        int index = 0;
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 2; ++i) {
                float ratio = images.at(index).getWidth() / images.at(index).getHeight();
                float newWidth = (comp.getWidth() - inMargin - (outMargin * 2)) / 2;
                float newHeight = newWidth / ratio;
                images.at(index).resize(newWidth, newHeight);
                float x = outMargin + i * (images.at(index).getWidth() + inMargin);
                float y = outMargin + 10 + j * (images.at(index).getHeight() + inMargin);
                images.at(index).draw(newWidth + x, y, -newWidth, newHeight);
                index++;
            }
        }
    }
    else {
        float ratio = images.at(0).getWidth() / images.at(0).getHeight();
        float newWidth = comp.getWidth() - (outMargin * 2);
        float newHeight = newWidth / ratio;
        images.at(0).resize(newWidth, newHeight);
        images.at(0).draw(newWidth + outMargin, outMargin + 10, -newWidth, newHeight);
    }
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
    float y = height + footer + 10 - 50;
    ofSetColor(0);
    title.drawString(labels.at(0), x, y);
    comp.end();
    comp.readToPixels(bat); // save as pixel array for further processing like saving file and printing
    ofNotifyEvent(compositingDone, true);
}

void Composer::save()
{
    string timeFormat = "%H%M%S";
    string timeStamp = ofGetTimestampString(timeFormat);
    ofSaveImage(bat, "photo_" + timeStamp + ".png");
}

void Composer::print()
{
// PRINT VIA CUPS COMMANDLINE ON USB OR WIFI
    system("lp -o natural-scaling=100 /Users/Martial/Desktop/DEV/oF093/apps/playground/photoBooth/bin/data/test.png");

    
// PRINT VIA BLUETOOTH
//    ofSerial printer;
//    printer.setup(0, 9600);
//    if(printer.isInitialized() && printer.available()) {
//        //unsigned char *buffer = bat.getPixels();
//        unsigned char *buffer = bat.getData();
//        printer.writeBytes(buffer, sizeof(buffer));
//        printer.flush();
//    }
}
