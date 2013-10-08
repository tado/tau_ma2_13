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
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for(int i = 0; i < particle.size(); i++){
        particle[i].draw();
    }
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    for(int i = 0; i < 500; i++){
        ofVec2f pos = ofVec2f(x, y);
        float length = ofRandom(20);
        float angle = ofRandom(PI * 2);
        ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
        Particle p;
        p.setup(pos, vel);
        p.radius = 3;
        p.friction = 0.01;
        particle.push_back(p);
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
