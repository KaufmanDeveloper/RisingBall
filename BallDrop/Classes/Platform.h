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

USING_NS_CC;

class Platform : public Sprite{
    
private:
    
    //These tell us some things about the platform movement
    
    float platformSpeed = 10;
    float risingObjects = 0;
    
    
public:
    
    //For our movement algorithm
    //Vector<Sprite*> _risingObjects;
    
    
    
    //We'll probably add to the batch node in gamelayer.cpp?
    //SpriteBatchNode* _mygameBatchNode;
    
    Platform();
    virtual ~Platform();
    
    void resetPlatform(Size screenSize, Layer* ourScene, Sprite* ourPlatform);
    
    
    //void movePlatform(void);
    
};

#endif /* Platform_h */
