#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct {

	float Im;
	float Re;

} complexNum;


complexNum Sum (complexNum * a, complexNum * b);
complexNum Sub (complexNum * a, complexNum * b);
complexNum Mult (complexNum * a, complexNum * b);
complexNum Div (complexNum * a, complexNum * b);



int main() {

	complexNum a, b, result;
	
	
	/* Initial values */
	
	a.Im = 2;
	a.Re = 2;
	b.Im = 3;
	b.Re = 4;
	
	
	/* Test */
	
	result = Sum(&a, &b);
	printf("Sum:\n result = %.2f + %.2fi \n\n", result.Re, result.Im);
	
	result = Sub(&a, &b);
	printf("Subtraction:\n result = %.2f + %.2fi \n\n", result.Re, result.Im);
	
	result = Mult(&a, &b);
	printf("Multiplication:\n result = %.2f + %.2fi \n\n", result.Re, result.Im);
	
	result = Div(&a, &b);
	printf("Division:\n result = %.2f + %.2fi \n\n", result.Re, result.Im);
	
	
	return 0;
}




complexNum Sum (complexNum * a, complexNum * b) {

	complexNum sum;
	
	sum.Im = a->Im + b->Im;
	sum.Re = a->Re + b->Re;
	

	return sum;
}



complexNum Sub (complexNum * a, complexNum * b) {
	
	complexNum sub;
	
	sub.Im = a->Im - b->Im;
	sub.Re = a->Re - b->Re;
	
	return sub;
}



complexNum Mult (complexNum * a, complexNum * b) {
	
	complexNum mult;
	
	mult.Im = a->Im * b->Re + a->Re * b->Im;
	mult.Re = a->Re * b->Re - a->Im * b->Im;
	
	return mult;
}



complexNum Div (complexNum * a, complexNum * b) {
	
	complexNum div;
	
	div.Im = (a->Im * b->Re - a->Re * b->Im) / (pow(b->Re, 2) + pow(b->Im, 2));
	div.Re = (a->Re * b->Re + a->Im * b->Im) / (pow(b->Re, 2) + pow(b->Im, 2));
	
	return div;
}



