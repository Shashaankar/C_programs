#include<stdio.h>


struct test {
    char c;
    int X;
    double d;
    void *p;
    int a[0];
};

void main() {
    
          printf("size of sruct %d\n", sizeof(struct test));
}
