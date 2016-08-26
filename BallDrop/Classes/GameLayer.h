//
//  GameLayer.h
//  BallDrop
//
//  Created by Michael Kaufman on 8/18/16.
//
//

#ifndef GameLayer_h
#define GameLayer_h

#include "cocos2d.h"
#include "Platform.h"

USING_NS_CC;

class GameLayer : public cocos2d::Layer
{
private:
    //Our screen size is determined in the init function
    Size visibleSize;
    
    //We can call a sprite file multiple times with this baby
    SpriteBatchNode* gameBatchNode;
    
    //Info for our update function in which we'll draw a platform if necessary
    float platformInterval;
    float platformTimer;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    //We'll work with this later, but we need this to constantly be updating game info
    //dt stands for delta time, or time between frames
    void update(float dt);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);
};

#endif /* GameLayer_h */
