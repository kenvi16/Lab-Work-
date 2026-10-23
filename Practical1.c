
#include <stdio.h>

void callByValue(int x)
{
    x = x + 10;
    printf("Value inside call by value function = %d\n", x);
}

void callByReference(int *x)
{
    *x = *x + 10;
    printf("Value inside call by reference function = %d\n", *x);
}

int main()
{
    int a = 10;
    int *p;
    p = &a;

  printf("Pointer Demonstration\n");
  
     printf("Value of a = %d\n", a);
     printf("Address of a = %p\n", (void *)&a);
     printf("Pointer p stores address = %p\n", (void *)p);
     printf("Value pointed to by p = %d\n", *p);       
     printf("\nBefore call by value: a = %d\n", a);
    
  callByValue(a);
     printf("After call by value: a = %d\n", a);
     printf("\nBefore call by reference: a = %d\n", a);
   
  callByReference(&a);
     printf("After call by reference: a = %d\n", a);

    return 0;
}
