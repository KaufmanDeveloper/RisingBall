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
    inline virtual float top() {
        //The y position, which is at the center of the sprite, added to the
        //height of the sprite divided by two in order to get the top positional value
        //return this->getPositionY() + (this->getContentSize().height / 2);
        
        Point onScreenPosition = this->getParent()->convertToWorldSpace(this->getPosition());
        float returnValue = onScreenPosition.y + (this->getContentSize().height / 2);
        //float returnValue = onScreenPosition.y;
        return (returnValue);
    }
    
    inline virtual float platformleftside(){
        
        Point onScreenPosition = this->getParent()->convertToWorldSpace(this->getPosition());
        float returnValue = onScreenPosition.x - (this->getContentSize().width / 2);
        return (returnValue);
    }
    
    inline virtual float platformrightside(){
        
        Point onScreenPosition = this->getParent()->convertToWorldSpace(this->getPosition());
        float returnValue = onScreenPosition.x + (this->getContentSize().width / 2);
        return (returnValue);
    }
    
    //Begin platform movement
    void resetPlatform();
    
    //Check collision with our ball
    bool checkCollision(Ball* ball);
};

#endif /* Platform_h */
