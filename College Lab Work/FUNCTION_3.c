#include<stdio.h>
#include<stdlib.h>

int findmax1(int, int []);
int findmax2(int, int *);
 
int main()
{
 int i,A[100],n;
 //int i,*A,n;
 do
 {
   printf("\n\t------** FINDOUT MAIMUM NUMBER IN AN ARRAY **------");
   printf("\n\n\nEnter How many Numbers? ");
   scanf("%d",&n);
   
   //A = (int *) malloc(n*sizeof(int *)); //MEMORY ALLOCATION USING MALLOC 
   //A = (int *) calloc(n,sizeof(int *)); //MEMORY ALLOCATION USING CALLOC 
   printf("\nEnter The Array Elements:\n");
   for (i=0;i<n;i++)
   {
      printf("\tA[%d]= ",i);
      scanf("%d",&A[i]);
   }

   printf("\nThe Array Elements are:\n");
   for (i=0;i<n;i++)
   {
      printf("\n\tA[%d]= %d and &A[%u]=%u",i,A[i],i,&A[i]);
   }
   
   printf("\n\n\tBase Address of &A=%u & &A[0]=%u in main()\n\n",&A,&A[0]);
   
    printf("\n\n\t%d is the Maximum  Number in the Array using findmax1() Function.\n",findmax1(n,A));
    //printf("\n\n\t%d is the Maximum  Number in the Array using findmax1() Function.\n",findmax1(n,&A[0]));
    
    printf("\n\n\tAGAIN %d is the Maximum  Number in the Array using findmax2() Function.\n",findmax2(n,A));
   //printf("\n\n\tAGAIN %d is the Maximum  Number in the Array using findmax2() Function.\n",findmax2(n,&A[0]));
  
   
   printf("\n\n\n\n\tDo Again? Press y for Yes & No for any Key  ");
   fflush(stdin);
 }while(getchar()=='y');
 return 0;
}

int findmax1(int n, int p[])
{
   int i,max;
   printf("\n\tBase Address of n=%u and &p=%u and &max= %u in findmax2(int,int *) ",&n,&p,&max);
   printf("\n\nThe Array Elements of p[]:\n");
   for (i=0;i<n;i++)
    printf("\n\tp[%d]= %d and &p[%u]=%u",i,p[i],i,&p[i]);
    
   max=p[0];
   for (i=1;i<n;i++)
    if(p[i]>max)
      max=p[i];
      
  return max;
}

int findmax2(int n, int *p)
{
   int i,max;
   printf("\n\tBase Address of n=%u and &p=%u and &max= %u in findmax2(int,int *) ",&n,&p,&max);
   printf("\n\nThe Array Elements of p*:\n");
   for (i=0;i<n;i++)
    printf("\n\tp[%d]= %d and &p[%u]=%u",i,p[i],i,&p[i]);
   max=p[0];
   for (i=1;i<n;i++)
    if(p[i]>max)
      max=p[i];
      
  return max;
}



