#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <iostream>

#include "methods.h"

#define PATTERN_VECTOR 20 // tamanho padrão atribuído no vetor
#define MAX_VECTOR  30     // maior tamanho a ser alocado no vetor

using namespace std;

int main(int argc, char const *argv[])
{
    auto arraySize(PATTERN_VECTOR);
    int seed = 1;
    //1 - ATRIBUIR VALOR PADRÃO AO VETOR DA LINHA DE COMANDO
    if(argc > 1){
        stringstream(argv[1]) >> arraySize;
    }
    //2 - VERIFICAR SE A QUANTIDADE DE TERMOS NO VETOR É VÁLIDA (size >= 5)
    if(arraySize < 5 || arraySize > MAX_VECTOR){
        cout << "TAMANHO DO VETOR DEVE SER MAIOR QUE 5 E MENOR QUE 31! O VALOR PADRAO SERÁ ATRIBUIDO" << endl;
        arraySize = PATTERN_VECTOR;
    }

    arraySize = pow(2, arraySize);


    //3 - CONSTRUIR ARRAY DE FUNÇÕES

    int (*funcArray[])(vector<long int> , long int , int , int) = {
        sSearchRec,
        bSearchIte,
        bTernRec,
    };

    // long int *V;
    // V = new long int[arraySize];
    cout << "ALOCATING VECTOR" << endl;

    vector<long int> V(arraySize);
    long int l = -98765, r = 98765;

    cout << arraySize << endl;

    randomFill(V, l, r, seed, arraySize);

    cout << "FINISHED" << endl;

    for(int n = 16; n < arraySize; n *= 2){
        for(int i=0; i < 3; ++i){
           cout <<  calculateTime(V, funcArray[i], 3, l, r) << endl;
        }
    }

    //4 - ATRIBUIR VALOR TOTAL A SER UTILIZADO NO ARRAY, EM UMA VARIAVEL
    //5 - CRIAR VARIÁVEIS E ATRIBUIR VALOR DE MAIOR E MENOR A CADA

    return 0;
}