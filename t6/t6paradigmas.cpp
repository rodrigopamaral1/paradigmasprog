#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define PI 3.14159265358979323846

using namespace std;

class Quadrado { //SERVE PARA RETANGULOS TAMBEM
protected:
  float area;
public:
  Quadrado() {
    this->area = 0;
  }
  void Calc_Area_Quad(float b, float h) {
    this->area = (b*h);
  }
  float Ret_Quad_Area() {
    return this->area;
  }
};

class Triangulo {
protected:
  float area;
public:
  Triangulo() {
    this->area = 0;
  }
  void Calc_Area_Triang(float b, float h) {
    this->area = ((b*h)/2);
  }
  float Ret_Triang_Area() {
    return this->area;
  }
};

class Circulo {
protected:
  float area;
public:
  Circulo() {
    this->area = 0;
  }
  void Calc_Area_Circ(float r) {
    this->area = (PI*(r*r));
  }
  float Ret_Circ_Area() {
    return this->area;
  }
};

class Biscoito: public Quadrado, public Triangulo, public Circulo {
private:
  string tamanho; // GUARDA UMA STRING INFORMANDO SE E PEQUENO, MEDIO OU GRANDE
  float preco; // GUARDA O PRECO DO BISCOITO
  int forma; // GUARDA UM INTEIRO QUE REPRESENTA A FORMA
public:
  Biscoito(int forma) {
    this->preco = 0;
    this->forma = forma;
  }
  GetForma() {
    return this->forma;
  }
  float GetArea() { // RETORNA A AREA PARA A FORMA QUE O BISCOITO É
    if(forma == 1) return this->Ret_Circ_Area();
    else if(forma == 2) return this->Ret_Triang_Area();
    else if(forma == 3) return this->Ret_Quad_Area();
  }
  float GetPreco() {
    return this->preco;
  }
  string GetTamanho() {
    return this->tamanho;
  }
  Calcula_Preco() { // FAZ O CALCULO NO PRECO BASEADO NA AREA DO BISCOITO
    int area = GetArea();
    if(area <= 5) { // DE 0 A 5 E PEQUENO E CUSTA 2 REAIS
      this->preco = 2;
      this->tamanho = "pequeno";
    }
    else if(area > 5 && area <= 10) { // DE 6 A 10 E MEDIO E CUSTA 4 REAIS
      this->preco = 4;
      this->tamanho = "medio";
    }
    else if(area > 10) { // MAIOR QUE 10 E GRANDE E CUSTA 6 REAIS
      this->preco = 6;
      this->tamanho = "grande";
    }
  }
};

bool cmpArea(Biscoito &a, Biscoito &b) {
  return a.GetArea() < b.GetArea();
}

int main() {
  int n;
  std::cin >> n;

  srand(time(NULL));
  vector<Biscoito> Vetor; // VETOR QUE REPRESENTA OS BISCOITOS

  for(auto i = 0; i < n; i++) {
    int forma = 1 + rand()% 3; // SORTEIA A FORMA DO BISCOITO, 1 eh CIRCULO, 2 TRIANGULO e 3 QUADRADO/RETANGULO

    Biscoito *novo = new Biscoito(forma); // CRIA UM BISCOITO

    float raio = 1 + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/1)); // SORTEIA UM RAIO
    float b = 1 + rand() % 5; // BASE
    float h = 1 + rand() % 3; // ALTURA

    if(forma == 1) novo->Calc_Area_Circ(raio); // CALCULA A AREA PARA A FORMA CORRESPONDENTE
    else if(forma == 2) novo->Calc_Area_Triang(b, h);
    else if(forma == 3) novo->Calc_Area_Quad(b, h);

    novo->Calcula_Preco(); // COM A AREA JA CALCULADA, PEGA ELA E CALCULA O PRECO E JA INSERE NA CLASSE DIRETAMENTE
    Vetor.push_back(*novo); // INSERE NO VETOR

    delete novo;
  }
  //########################################
  /*cout << "PRINT DO VETOR DETELHADAMENTE" << endl;
  for(auto i = n-1;i > -1; i--) { // ######## DESCOMENTE ESTA PARTE PARA VER O VETOR DETALHADAMENTE E ORIGINAL#######
   int forma = Vetor[i].GetForma();
   if(forma == 1) cout << "Circulo de Area  : " << Vetor[i].GetArea() << " e preco: $" << Vetor[i].GetPreco() << " " << Vetor[i].GetTamanho();
   else if(forma == 2) cout << "Triangulo de Area: " << Vetor[i].GetArea()<< " e preco: $" << Vetor[i].GetPreco() << " " << Vetor[i].GetTamanho();
   else if(forma == 3) cout << "Quadrado de Area : " << Vetor[i].GetArea()<< " e preco: $" << Vetor[i].GetPreco() << " " << Vetor[i].GetTamanho();
   cout << std::endl;
   }
   cout << std::endl;*/
 //####################################
  sort(Vetor.begin(), Vetor.end(), cmpArea); // SORTE PELA AREA/TAMANHO DOS BISCOITOS

  cout << "* Lista de Todos Biscoitos ordenados por Tamanho do Maior para o Menor:" << endl << endl; // PRIMEIRA SAIDA REQUISITADA
  for(auto i = n-1;i > -1; i--) {
    cout << " -> " <<Vetor[i].GetArea() << " cm2" << endl;
   }
   cout << endl;

  float somapeq = 0, somamed = 0, somagrand = 0;
  int peq = 0, med = 0, grand = 0;

  for(auto i = 0; i < n; i ++) { // CALCULO DOS TAMANHOS E SEUS RESPECTIVOS LUCROS PARA A SEGUNDA SAIDA
    if(Vetor[i].GetTamanho() == "pequeno") {
      peq++;
      somapeq = somapeq + Vetor[i].GetPreco();
    }
    else if(Vetor[i].GetTamanho() == "medio") {
      med++;
      somamed = somamed + Vetor[i].GetPreco();
    }
    else if(Vetor[i].GetTamanho() == "grande") {
      grand++;
      somagrand = somagrand + Vetor[i].GetPreco();
   }
  } // SEGUNDA SAIDA
  cout << "* Quantidade de biscoitos pequenos, médios e grandes, e a respectiva estimativa do valor total a ser arrecadado com cada tamanho de biscoito:" << endl << endl;
  cout << " -> Existem " << peq << " Biscoitos Pequenos e o Dinheiro Total eh $" << somapeq << " Reais" << endl;
  cout << " -> Existem " << med << " Biscoitos Medios e o Dinheiro Total eh $" << somamed << " Reais" <<endl;
  cout << " -> Existem " << grand << " Biscoitos Grandes e o Dinheiro Total eh $" << somagrand << " Reais" <<endl << endl;

  return 0;
}
