#include <cstdio>
#define mod 1000000000
using namespace std;

int main() {
	int N, K;
	long long dp[201][201];
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= N; i++)	dp[1][i] = 1;
	for(int k = 2; k <= K; k++) {
		for(int n = 0; n <= N; n++) {
			for(int i = 0; i <= n; i++) {
				dp[k][n] = dp[k][n] + dp[k-1][n-i];
			}
			dp[k][n] = dp[k][n] % mod;
		}
	}
	printf("%lld\n", dp[K][N]);
	return 0;
}
