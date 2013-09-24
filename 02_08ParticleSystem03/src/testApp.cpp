#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particle.size(); i++){
        particle[i].resetForce();
        particle[i].updateForce();
        particle[i].updatePos();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    // 設定した場所に円を描く
    for(int i = 0; i < particle.size(); i++){
        particle[i].draw();
    }
    
    ofSetHexColor(0xffffff);
    ofDrawBitmapString("particle num = " + ofToString(particle.size()), 10, 15);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    if (key == 'c') {
        particle.clear();
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
    for(int i = 0; i < 10; i++){
        ofVec2f pos = ofVec2f(x, y);
        float length = ofRandom(1);
        float angle = ofRandom(PI * 2);
        ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
        Particle p;
        p.setup(pos, vel);
        p.radius = 2;
        p.friction = 0.002;
        particle.push_back(p);
    }
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
