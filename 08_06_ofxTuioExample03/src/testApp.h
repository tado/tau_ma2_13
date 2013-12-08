#pragma once

#include "ofMain.h"
#include "ofxTuio.h"

#define NUM 5

class testApp : public ofSimpleApp{
public:
    void setup();
    void update();
    void draw();
    void objectAdded(ofxTuioObject & tuioObject);
    void objectRemoved(ofxTuioObject & tuioObject);
    void objectUpdated(ofxTuioObject & tuioObject);
    void tuioAdded(ofxTuioCursor & tuioCursor);
    void tuioRemoved(ofxTuioCursor & tuioCursor);
    void tuioUpdated(ofxTuioCursor & tuioCursor);
    
    ofxTuioClient tuio;
    string log;
    ofSoundPlayer mySounds[NUM];
};