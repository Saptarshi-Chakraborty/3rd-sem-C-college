/* Program for Pointer */
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int a,*p,**q;
  system("cls");
  printf("\nEnter the  Value of A: ");
  scanf("%d",&a);
  p=&a;
  q=&p;

  printf("\n\nBase Address of Variable(&a)=%u, pointer (&p)=%u, Pointer of Pointer (&q)=%u",&a,&p,&q);
  printf("\n\nValue of a=%u, p=%u, q=%u",a,p,q);
  
  fflush(stdin);
  getchar();
  
  printf("\n\n\n\tp = %u\n",p);
  printf("\n\t*p = %u\n",*p);
  printf("\n\t&p = %u\n",&p);
  printf("\n\t*(&p) = %u\n",*(&p));
  printf("\n\t*(*(&p)) = %u\n",*(*(&p)));
  
  fflush(stdin);
  getchar();
  
  printf("\n\n\n\tq = %u\n",q);
  printf("\n\t*q = %u\n",*q);
  printf("\n\t&q = %u\n",&q);
  printf("\n\t*(&q) = %u\n",*(&q));
  printf("\n\t*(*(&q)) = %u\n",*(*(&q)));
  printf("\n\t*(*(*(&q))) = %u\n",*(*(*(&q))));
  printf("\n\t**q = %u\n",**q);
  
  //printf("\n\nValue of ++a=%u, ++p=%u, ++q=%u, ++(*p)=%u,++(**q)=%u,",++a,++p,++q,++(*p),++(**q));
  a++;
  p++;
  q++;
  printf("\n\nValue of a=%u, p=%u, q=%u",a,p,q);
  (*p)++;
  (**q)++;
  printf("\n\nValue of a=%u, *p=%u, **q=%u",a,*p,**q);
  return(0);
}
