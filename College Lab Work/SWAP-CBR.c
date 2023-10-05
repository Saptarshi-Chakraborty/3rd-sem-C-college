#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
  int temp;
  
  printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin SWAP Function Before Swap\n");
  printf("\n&a=%u, a=%u, *a=%u, *(&a)=%u, *(*(&a))=%u\n",&a,a,*a,*(&a),*(*(&a)));
  printf("\n&b=%u, b=%u, *b=%u, *(&b)=%u, *(*(&b))=%u\n",&b,b,*b,*(&b),*(*(&b)));
  printf("\n-------------------------------------------------------------------------------\n");

  temp=*a;
  *a=*b;
  *b=temp;

  //printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin SWAP Function After Swap\n");
  printf("\n&a=%u, a=%u, *a=%u, *(&a)=%u, *(*(&a))=%u\n",&a,a,*a,*(&a),*(*(&a)));
  printf("\n&b=%u, b=%u, *b=%u, *(&b)=%u, *(*(&b))=%u\n",&b,b,*b,*(&b),*(*(&b)));
  printf("\n-------------------------------------------------------------------------------\n");

}

main()
{
  int a,b;
  system("cls");
  printf("\n---------------------Swaping of two given Numbers(using Call By Reference)------------------\n");
  printf("\nEnter the  Value of A: ");
  scanf("%d",&a);
  printf("\nEnter the  Value of B: ");
  scanf("%d",&b);
  printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin Main Function Before Swap\n");
  printf("\n&a=%u, a=%u\n",&a,a);
  printf("\n&b=%u, b=%u\n",&b,b);
  //printf("\n-------------------------------------------------------------------------------\n");

  swap(&a,&b);

  //printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin Main Function After Swap\n");
  printf("\n&a=%u, a=%u\n",&a,a);
  printf("\n&b=%u, b=%u\n",&b,b);
  printf("\n-------------------------------------------------------------------------------\n");
  fflush(stdin);
  getchar();
}

