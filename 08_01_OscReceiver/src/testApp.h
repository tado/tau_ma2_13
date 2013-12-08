#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// OSCを受信するポート番号を設定
#define PORT 8000

class testApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();

    void dumpOSC(ofxOscMessage m); //OSCメッセージを出力
    
    // OSCメッセージを受信するインスタンス
    ofxOscReceiver receiver;

    // 受信したマウス座標
    ofPoint remoteMouse;

    // 受信したマウスボタンの状態 ("up", "down")
    string mouseButtonState;
};