#include "jogo.h"
#include <math.h>

Vector2 v;

jogo::jogo() 
{
  this->mesa = new objeto("mesa");
  this->bola = new objeto("ball", 0.3);
  this->bola->position(165, 360);
  this->p1 = new objeto("hand", 0.3);
  this->p2 = new objeto("hand", 0.3);
  this->p1->position(165, 500);
  this->p2->position(165, 190);
  v = Vector2(0, 0);
 
  getStage()->addEventListener(TouchEvent::MOVE, CLOSURE(this, &jogo::att_mouse));
  this->p_m = Vector2(0, 0);
}

void jogo::att_mouse(Event *ev) 
{
  this->p_m = Vector2(((TouchEvent*)ev)->localPosition.x, ((TouchEvent*)ev)->localPosition.y);
}

float jogo::colisao_p1() {
  Vector2 p1 = this->p1->ret();
  Vector2 bolas = this->bola->ret();
  
  float dist = sqrt((p1.x - bolas.x)*(p1.x - bolas.x)+(p1.y - bolas.y)*(p1.y - bolas.y));
  if(dist < (60)) {
    v = Vector2((bolas.x - p1.x)/9, (bolas.y - p1.y)/9);
   
    this->bola->position(bolas.x + v.x, bolas.y + v.y);
  }
  v = Vector2(v.x * 0.999, v.y * 0.999);
  this->bola->position(bolas.x + v.x, bolas.y + v.y);
  return dist;
}

void jogo::move_p1(float dist) 
{
  Vector2 ponto = this->p1->ret(); 
  
  ponto.x = ponto.x + 0.5 * (this->p_m.x - ponto.x);
  ponto.y = ponto.y + 0.5 * (this->p_m.y - ponto.y);

  if(ponto.y < 400) ponto.y = 400;
  if(dist > 50) this->p1->position(ponto.x - 17, ponto.y - 15);
}

void jogo::move_bola()
{
  Vector2 test = this->bola->ret();
  Vector2 vv = v;
  if(test.x > 330 && vv.x > 0) v = Vector2(-vv.x, vv.y);
  if(test.x < 0 && vv.x < 0) v = Vector2( -vv.x, vv.y);
  //if(test.y > 670 && vv.y > 0) v = Vector2( vv.x, -vv.y);
  //if(test.y < 45 && vv.y < 0) v = Vector2( vv.x, -vv.y);
}

void jogo::move_p2() {
  Vector2 ia = this->p2->ret();
  Vector2 bolinha = this->bola->ret();

  if(bolinha.y > ia.y - 40)ia.x = ia.x + 0.05  * (bolinha.x - ia.x);
  this->p2->position(ia.x, ia.y);
}

void jogo::colide_p2()
{
  Vector2 p2 = this->p2->ret();
  Vector2 bolass = this->bola->ret();
  Vector2 vb2 = v;
  
  float dist2 = sqrt((p2.x - bolass.x)*(p2.x - bolass.x)+(p2.y - bolass.y)*(p2.y - bolass.y));
  if(dist2 < (60)) {
    v= Vector2((bolass.x - p2.x)/9, (bolass.y - p2.y)/9);
    this->bola->position(bolass.x + vb2.x, bolass.y + vb2.y);
  }
}

void jogo::ponto_reset()
{
  Vector2 bb = this->bola->ret();
  if(bb.y < 50 || bb.y > 668) {
    this->p1->position(165, 500);
    this->p2->position(165, 190);
    this->bola->position(165, 360);
    v = Vector2(0, 0);
  }
}




