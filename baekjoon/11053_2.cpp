#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int A[1001];
int N;

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d", &A[i]);
                dp[i] = 1;
        }

        for (int i = 1; i < N; i++) {
                int res = 1;
                for (int j = 0; j < i; j++) {
                        if (A[i] > A[j])
                                res = max(res, dp[j] + 1); 
                }
                dp[i] = res;
        }
        
        sort(dp, dp + N);
        printf("%d", dp[N - 1]);
        return 0;
}