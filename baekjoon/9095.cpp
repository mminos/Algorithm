#include <bits/stdc++.h>
using namespace std;

int memo[11] = {1, 2, 4, };
int T ,n;

int main(void) {
	scanf("%d" ,&T);

	for (int i = 3; i < 11; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
	}

	while (T--) {
		scanf("%d", &n);

		printf("%d\n", memo[n - 1]);
	}
	return 0;
}