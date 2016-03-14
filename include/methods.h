
using namespace std;

template <typename Obj>

int sSearchRec(std::vector<Obj> , Obj , int , int ); // busca sequencial recursiva

int bSearchIte(std::vector<Obj> , Obj , int , int ); // busca binária iterativa

int bTernRec(std::vector<Obj> , Obj , int , int ); // busca ternária recursiva

int wStdSearch(std::vector<Obj> , Obj , int , int ); // wrapper para busca sequencial

void randomFill(std::vector<Obj> , const Obj , const Obj , const unsigned int , const int );

