#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
    // CV初期設定
    camera.initGrabber(320, 240);
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    // GUI
    resetParticleButton.addListener(this, &testApp::resetParticlePressed);
    gui.setup();
    gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
    gui.add(levels.setup("levels", 4, 1, 8));
    gui.add(winsize.setup("winsize", 8, 4, 64));
    gui.add(iterations.setup("iterations", 2, 1, 8));
    gui.add(polyN.setup("polyN", 7, 5, 10));
    gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
    gui.add(flowScale.setup("flowScale", 0.05, 0.0, 0.2));
    gui.add(drawFlow.setup("draw opticalflow", true));
    gui.add(fullscreen.setup("fullscreen", false));
    gui.add(resetParticleButton.setup("reset particles"));
    
    //パーティクルを生成
	for (int i = 0; i < NUM; i++){
		Particle myParticle;
        myParticle.friction = 0.01;
        myParticle.radius = 2;
		myParticle.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
		particles.push_back(myParticle);
	}
}

void testApp::update() {
    camera.update();
    if(camera.isFrameNew()) {
        flow.setPyramidScale(pyrScale);
        flow.setNumLevels(levels);
        flow.setWindowSize(winsize);
        flow.setNumIterations(iterations);
        flow.setPolyN(polyN);
        flow.setPolySigma(polySigma);

        // オプティカルフローを計算
        flow.calcOpticalFlow(camera);
    }
    
    // Particleのアップデート
    for (int i = 0; i < particles.size(); i++){
		
		//particleの力をリセット
		particles[i].resetForce();
		
		//オプティカルフローから、それぞれのparticleにかかる力を算出
		ofVec2f force;
        ofVec2f pos;
        pos.x = particles[i].position.x * float(camera.getWidth()) / float(ofGetWidth());
        pos.y = particles[i].position.y * float(camera.getHeight()) / float(ofGetHeight());
        force = flow.getFlowOffset(pos.x, pos.y) * flowScale;
        
		//Particleの状態を更新
		particles[i].addForce(ofVec2f(force.x, force.y));
		particles[i].updateForce();
        particles[i].bounceOffWalls();
		particles[i].update();
	}
}

void testApp::draw() {
    ofSetFullscreen(fullscreen);
    ofBackground(0);
    
    ofSetColor(255);
    camera.draw(0,0,ofGetWidth(),ofGetHeight());
    
    if (drawFlow) {
        ofSetColor(255, 0, 255);
        flow.draw(0,0,ofGetWidth(),ofGetHeight());
    }
    
    ofSetColor(0, 127, 255);
    for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
    gui.draw();
}

void testApp::resetParticlePressed(){
    particles.clear();
    for (int i = 0; i < NUM; i++){
		Particle myParticle;
        myParticle.friction = 0.01;
        myParticle.radius = 2;
		myParticle.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
		particles.push_back(myParticle);
	}
}
