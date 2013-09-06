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

	mm = new MonsterManage();
	this->addChild(mm->createMonster(Point(x*wScale, y*hScale)),1);
	mm->playMonster();

//	this->schedule(schedule_selector(HelloWorld::checkPosition), 0.3f);
    return true;
}

void HelloWorld::checkPosition(float dt) {
/*	Point p = sprite->getPosition();
	int pX = p.x/(wScale*tSize.width); 
	int pY = (hScale*mSize.height*tSize.height-p.y)/(hScale*tSize.height);
	int Gid = wayinfo->getTileGIDAt(Point(pX-1,pY));
	if (Gid){
		Dictionary* properties = tmxMap->propertiesForGID(Gid);
		if(properties) {
			String* way = (String*)properties->objectForKey("is_way");
			if (way&&(way->compare("YES")==0)) {
			}
			else {
				sprite->stopAllActions();
				ActionInterval* animate = monster->downAnimation();
				ActionInterval* move = monster->downMove();
				ActionInterval* swq = Spawn::create(move, animate, NULL);
				Action* rep = RepeatForever::create(swq);
				sprite->runAction(rep);
			}
		}
		else {
			sprite->stopAllActions();
				ActionInterval* animate = monster->downAnimation();
				ActionInterval* move = monster->downMove();
				ActionInterval* swq = Spawn::create(move, animate, NULL);
				Action* rep = RepeatForever::create(swq);
				sprite->runAction(rep);
		}
	}
	else {
		sprite->stopAllActions();
			ActionInterval* animate = monster->downAnimation(); //here runtime ERROR!!
				ActionInterval* move = monster->downMove();
				ActionInterval* swq = Spawn::create(move, animate, NULL);
				Action* rep = RepeatForever::create(swq);
				sprite->runAction(rep);
	}*/
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
