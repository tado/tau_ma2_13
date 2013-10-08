#pragma once //インクルードガード
#include "ofMain.h" // oFの機能をインポート

class Particle {

public:
    void draw();
    ofVec2f position;
};
// 最後にセミコロンを忘れずに!!