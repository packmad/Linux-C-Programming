#include "calc.h"

double summ(double x, double y) {
	return x+y;
}

double diff(double x, double y) {
	return x-y;
}

double mult(double x, double y) {
	return x*y;
}

double divi(double x, double y) {
	if (y == 0) {
        perror("Can't divide by zero\n");
        exit(EX_DATAERR);;
    }
    return x/y;
}
