//
//  Ball.h
//  BallDrop
//
//  Created by Michael Kaufman on 8/26/16.
//
//

#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Ball : public Sprite{
private:
    bool rightTouching = false;
    bool leftTouching = false;
    
public:
    
    Ball();
    ~Ball();
    
    static Ball* create(Size screenSize);
    
    void initOptions(Size screenSize);
    
    void addEvents(Size screenSize);
    void touchEvent(Touch* touch, Vec2 p);
    
    //Update frame by frame based on input/collision/whatever we need
    void update(float dt);
    
    //Animation for ball when it's in a falling state, switches to true when done
    bool ballFalling(Size screenSize, Layer* ourScene, Sprite* ourBall);
    
    
    
};

#endif /* Ball_h */
