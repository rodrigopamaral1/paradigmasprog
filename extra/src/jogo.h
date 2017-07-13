#pragma once
#include "oxygine-framework.h"
#include "objeto.h"

using namespace oxygine;

DECLARE_SMART(jogo, JOGO);

class jogo: public Actor {
public:
  objeto *mesa;
  objeto *bola;
  objeto *p1, *p2;

  Vector2 p_m;

  jogo();

  void att_mouse(Event *ev);
  void move_p1(float dist);
  float colisao_p1();
  void move_bola();
  void move_p2();
  void colide_p2();
  void ponto_reset();
};

