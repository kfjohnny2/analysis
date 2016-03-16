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

    //------------------------------------------//
    cout << ">>> Alocando Vetor..." << endl;

    arraySize = pow(2, arraySize);
    vector<long int> V(arraySize);
    cout << arraySize << endl;
    
    cout << "\n>>> Alocação Concluida..." << endl;
    //------------------------------------------//
    cout << "\n>>> Preenchendo Vetor" << endl;

    //randomFill(V, l, r, seed, arraySize);
    randomFill( V, arraySize, seed);
    
    cout << "\n>>> Preenchimento Concluido" << endl;

    cout<< "\n>>> Ordenando o Vetor"<<endl;
    sort(V.begin(), V.end() );
    cout<< "\n>>> Ordenação Concluida"<<endl;
    //------------------------------------------//

    //3 - CONSTRUIR ARRAY DE FUNÇÕES

    long int (*funcArray[])(vector<long int> , long int , long int , long int) = {
        sSearchRec,
        bSearchIte,
        bTernRec,
        sSearchIte,
        bSearchRec,
        tSearchIte,
    };

    // long int *V;
    // V = new long int[arraySize];

    int z=5;
    for(long int n = 32; n <= arraySize; n *= 2){
        cout <<  "\n>>> Entrada: 2^"<< z << " " << n << endl;
        for(int i=0; i < 6; ++i){
           cout <<  "\n>>> Função "<< i << " : ";
           cout <<  calculateTime(V, funcArray[i], 3, 0, n-1) << "";
        }
        cout<<"\n";
        z++;
    }
    cout<<"\n";

    //4 - ATRIBUIR VALOR TOTAL A SER UTILIZADO NO ARRAY, EM UMA VARIAVEL
    //5 - CRIAR VARIÁVEIS E ATRIBUIR VALOR DE MAIOR E MENOR A CADA

    return 0;
}