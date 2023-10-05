#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
//#include <Windows.h> 
int main()
{
 int i,*A,n,an,R;
 
 do
 {
   printf("\n\t------** DYNAMIC MEMORY ALOCATION WITH RANDOM NUMBER GENERATION FOR ARRAY **------");
   printf("\n\n\nEnter How many Numbers You Want? ");
   scanf("%d",&n);
   
   //A = (int *) malloc(n*sizeof(int)); //MEMORY ALLOCATION USING MALLOC 
   A = (int *) calloc(n,sizeof(int)); //MEMORY ALLOCATION USING CALLOC 

   printf("\n Enter the Range of Random Number(0 to X THE HIGHER THE BETTER): ");
   scanf("%d",&R);

   printf("\n Please Wait for a While, to Generate the Random Array ");
   for (i=1; i<=5; i++)
   {
     printf(".");
     sleep(1);
   }
   srand(time(0));
  
   printf("\n\nThe Array Elements with Random Numbers are:\n");
   for (i=0;i<n;i++)
   {
   	  A[i] = rand() % R;  // Generating Random Numbers Between Given R (eg. 100)
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
   
   printf("\n\n\nAgain Enter How many Numbers You Want to Add? ");
   scanf("%d",&an);
   
   A = (int *) realloc(A,sizeof(int )*(n+an));
   printf("\n\n Please Wait Again for a While, to Generate the Extra %d Random Numbers ",an);
   for (i=1; i<=5; i++)
   {
     printf(".");
     sleep(1);
   }
   srand(time(0));
  
   printf("\n\nThe Extra Array Elements after realloc():\n");
   for (i=n;i<(n+an);i++)
   {
   	  A[i] = rand() % R;  // Generating Random Numbers Between Given R (eg. 100)
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
    
   printf("\n\nThe Status of All Array Elements with Random numbers after realloc() with Ran:\n");
   for (i=0;i<(n+an);i++)
   {
      printf("\n\tA[%d]= %d and Base Address &A[%u]=%u",i,A[i],i,&A[i]);
   }
   printf("\n\n\n\n\tDo Again? Press y for Yes & No for any Key  ");
   fflush(stdin);
 }while(getchar()=='y');
 return 0;
}




