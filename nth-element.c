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

     for(i = 0; i < n; i++) scanf("%d", &arr[ i ]); 

     fclose( stdin );
};

void swap(int i, int j) {

     int aux = arr[ i ] ^ arr[ j ];

         arr[ i ] = aux ^ arr[ i ]; 

         arr[ j ] = aux ^ arr[ j ];
};

int nth_element(int li, int ls) {

     int i = li,

         j = ls,

         p = arr[ ( li + ls) >> 1 ]; 
          
         do {

            while(arr[ i ] < p) i++; 

            while(arr[ j ] > p) j--;

            if( i <= j ) {

               swap(i, j); i++; j--;
            }

         } while( i <= j );

         if(li < j && (k-1) <= j) nth_element(li, j); 

         if(i < ls && (k-1) >= i) nth_element(i, ls);
};

void write() {

    freopen(FOUT, "w", stdout);

    printf("%d", arr[ k - 1]);

    fclose( stdout); 
}

int main() {

    read();
    nth_element(0, n - 1);
    write();

    return(0);
};