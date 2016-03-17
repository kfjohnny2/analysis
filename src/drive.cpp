#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#include <iostream>

#include "methods.h"

#define PATTERN_VECTOR    5     // DEFAULT VALUE TO THE VECTOR
#define MAX_VECTOR       30     // HIGHEST VALUE TO THE VECTOR
/* enum alike defines*/
#define NORMAL            0     // FOR NORMAL MIXED SEARCHS
#define WORST_CASE        1     // FOR WORST CASE: WHEN THE VALUE ISN'T IN IN THE VECTOR
#define THIRD_PART  2     // FOR THE THIRD PART OF THE VECTOR

using namespace std;

int main(int argc, char const *argv[])
{
    auto arraySize(PATTERN_VECTOR);
    int seed = 1;
    ofstream myfile_third;
    ofstream myfile_worst;

    /*VERIFY IF HAVE ANY ARGUMENTS ON COMMANDO LINE FOR THE VECTOR EXPONENT,
    IF YES PUT ON ARRAY SIZE, ELSE USES THE DEFAULT VALUE FOR THE EXPONENT*/
    if(argc > 1){
        stringstream(argv[1]) >> arraySize;
    } else{
        arraySize = PATTERN_VECTOR;
    }
    //CHECK IF THE SIZE(size >= 5), ELSE USES DEFAULT VALUE
    if(arraySize < 5 || arraySize > MAX_VECTOR){
        cout << ">>> SIZE OF THE VECTOR MUST BE BETWEEN 5 AND 30! THE LOWEST VALUE WILL BE APPLIED DO THE VECTOR" << endl;
        arraySize = PATTERN_VECTOR;
    }

    //------------------------------------------//
    cout << ">>> Allocating vector..." << endl;

    //USES THE EXPONENT TO CREATE THE VALUE TO ALLOCATE THE VECTOR
    arraySize = pow(2, arraySize);
    vector<long int> V(arraySize);
    cout << arraySize << endl;

    cout << "\n>>> Allocating finished..." << endl;
    //------------------------------------------//
    cout << "\n>>> Filling vector" << endl;

    randomFill( V, arraySize, seed);

    cout << "\n>>> Filling finished" << endl;


    //------------------------------------------//

    // BUILD THE ARRAY OF FUNCTION WITH ALL SEARCHS
    

    long int (*funcArray[])(vector<long int> , long int , long int , long int) = {
        sSearchRec,
        sSearchIte,
        bTernRec,
        bSearchIte,
        bSearchRec,
        tSearchIte,
        bWrapperSearch,
    };

    string n_function[] = {"sequencial_search_rec",
                           "sequencial_search_ite",
                           "ternary_search_rec",
                           "binary_search_ite",
                           "binary_search_rec",
                           "ternary_search_ite",
                           "wrapper_binary_search" };
    
    long int third;
    long int worst = 1001; //I'm using a vector with values from 0 to 1000, and 1001 dont exist
    cout << "\n>>> Calculando Tempo de Algoritimos" << endl;
    for(int i = 0; i < 7; i++){
        if (i == 2){
            cout << "\n>>> Sorting vector" << endl;
            sort(V.begin(), V.end()); // sort the vector for sorted searchs
            cout << "\n>>> Sorting completed\n" << endl;
        }
        
        //int t;
        myfile_third.open("files/thirdFour/" + n_function[i] + "_thirdFour.dat"  );
        myfile_worst.open("files/worstCase/" + n_function[i] + "_worstCase.dat"  );

                cout << n_function[i] << endl;
        if(i == 0 && arraySize > pow(2, 13)){// VERIFIQUE O LIMITE DE ITERAÇÕES PARA A SEQUENCIAL RECURSIVA E ALTERE AQUI .. PQ DEPOIS DO LIMITE ELE PARA DE EXECUTAR 
            for(long int n = 32; n <= pow(2, 13); n *= 2){
                third = V[3*n/4];
                
                cout << n << endl;
                myfile_third << n << " " << calculateTime(V, funcArray[i], third, 0, n-1) << endl; //imprime o valor da variavel cont no dat    
                myfile_worst << n << " " << calculateTime(V, funcArray[i], worst, 0, n-1) << endl; //imprime o valor da variavel cont no dat   
            }


        }else{

            for(long int n = 32; n <= arraySize; n *= 2){
                third = V[3*n/4];
                
                //cout << n << endl;
                myfile_third << n << " " << calculateTime(V, funcArray[i], third, 0, n-1) << endl; //imprime o valor da variavel cont no dat    
                myfile_worst << n << " " << calculateTime(V, funcArray[i], worst, 0, n-1) << endl; //imprime o valor da variavel cont no dat   
            }
        }    

        myfile_third.close();
        myfile_worst.close(); 
    }          

    cout << "\n>>> Medições concluidas, Obrigado .." << endl;
    
    V.clear();
    return EXIT_SUCCESS;
}