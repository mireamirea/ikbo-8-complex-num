#include <stdio.h>
#include <stdlib.h>


typedef struct{
    float Re;
    float Im;
} complex_t;

complex_t* add(complex_t* a, complex_t* b){
    complex_t* t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t->Im = a->Im + b->Im;
    t->Re = a->Re + b->Re;
    return t;
}
complex_t* mul(complex_t* a, complex_t* b){
    complex_t* t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t->Re = a->Re * b->Re - a->Im * b->Im;
    t->Im = a->Im * b->Re + b->Im * a->Re;
    return t;
}
complex_t* sub(complex_t* a, complex_t* b){
    complex_t* t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t->Re = a->Re - b->Re;
    t->Im = a->Im - b->Im;
    return t;
}
complex_t* divide(complex_t* a, complex_t* b){
    complex_t* t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t->Re = (a->Re * b->Re + a->Im * b->Im)/((b->Re * b->Re)+(b->Im * b->Im));
    t->Im = (b->Re * a->Im - a->Re * b->Im)/((b->Re * b->Re)+(b->Im * b->Im));
    return t;
}
void printcomp(complex_t a){
    if (a.Im<0)
        printf("z = %f - %f i/n", a.Re, (-1)*a.Im);
    else
        printf("z = %f + %f i/n", a.Re, a.Im);
}

int main()
{
    complex_t x;
    x.Re = 14;
    x.Im = 10;
    printcomp(x);
    return 0;
}
