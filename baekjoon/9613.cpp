#include <bits/stdc++.h>
using namespace std;

int arr[100];

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	int T;

	scanf("%d", &T);

	while (T--) {
		int n;
		long long sum = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		
		

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)  {
				if (arr[i] > arr[j]) 
					sum += gcd(arr[i], arr[j]);
				else
					sum += gcd(arr[j], arr[i]);
			}
		
		printf("%lld\n", sum);
	}

	return 0;
}
