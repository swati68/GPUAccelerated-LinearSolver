#include<stdlib.h>
#include <stdio.h>
#include<omp.h>

int main() {
   int i,j,k,n; 
   
   float a[1100][1100],b,x[1100];
	
   printf("\nEnter the size of matrix: ");
   scanf("%d",&n);
  
   for(i=0; i<n; i++) {
      for(j=0; j<(n+1); j++) {
         a[i][j]=rand() %100 + 1; 
      }
   }
   
   double time;
   time=omp_get_wtime();
   for(i=0; i<n; i++) 
   {
      for(j=0; j<n+1; j++) 
      {
         if(i!=j) 
         {
            b=a[j][i]/a[i][i];
            for(k=0; k<n+1; k++)
             { 
               a[j][k]=a[j][k]-b*a[i][k];
            }
         }
      }
   }
   printf("\nThe solution is:\n");
   for(i=0; i<n; i++) 
   {
      x[i]=a[i][n]/a[i][i];
      printf("\nx%d =%f",i,x[i]);
      
   }
   time=(omp_get_wtime()-time);
   printf("\nMatrix:%d x %d",n,n);
    printf("\nCPU Time=%f sec",time);
   return(0);
   }
