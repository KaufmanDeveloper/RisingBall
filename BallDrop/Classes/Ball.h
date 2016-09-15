//
//  Ball.h
//  BallDrop
//
//  Created by Michael Kaufman on 8/26/16.
//
//

#ifndef Ball_h
#define Ball_h

#include "cocos2d.h"

USING_NS_CC;

class Ball : public Sprite{
private:
    bool rightTouching = false;
    bool leftTouching = false;
    
public:
    
    Ball();
    ~Ball();
    
    static Ball* create();
    
    void initOptions();
    
    void addEvents();
    void touchEvent(Touch* touch, Vec2 p);
    
    //Update frame by frame based on input/collision/whatever we need
    void update(float dt);
    
    //Reports the bottom position of the ball
    inline virtual float bottom() {
        //Subtract from the middle position the height value divided by two for the bottom
        //return this->getPositionY() - (this->getContentSize().height / 2);
        
        Point onScreenPosition = this->getParent()->convertToWorldSpace(this->getPosition());
        float returnValue = onScreenPosition.y - (this->getContentSize().height / 2);
        return (returnValue);
    }
    
    //Animation for ball when it's in a falling state, switches to true when done
    bool ballFalling(Size screenSize, Layer* ourScene, Sprite* ourBall);
    
    
    
};

#endif /* Ball_h */
