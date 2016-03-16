#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>

#include "methods.h"

using namespace std;
using namespace chrono;

template <typename Obj>
int sSearchRec(Obj v, Obj n, int l, int r){
    if(l>r)
        return -1;
    else if (v[l] == n)
        return 1;
    else
        return sSearchRec(v, n, l+1, r);
}

template <typename Obj>
int bSearchIte(Obj v, Obj n, int l, int r){
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
int bTernRec (Obj v, Obj n, int l, int r){
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
void randomFill(vector<Obj> *&v, const Obj l, const Obj u, const unsigned int seed, const int size) {
    // use the default random engine and an uniform distribution
    default_random_engine eng(seed);
    uniform_real_distribution<double> distr(l, u);

    // Fill up vector
    for (int i = 0; i < size; i++)
        v[i] = distr(eng);
}

template <typename Obj>
long double calculateTime(const Obj x , int (*function)(Obj, Obj ,int , int ), const Obj n, const Obj l, const Obj r, const Obj s){
    long double duration = 0;
    vector<long int> v(s+l, s+r) ;
    for (int i = 0; i < x; ++i)
    {
        auto start = steady_clock::now();
        function(v, n, l, r);
        auto end = steady_clock::now();
        auto diff = chrono::duration <double, std::milli> (end-start).count();

        duration += (diff-duration)/(i+1);
    }
    return duration;
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