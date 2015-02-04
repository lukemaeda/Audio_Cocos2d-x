//
//  TopAudioScene.cpp
//  Audio
//
//  Created by MAEDAHAJIME on 2015/02/04.
//
//

#include "TopAudioScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* TopAudioScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TopAudioScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}


// 「INIT」初期化
bool TopAudioScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    
    // ラベルを生成
    Label* label1 = Label::createWithSystemFont("     Cocos2d-x     \nタップで音が鳴る", "Arial", 100);
    
    // ラベルの設置
    label1->setPosition(Point(winSize.width / 2 ,winSize.height / 2));
    
    // ラベルタイトルを追加
    this->addChild(label1,1);
    
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    //init()内
    //あらかじめ、音楽データを読み込む
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("onepoint26.mp3");
    
    // 3.x系 タップイベントを取得する
    // シングルタッチモード
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(TopAudioScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TopAudioScene::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(TopAudioScene::onTouchCancelled, this);
    listener->onTouchEnded = CC_CALLBACK_2(TopAudioScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

//タッチ開始イベント
bool TopAudioScene::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ開始！");
    
    //音楽を再生する
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("onepoint26.mp3");
    
    return true;
}

//タッチ移動イベント
void TopAudioScene::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ中");
    
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
}

//タッチキャンセルイベント
void TopAudioScene::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップキャンセル");
    
}

//タッチ終了イベント
void TopAudioScene::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ終了！");
}

