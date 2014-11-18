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
};

int nth_element(int li, int ls) {

     if(li == ls) return arr[ li ];

     int i = li,

         j = ls,

         p = arr[ ( li + ls) >> 1 ]; 
          
         do {

            while(arr[ i ] < p) i++; 

            while(arr[ j ] > p) j--;

            if( i <= j ) {

               swap(i,j); i++; j--;
            }

         } while( i <= j );

         if(j >= k) return nth_element(li, j);

                else 

                    return nth_element(j + 1, ls);
};

int main() {

    read();

    //freopen(FOUT, "w", stdout);

    printf("%d", nth_element(1, n));

    fclose( stdout );

    return(0);
};