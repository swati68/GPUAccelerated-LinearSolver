#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	FILE* f;
	f = fopen("result_serial.txt","r");
	char ch;
	long length;
	fseek(f,0,SEEK_END);
	length = ftell(f);
	fseek(f,length-2,SEEK_SET);
	ch=fgetc(f);
	int count = ch-'0';
	//printf("%c",ch);
	fclose(f);
	FILE* Output;
	Output = fopen("result_serial.txt","a+");
	int d;
	printf("Enter the dimension of the matrix:");
	scanf("%d",&d);
	float A[d][d],L[d][d],U[d][d];
	float B[d],X[d],Y[d];
	int i,j,k;
	srand(time(0));
	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			A[i][j]=(((float)rand()/RAND_MAX)*(float)1000)+1;
			//scanf("%f",&A[i][j]);
		}
	}
	for(i=0;i<d;i++)
	{
		B[i]=(((float)rand()/RAND_MAX)*(float)1000)+1;
		//scanf("%f",&B[i]);
	}
	double runtime;
	runtime = clock()/(double)CLOCKS_PER_SEC;
	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			if(j<=i)
			{
				U[j][i]=A[j][i];
				for(k=0;k<=(j-1);k++)
					U[j][i]-=L[j][k]*U[k][i];
				if(i==j)
					L[j][i]=1;
				else
					L[j][i]=0;
			}
			else
			{
				L[j][i]=A[j][i];
				for(k=0;k<=i-1;k++)
					L[j][i]-=L[j][k]*U[k][i];
				L[j][i]/=U[i][i];
				U[j][i]=0;
			}
		}
	}
	runtime = (clock()-runtime)/(float)CLOCKS_PER_SEC;
	printf("Time taken for execution is: %f\n\n",runtime);
	fprintf(Output,"\nMatrix A is:\n");
	//printf("A:\n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			fprintf(Output,"%f ",A[i][j]);
			//printf("%f\t",A[i][j]);
		}
		fprintf(Output,"\n");
		//printf("\n\n");
	}
	fprintf(Output,"Matrix B is:\n");
	//printf("B:\n");
	for(i=0;i<d;i++)
	{
		fprintf(Output,"%f ",B[i]);
		//printf("%f\t",B[i]);
	}
	fprintf(Output,"\n");
	//printf("\n\n");

	fprintf(Output,"Matrix L is:\n");
	//printf("L:\n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			//printf("%f\t",L[i][j]);
			fprintf(Output,"%f ",L[i][j]);
		}
		fprintf(Output,"\n");
		//printf("\n\n");
	}
	fprintf(Output,"Matrix U is:\n");
	//printf("U:\n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			//printf("%f\t",U[i][j]);
			fprintf(Output,"%f ",U[i][j]);
		}
		//printf("\n\n");
		fprintf(Output,"\n");
	}

	for(i=0;i<d;i++)
	{
		Y[i]=B[i];
		for(j=0;j<i;j++)
		{
			Y[i]-=L[i][j]*Y[j];
		}
	}
	for(i=d-1;i>=0;i--)
	{
		X[i]=Y[i];
		for(j=i+1;j<d;j++)
		{
			X[i]-=U[i][j]*X[j];
		}
		X[i]/=U[i][i];
	}
	fprintf(Output,"Solution(X) is:\n");
	//printf("Solution is(X):\n");
	for(i=0;i<d;i++)
	{
		fprintf(Output,"%4.2f ",X[i]);
		//printf("%4.2f\t",X[i]);
	}
	fprintf(Output,"\nFor %d x %d Matrix,Time Taken is:",d,d);
	fprintf(Output,"%f\n\n",runtime);
	fprintf(Output,"Count %d\n",count+1);
	printf("\n");
}


