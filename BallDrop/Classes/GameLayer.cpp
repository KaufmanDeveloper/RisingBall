#include "GameLayer.h"
#include "Platform.h"
#include "Ball.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameLayer::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("song.mp3", true);
    
    platformInterval = 3.5;
    platformTimer = platformInterval * 0.99f;
    
    //Have our platforms flow upwards on the game screen
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites.plist");
    
    ball = Ball::create();
    this->addChild(ball, 1);
    
    platform1 = Platform::create();
    this->addChild(platform1, 1);
    platform2 = Platform::create();
    this->addChild(platform2, 1);
    platform3 = Platform::create();
    this->addChild(platform3, 1);
    platform4 = Platform::create();
    this->addChild(platform4, 1);
    platform5 = Platform::create();
    this->addChild(platform5, 1);
    platform6 = Platform::create();
    this->addChild(platform6, 1);
    platform7 = Platform::create();
    this->addChild(platform7, 1);
    platform8 = Platform::create();
    this->addChild(platform8, 1);
    
    //Initialize our platform objects for screen drawing purposes
    platformPool.pushBack(platform1);
    platformPool.pushBack(platform2);
    platformPool.pushBack(platform3);
    platformPool.pushBack(platform4);
    platformPool.pushBack(platform5);
    platformPool.pushBack(platform6);
    platformPool.pushBack(platform7);
    platformPool.pushBack(platform8);
    
    
    auto bg = Sprite::create("bg.png");
    bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(bg, 0);
    
    
    //This calls the update function between each frame of the game
    //this->scheduleUpdate();
    scheduleUpdate();
    
    
    return true;
}

void GameLayer::update(float dt){

    //Our update functions
    //platform->update(dt);
    ball->update(dt);
    
    //When to move our platforms
    platformTimer += dt;
    if(platformTimer > platformInterval){
        platformTimer = 0;
        
        //This makes platforms initialize at the bottom of the screen
        platformPool.at(i)->resetPlatform();
        
        i++;
        scoreCount++;
    
    }
    
    for(int j = 0; j <= 7; j++){
        if(platformPool.at(j)->getPositionY() <= visibleSize.height * 0.99f and
           platformPool.at(j)->isVisible() == true){
            for(int k = 0; k <= 2; k++){
                
                platformPool.at(j)->setPositionY(platformPool.at(j)->getPositionY() + 1);
                
                if(platformPool.at(j)->checkCollision(ball)){
                    //Play sound when a collision initially occurs
                    if(playSound == true){
                    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("hit.wav");
                    }
                    //We don't want it to play the sound again
                    playSound = false;
                    
                    isFalling = false;
                    ball->setPositionY(ball->getPositionY() + 1);
                }
                else{
                    isFalling = true;
                }
            }
        }
    }
    
    if(isFalling == true){
        playSound = true;
        ball->setPositionY(ball->getPositionY() - 1);
    }
    
   /*
    for(int j = 0; j <= 7; j++){
        if(platformPool.at(j)->checkCollision(ball)){
            ball->setPositionY(ball->getPositionY() + 3);
        }
        
        else{
            ball->setPositionY(ball->getPositionY() - 0.5f);
        }
    }*/
    
    
    //If we've reached the end of our platform pool, begin again!
    if(i == 7){
        i = 0;
    }

    if(ball->getPositionY() <= visibleSize.height * 0.1){
        CCLOG("You lose!");
        CCLOG("Your score is %d", scoreCount);
        toGameOver(this);
    }
    
    if(ball->getPositionY() >= visibleSize.height * .8){
        CCLOG("You lose!");
        CCLOG("Your score is %d", scoreCount);
        toGameOver(this);
    }
    
}

void GameLayer::toGameOver(cocos2d::Ref* psender){
    auto gameoverscene = GameOver::createScene();
    
    Director::getInstance()->replaceScene(gameoverscene);
}



void GameLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}