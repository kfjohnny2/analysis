#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <iostream>

#include "methods.h"

#define PATTERN_VECTOR 5 // tamanho padrão atribuído no vetor
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
        cout << "TAMANHO DO VETOR DEVE SER MAIOR QUE 5 E MENOR QUE 31! O MENOR VALOR SERÁ ATRIBUÍDO" << endl;
        arraySize = PATTERN_VECTOR;
    }

    arraySize = pow(2, arraySize);


    //3 - CONSTRUIR ARRAY DE FUNÇÕES

    int (*funcArray[])(vector<long int> , long int , int , int) = {
        sSearchRec,
        bSearchIte,
        bTernRec,
        // sSearchIte,
        // bSearchRec,
        // tSearchIte,
    };

    // long int *V;
    // V = new long int[arraySize];
    cout << "ALOCATING VECTOR" << endl;

    vector<long int> V(arraySize);
    long int l = 0, r = 1000;

    cout << arraySize << endl;

    randomFill(V, l, r, seed, arraySize);
    // randomFill( V, arraySize, seed);

    cout << "FINISHED" << endl;

    for(long int n = 16; n < arraySize; n *= 2){
        for(int i=0; i < 3; ++i){
           long double duration = calculateTime(V, funcArray[i], 3, 0, n-1) ;
           cout << i << ", " << n << ", " << duration << endl;
           printFile(i, duration, n);
        }
    }

    //4 - ATRIBUIR VALOR TOTAL A SER UTILIZADO NO ARRAY, EM UMA VARIAVEL
    //5 - CRIAR VARIÁVEIS E ATRIBUIR VALOR DE MAIOR E MENOR A CADA

    return 0;
}