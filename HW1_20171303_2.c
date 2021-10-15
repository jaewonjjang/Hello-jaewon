#include <stdio.h>

int GCD(int a, int b);

struct Rationum {
	int num;
	int denom;
};

void Addition(struct Rationum a, struct Rationum b);
void Subtraction(struct Rationum a, struct Rationum b);
void Multiplication(struct Rationum a, struct Rationum b);
void Division(struct Rationum a, struct Rationum b);


void main() {
	struct Rationum q1, q2;
	printf("Enter Rational number : ");
	scanf("%d %d %d %d", &q1.num, &q1.denom, &q2.num, &q2.denom);

	Addition(q1, q2);
	Subtraction(q1, q2);
	if (q1.num == 0 || q2.num == 0) {
		printf("(%d/%d) * (%d/%d) = 0\n", q1.num, q1.denom, q2.num, q2.denom);
	}
	else {
		Multiplication(q1, q2);
	}

	if (q2.num == 0) {
		printf("Division Error!!\n");
	}
	else if (q1.num == 0) {
		printf("(%d/%d) / (%d/%d) = 0\n", q1.num, q1.denom, q2.num, q2.denom);
	}
	else {
		Division(q1, q2);
	}
}

int GCD(int a, int b) {
	int min, max;
	int gcd = 0;

	if (a < 0) {
		a *= -1;
	}
	if (b < 0) {
		b *= -1;
	}

	if (a < b) {
		max = b;
		min = a;
	}
	else {
		max = a;
		min = b;
	}

	for (int i = 1; i <= min; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
		else continue;
	}
	return gcd;
}
void Addition(struct Rationum a, struct Rationum b) {
	struct Rationum addresult;
	int num, denom;

	denom = a.denom * b.denom;
	num = a.num * b.denom + b.num * a.denom;

	addresult.num = num / GCD(num, denom);
	addresult.denom = denom / GCD(num, denom);

	if (addresult.denom < 0) {
		addresult.num *= -1;
		addresult.denom *= -1;
	}

	if (addresult.denom != 1) {
		printf("(%d/%d) + (%d/%d) = %d/%d\n", a.num, a.denom, b.num, b.denom, addresult.num, addresult.denom);
	}
	else {
		printf("(%d/%d) + (%d/%d) = %d\n", a.num, a.denom, b.num, b.denom, addresult.num);
	}
}
void Subtraction(struct Rationum a, struct Rationum b) {
	struct Rationum subresult;
	int num, denom;
	denom = a.denom * b.denom;
	num = a.num * b.denom - b.num * a.denom;

	subresult.num = num / GCD(num, denom);
	subresult.denom = denom / GCD(num, denom);

	if (subresult.denom < 0) {
		subresult.num *= -1;
		subresult.denom *= -1;
	}

	if (subresult.denom != 1) {
		printf("(%d/%d) - (%d/%d) = %d/%d\n", a.num, a.denom, b.num, b.denom, subresult.num, subresult.denom);
	}
	else {
		printf("(%d/%d) - (%d/%d) = %d\n", a.num, a.denom, b.num, b.denom, subresult.num);
	}
}
void Multiplication(struct Rationum a, struct Rationum b) {
	struct Rationum mulresult;
	int num, denom;

	denom = a.denom * b.denom;
	num = a.num * b.num;

	mulresult.num = num / GCD(num, denom);
	mulresult.denom = denom / GCD(num, denom);

	if (mulresult.denom < 0) {
		mulresult.num *= -1;
		mulresult.denom *= -1;
	}

	if (mulresult.denom != 1) {
		printf("(%d/%d) * (%d/%d) = %d/%d\n", a.num, a.denom, b.num, b.denom, mulresult.num, mulresult.denom);
	}
	else {
		printf("(%d/%d) * (%d/%d) = %d\n", a.num, a.denom, b.num, b.denom, mulresult.num);
	}
}
void Division(struct Rationum a, struct Rationum b) {
	struct Rationum divresult;
	int num, denom;

	denom = a.denom * b.num;
	num = a.num * b.denom;

	divresult.num = num / GCD(num, denom);
	divresult.denom = denom / GCD(num, denom);

	if (divresult.denom < 0) {
		divresult.num *= -1;
		divresult.denom *= -1;
	}

	if (divresult.denom != 1) {
		printf("(%d/%d) / (%d/%d) = %d/%d\n", a.num, a.denom, b.num, b.denom, divresult.num, divresult.denom);
	}
	else {
		printf("(%d/%d) / (%d/%d) = %d\n", a.num, a.denom, b.num, b.denom, divresult.num);
	}
}