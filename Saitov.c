#include <stdio.h>
#include <stdlib.h>

typedef struct {
float Re;
float Im;}  complex_t;

complex_t* add( complex_t* a, complex_t* b){
complex_t *t=(complex_t*) malloc (sizeof (complex_t));
t->Im=a->Im+b->Im;
t->Re=a->Re+b->Re;
return t;
}

complex_t* mul( complex_t* a, complex_t* b){
complex_t *t=(complex_t*) malloc (sizeof (complex_t));
t->Re= -(a->Im * b->Im) + (a->Re * b->Re);
t->Im= (a->Im * b->Re) + (a->Re * b->Im);
return t;
}

complex_t* sub( complex_t* a, complex_t* b){
complex_t *t=(complex_t*) malloc (sizeof (complex_t));
t->Im=a->Im-b->Im;
t->Re=a->Re-b->Re;
return t;
}

complex_t* division (complex_t* a, complex_t* b){
complex_t *t=(complex_t*) malloc (sizeof (complex_t));
t->Im=(-a->Re*b->Im+a->Im*b->Re)/(b->Re*b->Re+b->Im*b->Im);
t->Re=(a->Re*b->Re+a->Im*b->Im)/(b->Re*b->Re+b->Im*b->Im);
return t;
}

void print (complex_t *t){
t->Im<0 ? printf("z= %f - %fi\n",t->Re, (-1)*t->Im) : printf("z=%f + %fi\n",t->Re,t->Im);
}

int main()
{
    complex_t a;
 printf("First number\nEnter real number:");
 scanf("%f", &a.Re);
 printf("Enter imaginary unit:");
 scanf("%f", &a.Im);
    complex_t b;
printf("\nSecond number\nEnter real number:");
scanf("%f", &b.Re);
printf("Enter imaginary unit:");
scanf("%f", &b.Im);
int c;
printf("\nChoose operation\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
scanf ("%d",&c);
switch (c){
case 1:
    print(add(&a,&b));
    break;
case 2:
    print(sub(&a,&b));
    break;
case 3:
    print(mul(&a,&b));
    break;
case 4:
    print(division(&a,&b));
    break;
default:
    exit(-1);}
    return 0;

}
