#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Ring.h"

//ポート番号を設定
#define PORT 8000

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void dumpOSC(ofxOscMessage m);
    
    ofxOscReceiver	receiver;
    ofPoint remoteMouse;
    string mouseButtonState;
    string oscString;
    vector <Ring *> rings; // 拡大する輪"Ring"の配列
};