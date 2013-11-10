#include "Particle.h"

//コンストラクタ(初期化)
Particle::Particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
}

//力(加速度)をリセット
void Particle::resetForce(){
    frc.set(0,0);
}

//力を加える
void Particle::addForce(float x, float y){
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//抵抗力の計算
void Particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//初期状態を設定
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//更新
void Particle::update(){	
	vel = vel + frc;
	pos = pos + vel; 
}

//描画
void Particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

