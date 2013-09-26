//
//  Particle.cpp
//  OneParticleClass
//
//  Created by Tadokoro Atsushi on 2013/09/24.
//
//

#include "Particle.h"

void Particle::setup(ofVec3f _position, ofVec3f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
}

// 力をリセット
void Particle::resetForce(){
    force.set(0, 0, 0);
}

// 力を加える
void Particle::addForce(ofVec3f _force){
    force = _force;
}

// 力の更新
void Particle::updateForce(){
    force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos(){
    velocity += force;
    position += velocity;
}

void Particle::checkBounds(float xmin, float ymin, float xmax, float ymax){
    // 画面の端でバウンドする
    if (position.x < xmin || position.x > xmax) {
        velocity.x *= -1;
    }
    if (position.y < ymin || position.y > ymax) {
        velocity.y *= -1;
    }
    
    // 枠内に収める
    if (position.x < xmin) {
        position.x = xmin + (xmin - position.x);
    }
    if (position.x > xmax) {
        position.x = xmax - (position.x - xmax);
    }
    if (position.y < ymin) {
        position.y = ymin + (ymin - position.y);
    }
    if (position.y > ymax) {
        position.y = ymax - (position.y - ymax);
    }
}

// 描画
void Particle::draw(){
    ofSetHexColor(0x3399cc);
    ofCircle(position.x, position.y, position.z, radius);
}

