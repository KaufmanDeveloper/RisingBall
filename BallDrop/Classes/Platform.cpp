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
        //platform->setScale(1.5);
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
    platform->setPosition(Vec2(platform_x, (screenSize.width / 2) - 120));
    
    //Alright, now we create our action! platformSpeed determines number of seconds to get
    //to the top of the screen
    //auto moveplatform = MoveTo::create(platformSpeed, Vec2(platform_x,
                                                            //screenSize.height * .99f));
    //This would be used to figure out when our platform is done moving
    //CallFunc::create(std::bind(&GameLayer::fallingObjectDone, this
    //meteor) ), nullptr);
    
    //ourScene->addChild(platform, 1);
    platform->setVisible(true);
    //We can just run the action, or we can try to clone the action
    //platform->runAction(moveplatform->clone());
    
    
   // platform->setPositionY(platform->getPositionY() + 3);

}

//Check if the ball has landed on a platform and perform actions accordingly
//We'll test first without checking an x-coordinate to get movement correct
bool Platform::checkCollision(Ball* ball){
    //Check if we have a collision on the y-coordinate
    if(this->top() - 1 <= ball->bottom() and this->top() + 1 >= ball->bottom()){
        //Check if we have a collision on the x-coordinate
        if(ball->getPositionX() >= this->platformleftside() and
           ball->getPositionX() <= this->platformrightside()){
            
            return true;
        }
    }
    
    else{
        return false;
    }
}
