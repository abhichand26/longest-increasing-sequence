#include<stdio.h>
#include<stdlib.h>
#define N 20
#define inf 9999

/*
** Program to find longest increasing sequence using Dynamic Programming
** Made by - Abhishek Chand
*/

int A[N],L[N],P[N];


void printLIS(int j)
{
	if(j==-1)
		return;
	printLIS(P[j]);
	printf("%d ",A[j]);
}

void LIS(int n)
{
	int i,j,maxl,maxj;
	maxj=1;
	maxl=1;
	for(j=1;j<=n;j++)
	{
		L[j]=1;
		P[j]=-1;
		for(i=1;i<j;i++)
		{
			if(A[i]<A[j]&&L[j]<1+L[i])
			{
				L[j]=1+L[i];
				P[j]=i;
			}
		}
		if(L[j]>maxl)
		{
			maxl=L[j];
			maxj=j;
		}
	}
	printf("\nLongest Increasing Sequence of length %d",maxl);
	printf("\nSequence: ",maxl);
	printLIS(maxj);
}



int main()
{
	int i,j,n;
	printf("Enter the size of sequence: ");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);

	LIS(n);
	return 0;
}
