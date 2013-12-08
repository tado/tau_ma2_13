#pragma once

#include "ofMain.h"
#include "ofxTuio.h"

class testApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    //TUIOの物体(マーカー)に関係するイベントを追加
    //物体の追加を検知
    void objectAdded(ofxTuioObject & tuioObject);
    //物体の削除を検知
    void objectRemoved(ofxTuioObject & tuioObject);
    //物体の状態の更新を検知
    void objectUpdated(ofxTuioObject & tuioObject);
    
    //TUIOのカーソル(タッチポイントなど)に関係するイベント
    //カーソルの追加を検知
    void tuioAdded(ofxTuioCursor & tuioCursor);
    //カーソルの削除を検知
    void tuioRemoved(ofxTuioCursor & tuioCursor);
    //カーソルの状態の更新を検知
    void tuioUpdated(ofxTuioCursor & tuioCursor);
    
    //TUIOのクライアントのインスタンス化
    ofxTuioClient tuio;
    //ログの出力用
    string log;
};












