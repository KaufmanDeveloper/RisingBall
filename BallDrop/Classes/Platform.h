//
//  Platform.h
//  SkyDefense
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
    float _platformInterval = 3.5;
    float _platformTimer = _platformInterval * 0.99f;
    float _platformSpeed = 10;
    
    
    
public:
    
    //For our movement algorithm
    Vector<Sprite*> _risingObjects;
    
    
    
    //We'll probably add to the batch node in gamelayer.cpp?
    //SpriteBatchNode* _mygameBatchNode;
    
    Platform();
    virtual ~Platform();
    
    void resetPlatform(Size screenSize, Layer* thisScene, int _platformPoolIndex,
                       Vector<Sprite* > _platformPool);
    Vector<Sprite* > createPlatformPool();
    
    //void movePlatform(void);
    
};

#endif /* Platform_h */
