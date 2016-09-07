//
//  Platform.h
//  Falling Ball
//
//  Created by Michael Kaufman on 8/17/16.
//
//

#ifndef Platform_h
#define Platform_h

#include "cocos2d.h"
#include "Ball.h"

USING_NS_CC;

class Platform : public Sprite{
    
private:
    
    //These tell us some things about the platform movement
    float platformSpeed = 10;
    float risingObjects = 0;
    
    
public:
    
    //Our create function
    static Platform* create();
    
    //Constructors
    Platform();
    virtual ~Platform();
    
    //To return the top of our platform for collision detection algorithm
    inline virtual int top() {
        //The y position, which is at the center of the sprite, added to the
        //height of the sprite divided by two in order to get the top positional value
        return this->getPositionY() + (this->getContentSize().height / 2);
    }
    
    inline virtual float platformrightside(){
        return this->getPositionX();
    }
    
    //Begin platform movement
    void resetPlatform();
    
    //Check collision with our ball
    void checkCollision(Ball* ball);
};

#endif /* Platform_h */
