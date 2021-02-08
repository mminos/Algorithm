#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int arr[100001];
int N;

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

        dp[0] = arr[0];
        for (int i = 1; i < N; i++) {
                dp[i] = max(arr[i], arr[i] + dp[i - 1]);
        }
        sort(dp, dp + N);
        printf("%d", dp[N - 1]);
        return 0;
}