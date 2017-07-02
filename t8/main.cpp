#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

#include <FL/fl_ask.H>
#include "window.h"

using namespace std;

class Estrutura_Editor {
private:
  string id, label;
public:
  Estrutura_Editor(string id, string label) {
    this->id = id;
    this->label = label;
  }
  string Ret_Id(void) {
    return this->id;
  }
  string Ret_Label(void) {
    return this->label;
  }
  void Editar(string id, string label) {
    this->id = id;
    this->label = label;
  }
};

class Web_Editor: public UserInterface {
private:
  ifstream arq_projeto, arq_template;
  vector<Estrutura_Editor> linhas;
  vector<string> lin_template;
  string titulo;

public:
  Web_Editor() {
    Botao_Abrir_Carregar->callback((Fl_Callback*) cbBotao_Abrir_Carregar, (void*)(this));
    Botao_Deletar->callback((Fl_Callback*) cbBotao_Deletar, (void*)(this));
    Botao_Alterar->callback((Fl_Callback*) cbBotao_Alterar, (void*)(this));
    Botao_Inserir->callback((Fl_Callback*) cbBotao_Inserir, (void*)(this));
    Botao_Limpar->callback((Fl_Callback*) cbBotao_Limpar, (void*)(this));
    Botao_Salvar->callback((Fl_Callback*) cbBotao_Salvar, (void*)(this));
    Botao_Gerar->callback((Fl_Callback*) cbBotao_Gerar, (void*)(this));

    Navegador->callback((Fl_Callback*) cbNavegador, (void*)(this));
  }

  void show() {
    janela->show();
  }

  static void cbBotao_Salvar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);
    if(!gui->arq_projeto.is_open()) return;
    ofstream saida{"projeto.csv"};

    gui->linhas[0].Editar("titulo", gui->Titulo_Input->value());

    for(auto i = 0; i < gui->linhas.size(); i++) {
      saida << gui->linhas[i].Ret_Id() << "," << gui->linhas[i].Ret_Label() << endl;
    }
  }

  static void cbBotao_Limpar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);
    gui->Botao_Editar->value(" ");
  }

  static void cbBotao_Inserir(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);
    if(gui->linhas.size() == 0) return;

    stringstream linestream(gui->Botao_Editar->value());
    string id, label;
    getline(linestream, id, ',');
    getline(linestream, label,'\n');

    gui->linhas.push_back(Estrutura_Editor(id, label));
    gui->Navegador->add(gui->Botao_Editar->value());
  }

  static void cbBotao_Alterar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);
    int index = gui->Navegador->value();

    if(index <= 0) return;

    stringstream linestream(gui->Botao_Editar->value());
    string id, label;
    getline(linestream, id, ',');
    getline(linestream, label, '\n');

    std::cout << id << label << endl;

    gui->linhas[index].Editar(id, label);
    gui->Navegador->text(index, gui->Botao_Editar->value());
  }
  static void cbBotao_Deletar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);

    int index = gui->Navegador->value();
    if(index <= 0) return;

    gui->Navegador->remove(index);
    gui->linhas.erase(gui->linhas.begin() + index);
  }

  static void cbNavegador(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);
    int index = gui->Navegador->value();

    if(index <= 0) return;
    string atual = gui->linhas[index].Ret_Id() + "," + gui->linhas[index].Ret_Label() ;
    gui->Botao_Editar->value(atual.c_str());

  }

  static void cbBotao_Abrir_Carregar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);

    gui->arq_projeto.open("projeto.csv");
    gui->arq_template.open("template.html");

    if(!gui->arq_projeto.is_open()) {
      fl_alert("Arquivo projeto.csv não encontrado");
      return;
    }
    if(!gui->arq_template.is_open()) {
      fl_alert("Arquivo template.html não encontrado");
      return;
    }

    if(gui->linhas.size() > 0) {
      fl_alert("Arquivo ja carregado ou incompatível");
      return;
    }
    string linha, aux1, aux2;

    while(getline(gui->arq_projeto, linha)) {
      stringstream linestream(linha);
      getline(linestream, aux1, ',');
      getline(linestream, aux2, '\n');

      gui->linhas.push_back(Estrutura_Editor(aux1, aux2));
    }

    gui->titulo = gui->linhas[0].Ret_Label();
    gui->Titulo_Input->value(gui->titulo.c_str());

    for(auto i = 1; i < gui->linhas.size(); i++) {
      string l = gui->linhas[i].Ret_Id() + "," + gui->linhas[i].Ret_Label();
      gui->Navegador->add(l.c_str());
    }
    gui->Projeto_Aberto->label("Projeto e Templates carregados!");
  }
  static void cbBotao_Gerar(Fl_Widget* btn, void *userdata) {
    Web_Editor *gui = static_cast<Web_Editor*>(userdata);

    gui->linhas[0].Ret_Label() = gui->Titulo_Input->value();
    gui->titulo = gui->Titulo_Input->value();

    string linha;
    while(getline(gui->arq_template, linha)) {
      gui->lin_template.push_back(linha);
    }

    int n = gui->linhas.size();
    ofstream saida{"index.html"};
      for(auto i = 0; i < gui->lin_template.size(); i++){
        if(gui->lin_template[i] == ">>>1<<<") saida << "<title>" << gui->titulo << "</title>" << endl;
        else if(gui->lin_template[i] == ">>>2<<<") saida << "<h1>" << gui->titulo << "</h1>" << endl;
        else if(gui->lin_template[i] == ">>>3<<<") {
          for(auto j = 1;j < n; j++) {
            saida << "<div class=\"form-group\">" << endl;
            saida << "<label for=\"" << gui->linhas[j].Ret_Id() << "\" class=\"col-sm-2 control-label\">" << gui->linhas[j].Ret_Label() << "</label>" << endl;
            saida << "<div class=\"col-sm-6\">" << endl;
            saida << "<input type=\"text\" class=\"form-control validate[required]\" id=\"" << gui->linhas[j].Ret_Id() << "\" placeholder=\"" << gui->linhas[j].Ret_Label() << "\">" << endl;
            saida << "</div>" << endl;
            saida << "</div>" << endl;
          }
        }
        else if(gui->lin_template[i] == ">>>4<<<") {
          saida << "dataSet[seq]=[index, icons, ";
          for(auto j = 1; j < n; j++) {
            if(j + 1 == n) saida << "object." <<  gui->linhas[j].Ret_Id() << "];" << endl;
            else saida << "object." <<  gui->linhas[j].Ret_Id() << ", ";

          }
        }
       else if(gui->lin_template[i] == ">>>5<<<") {
         saida << "oTable=$('#table').dataTable({" << endl;
         saida  << "\"data\": dataSet," << endl;
         saida << "\"columns\": [" << endl;
         saida << "{ \"title\": \"Seq\", \"class\": \"center\" }," << endl;
         saida  << "{ \"title\": \"\", \"class\": \"center\" }," << endl;
         for(auto j = 1; j < n; j++) {

          saida  << "{ \"title\": \"" << gui->linhas[j].Ret_Label() << "\"}," << endl;

         }
         saida << "]" << endl;
         saida << "});" << endl;

        }
        else if(gui->lin_template[i] == ">>>6<<<") {
          saida << "$('#table tbody').on( 'click', '.glyphicon-edit', function () {" << endl;
		  saida << "$('#list').hide();" << endl;
	      saida << "var rows = $(this).parents('tr').children();" << endl;
	      saida << "$('#seq').text(rows[0].innerHTML);" << endl;
	     for(auto j = 1; j < n; j++) {
	       saida <<  "$('#" << gui->linhas[j].Ret_Id() << "').val(rows[" << j+1 << "].innerHTML);" << endl;
	     }
	      saida << "$('#formID').show();" << endl;
      	  saida << "} );" << endl;
        }
        else if(gui->lin_template[i] == ">>>7<<<") {

          saida << "function save() {" << endl;
         saida << "var seq=$('#seq').text();" << endl;
         saida << "if ( isNaN(seq) ) { seq=0; }" << endl;
         saida << "var key=formId+\"_\"+seq;" << endl;
         saida << "var object={" << endl;
         for(auto j = 1; j < n; j++) {
           saida << "\"" << gui->linhas[j].Ret_Id() << "\":$(\"#" << gui->linhas[j].Ret_Id() << "\").val()," << endl;
         }
          saida << "}" << endl;
          saida << "localStorage.setItem(key, JSON.stringify(object));" << endl;
          saida << "}" << endl;
        }
        else {
          saida << gui->lin_template[i] << endl;
        }
      }
  }
};

int main() {
  Web_Editor gui;
  gui.show();
  return Fl::run();
}
