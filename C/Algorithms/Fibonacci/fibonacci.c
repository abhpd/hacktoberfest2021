#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

main() {

  

    int a, b, aux, i, n;

    a = 0;
    b = 1;

    printf("type a number: ");
    scanf("%d", &n);
    printf("\nFibonacci:\n");
    printf("%d\n", b);

    for(i = 0; i < n; i++) {

        aux = a + b;
        a = b;
        b = aux;

        printf("%d\n", aux);
    }
}
