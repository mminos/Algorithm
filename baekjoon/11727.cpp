#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];

int solv(int n) {
        if (n == 1) return 1;
        if (n == 2) return 3;

        if (dp[n] != 0) return dp[n];
        else {
                dp[n] = solv(n - 1) % 10007 + 2 * solv(n - 2) % 10007;
                return dp[n];
        }
}

int main(void) {
        scanf("%d", &N);
        
        printf("%d", solv(N) % 10007);
}