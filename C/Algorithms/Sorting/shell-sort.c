#include <stdio.h>

void shell_sort (int *a, int n){
    int h, i, j, t;
    for (h = n; h /= 2;){
        for (i = h; i < n; i++){
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h){
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}

int main (int ac, char **av){
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    shell_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
