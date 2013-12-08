#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Ring.h"

#define HOST "127.0.0.1"
#define PORT 8000

//--------------------------------------------------------
class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    // OSCメッセージの送信者
    ofxOscSender sender;
    vector <Ring *> rings; //輪の動的配列
};
