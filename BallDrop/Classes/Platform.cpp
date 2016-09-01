//
//  Platform.cpp
//  Falling Ball
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
void Platform::resetPlatform(Size screenSize, Layer* ourScene, Sprite* ourPlatform){
    
    //return if too many rising objects
    
    if(risingObjects > 30) {
        return;
    }
    
    auto platform = ourPlatform;

    //Set a random x position to be where the platform starts rising
    int platform_x = rand() % (int) (screenSize.width * 0.8f) + screenSize.width * 0.1f;
    int platformtarget_x = rand() % (int) (screenSize.width * 0.8f) + screenSize.width * 0.1f;
    
    //If any actions are being run on this platform sprite, we want to stop them first
    platform->stopAllActions();
    platform->setPosition(Vec2(platform_x, (screenSize.height * 0.1) +
                               platform->getBoundingBox().size.height * 0.5));
    
    //Alright, now we create our action! platformSpeed determines number of seconds to get
    //to the top of the screen
    auto moveplatform = MoveTo::create(platformSpeed, Vec2(platform_x,
                                                            screenSize.height * .99f));
    //This would be used to figure out when our platform is done moving
    //CallFunc::create(std::bind(&GameLayer::fallingObjectDone, this
    //meteor) ), nullptr);
    
    ourScene->addChild(platform, 1);
    platform->setVisible(true);
    platform->runAction(moveplatform);
    
    if(platform->getPositionY() >= screenSize.height * screenSize.height * .99f){
        ourScene->removeChild(platform);
    }
    
    risingObjects++;
    
    
    
}