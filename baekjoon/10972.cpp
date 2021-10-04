#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	bool res = next_permutation(arr, arr + n);

	if (res) {
		for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	}
	else printf("-1");

	return 0;
}