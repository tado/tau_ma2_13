#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // ランダムな場所と速度を指定
    positionX = ofRandom(ofGetWidth());
    positionY = ofRandom(ofGetHeight());
    velocityX = ofRandom(-10, 10);
    velocityY = ofRandom(-10, 10);
}

//--------------------------------------------------------------
void testApp::update(){
    // 円の座標を更新
    positionX += velocityX;
    positionY += velocityY;

    // 画面からはみ出ないように
    if (positionX < 0 || positionX > ofGetWidth()) {
        velocityX *= -1;
    }
    if (positionY < 0 || positionY > ofGetHeight()) {
        velocityY *= -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0x3399cc);
    // 円を描画
    ofCircle(positionX, positionY, 20);
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
