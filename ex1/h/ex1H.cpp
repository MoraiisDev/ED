/*
João Vitor Morais Dias - 2 Semestre DSM
h) Elaborar um programa que calcule e apresente o volume de uma caixa retangular, por meio da fórmula
VOLUME ← COMPRIMENTO * LARGURA * ALTURA
*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//variáveis globais
int base; // base/comprimento
int width; // largura
int height; // altura

int main()
{
    //dados de entrada
    cout << "Vamos calcular o Volume de uma caixa retângular!";
    cout << "\nInsira o valor da base dessa caixa em cm: ";
    cin >> base;
    
    cout << "\nAgora insira o valor largura da mesma também em cm: ";
    cin >> width;
    
    cout << "\nAgora a altura: ";
    cin >> height;
    
    const int size = base * width * height; //cálculo do volume
    cout << "O volume da sua caixa é de " << size << "cm³"; 

    return 0;
}