//
//  Ball.cpp
//  BallDrop
//
//  Created by Michael Kaufman on 8/26/16.
//
//

#include "Ball.h"
#include "cocos2d.h"

USING_NS_CC;

Ball::~Ball(){
    
}

Ball::Ball(){
    
}

Ball* Ball::create(Size screenSize){
    
    Ball* ball = new Ball();
    
    if(ball->initWithSpriteFrameName("ballworking.png")){
        ball->autorelease();
        ball->initOptions(screenSize);
        ball->addEvents(screenSize);
        
        return ball;
    }
    
    CC_SAFE_DELETE(ball);
    return NULL;
}

void Ball::initOptions(Size screenSize){
    this->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
    this->setScale(0.3);
}

void Ball::addEvents(Size screenSize){
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        //Make a rectangle object that encompasses the entire screen
        Size ourScreenSize = Director::getInstance()->getWinSize();
        
        Point point = touch->getLocation();
        
        //Perhaps this can get us our screen touched position
        //Returns our graph priority nod
        
        //CCLOG("You touched the screen!");
        
        //If you touch to the right of the screen, the ball moves right
        if(point.x > (ourScreenSize.width / 2)){
            
            //This moves 5 to the right with every touch, we want constant
            //movement using our update function most likely
            rightTouching = true;
            return true;
        }
        
        if(point.x <= (ourScreenSize.width / 2)){
            
            //This moves 5 to the right with every touch, we want constant
            //movement using our update function most likely
            leftTouching = true;
            return true;
        }
        
        
        
        
        return false; // we did not consume this event, pass thru.
    };
    
    listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        rightTouching = false;
        leftTouching = false;
    };
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void Ball::update(float dt){
    //If we're touching to the right of the screen
    if(rightTouching){
    this->setPositionX(this->getPositionX() + 3);
    }
    
    if(leftTouching){
        this->setPositionX(this->getPositionX() - 3);
    }
    
}

