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

Platform* Platform::create(){
    Platform* platform = new Platform();
    
    if(platform->initWithSpriteFrameName("platformv1.png")){
        platform->autorelease();
        //platform->resetPlatform();
        platform->setVisible(false);
        return platform;
    }
    
    CC_SAFE_DELETE(platform);
    return NULL;
}


//_screenSize will be our argument in GameLayer
void Platform::resetPlatform(){
    
    Size screenSize = Director::getInstance()->getWinSize();
    
    auto platform = this;

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
    
    //ourScene->addChild(platform, 1);
    platform->setVisible(true);
    //We can just run the action, or we can try to clone the action
    platform->runAction(moveplatform->clone());

}

//Check if the ball has landed on a platform and perform actions accordingly
//We'll test first without checking an x-coordinate to get movement correct
void Platform::checkCollision(Ball* ball){
    if(this->top() == ball->bottom()){
        //ball->setPositionY(ball->getPositionY() *1.1f);
        CCLOG("Collision detected!");
    }
}
