#include <stdio.h>
#include <stdlib.h>

struct ComplexNum
{
    float Im;
    float Re;
};


struct ComplexNum complex_sum(struct ComplexNum num1, struct ComplexNum num2){
    struct ComplexNum answ;
    answ.Im = num1.Im + num2.Im;
    answ.Re = num1.Re + num2.Re;
    return answ;
}

struct ComplexNum complex_substruct(struct ComplexNum num1, struct ComplexNum num2){
    struct ComplexNum answ;
    answ.Im = num1.Im - num2.Im;
    answ.Re = num1.Re - num2.Re;
    return answ;
}

struct ComplexNum complex_mult(struct ComplexNum num1, struct ComplexNum num2){
    struct ComplexNum answ;
    answ.Im = num1.Re * num2.Im + num2.Re * num1.Im;
    answ.Re = num1.Re * num2.Re + (-1) * num1.Im * num2.Im;
    return answ;
}

struct ComplexNum complex_divide(struct ComplexNum num1, struct ComplexNum num2){
    struct ComplexNum answ, sopr, dividor, top;
    /* firstly, calculate the dividor, at the bottom  */
    sopr.Re = num2.Re;
    sopr.Im = -num2.Im;
    dividor = complex_mult(num2, sopr);

    /* The resultant Im should be zero, so we can use just its Real for our dirty purposes */
    
    /* Calculating top part of our fractional */
    top = complex_mult(num1, sopr);
    answ.Re = top.Re / dividor.Re;
    answ.Im = top.Im / dividor.Re;
    return answ;
}

int main()
{
    struct ComplexNum num1, num2, answ;
    printf("First number's Re = ");
    scanf("%f", &num1.Re);
    printf("First number's Im = ");
    scanf("%f", &num1.Im);
    printf("Second number's Re = ");
    scanf("%f", &num2.Re);
    printf("Second number's Im = ");
    scanf("%f", &num2.Im);

    printf("\nThanks, numbers data was recorded into structures.\nDemonstration of the functions under inputted complex numbers:\n\n");
    answ = complex_sum(num1, num2);
    printf("Sum: %f + %fi\n", answ.Re, answ.Im);
    answ = complex_substruct(num1, num2);
    printf("Subtraction: %f + %fi\n", answ.Re, answ.Im);
    answ = complex_mult(num1, num2);
    printf("Multiplication: %f + %fi\n", answ.Re, answ.Im);
    answ = complex_divide(num1, num2);
    printf("Division: %f + %fi\n\nThanks for watching.\n(C) Garraty\n", answ.Re, answ.Im);

    return 0;
}
