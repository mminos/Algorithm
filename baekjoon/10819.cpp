#include <bits/stdc++.h>
using namespace std;

int main(void) {
        int n, res = 0;
        int arr[8];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        sort(arr, arr + n);
        do {
                int sum = 0;
                for (int i = 0; i < n - 1; i++) sum += abs(arr[i] - arr[i + 1]);

                res = max(res, sum);
        } while (next_permutation(arr, arr + n));

        printf("%d", res);
        return 0;
}