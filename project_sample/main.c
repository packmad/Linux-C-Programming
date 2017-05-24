#include "calc.h"
#include <assert.h>



int main() {
	double a, b, res;
	
	a = 32;
	b = 4;
	
	res = summ(a, b);
	assert(res == 36);
	
	res = diff(a, b);
	assert(res == 28);
	
	res = mult(a, b);
	assert(res == 128);
	
	res = divi(a, b);
	assert(res == 8);
	
	printf("It works!\n");
}
