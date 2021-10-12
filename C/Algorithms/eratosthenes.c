#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char arg1[6];
	if (argc > 1) strcpy(arg1, argv[1]);

	int end = 10000;
	char primes[end];
	for (int i = 0; i < end; i++)
		primes[end] = 1;

	primes[0] = 0;
	primes[1] = 0;

	for (int n = 2; n < end; n++) {
		for (int multiple = n << 1; multiple < end; multiple += n) {
			primes[multiple] = 0;
		}
	}

	// Print primes if "print" arg passed
	if (argc == 2 && !strcmp(arg1, "print")) {
		for (int i = 0; i < end; i++) {
			if (primes[i]) printf("%d\n", i);
		}
	}

	return 0;
}

