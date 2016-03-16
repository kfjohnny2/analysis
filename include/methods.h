#ifndef _COMPACT_H_
#define _COMPACT_H_


using namespace std;


template <typename Obj>
int sSearchRec(std::vector<Obj> * , Obj , int , int ); // busca sequencial recursiva

template <typename Obj>
int bSearchIte(std::vector<Obj> * , Obj , int , int ); // busca binária iterativa

template <typename Obj>
int bTernRec(std::vector<Obj> * , Obj , int , int ); // busca ternária recursiva

template <typename Obj>
int wStdSearch(std::vector<Obj> * , Obj , int , int ); // wrapper para busca sequencial

template <typename Obj>
void randomFill(std::vector<Obj> &, const Obj , const Obj , const unsigned int , const int );

// template<typename Obj>
// void randomFill( vector<Obj> &, Obj, const unsigned int );

long double calculateTime(const std::vector<long int> , int (*)(std::vector<long int>, long int, int, int ), long int , long int , long int  );

void printFile(int, long double , long int );

/*template <typename Obj>
long double calculateTime(int, int (*)(Obj *, Obj, int, int), Obj , int , int, const std::vector<Obj> v);*/

template<typename Obj>
long int sSearchIte( vector<Obj>, const Obj, long int, long int  );

template<typename Obj>
long int bSearchRec( vector<Obj>, const Obj, long int, long int );

template<typename Obj>
long int tSearchIte( vector<Obj>, const Obj , long int, long int );

template<typename Obj>
long int bWrapperSearch( vector<Obj>, const Obj, long int, long int );

template<typename Obj>
int comparar ( const Obj, const Obj );

#include "methods.inl"

#endif