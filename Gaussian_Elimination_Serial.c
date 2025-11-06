//Serial code for Gaussian Elimination
#include<stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main()
{
    int i,j,k,n;
    float A[1005][1005],c,x[1005],sum=0.0;
    int upper=10,lower=0;
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    
    printf("\nGenerated matrix: \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            A[i][j]=(rand() % (upper - lower + 1)) + lower; 
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    
    clock_t start, end;
    double cpu_time_used;
     
    start = clock();
    
    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
    printf("\nTime taken: %f sec\n",cpu_time_used);
    return(0);
}

