#ifndef _COMPACT_H_
#define _COMPACT_H_


using namespace std;


template <typename Obj>
int sSearchRec(Obj * , Obj , int , int ); // busca sequencial recursiva

template <typename Obj>
int bSearchIte(Obj * , Obj , int , int ); // busca binária iterativa

template <typename Obj>
int bTernRec(Obj * , Obj , int , int ); // busca ternária recursiva

template <typename Obj>
int wStdSearch(Obj * , Obj , int , int ); // wrapper para busca sequencial

template <typename Obj>
void randomFill(Obj *, const Obj , const Obj , const unsigned int , const int );

template <typename Obj>
long double calculateTime(const Obj, int * ( Obj *, const Obj, int, int), const Obj);


#include "methods.inl"

#endif