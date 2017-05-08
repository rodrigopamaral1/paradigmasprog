#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PontosMax {  // Classe para guardar nomes sem repetiçoes, e a soma de suas pontuaçoes, ou seja, sua pontuaçao Total
  string nome;
  int ptmax;

public:
  PontosMax(string nome, int ptmax) {
  this->nome = nome;
  this->ptmax = ptmax;
  }
  string Ret_Nome(void) {
    return nome;
  }
  int Ret_Ptmax(void) {
    return ptmax;
  }
  bool operator<(PontosMax& p) {
    return this->ptmax < p.ptmax;
  }
};

class Pontos {  // Classe para guardar nome, atividade e pontuaçao dos jogadores
  string nome, atividade;
  int pontos;

public:
  Pontos(string nome, string atividade, int pontos) {
    this->nome = nome;
    this->atividade = atividade;
    this->pontos = pontos;
  }
  string Ret_Nome(void) {
    return nome;
  }
  string Ret_Atividade(void) {
    return atividade;
  }
  int Ret_Pontos(void) {
    return pontos;
  }
  bool operator<(Pontos& p) {
    return this->pontos < p.pontos;
  }
};

bool Compara_Nome(Pontos& p1, Pontos& p2) {
  return p1.Ret_Nome() < p2.Ret_Nome();
}

int main(void)  {
  ifstream arquivo{"data.csv"};

  if(!arquivo.is_open()) return 1;

  vector<Pontos> pt; // Classe para guardar nome, atividade e pontuaçao dos jogadores
  vector<PontosMax> ptmax; // Classe para guardar nomes sem repetiçoes, e a soma de suas pontuaçoes, ou seja, sua pontuaçao Total

  string linha;
  string inf[3];
  while(getline(arquivo, linha)) {
    stringstream linestream(linha);
    getline(linestream, inf[0], ',');
    getline(linestream, inf[1], ',');
    getline(linestream, inf[2], '\0');
    pt.push_back(Pontos(inf[0], inf[1], atoi(inf[2].c_str()))); // Inserção na Classe normal (Nome, Atividade, Ponto)
  }

  sort(pt.begin(), pt.end()); // Ordena o vetor a partir das pontuaçoes
  cout << "<Lista das pontuacoes em atividades ordenadas da maior para a menor pontuacao>" << endl;
  for(auto i = pt.size()-1 ; i != -1; i--) // Printa o vetor ordenado do maior para a menor pontuação
    std::cout << "-> " << pt[i].Ret_Nome() << " " << pt[i].Ret_Atividade() << " " << pt[i].Ret_Pontos() << endl;
  std::cout << std::endl;

   sort(pt.begin(), pt.end(), Compara_Nome); //Ordena o Vetor por Ordem Alfabetica, assim ja fica ordenado e fica facil juntar os nomes repetidos
                                             // Para por na Classe PtsMax
   for(auto i = 0 ; i < pt.size(); i++) { // Aqui com os nomes ja ordenados, tira os nomes repetidos e faz a soma das pontuaçoes maximas por nome
     string nome = pt[i].Ret_Nome();
     int pontos = pt[i].Ret_Pontos();
     bool c = true;
     while(c == true && i + 1 != pt.size()) {
       c = false;
       if(pt[i].Ret_Nome() == pt[i+1].Ret_Nome()) {
         pontos = pontos + pt[i+1].Ret_Pontos();
         i++;
         c = true;
       }
     }
     ptmax.push_back(PontosMax(nome, pontos)); // Poem na classe as pontuações totais por ordem alfabética do nome do jogador
   }

  cout << "<Liste as pontuacoes totais por ordem alfabetica do nome do jogador>" << endl;
  for(auto i = 0; i < ptmax.size(); i++) { // Printa as pontuações totais por ordem alfabética do nome do jogador
    cout << "-> " << ptmax[i].Ret_Nome() << " " << ptmax[i].Ret_Ptmax() << endl;
  }
  cout << endl;

  sort(ptmax.begin(), ptmax.end()); // Ordena as pontuações totais por ordem de pontuação, da menor para a maior

  cout << "<Lista das pontuacoes totais por ordem de pontuacao, da menor para a maior>" << endl;
  for(auto i = 0 ; i < ptmax.size(); i++) // Printa as pontuações totais por ordem de pontuação, da menor para a maior
    std::cout << "-> " << ptmax[i].Ret_Nome() << " "  << ptmax[i].Ret_Ptmax() << endl;
  std::cout << std::endl;

  return 0;
}
