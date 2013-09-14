#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        pos[i].x = ofRandom(ofGetWidth());
        pos[i].y = ofRandom(ofGetHeight());
        velocity[i].x = ofRandom(-10, 10);
        velocity[i].y = ofRandom(-10, 10);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        pos[i] += velocity[i];

        // 画面からはみ出たらバウンドさせる
        if (pos[i].x < 0 || pos[i].x > ofGetWidth()) {
            velocity[i].x *= -1;
        }
        if (pos[i].y < 0 || pos[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0x3399cc);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(pos[i], 20);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
