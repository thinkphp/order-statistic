/**
 *   Description: Order statistic
 *   Author     : Adrian Statescu <mergesortv@gmail.com>.
 *   License    : MIT
 *   Feel free to use and distribute as long as this note is kept.
 */
 
#include <stdio.h>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000005

typedef unsigned int uint;

uint vec[ MAXN ];

//function prototypes
uint nth_element(uint vec[],uint,uint);
void nth_element_helper(uint vec[],int,int,uint);
void swap(int*,int*);

int main() {

    uint n,
         i,
         k;

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d%d", &n, &k);   

     k--;

     for(i = 0; i < n; i++) fscanf(fin, "%d", &vec[ i ]);

     fclose( fin );

     FILE *fout = fopen(FOUT, "w");

     fprintf(fout, "%d", nth_element(vec, n, k));     

     fclose( fout );

     return(0);
};

void swap(int *a,int *b) {

     int aux;

         aux = *a;

         *a = *b;

         *b = aux;  
};

void nth_element_helper(uint vec[], int left, int right, uint k) {

     int i = left, 

         j = right,

        pivot = vec[ (left + right) >> 1 ];

    while(i <= j ) {

          while( vec[ i ] < pivot ) i++; 

          while( vec[ j ] > pivot ) j--;

          if( i <= j ) swap(vec + i, vec + j), i++, j--;
    }

    if(left < j && k <= j) nth_element_helper(vec, left, j, k);    

    else 

    if(i < right && k >= i) nth_element_helper(vec, i, right, k);    
      
};

uint nth_element(uint vec[], uint n, uint k) {
 
     nth_element_helper(vec, 0, n - 1, k);

     return vec[ k ];
};

