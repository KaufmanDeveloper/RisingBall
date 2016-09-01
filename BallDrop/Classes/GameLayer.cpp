#include "GameLayer.h"
#include "Platform.h"
#include "Ball.h"

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
    
    /*
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);*/

    /*                            *
     *                            *
     * This is where my code goes *
     *                            *
     *                            *
     */
    
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist");
    
    platformInterval = 3.5;
    platformTimer = platformInterval * 0.99f;
    
    //Have our platforms flow upwards on the game screen
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites.plist");
    
    ball = Ball::create(visibleSize);
    this->addChild(ball, 1);
    
    /*
    auto sprite = Sprite::createWithSpriteFrameName("platformv1.png");
    
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 +
                             origin.y));
    
    this->addChild(sprite, 1);*/
    
    
    
    //This calls the update function between each frame of the game
    //this->scheduleUpdate();
    scheduleUpdate();
    
    
    return true;
}

void GameLayer::update(float dt){
    //We'll need to draw a platform if necessary in our update function
    platformTimer += dt;
    if(platformTimer > platformInterval){
        platformTimer = 0;
        //this->platformFlow(visibleSize);
        //auto spritecache = SpriteFrameCache::getInstance();
        //spritecache->addSpriteFramesWithFile("sprites.plist");
        auto sprite = Sprite::createWithSpriteFrameName("platformv1.png");
        sprite->setScale(1.5);
        Platform* platform = new Platform();
        //This makes platforms rise from the bottom of the screen!
        platform->resetPlatform(visibleSize, this, sprite);
        //We this update function working at a proper interval, we just need platforms
        CCLOG("TESTING");
    }
    
    ball->update(dt);
    
    //Point ballPoint = ball->getPosition();
    //this->setPosition(ballPoint.x + 5, ballPoint.y);
    
    //auto ball = Ball::create(visibleSize);
    //this->addChild(ball, 1);
    
    //This function will likely be where we call our collision detection function
    
}




/*

 */

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