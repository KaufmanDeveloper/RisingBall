//
//  Platform.cpp
//  SkyDefense
//
//  Created by Michael Kaufman on 8/17/16.
//
//

#include "Platform.h"
#include "Gamelayer.h"

Platform::Platform(){
    
}

Platform::~Platform(){
    
}

//_screenSize will be our argument in GameLayer
void Platform::resetPlatform(Size screenSize, Layer* thisScene,
                             int _platformPoolIndex, Vector<Sprite* > _platformPool){
    
    //return if too many rising objects
    /*
    if(_risingObjects.size() > 30) {
        return;
    }*/
    
    auto platform = _platformPool.at(_platformPoolIndex);
    _platformPoolIndex++;
    
    //We've reached the end of our platform pool, reset our index to the beginning
    if(_platformPoolIndex == _platformPool.size()){
        _platformPoolIndex = 0;
    }
    
    //Set a random x position to be where the platform starts rising
    int platform_x = rand() % (int) (screenSize.width * 0.8f) + screenSize.width * 0.1f;
    int platformtarget_x = rand() % (int) (screenSize.width * 0.8f) + screenSize.width * 0.1f;
    
    //If any actions are being run on this platform sprite, we want to stop them first
    platform->stopAllActions();
    platform->setPosition(Vec2(platform_x, (screenSize.height * 0.1) +
                               platform->getBoundingBox().size.height * 0.5));
    
    //Alright, now we create our action!
    auto moveplatform = MoveTo::create(_platformSpeed, Vec2(platform_x,
                                                            screenSize.height * .99f));
    //In example, this is in a sequence with our moveplatform
    //CallFunc::create(std::bind(&GameLayer::fallingObjectDone, this
    //meteor) ), nullptr);
    
    thisScene->addChild(platform, 1);
    platform->setVisible(true);
    platform->runAction(moveplatform);
    
    _risingObjects.pushBack(platform);
    
    
    
}

Vector<Sprite* > Platform::createPlatformPool(){
    
    //Create platform pool
    //Load the sprite sheet
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites.plist");
    
    Vector<Sprite* > _platformPool;
    
    for(int i = 0; i < 50; i++){
        auto sprite = Sprite::createWithSpriteFrameName("platformv1.png");
        sprite->setVisible(false);
        _platformPool.pushBack(sprite);
    }
    
    return (_platformPool);
    
}