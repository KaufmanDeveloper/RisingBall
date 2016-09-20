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
#include "Ball.h"
#include "GameOver.h"

USING_NS_CC;

class GameLayer : public cocos2d::Layer
{
private:
    //Our screen size is determined in the init function
    Size visibleSize;
    
    //Perform an action for if our ball is not falling
    bool isFalling = true;
    
    //Should I play sound effect or nah? Only want it to play for initial collision.
    bool playSound = true;
    
    //Info for our update function in which we'll draw a platform if necessary
    float platformInterval;
    float platformTimer;
    
    //Our ball object, yaya
    Ball* ball;
    //Our platform object (will need to make a pool of these)
    Platform* platform1;
    Platform* platform2;
    Platform* platform3;
    Platform* platform4;
    Platform* platform5;
    Platform* platform6;
    Platform* platform7;
    Platform* platform8;
    
    //Pool of platforms for screen drawing
    Vector<Platform* > platformPool;
    
    //Iterator for platforms
    int i = 0;
    
    //Score count
    int scoreCount = 0;
    //Display score
    Label* scoreLabel;

    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    //To go to game over screen
    void toGameOver(cocos2d::Ref* pSender);
    
    //We'll work with this later, but we need this to constantly be updating game info
    //dt stands for delta time, or time between frames
    void update(float dt);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);
};

#endif /* GameLayer_h */
