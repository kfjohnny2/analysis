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

long double calculateTime(const std::vector<long int> , int (*)(std::vector<long int>, long int, int, int ), long int , int , int  );

/*template <typename Obj>
long double calculateTime(int, int (*)(Obj *, Obj, int, int), Obj , int , int, const std::vector<Obj> v);*/

template <typename Obj>
int searchIte( std::vector<Obj> *, const Obj &x, int high );

template <typename Obj>
int bSearchRec(std::vector<Obj> *, Obj &x, int low, int high);

template <typename Obj>
int tSearchIte(std::vector<Obj> *, Obj &x, int low, int high);

#include "methods.inl"

#endif