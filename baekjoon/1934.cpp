#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	int T, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		int _gcd = gcd(a, b);
		printf("%d\n", a * b / _gcd);
	}
	
	return 0;
}