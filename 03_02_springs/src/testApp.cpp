#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    //particleの配列を生成
    for (int i = 0; i < 20; i++) {
        Particle p;
        p.friction = 0.03;
        p.setup(ofVec2f(ofRandom(400, 450), ofRandom(400, 450)), ofVec2f(0,0));
        particles.push_back(p);
    }
    
	//全ての配列を順番にspringで接続していく
	for (int i = 0; i < (particles.size()-1); i++){
		Spring mySpring;
		mySpring.distance = 25;
		mySpring.springiness = 0.2;
		mySpring.particleA = &(particles[i]);
		mySpring.particleB = &(particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//全てのparticleの力をリセット
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	//バネを更新
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
	
	//パーティクルの状態を更新 (壁でバウンド)
    for (int i = 0; i < particles.size(); i++){
        particles[i].addForce(ofVec2f(0, 0.1));
        particles[i].updateForce();
        particles[i].bounceOffWalls();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	//全てのばねを描画
	ofSetColor(127, 127, 127);
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	
	//全てのparticleを描画
	ofSetColor(0, 127, 255);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
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
    particles[0].position.set(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;   
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	particles[0].bFixed = false;   
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