#include <bits/stdc++.h>
using namespace std;

int main(void) {
        int dp[41] = {0, 1, 1};
        for (int i = 2; i < 41; i++)
                dp[i] = dp[i - 1] + dp[i - 2];
        
        int tc;
        scanf("%d", &tc);
        while (tc--) {
                int n;
                scanf("%d", &n);
                if(n == 0) printf("%d %d\n", 1, 0);
                else if (n == 1) printf("%d %d\n", 0, 1);
                else printf("%d %d\n", dp[n-1], dp[n]);
        }
        return 0;
}