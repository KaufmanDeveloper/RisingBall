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
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //The loop that will move our platforms
    void platformFlow(Size screenSize);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);
};

#endif /* GameLayer_h */
