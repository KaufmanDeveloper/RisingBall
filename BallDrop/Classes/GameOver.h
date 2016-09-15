//
//  GameOver.h
//  BallDrop
//
//  Created by Michael Kaufman on 8/18/16.
//
//

#ifndef GameOver_h
#define GameOver_h

#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;

class GameOver : public cocos2d::Layer
{
private:
    //Our screen size is determined in the init function
    Size visibleSize;
    
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
};

#endif /* GameOver_h */
