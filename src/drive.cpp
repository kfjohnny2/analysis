#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <iostream>

#include "methods.h"

#define PATTERN_VECTOR    5 // tamanho padrão atribuído no vetor
#define MAX_VECTOR       30     // maior tamanho a ser alocado no vetor
#define NORMAL            0
#define WORST_CASE        1
#define THIRD_APPEARANCE  2

using namespace std;

int main(int argc, char const *argv[])
{
    auto arraySize(PATTERN_VECTOR);
    int seed = 1;
    //1 - ATRIBUIR VALOR PADRÃO AO VETOR DA LINHA DE COMANDO
    if(argc > 1){
        stringstream(argv[1]) >> arraySize;
    }
    //VERIFICAR SE O TAMANHO DO VETOR É VÁLIDO (size >= 5)
    if(arraySize < 5 || arraySize > MAX_VECTOR){
        cout << "TAMANHO DO VETOR DEVE SER MAIOR QUE 5 E MENOR QUE 31! O MENOR VALOR SERÁ ATRIBUÍDO" << endl;
        arraySize = PATTERN_VECTOR;
    }

    //------------------------------------------//
    cout << ">>> Alocando Vetor..." << endl;

    arraySize = pow(2, arraySize);
    vector<long int> V(arraySize);
    cout << arraySize << endl;

    cout << "\n>>> Alocação Concluida..." << endl;
    //------------------------------------------//
    cout << "\n>>> Preenchendo Vetor" << endl;

    randomFill( V, arraySize, seed);

    cout << "\n>>> Preenchimento Concluido" << endl;

    cout<< "\n>>> Ordenando o Vetor"<<endl;

    cout<< "\n>>> Ordenação Concluida"<<endl;
    //------------------------------------------//

    //3 - CONSTRUIR ARRAY DE FUNÇÕES

    long int (*funcArray[])(vector<long int> , long int , long int , long int) = {
        sSearchRec,
        sSearchIte,
        bTernRec,
        bSearchIte,
        bSearchRec,
        tSearchIte,
    };
    long double duration;
    long int worst = 1001; //I'm using a vector with values from 0 to 1000, and 1001 dont exist
    long int third;

    for(long int n = 32; n <= arraySize; n *= 2){
        // cout <<  "\n>>> Entrada: 2^"<< z << " " << n << endl;
        for(int i=0; i < 6; ++i){
            if(i == 2)
        third = V[3*n/4];
        duration = calculateTime(V, funcArray[i], third, 0, n-1);
        printFile(i, duration, n, THIRD_APPEARANCE);
        duration = calculateTime(V, funcArray[i], worst, 0, n-1);
        printFile(i, duration, n, WORST_CASE);
        duration = calculateTime(V, funcArray[i], 47, 0, n-1);
        printFile(i, duration, n, NORMAL);
        }
    }

    return 0;
}