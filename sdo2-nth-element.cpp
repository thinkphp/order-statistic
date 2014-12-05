#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000005

typedef unsigned int uint;

using namespace std;

vector<uint> arr;
uint n,
     k,
     x;

int main() {

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n>>k;

    for(uint i = 0; i < n; i++) fin>>x, arr.push_back( x );  

    nth_element(arr.begin(), arr.begin() + (k - 1), arr.end());

    fout<<arr[ k - 1 ];  
    
    return(0);
};