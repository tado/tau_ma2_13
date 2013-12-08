#include "testApp.h"

void testApp::setup(){
	ofBackground(0, 0, 0);

    // 指定したIPアドレスとポート番号でサーバーに接続
	sender.setup(HOST, PORT);
}

void testApp::update(){
}

void testApp::draw(){
    //現在のマウスの場所に円を描画
    ofSetColor(255, 255, 255);
    ofCircle(mouseX, mouseY, 10);
}

void testApp::mouseMoved(int x, int y){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress("/mouse/position");
    //OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(x);
	m.addIntArg(y);
    //メッセージを送信
	sender.sendMessage(m);
}

void testApp::mouseDragged(int x, int y, int button){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress("/mouse/position");
    //OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(x);
	m.addIntArg(y);
    //メッセージを送信
	sender.sendMessage(m);
}

void testApp::mousePressed(int x, int y, int button){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress("/mouse/button");
    //OSC引数として、マウス状態"down"を送信
	m.addStringArg("down");
    //メッセージを送信
	sender.sendMessage(m);
}

void testApp::mouseReleased(int x, int y, int button){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress("/mouse/button");
    //OSC引数として、マウス状態"up"を送信
	m.addStringArg("up");
    //メッセージを送信
	sender.sendMessage( m );
}