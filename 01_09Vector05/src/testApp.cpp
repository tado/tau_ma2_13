#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    // 摩擦係数を設定
    friction = 0.002;
    // 円を初期化
    setInit(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
}

//--------------------------------------------------------------
void testApp::update(){
    // 力をリセット
    resetForce();
    
    // 重力を加える
    addForce(ofVec2f(0, 0.25));
    
    // 力の更新 (摩擦)
    updateForce();
    
    // 円の座標を全て更新
    updatePos();
    
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
        ofCircle(position[i], 2);
    }
}

//--------------------------------------------------------------

void testApp::setInit(ofVec2f initPos){
    // 画面内のランダムな場所と速度を円の数だけ指定
    for (int i = 0; i < CIRCLE_NUM; i++) {
        position[i].x = initPos.x;
        position[i].y = initPos.y;
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        velocity[i].x = cos(angle) * length;
        velocity[i].y = sin(angle) * length;
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
        force[i] -= velocity[i] * friction;
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
            position[i].x = xmin + (xmin - position[i].x);
        }
        if (position[i].x > xmax) {
            position[i].x = xmax - (position[i].x - xmax);
        }
        if (position[i].y > ymax) {
            position[i].y = ymax - (position[i].y - ymax);
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
        if (position[i].y > ymax) {
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ofToggleFullscreen();
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
    setInit(ofVec2f(x, y));
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
