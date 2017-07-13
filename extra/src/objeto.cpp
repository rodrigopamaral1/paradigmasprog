#include "objeto.h"
#include <string>

Resources way;

objeto::objeto(){}

objeto::objeto (std::string arq)
{
  this->img = new Sprite();
 
  way.loadXML("res.xml");
  this->pos = Vector2(0,0);
  this->img->setPosition(this->pos);

  this->img->setResAnim(way.getResAnim(arq));
  
  getStage()->addChild(this->img);
}

objeto::objeto (std::string arq, float escala)
{
  this->img = new Sprite();
  
  way.loadXML("res.xml");
  this->pos = Vector2(0,0);
  this->img->setPosition(this->pos); 

  this->img->setResAnim(way.getResAnim(arq));
  this->img->setScale(escala);

  getStage()->addChild(this->img);
}

void objeto::position(float x, float y) 
{
  this->pos = Vector2(x, y);
  this->img->setPosition(this->pos);
}

Vector2 objeto::ret(void)
{
  return this->pos;
}
