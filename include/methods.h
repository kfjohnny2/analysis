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

template <typename Obj>
int searchIte( Obj *, const Obj &x, int high );

template <typename Obj>
int bSearchRec(Obj *, Obj &x, int low, int high);

template <typename Obj>
int tSearchIte(Obj *, Obj &x, int low, int high);

#include "methods.inl"

#endif