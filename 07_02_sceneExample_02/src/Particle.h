#pragma once

#include "ofMain.h"

class Particle {
public:
	
    ofVec2f pos; //位置
    ofVec2f vel; //速度
    ofVec2f frc; //力(加速度)
    float damping; //摩擦力
    
    Particle();
    virtual ~Particle(){};
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
protected:
private:
};