#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    for (int i = 0; i < 200; i++){
		Particle myParticle;
        myParticle.friction = 0.03;
		float x = 500 + 100 * cos ( (i / 200.0) * TWO_PI);
		float y = 500 + 100 * sin ( (i / 200.0) * TWO_PI);
        myParticle.setup(ofVec2f(x, y), ofVec2f(0, 0));
		particles.push_back(myParticle);
	}
    
	//全ての配列を順番にspringで接続していく
	for (int i = 0; i < particles.size(); i++){
		Spring mySpring;
		mySpring.distance = 4;
		mySpring.springiness = 0.5;
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

	for (int i = 0; i < particles.size(); i++){
        if(pressed){
            // マウスの位置に反発する力
            particles[i].addAttractionForce(mouseX, mouseY, 200, 0.7f);
        } else {
            // マウスの位置に引きつけられる力
            particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.7f);
        }
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 50, 0.1);
		}
	}
	
	//バネを更新
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
	
	//パーティクルの状態を更新 (壁でバウンド)
    for (int i = 0; i < particles.size(); i++){
        particles[i].updateForce();
        particles[i].update();
        particles[i].bounceOffWalls();
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
    if (key == ' ') {
        for (int i = 0; i < particles.size(); i++){
            particles[i].setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        }
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
    pressed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    pressed = false;
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