#include "testApp.h"

void testApp::setup(){
    //指定したポートで接続
    receiver.setup( PORT );
    ofSetFrameRate(60);
    
    //値を初期化
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
    
    ofBackground(0, 0, 0);
}

void testApp::update(){
    //現在順番待ちのOSCメッセージがあるか確認
    while(receiver.hasWaitingMessages()){
        //次のメッセージを取得
        ofxOscMessage m;
        oscString = m.getAddress();
        receiver.getNextMessage(&m);
        
        //マウスの位置を取得
        if(m.getAddress() == "/mouse/position"){
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
            
        }
        //マウスボタンの状態を取得
        else if (m.getAddress() == "/mouse/button") {
            mouseButtonState = m.getArgAsString(0) ;
        }
        
        //OSCメッセージをそのままコンソールに出力
        dumpOSC(m);
    }
    
    //マウスアップされたら、新規にRingを追加
    if(mouseButtonState == "up"){
        rings.push_back(new Ring(ofPoint(remoteMouse.x, remoteMouse.y)));
        mouseButtonState = "";
    }
    
    //Ring更新
    for(vector <Ring *>::iterator it = rings.begin(); it != rings.end();){
        (*it)->update();
        if ((*it)->dead) {
            delete (*it);
            it = rings.erase(it);
        } else {
            ++it;
        }
    }
}

void testApp::draw(){
    //Ringを描画
    for(vector <Ring *>::iterator it = rings.begin(); it != rings.end(); ++it){
        (*it)->draw();
    }
}

//OSCメッセージをコンソールに出力する関数
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