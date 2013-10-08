#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    
    for(int i = 0; i < NUM; i++){
        ofVec2f pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
        particle[i].setup(pos, vel);
        particle[i].radius = 3;
        particle[i].friction = 0.01;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < NUM; i++){
        particle[i].resetForce();
        particle[i].addForce(ofVec2f(0, 0.25));
        particle[i].updateForce();
        particle[i].updatePos();
        particle[i].bounceOffWalls();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    // 設定した場所に円を描く
    ofSetHexColor(0x3399ff);
    for(int i = 0; i < NUM; i++){
        particle[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    // fキーでフルスクリーンに
    if (key == 'f') {
        ofToggleFullscreen();
    }
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
    for(int i = 0; i < NUM; i++){
        ofVec2f pos = ofVec2f(x, y);
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
        particle[i].setup(pos, vel);
    }
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
