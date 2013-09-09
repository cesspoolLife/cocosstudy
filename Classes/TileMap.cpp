#include "TileMap.h"

USING_NS_CC;

TileMap::TileMap(char* file){
	this->tmxMap = TMXTiledMap::create(file);
	this->building = this->tmxMap->layerNamed("Building");
	this->wayinfo = this->tmxMap->layerNamed("way");
	this->wayinfo->setVisible(false);
	this->mSize = this->tmxMap->getMapSize();
	this->tSize = this->tmxMap->getTileSize();
	TMXObjectGroup* objects = tmxMap->objectGroupNamed("Object");
	Dictionary* spawnPoint = objects->objectNamed("SpawnPoint");
	this->xSpawn = ((String*)spawnPoint->objectForKey("x"))->intValue();
	this->ySpawn = ((String*)spawnPoint->objectForKey("y"))->intValue();
}

void TileMap::setScale(Size v) {
	this->wScale = v.width/(this->mSize.width*this->tSize.width);
	this->hScale = v.height/(this->mSize.height*this->tSize.height);
	this->tmxMap->setScaleX(wScale);
	this->tmxMap->setScaleY(hScale);
	this->xSpawn = this->wScale*this->xSpawn;
	this->ySpawn = this->hScale*this->ySpawn;
}
