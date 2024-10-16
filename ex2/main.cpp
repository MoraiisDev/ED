#include <iostream>
#include <cstdlib>
#include <math.h>
#include <experimental/random> 
using namespace std;

void exA () {
// a) Ler 10 elementos de uma matriz tipo vetor e apresentá-los.
// Resolução:
int vetorA[10], i; 
    for (i=0 ; i<10 ; i++) {
      vetorA[i] = experimental::randint(20,50); // Preenche os índices de A
      cout << vetorA[i] << endl; // Exibe o número que está alocado em cada índice
    }
}

void exB () {
/*  b) Ler 8 elementos em uma matriz A tipo vetor. Construir uma matriz B de mesma dimensão com os
elementos da matriz A multiplicados por 3. Apresentar o vetor B. */
//  Resolução:
int vetorA[8], vetorB[8], i;

  //Preenchendo vetor A,B e exibindo B
  cout << "Vetor B: " << endl;
  for (i=0; i<8; i++) {
    vetorA[i] = experimental::randint(10,30);
    vetorB[i] = vetorA[i] * 3;
    cout << vetorB[i] << endl;
  }
}

void exC () {
/*c) Ler duas matrizes A e B do tipo vetor com 20 elementos. Construir uma matriz C, onde cada
elemento de C é a subtração do elemento correspondente de A com B. Apresentar a matriz C.*/
int vetorA[20], vetorB[20], vetorC[20], i;

  //Preenchendo vetor A,B e C, exibindo C
  cout << "Vetor C:" << endl;
  for (i = 0; i<20; i++)
    {
      vetorA[i] = experimental::randint(40,50); //Preenche A
      vetorB[i] = experimental::randint(5,30);  //Preenche B
      vetorC[i] = vetorA[i] - vetorB[i]; //Preenche C
      cout << vetorC[i] << endl; //Exibe C
    }
}

void exD() {
/* d) Ler 15 elementos de uma matriz tipo vetor. Construir uma matriz B de mesmo tipo, observando a
seguintes lei de formação: “Todo elemento de B deverá ser o quadrado do elemento de A
correspondente”. Apresentar as matrizes A e B. */
int vetorA[15], vetorB[15], i;

  //Preenchendo os índices da matriz A, exibindo-a
  cout << "Vetor A" << endl;
  for (i = 0; i<15; i++) {
    vetorA[i] = experimental::randint(10,20);
    cout << vetorA[i] << endl;
  }
  //Preenchendo os índices da matriz B, exibindo-a
  cout << "Vetor B" << endl;
  for (i = 0; i<15; i++) {
    vetorB[i] = pow(vetorA[i], 2); // vetorA[i]^2 
    cout << vetorB[i] << endl;
  }
}

void exE() {
/*e) Ler duas matrizes A e B do tipo vetor com 15 elementos cada. Construir uma matriz C, sendo esta a
junção das duas outras matrizes. Desta forma, C deverá ter o dobro de elementos, ou seja, 30.
Apresentar a matriz C*/
const int sizeEl = 15; // tamanho de elementos a serem preenchidos
int vetorA[sizeEl], vetorB[sizeEl], vetorC[2*sizeEl], i;

  //Preenchendo os índices das matrizes A e B
  for (i=0; i<sizeEl; i++) {
    vetorA[i] = experimental::randint(10,20);
    vetorB[i] = experimental::randint(10,20);
  }

  //Preenchendo os índices da matriz C
  for (i=0; i<sizeEl; i++) {
    vetorC[i] = vetorA[i]; // Primeiros 15 índices = ao do vetor A
    vetorC[i + sizeEl] = vetorB[i]; // Índices restantes = ao do vetor B
  }

  //Exibindo matriz C - for com (i < tamanho total do vetor C)
  cout << "Vetor C" << endl;
  for (i = 0; i<2*sizeEl; i++) {
    cout << vetorC[i] << endl;
  }
}

void exF() {
/*f) Ler duas matrizes do tipo vetor, sendo A com 20 elementos e B com 30 elementos. Construir uma
matriz C, sendo esta a junção das duas outras matrizes. Desta forma, C deverá ter a capacidade de
armazenar 50 elementos. Apresentar a matriz C.*/
const int sizeA = 20;
const int sizeB = 30;
const int sizeC = (sizeA+sizeB);
int vetorA[20], vetorB[30], vetorC[sizeC], i;

  //Preenchendo os índices do vetor A
  for (i=0; i<sizeA; i++) {
    vetorA[i] = experimental::randint(10,20);
  }

  //Preenchendo os índices do vetor B
  for (i=0; i<sizeB; i++) {
    vetorB[i] = experimental::randint(30,40);
  }

  //Preenchendo os índices do vetor C
  for (i=0; i<sizeA; i++) {
    vetorC[i] = vetorA[i];
  }
  for (i=0; i<sizeB; i++) {
    vetorC[i + sizeA] = vetorB[i];
  }
  
  //Exibindo vetor C
  cout << "Vetor C:" << endl;
  for (i = 0; i<sizeC; i++) {
    cout << i+1 << " -> " << vetorC[i] << endl;
  }
}

void exG() {
/*g) Ler 20 elementos de uma matriz A tipo vetor e construir uma matriz B de mesma dimensão com os
mesmo elementos da matriz A, sendo que deverão estar invertidos. Ou seja, o primeiro elemento de
A passa a ser o último de B, o segundo elemento de A passa a ser o penúltimo elemento de B e
assim por diante. Apresentar as matrizes A e B lado a lado. */
const int sizeEl = 20;
int vetorA[sizeEl], vetorB[sizeEl], i;

  for (i = 0; i < sizeEl; i++) {
    vetorA[i] = experimental::randint(30,40); //Preenchendo o vetor A
  }

  for (i = 0; i < sizeEl; i++) {
    vetorB[i] = vetorA[sizeEl - 1 - i]; //Invertendo A e preenchendo B
  }

  cout << "MA \t MB" << endl;
  for (i = 0; i < sizeEl; i++) {
    cout << vetorA[i] << "\t" << vetorB[i] << endl;
  }
}

void start() {
int escolhaExercicio,escolha;

  cout << "Escolha o exercicio que deseja realizar:\n";
  cout << "1 - Exercicio A\n";
  cout << "2 - Exercicio B\n";
  cout << "3 - Exercicio C\n";
  cout << "4 - Exercicio D\n";
  cout << "5 - Exercicio E\n";
  cout << "6 - Exercicio F\n";
  cout << "7 - Exercicio G\n";
  cout << endl;
  cout << "Escolha: ";
  cin >> escolhaExercicio;

  switch (escolhaExercicio)
  {
  case 1:
    exA();
    break;

  case 2:
    exB();
    break;

  case 3: 
    exC();
    break;

  case 4:
    exD();
    break;

  case 5:
    exE();
    break;

  case 6:
     exF();
     break;

  case 7:
    exG();
    break;

  default:
     cout << "Valor inválido";
     start();
     break;
  }

  cout << "Deseja reiniciar o programa? 1-Sim / 2-Nao ";
  cin >> escolha;
    if (escolha == 1) {
      start();
    }
    else {
      cout << "Obrigado por utilizar o programa"; 
    }
  }

int main () {
  start();
  return 0;
}