#include "oxygine-framework.h"
#include <functional>
#include <iostream>

#include "jogo.h"
#include "objeto.h"
#include <math.h>

using namespace oxygine;

JOGO principal;

void inicia_jogo(void) {
  principal = new jogo;

  getStage()->addChild(principal);
}

void atualiza_jogo(void) {
  float distancia = principal->colisao_p1();
  principal->move_bola();
  principal->move_p1(distancia);
  principal->move_p2();
  principal->colide_p2();
  principal->ponto_reset();
}

void finaliza_jogo(void) {

}
