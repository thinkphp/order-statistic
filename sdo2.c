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

int pivot(int li, int ls) {

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

     return i;
};

int qsort(int li, int ls, int k) {

     int p;

     if( li == ls ) return arr[ li ]; 

     p = pivot(li, ls); 

     //if(p == k) return arr[ k ]; 

     if(p > k) qsort(li, p - 1, k);

        else 

              qsort(p + 1, ls, k);  
};

void write(int s) {

    freopen(FOUT, "w", stdout);

    printf("%d", s);

    fclose( stdout); 
}

int main() {

    int s;

    read();

    s = qsort(1, n, k);

    //printf("%d", s);

    write( s );

    return(0);
};