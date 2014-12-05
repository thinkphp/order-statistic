#include <iostream>
#include <fstream>
#include <algorithm>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000005

typedef unsigned int uint;

using namespace std;

uint arr[ MAXN ],

     n,

     k;

int main() {

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n>>k;

    for(uint i = 1; i <= n; i++) fin>>arr[ i ];  

    sort(arr + 1, arr + n + 1);

    fout<<arr[ k ];  
    
    return(0);
};