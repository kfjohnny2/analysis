#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <random>
#include "methods.h"

using namespace std;
using namespace chrono;

template <typename Obj>
int sSearchRec(vector<Obj> v, Obj n, int l, int r){
    if(l>r)
        return -1;
    else if (v[l] == n)
        return 1;
    else
        return sSearchRec(v, x, l+1, r);
}

template <typename Obj>
int bSearchIte(vector<Obj> v, Obj n, int l, int r){
    while (l <= r){
        int media = (l+r)/2;
        if(v[m] == n){
            return m
        } else if (v[m] < n){
            l = m+1;
        } else{
            r = m-1;
        }
    }

    return -1;
}

template <typename Obj>
int bTernRec (vector<Obj> v, Obj n, int l, int r){
    int media0 = (r+(2*l))/3;
    int media1 = (l+(2*r))/3;

    if(l > r)
        return -1;
    else if( n == v[media0]){
        return media0;
    } else if( n == v[media1]){
        return media1;
    } else if( n > v[media1]){
        return bTernRec(v, x, media1+1, r);
    } else if( n < v[media0]){
        return bTernRec(v, n, l, media0-1);
    } else{
        return bTernRec(v, n, media0+1, media1-1);
    }
}

template <typename Obj>
int wStdSearch (vector<Obj> v, Obj n, int l, int r){

}

template <typename Obj>
void randomFill(std::vector<Obj> &v, const Obj l, const Obj u, const unsigned int seed, const int s) {
    // use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(l, u);

    // Fill up vector
    for (int i = 0; i < s; i++)
        v[i] = distr(eng);
}

long double calculateTime(int x int *function, int n, int l, int r){
    long double duration = 0;
    std::vector<long int> v;
    for (int i = 0; i < n; ++i)
    {
        auto start = steady_clock::now();
        function(v, x, l, r);
        auto end = steady_clock::now();
        auto diff = std::chrono::duration <double, std::milli> (end-start).count();

        duration += (diff-duration);
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

//     std::cout << ">>> STARTING computation that needs timing <<<\n";
//     for(auto x(0ul);x<=maxN;x++){
//     auto start = std::chrono::steady_clock::now();

//     generateArray(x);
//     // cout << "Factorial of " << x << " is " << "( " << fat(x) << " )" << endl;

//     auto end = std::chrono::steady_clock::now();
//     std::cout << ">>> ENDING computation that needs timing <<<"<<x<<endl;
//     //Store the time difference between start and end
//     auto diff = end - start;

//     // Milliseconds (10^-3)
//     std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
//     auto aux =  std::chrono::duration <double, std::milli> (diff).count();
//     // Nanoseconds (10^-9)
//     //std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;
//     // Seconds
//     auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
//     std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;
//     myfile<<x<<" "<<aux<<"\n";
//     }
//     myfile.close();


// }