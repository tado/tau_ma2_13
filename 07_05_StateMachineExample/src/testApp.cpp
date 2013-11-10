#include "testApp.h"
#include "CircleState.h"
#include "BoxState.h"
#include "ParticleState.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    // initialise state machine
    stateMachine.addState<CircleState>();
    stateMachine.addState<BoxState>();
    stateMachine.addState<ParticleState>();

    stateMachine.changeState("circle");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '1') {
        stateMachine.changeState("circle");
    }
    if (key == '2') {
        stateMachine.changeState("box");
    }
    if (key == '3') {
        stateMachine.changeState("particle");
    }
    
    // fキーでフルスクリーン表示
    if(key == 'f'){
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