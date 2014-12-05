#include <stdio.h>
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

     for(i = 1; i <= n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );
};

void swap(int i, int j) {

     int aux = arr[ i ] ^ arr[ j ];

         arr[ i ] = aux ^ arr[ i ]; 

         arr[ j ] = aux ^ arr[ j ];
}

void qsort(int li, int ls) {

     int i = li,

         j = ls,

         p = arr[ ( li + ls) >> 1 ]; 
          
         do {

            while(arr[ i ] < p) i++; 

            while(arr[ j ] > p) j--;

            if(i<=j) {

               swap(i,j);i++;j--;
            }

         } while( i <= j );

         if(li <= k && k <= j) qsort(li, j); 
          
            else if(i <= k && k <= ls) qsort(i, ls);
};

int main() {

    read();

    qsort(1, n);

    freopen(FOUT, "w", stdout);

    printf("%d", arr[ k ]);

    return(0);
};