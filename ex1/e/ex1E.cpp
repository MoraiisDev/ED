/*
João Vitor Morais Dias - 2 Semestre DSM
e) Efetuar o cálculo e a apresentação do valor de uma prestação em atraso, utilizando a fórmula
PRESTACAO ← VALOR + (VALOR * TAXA/100) * TEMPO).
*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//variáveis globais
int valor;
int taxa;
int tempo;
const int prestacao = (valor + (valor * taxa/100) * tempo);

int main()
{
    cout << "Vamos calcular o valor da sua prestação em atraso";
    cout << "\nInsira o valor inicial dessa prestação em R$: ";
    cin >> valor;
    
    cout << "\nAgora insira o valor da taxa atual (esse valor será convertido para %): ";
    cin >> taxa;
    
    cout << "\nInsira agora o tempo de atraso: ";
    cin >> tempo;
    
    const int prestacao = valor + (valor * taxa/100) * tempo;
    cout << "O valor da sua prestação é de: R$ " << prestacao; 

    return 0;
}