#include <stdio.h>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000005

int vec[ MAXN ],

    n,

    k;

void read() {
 
     FILE *fin = fopen(FIN, "r");

     int i;

     fscanf(fin, "%d%d", &n, &k);

     k--;

     for(i = 0; i < n; i++) fscanf(fin, "%d", &vec[ i ]);

     fclose( fin );
};

void swap(int a,int b) {

     int aux;

         aux = vec[ a ] ^ vec[ b ];

         vec[ a ] = aux ^ vec[ a ]; 

         vec[ b ] = aux ^ vec[ b ];
};

void nth_element(int left, int right) {

    int i = left, 

        j = right,

        pivot = vec[ (left + right) >> 1 ];

    while(i <= j ) {

          while( vec[ i ] < pivot ) i++; 

          while( vec[ j ] > pivot ) j--;

          if( i <= j ) swap(i, j), i++, j--;
    }

    if(left < j && k <= j) nth_element(left, j);    

    else 

    if(i < right && k >= i) nth_element(i, right);    
};


void write() {
 
    FILE *fout = fopen(FOUT, "w");

    fprintf(fout, "%d", vec[ k ]);

    fclose( fout );
}

int main() {

    read();

    nth_element(0, n - 1);

    write();
};