#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    
    // 円を初期化
    setInit();
}

//--------------------------------------------------------------
void testApp::update(){
    // 力をリセット
    resetForce();
    
    // 力の更新 (摩擦)
    updateForce();
    
    // 円の座標を全て更新
    updatePos();
    
    // 画面からはみ出たらバウンドさせる
    checkBounds();
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

void testApp::setInit(){
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        pos[i].x = ofGetWidth()/2;
        pos[i].y = ofGetHeight()/2;
        velocity[i].set(ofRandom(-30, 30), ofRandom(-30, 30));
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::resetForce(){
    // 力をリセット
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::updateForce(){
    // 力の更新 (摩擦)
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] = force[i] - velocity[i] * friction;
    }
}

//--------------------------------------------------------------
void testApp::updatePos(){
    // 円の座標を全て更新
    for (int i = 0; i < CIRCLE_NUM; i++) {
        velocity[i] += force[i];
        pos[i] += velocity[i];
    }
}

//--------------------------------------------------------------
void testApp::checkBounds(){
    // 画面からはみ出たらバウンドさせる
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (pos[i].x < 0 || pos[i].x > ofGetWidth()) {
            velocity[i].x *= -1;
        }
        if (pos[i].y < 0 || pos[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    setInit();
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
