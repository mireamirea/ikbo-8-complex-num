/*
  main.c
  complex

  Created by Денис Скоробогатов on 28.03.17.
  Copyright © 2017 Denis Skorobogatov. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float Re;
    float Im;
} complex_t;

complex_t* add(complex_t* a, complex_t* b)
{
    complex_t* result = (complex_t*)malloc(sizeof(complex_t));
    result->Im = a->Im + b->Im;
    result->Re = a->Re + b->Re;
    return result;
}

complex_t* sub(complex_t* a, complex_t* b)
{
    complex_t* result = (complex_t*)malloc(sizeof(complex_t));
    result->Im = a->Im - b->Im;
    result->Re = a->Re - b->Re;
    return result;
}


complex_t* mult(complex_t* a, complex_t* b)
{
    complex_t* result = (complex_t*)malloc(sizeof(complex_t));
    result->Re = a->Re * b->Re - (a->Im * b->Im);
    result->Im = a->Re * b->Im + a->Im * b->Re;
    return result;
}

complex_t* divis(complex_t* a, complex_t* b)
{
    complex_t* result = (complex_t*)malloc(sizeof(complex_t));
    result->Re = ((a->Re * b->Re) + (a->Im + b->Im)) / (b->Re * b->Re + b->Im * b->Im);
    result->Im = ((b->Re * a->Im) - (a->Re * b->Im)) / (b->Re * b->Re + b->Im * b->Im);
    return result;

}

void print(complex_t* a)
{
    printf("%.0f %c %.0fi\n", a->Re, (a->Im < 0) ? '-' : '+', (a->Im < 0) ? -1*a->Im : a->Im);
}

int main(int argc, const char * argv[]) {
    complex_t a;
    a.Im = 5;
    a.Re = 10;
    print(&a);
    return 0;
}
