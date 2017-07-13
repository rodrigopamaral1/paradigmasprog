#pragma once
#include "oxygine-framework.h"

using namespace oxygine;

class objeto {
protected:
  spSprite img;
  Vector2 pos;
public:
  objeto();
  objeto(std::string arq);
  objeto(std::string arq, float escala);
 
  void position(float x, float y);

  Vector2 ret(void);
};
