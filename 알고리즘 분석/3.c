#include <stdio.h>
#include <stdlib.h>
int * prefixAverages1(int *X, int n);
int * prefixAverages2(int *X, int n);
int main(){
    int n;scanf("%d", &n);
    int *X = (int *) malloc(n*sizeof(int));
    // if (X == NULL) {
    //     return -1;
    // }
    for(int i  = 0; i<n; i++) scanf("%d", &X[i]);

    int *result1 = prefixAverages1(X, n);
    int *result2 = prefixAverages2(X, n);
    for(int i = 0; i<n;i ++){
        printf("%d ", result1[i]);
    }
    printf("\n");

    for(int i = 0; i<n; i++){
        printf("%d ", result2[i]);
    }
}

int *prefixAverages1(int *X, int n) {
    int *prefix_avg = (int *) malloc(n * sizeof(int));
    if (prefix_avg == NULL) {
        // handle memory allocation error
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += X[j];
        }
        prefix_avg[i] = sum / (i + 1);
    }
    return prefix_avg;
}


int *prefixAverages2(int *X, int n) {
    int *prefix_sum = (int *) malloc(n * sizeof(int));
    int *prefix_avg = (int *) malloc(n * sizeof(int));
    if (prefix_sum == NULL || prefix_avg == NULL) {
        // handle memory allocation error
        return NULL;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += X[i];
        prefix_sum[i] = sum;
        prefix_avg[i] = sum / (i + 1);
    }
    free(prefix_sum);
    return prefix_avg;
}
