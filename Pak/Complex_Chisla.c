#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float Re;
	float Im;
} complex_t;

complex_t* add(complex_t* a, complex_t* b){
    complex_t*t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t -> Im = a -> Im + b -> Im;
    t -> Re = a -> Re + b -> Re;
 return t;
}
complex_t* sub(complex_t*a, complex_t*b){
    complex_t*t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t -> Im = a -> Im - b -> Im;
    t -> Re = a -> Re - b -> Re;
    return t;
}
complex_t* mult(complex_t*a, complex_t*b){
    complex_t*t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t -> Im = a -> Im * b -> Re + b-> Im * a -> Re;
    t -> Re = a -> Re * b -> Re - a -> Im * b -> Re;
    return t;
}
complex_t* divi(complex_t*a, complex_t*b){
    complex_t* t;
    t = (complex_t*)malloc(sizeof(complex_t));
    t -> Im = (b -> Im * a -> Re - a -> Re * b -> Im) / (pow(a -> Re, 2) + (pow(b -> Im, 2)));
    t -> Re = (a -> Re * a -> Re + b -> Im * b -> Im) / (pow(a -> Re, 2) + (pow(b -> Im, 2)));
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
    x.Re = 36;
    x.Im = 16;
    printcomp(x);
    return 0;
}