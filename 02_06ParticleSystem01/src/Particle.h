#pragma once
#include "ofMain.h"

class Particle {

public:

    // 初期設定
    void setup(ofVec2f position, ofVec2f velocity);
    // 力をリセット
    void resetForce();
    // 力を加える
    void addForce(ofVec2f force);
    // 力を更新
    void updateForce();
    // 位置の更新
    void updatePos();
    // 画面からはみ出たらバウンドさせる
    void checkBounds(float xmin, float ymin, float xmax, float ymax);
    // 描画
    void draw();
    
    // 位置ベクトルの配列
    ofVec2f position;
    
    // 速度ベクトルの配列
    ofVec2f velocity;
    
    // 力ベクトルの配列
    ofVec2f force;
    
    // 摩擦係数
    float friction;
    
    // パーティクルの半径
    float radius;
};