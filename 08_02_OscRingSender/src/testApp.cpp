#include "testApp.h"

void testApp::setup(){
	ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    //指定したIPアドレスとポート番号でサーバーに接続
	sender.setup( HOST, PORT );
}

void testApp::update(){
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

void testApp::mouseMoved(int x, int y ){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress( "/mouse/position" );
    //OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg( x );
	m.addIntArg( y );
    //メッセージを送信
	sender.sendMessage( m );
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress( "/mouse/button" );
    //OSC引数として、マウス状態"down"を送信
	m.addStringArg( "down" );
    //OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg( x );
	m.addIntArg( y );
	sender.sendMessage( m );
}

void testApp::mouseReleased(int x, int y, int button){
    //OSCメッセージの準備
	ofxOscMessage m;
    //OSCアドレスの指定
	m.setAddress( "/mouse/button" );
    //OSC引数として、マウス状態"up"を送信
	m.addStringArg( "up" );
    //OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg( x );
	m.addIntArg( y );
	sender.sendMessage( m );
    
    //Ringを追加
     rings.push_back(new Ring(ofPoint(x, y)));
}