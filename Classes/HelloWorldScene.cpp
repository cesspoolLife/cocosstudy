#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(ccc4(255,255,255,255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	tm = new TileMap("Tile/tdMap.tmx");
	tm->setScale(visibleSize);

	this->addChild(tm->tmxMap,0,1);

	mm = new MonsterManage(tmxMap, tm->wayinfo, tm->mSize, tm->tSize, tm->wScale, tm->hScale);
	this->schedule(schedule_selector(HelloWorld::createMonster), 1.0f);
	this->schedule(schedule_selector(HelloWorld::checkPosition), 0.1f);

    return true;
}
void HelloWorld::createMonster(float dt){
	this->addChild(mm->createMonster(Point(tm->xSpawn, tm->ySpawn)),1);
}

void HelloWorld::checkPosition(float dt) {
	MonsterManage::update(mm);
}

/*
void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
*/
