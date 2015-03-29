#include<stdio.h>


struct test {
    int x;
    char c;
    double d;
    void *p;
    char k;
};

void main() {
    
          printf("size of sruct %d\n", sizeof(struct test));
}
