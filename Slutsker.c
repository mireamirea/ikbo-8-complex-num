#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
float Re;
float Im;
} complex;

complex* add(complex* a, complex* b){
    complex*t;
    t = (complex*)malloc(sizeof(complex));
    t -> Im = a -> Im + b -> Im;
    t -> Re = a -> Re + b -> Re;
return t;
}
complex* sub(complex*a, complex*b){
    complex*t;
    t = (complex*)malloc(sizeof(complex));
    t -> Im = a -> Im - b -> Im;
    t -> Re = a -> Re - b -> Re;
return t;
}
 complex* mult(complex*a, complex*b){
     complex*t;
     t = (complex*)malloc(sizeof(complex));
     t -> Im = a -> Im * b -> Re + b-> Im * a -> Re;
     t -> Re = a -> Re * b -> Re - a -> Im * b -> Re;
 return t;
 }
 
 complex* divi(complex*a, complex*b){
     complex* t;
     t = (complex*)malloc(sizeof(complex));
     t -> Im = (b -> Im * a -> Re - a -> Re * b -> Im) / (pow(a -> Re, 2) + (pow(b -> Im, 2)));
     t -> Re = (a -> Re * a -> Re + b -> Im * b -> Im) / (pow(a -> Re, 2) + (pow(b -> Im, 2)));
 return t;
}
 
 void printc(complex a){
 if (a.Im<0)
	printf("z = %f - %f i \n", a.Re, (-1)*a.Im);
 else
 printf("z = %f + %f i \n", a.Re, a.Im);
 }
 
 int main()
 {
     complex x;
     x.Re = 54;
     x.Im = 31;
     printc(x);
     return 0;
 }
