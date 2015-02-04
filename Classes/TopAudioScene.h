//
//  TopAudioScene.h
//  Audio
//
//  Created by MAEDAHAJIME on 2015/02/04.
//
//

#ifndef __Audio__TopAudioScene__
#define __Audio__TopAudioScene__

#include <cocos2d.h>

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class TopAudioScene : public Layer
{
    
public:
    
    // 初期化のメソッド
    virtual bool init();
    
    
    static cocos2d::Scene* createScene();
    
    //タッチイベント用メソッドの宣言
    //TouchBegan()関数->タッチ開始
    bool onTouchBegan(Touch* pTouch, Event* pEvent);
    
    //TouchMoved()関数->タッチ中
    void onTouchMoved(Touch *pTouch, Event *pEvent);
    
    //TouchCancelled()関数->タッチキャンセル
    void onTouchCancelled(Touch *pTouch, Event *pEvent);
    
    //TouchEnded()関数->タッチ終了
    void onTouchEnded(Touch* pTouch, Event* pEvent);
    
    // create()を使えるようにしている。
    CREATE_FUNC(TopAudioScene);
};


#endif /* defined(__Audio__TopAudioScene__) */
