#include "testApp.h"

void testApp::setup(){
    ofBackground(0, 0, 0);
    //指定したポートで接続
    receiver.setup( PORT );
    //値を初期化
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
}

void testApp::update(){
    
    // 現在順番待ちのOSCメッセージがある間は受信を続ける
    while(receiver.hasWaitingMessages()){
        
        //次のメッセージを取得
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        // メッセージが /mouse/position ならマウスの位置を取得
        if (m.getAddress() == "/mouse/position"){
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
            
        }
        // メッセージが /mouse/button ならマウスボタンの状態を取得
        else if (m.getAddress() == "/mouse/button"){
            mouseButtonState = m.getArgAsString(0) ;
        }
        
        //OSCメッセージをそのままコンソールに出力
        dumpOSC(m);
    }
}

void testApp::draw(){
    int radius;

    // マウスボタンが押されていたら、赤い円を描画
    if (mouseButtonState == "down") {
        radius = 20;
        ofSetColor(255, 127, 0);
    } else {
        // そうでなければ、青い円を描画
        radius = 10;
        ofSetColor(0, 127, 255);
    }
    ofCircle(remoteMouse.x, remoteMouse.y, radius);
}

// OSCメッセージをコンソールに出力する関数
void testApp::dumpOSC(ofxOscMessage m) {
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

