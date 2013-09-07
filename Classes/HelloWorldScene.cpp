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


	tmxMap = TMXTiledMap::create("Tile/tdMap.tmx");
	building = tmxMap->layerNamed("Building");
	wayinfo = tmxMap->layerNamed("way");
	wayinfo->setVisible(false);
	mSize = tmxMap->getMapSize();
	tSize = tmxMap->getTileSize();
	wScale = visibleSize.width/(mSize.width*tSize.width);
	hScale = visibleSize.height/(mSize.height*tSize.height);
	tmxMap->setScaleX(wScale);
	tmxMap->setScaleY(hScale);

	this->addChild(tmxMap,0,1);
	TMXObjectGroup* objects = tmxMap->objectGroupNamed("Object");
	Dictionary* spawnPoint = objects->objectNamed("SpawnPoint");
	int x = ((String*)spawnPoint->objectForKey("x"))->intValue();
	int y = ((String*)spawnPoint->objectForKey("y"))->intValue();

	mm = new MonsterManage(tmxMap, wayinfo, mSize, tSize, wScale, hScale);
	this->addChild(mm->createMonster(Point(x*wScale, y*hScale)),1);
	this->schedule(schedule_selector(HelloWorld::checkPosition), 0.1f);
    return true;
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
