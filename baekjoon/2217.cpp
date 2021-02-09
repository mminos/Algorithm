#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int N, tot;

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
        
        sort(arr, arr + N);

        for (int i = 0; i < N; i++) {
                tot = max(tot, arr[i] * (N - i));
        }

        printf("%d", tot);
        return 0;
}