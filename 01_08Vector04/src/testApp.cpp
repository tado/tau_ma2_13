#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(32);
    setInit(); // 円を初期化
}

//--------------------------------------------------------------
void testApp::update(){
    resetForce(); // 力をリセット
    addForce(ofVec2f(0, 0.5)); // 重力を加える
    updateForce(); // 力の更新 (摩擦)
    updatePos(); // 円の座標を全て更新
    // 画面からはみ出たらバウンドさせる
    checkBounds(0, 0, ofGetWidth(), ofGetHeight());
    // 枠内に収める
    constrain(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0x3399cc);
    // 画面内のランダムな場所を円の数だけ描画
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofCircle(position[i], 20);
    }
}

//--------------------------------------------------------------

void testApp::setInit(){
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        position[i].x = ofGetWidth()/2;
        position[i].y = ofGetHeight()/2;
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
void testApp::addForce(ofVec2f _force){
    // 力を加える
    for (int i = 0; i < CIRCLE_NUM; i++) {
        force[i] += _force;
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
        position[i] += velocity[i];
    }
}

//--------------------------------------------------------------
void testApp::constrain(float xmin, float ymin, float xmax, float ymax){
    // 枠内に収める
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x < xmin) {
            position[i].x = xmin;
        }
        if (position[i].y < ymin) {
            position[i].y = ymin;
        }
        if (position[i].x > xmax) {
            position[i].x = xmax;
        }
        if (position[i].y > ymax) {
            position[i].y = ymax;
        }
    }
}

//--------------------------------------------------------------
void testApp::checkBounds(float xmin, float ymin, float xmax, float ymax){
    // 画面からはみ出たらバウンドさせる
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (position[i].x < xmin || position[i].x > xmax) {
            velocity[i].x *= -1;
        }
        if (position[i].y < ymin || position[i].y > ymax) {
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
