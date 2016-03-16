#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>

#include "methods.h"

using namespace std;
using namespace chrono;

template <typename Obj>
int sSearchRec(std::vector<Obj> v , Obj n, int l, int r){
    if(l>r)
        return -1;
    else if (v[l] == n)
        return 1;
    else
        return sSearchRec(v, n, l+1, r);
}

template <typename Obj>
int bSearchIte(std::vector<Obj> v, Obj n, int l, int r){
    while (l <= r){
        int media = (l+r)/2;
        if(v[media] == n){
            return media;
        } else if (v[media] < n){
            l = media+1;
        } else{
            r = media-1;
        }
    }

    return -1;
}

template <typename Obj>
int bTernRec (std::vector<Obj> v, Obj n, int l, int r){
    int media0 = (r+(2*l))/3;
    int media1 = (l+(2*r))/3;

    if(l > r)
        return -1;
    else if( n == v[media0]){
        return media0;
    } else if( n == v[media1]){
        return media1;
    } else if( n > v[media1]){
        return bTernRec(v, n, media1+1, r);
    } else if( n < v[media0]){
        return bTernRec(v, n, l, media0-1);
    } else{
        return bTernRec(v, n, media0+1, media1-1);
    }
}

// template <typename Obj>
// int wStdSearch (Obj v, Obj n, int l, int r){

// }

template <typename Obj>
void randomFill(std::vector<Obj> &v, const Obj l, const Obj u, const unsigned int seed, const int size) {
    // use the default random engine and an uniform distribution
    default_random_engine eng(seed);
    uniform_real_distribution<double> distr(l, u);

    // Fill up vector
    for (int i = 0; i < size; i++)
        v[i] = distr(eng);
}

long double calculateTime(const std::vector<long int> v, int (*function)(std::vector<long int>, long int, int, int ), long int x, int l, int r ){

    long double duration = 0;
    for (int i = 0; i < 99; ++i)
    {
        auto start = steady_clock::now();

            function(v, x, l, r);

        auto end = steady_clock::now();
        auto diff = chrono::duration <double, std::milli> (end-start).count();
        duration += (diff-duration)/(i+1);
    }
    return duration;
}

// template <typename Obj>
// long double calculateTime(int x , int (*function)(Obj , Obj , int , int ), Obj n, int l, int r, const std::vector<Obj> v){
//     long double duration = 0;
//     for (int i = 0; i < x; ++i)
//     {
//         auto start = steady_clock::now();
//         function(v, n, l, r);
//         auto end = steady_clock::now();
//         auto diff = chrono::duration <double, std::milli> (end-start).count();

//         duration += (diff-duration)/(i+1);
//     }
//     return duration;
// }

//PARTE DE BRENO
template <typename Obj>
int searchIte( std::vector<Obj> _V, Obj &x, int high )
{
    for (int z =0; z <= high; z++)
    {
        if(_V[z] == x)
            return z;
    }
    return -1;
}

template <typename Obj>
int bSearchRec(std::vector<Obj> _V, Obj &x, int low, int high)
{
    int mid = ( low+ high )/2;
    if ( low > high)
        return -1;
    if ( _V[mid] == x )
        return mid;
    else if ( _V[mid] < x )
        return bSearchRec( _V, x,  mid+1, high);
    else
        return bSearchRec( _V,  x, low, mid-1);
}

template <typename Obj>
int tSearchIte(std::vector<Obj> _V, Obj &x, int low, int high)
{
    while (low <= high)
    {
        int T1 = low + ( high - low )*1/3;
        int T2 = low + ( high - low )*2/3;
        if( _V[T1] == x )
            return T1;
        else if ( _V[T2] == x )
            return T2;
        else if ( _V[T1] > x )
            high = T1 -1;
        else if ( _V[T2] < x )
            low = T2 + 1;
        else{
            low = T1 + 1;
            high = T2 - 1;
        }
    }
    return -1;
}


// template <typename Obj>

// void calculateTime(Obj fileName, int _argc, Obj argv, Obj function){
//     ofstream myfile;
//     myfile.open("exemple.txt");
//     auto maxN(0ul);
//     if(_argc > 1)
//         stringstream(argv[1])>> maxN;

//     cout << ">>> STARTING computation that needs timing <<<\n";
//     for(auto x(0ul);x<=maxN;x++){
//     auto start = chrono::steady_clock::now();

//     generateArray(x);
//     // cout << "Factorial of " << x << " is " << "( " << fat(x) << " )" << endl;

//     auto end = chrono::steady_clock::now();
//     cout << ">>> ENDING computation that needs timing <<<"<<x<<endl;
//     //Store the time difference between start and end
//     auto diff = end - start;

//     // Milliseconds (10^-3)
//     cout << "\t\t>>> " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
//     auto aux =  chrono::duration <double, milli> (diff).count();
//     // Nanoseconds (10^-9)
//     //cout << "\t\t>>> " << chrono::duration <double, nano> (diff).count() << " ns" << endl;
//     // Seconds
//     auto diff_sec = chrono::duration_cast<chrono::seconds>(diff);
//     cout << "\t\t>>> " << diff_sec.count() << " s" << endl;
//     myfile<<x<<" "<<aux<<"\n";
//     }
//     myfile.close();


// }