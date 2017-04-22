#include <stdio.h>

typedef struct {
	double Re;
	double Im;
}Num;

Num* plus(Num* a, Num* b) {

	Num  *t = (Num*)malloc(sizeof(Num*));
	t->Re = a->Re + b->Re;
	t->Im = a->Im + b->Im;
    pr(t);
	return t;
}

Num* sub(Num* a, Num* b) {
	Num  *t = (Num*)malloc(sizeof(Num*));
	t->Re = a->Re - b->Re;
	t->Im = a->Im - b->Im;
    pr(t);
	return t;
}

Num* multi(Num* a, Num* b) {
	Num  *t = (Num*)malloc(sizeof(Num*));
	t->Re = a->Re * b->Re - a->Im * b->Im;
	t->Im = a->Im * b->Re + b->Im * a->Re;
	pr(t);
	return t;
}

Num* div(Num* a, Num* b) {
	Num  *t = (Num*)malloc(sizeof(Num*));
	Num  *c = (Num*)malloc(sizeof(Num*));
	Num  *d = (Num*)malloc(sizeof(Num*));
	Num  *v = (Num*)malloc(sizeof(Num*));
	c->Im = -(b->Im);
	v = multi(*a, *c);
	d =	multi(*b, *c);
	t = v->Re / d->Re + v->Im / d->Im;
	pr(t);
	return t;
}
void pr(Num t) {
	if (t.Im < 0)
		printf("t = %f %f*i\n", t.Re, t.Im);
	else
		printf("t = %f + %f*i\n", t.Re, t.Im);
	if (t.Im == 0)
		print("t = %f\n", t.Re);
}


