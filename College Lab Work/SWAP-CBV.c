// Swaping of two given Numbers(using Call By Value)
#include<stdio.h>
#include<stdlib.h>
void swap(int a,int b)
{
  int temp;
  printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tSWAP Function Before SWAP\n");
  printf("\nActual Address of A=(&a)=%u & Value at the address of A=(a)=%d\n",&a,a);
  printf("\nActual Address of B=(&b)=%u & Value at the address of B=(b)=%d\n",&b,b);
  printf("\n-------------------------------------------------------------------------------\n");

  temp=a;
  a=b;
  b=temp;

  //printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tSWAP Function After SWAP\n");
  printf("\nActual Address of A=(&a)=%u & Value at the address of A=(a)=%d\n",&a,a);
  printf("\nActual Address of B=(&b)=%u & Value at the address of B=(b)=%d\n",&b,b);
  printf("\n-------------------------------------------------------------------------------\n");
}
main()
{
  int a,b;
  system("cls");
  printf("\n---------------------Swaping of two given Numbers(using Call By Value)------------------\n");
  printf("\nEnter the  Value of A: ");
  scanf("%d",&a);
  printf("\nEnter the  Value of B: ");
  scanf("%d",&b);
  printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin Main Function Before Swap\n");
  printf("\n&a=%u, a=%u\n",&a,a);
  printf("\n&b=%u, b=%u\n",&b,b);
  //printf("\n-------------------------------------------------------------------------------\n");

  swap(a,b);

  //printf("\n-------------------------------------------------------------------------------\n");
  printf("\n\tin Main Function After Swap\n");
  printf("\n&a=%u, a=%u\n",&a,a);
  printf("\n&b=%u, b=%u\n",&b,b);
  printf("\n-------------------------------------------------------------------------------\n");
  fflush(stdin);
  getchar();
}


