#include <stdio.h>
#include <limits.h>
int main() {
	int a = 1;
	float b = 2.0;
	double c = 3.0;

	// both values and addresses are printed
	printf("Value: %d\n", a);
	printf("Address: %p\n", a);
	printf("Value: %f\n", b);
	printf("Address: %p\n", b);
	printf("Value: %f\n", c);
	printf("Address: %p\n", c);

	// INT_MAX, LONG_MAX, ULONG_MAX C types, values, and their sizes
	printf("INT_MAX: ");
	printf("%d\n", INT_MAX);
	printf("Size of INT_MAX: ");
	printf("%ld\n", sizeof(INT_MAX));

	printf("LONG_MAX: ");
	printf("%ld\n", LONG_MAX);
	printf("Size of LONG_MAX: ");
	printf("%ld\n", sizeof(LONG_MAX));

	printf("UNSIGNED_LONG_MAX: ");
	printf("%lu\n", ULONG_MAX);
        printf("Size of ULONG_MAX: ");
	printf("%ld\n", sizeof(ULONG_MAX));
	return 0;
}
