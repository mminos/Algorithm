#include <bits/stdc++.h>
using namespace std;

int dp[1010];
int N;

int prob(int n) {
        if (n < 1) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;

        if (dp[n] != 0) return dp[n];
        
        dp[n] = prob(n - 1) % 10007 + prob(n - 2) % 10007;
        return dp[n];
}

int main(void) {
        scanf("%d", &N);

        dp[1] = 1;
        dp[2] = 2;
        
        printf("%d", prob(N) % 10007);
        return 0;
}