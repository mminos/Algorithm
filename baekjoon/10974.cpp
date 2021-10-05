#include <bits/stdc++.h>
using namespace std;

int main(void) {
        int n;
        int arr[8] = {0, };

        scanf("%d", &n);

        for (int i = 0; i < n; i++) arr[i] = i + 1;

        do {
                for(int i = 0; i < n; i++) printf("%d ", arr[i]);
                putchar('\n');
        } while(next_permutation(arr, arr + n));

        return 0;
}