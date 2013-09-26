#pragma once
#include "ofMain.h"

class Particle {

public:

    // 初期設定
    void setup(ofVec3f position, ofVec3f velocity);
    // 力をリセット
    void resetForce();
    // 力を加える
    void addForce(ofVec3f force);
    // 力を更新
    void updateForce();
    // 位置の更新
    void updatePos();
    // 画面からはみ出たらバウンドさせる
    void checkBounds(float xmin, float ymin, float xmax, float ymax);
    // 描画
    void draw();
    
    // 位置ベクトルの配列
    ofVec3f position;
    
    // 速度ベクトルの配列
    ofVec3f velocity;
    
    // 力ベクトルの配列
    ofVec3f force;
    
    // 摩擦係数
    float friction;
    
    // パーティクルの半径
    float radius;
};