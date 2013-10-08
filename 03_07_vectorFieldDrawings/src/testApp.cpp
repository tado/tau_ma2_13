#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
    ofSetCircleResolution(3);
    ofEnableAlphaBlending();

	// 画面の中心付近にパーティクルを配置
	for (int i = 0; i < 50000; i++){
		Particle p;
        float angle, length;
        length = ofRandom(3);
        angle = ofRandom(PI * 2.0);
        ofVec2f pos;
        pos.x = cos(angle) * length + ofGetWidth()/2;
        pos.y = sin(angle) * length + ofGetHeight()/2;
        p.setup(pos, ofVec2f(0, 0));
        p.radius = 1.2;
        p.friction = 0.001;
		particles.push_back(p);
	}
	
	VF.setupField(400,200,ofGetWidth(), ofGetHeight());
    VF.randomizeField(0.1);
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < particles.size(); i++){
		
		//particleの力をリセット
		particles[i].resetForce();
		
		//ベクトル場から、それぞれのparticleにかかる力を算出
		ofVec2f force;
		force = VF.getForceFromPos(particles[i].position.x, particles[i].position.y);
		
		//Particleの状態を更新
		particles[i].addForce(ofVec2f(force.x, force.y));
		particles[i].updateForce();
        particles[i].bounceOffWalls();
		particles[i].update();
	}
	
	//ベクトル場の力の減衰
	VF.fadeField(1.0);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 0, 0, 23);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	//ベクトル場に配置されたparticleを描画
    ofSetColor(15, 63, 127);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key) {
		case 'c':
			VF.clear();
			break;
			
		case ' ':
			//パーティクルの場所を初期化
            for (int i = 0; i < particles.size(); i++){
                float angle, length;
                length = ofRandom(3);
                angle = ofRandom(PI * 2.0);
                ofVec2f pos;
                pos.x = cos(angle) * length + ofGetWidth()/2;
                pos.y = sin(angle) * length + ofGetHeight()/2;
                particles[i].setup(pos, ofVec2f(0, 0));
			}
            VF.randomizeField(0.1);
			break;
            
        case 'r':
            VF.randomizeField(0.1);
            break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
	
	//VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 10, 0.3);
    //VF.addClockwiseCircle(x, y, 100, 0.05);
    VF.addInwardCircle(x,y, 200, 0.02);
	
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x; 
	prevMouseY = y;
    VF.addInwardCircle(x,y, 100, 0.1);
    //VF.addClockwiseCircle(x, y, 100, 0.05);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
