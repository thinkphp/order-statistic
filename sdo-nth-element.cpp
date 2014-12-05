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

    for(uint i = 0; i < n; i++) fin>>arr[i];  

    nth_element(arr, arr + (k - 1), arr + n);

    cout<<arr[ k - 1 ];  
    
    return(0);
};