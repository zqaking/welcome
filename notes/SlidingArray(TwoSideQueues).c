#include<stdio.h>
int left[1000000];
int right[1000000];
int money[1000000];
int INT_MIN = 1 << 31;

int MAX(int a, int b) {
    if (a > b) return a;
    else return b;
} 
int main() {
    int n, k;
    int i, j, max;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &money[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (i % k == 0) max = INT_MIN;
        if (money[i] > max) max = money[i];
        left[i] = max;
    }

    max = INT_MIN;
    for (int i = n-1; i >= 0; i--) {
        if (i % k == k-1) max = INT_MIN;
        if (money[i] > max) max = money[i];
        right[i] = max;
    }
    
    for(int i = 0; i < n - k + 1; i++) {
        if ( i + k > n) j = n - 1;
        else j = i + k - 1;
        printf("%d ", MAX(right[i], left[j]));
    }

    return 0;
}
