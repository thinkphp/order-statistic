#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000005

typedef unsigned int uint;

uint arr[ MAXN ],

     n,

     k;

void read() {

     uint i;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &n, &k);

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );
};

void swap(int i, int j) {

     int aux = arr[ i ] ^ arr[ j ];

         arr[ i ] = aux ^ arr[ i ]; 

         arr[ j ] = aux ^ arr[ j ];
};

int pivot(int li, int ls) {

    int i = 0, 

        j = 1, 
 
        aux, 
 
        p = li + rand() % ( ls - li );

    swap(li, p);

    while(li < ls) {

          if(arr[ li ] > arr[ ls ]) {

             swap(li,ls);

             aux = i;

             i = j; 

             j = aux; 
          }  

       li += i;

       ls -= j;
    }
 
    return li;
};

int _qsort(int li, int ls) {

     int p;

     while(li < ls) {

           p = pivot(li, ls);

           if(p == (k - 1)) return arr[ k - 1 ];

           if( (k - 1) < p ) {

                ls = p - 1; 

           } else {

                li = p + 1;                
           }
     }

     return arr[ k - 1 ];
};

int main() {

    read();

    freopen(FOUT, "w", stdout);        

    srand(time(NULL));

    printf("%d", _qsort(0, n - 1));

    fclose( stdout );

    return(0);
};