#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
#include <stdexcept>
#include <FL/fl_ask.H>
#include "window.h"


class Sorteio: public UserInterface {
private:
  std::vector<int> participantes; // Vetor com o numero de participantes...
  int cont; // Este cont e para mostrar o N sorteado
public:
  Sorteio() {
    cont = 0;
    Entrada_Participantes->value("");
    Display1->label("");
    Janela1->label("");
    Botao_Sortear->callback((Fl_Callback*) cbBotao_Sortear, (void*)(this)); // Callback Botao Sortear
    Botao_Reset->callback((Fl_Callback*) cbBotao_Reset, (void*)(this));  // Callback Botao Resetar
  }
  void show() {
    w->show();
  }
  static void cbBotao_Reset(Fl_Widget* btn, void* userdata) { // Botao de Reset que deve ser chamada quando se deseja fazer outro Sorteio
    Sorteio *gui = static_cast<Sorteio*>(userdata);

    gui->Entrada_Participantes->value("");
    gui->cont = 0;
    gui->Display1->labelsize(30);
    gui->Display1->label("             ");
    gui->Janela1->label("");

    if(!gui->participantes.empty()) gui->participantes.erase(gui->participantes.begin(), gui->participantes.end());
  }

  static void cbBotao_Sortear(Fl_Widget* btn, void* userdata) { //Botao para sortear
    Sorteio *gui = static_cast<Sorteio*>(userdata);

    if(gui->participantes.empty() && gui->cont == 0) // Este if serve apenas para criar espaço no vetor e ler o numero de participantes
    try {                                            // A segunda condiçao serve pra saber se voce clicou no Botao Reset apos o fim do sorteio
      int max_part = std::stoi(gui->Entrada_Participantes->value()); // Este if so e usado 1 vez a cada sorteio
      if(max_part == 0) {
        fl_alert("O numero nao pode ser 0");
      }
      else {
        for(auto i = 0; i < max_part; i++) { // Inserimos no vetor/lista
          gui->participantes.push_back(i+1);
        }
        std::random_shuffle(gui->participantes.begin(), gui->participantes.end()); // Shuffle do vetor
      }
    }
    catch(std::invalid_argument&) {
      fl_alert("O numero participantes deve existir e ser um inteiro");
    }
    catch(std::out_of_range&) {
      fl_alert("Argumentos fora de faixa");
    }

    if(!gui->participantes.empty()) { // Este if serve para incrementar o N ganhador de atualizar alguns displays
      gui->cont++;
      std::string disp_ganhador = std::to_string(gui->cont) + "º Ganhador"; // Display do N ganhador
      gui->Display1->labelsize(disp_ganhador.size());
      gui->Display1->label(disp_ganhador.c_str());

      gui->Janela1->label(std::to_string(gui->participantes[0]).c_str()); // O ganhador sera o primeiro do vetor embaralhado
      gui->participantes.erase(gui->participantes.begin()); // Retiramos o ganhador do vetor
    }
    if(gui->participantes.empty() && gui->cont>0) { // Apenas para quando voce ja realiazou algum sorteio e chegou no fim
      fl_alert("Fim do sorteio, clique em reset para um novo sorteio"); // Segunda condiçao para saber se voce clicou em reset
    }
  }
};

int main() {
  Sorteio gui;
  gui.show();
  return Fl::run();
}
