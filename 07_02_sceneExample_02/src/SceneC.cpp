#include "SceneC.h"

void SceneC::setup(){	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	
	//イメージファイルを読込み
	img.loadImage("particle32.png");
}

void SceneC::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addDampingForce();
        particles[i].update();
    }
}

void SceneC::draw(){
	glDepthMask(GL_FALSE);
	ofEnablePointSprites();
	//パーティクルの位置に画像を表示
	for (int i = 0; i < particles.size(); i++){
		float posx = particles[i].pos.x - 16;
		float posy = particles[i].pos.y - 16;
		img.draw(posx, posy);
	}
	ofDisablePointSprites();
	glDepthMask(GL_TRUE);
}

void SceneC::mouseDragged(int x, int y, int button){
	//マウスをドラッグするとパーティクルが追加される
	Particle myParticle;
	float vx = ofRandom(-1, 1);
	float vy = ofRandom(-1, 1);
	myParticle.setInitialCondition(x, y, vx, vy);
	particles.push_back(myParticle);
}

void SceneC::mousePressed(int x, int y, int button){  
	particles.clear();
}
