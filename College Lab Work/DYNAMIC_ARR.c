#include<stdio.h>
#include<stdlib.h>
 
int main()
{
 int i,*A,n,an;
 
 do
 {
   printf("\n\t------** DYNAMIC MEMORY ALOCATION FOR ARRAY **------");
   printf("\n\n\nEnter How many Numbers You Want? ");
   scanf("%d",&n);
   printf("\n\tBase Address &A=%u & value of A=%u(Before malloc()/calloc())",&A,A);
   //A = (int *) malloc(n*sizeof(int)); //MEMORY ALLOCATION USING MALLOC 
   A = (int *) calloc(n,sizeof(int)); //MEMORY ALLOCATION USING CALLOC 
   printf("\n\tBase Address &A=%u & value of A=%u(After malloc()/calloc())",&A,A);
   printf("\nEnter The Array Elements:\n");
   for (i=0;i<n;i++)
   {
      printf("\n\tBase Address &A[%u]=%u & A[%u]= %u Now Enter A[%d]: ",i,&A[i],i,A[i],i);
      scanf("%d",&A[i]);
   }

   printf("\nThe Array Elements are:\n");
   for (i=0;i<n;i++)
   {
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
   /*
   free(A);
   
   printf("\n\nThe Array Elements After free() are:\n");
   for (i=0;i<n;i++)
   {
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }*/
   

   printf("\n\n\nAgain Enter How many Numbers You Want to Add? ");
   scanf("%d",&an);
   printf("\n\tBase Address &A=%u & value of A=%u(Before realloc())",&A,A);
   A = (int *) realloc(A,sizeof(int )*(n+an));
   printf("\n\tBase Address &A=%u & value of A=%u(After realloc())",&A,A);
   printf("\nThe Status of Array after realloc() are:\n");
   for (i=0;i<(n+an);i++)
   {
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
   
   printf("\n\nEnter The Extra Array Elements after realloc():\n");
   for (i=n;i<(n+an);i++)
   {
      printf("\n\tBase Address &A[%u]=%u & Enter A[%d]: ",i,&A[i],i);
      scanf("%d",&A[i]);
   }

   printf("\nThe Array Elements are after realloc():\n");
   for (i=0;i<(n+an);i++)
   {
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
 
   printf("\n\n\n\n\tDo Again? Press y for Yes & No for any Key  ");
   fflush(stdin);
 }while(getchar()=='y');
 return 0;
}




