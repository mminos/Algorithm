#include <bits/stdc++.h>
using namespace std;

int main(void) {
        int N, res = INT_MAX;
        int arr[10] = {0, };
        int W[10][10] = {0, };

        scanf("%d", &N);
        for (int i = 0 ; i < N; i++) arr[i] = i;

        for (int i = 0; i < N; i++) 
                for (int j = 0; j < N; j++)
                        scanf("%d", &W[i][j]);

        do {
                int sum = 0;

                for (int i = 0; i < N; i++) {
                        int w = W[arr[i]][arr[(i + 1) % N]];
                        if (w == 0) {
                                sum = INT_MAX;
                                break;
                        }

                        sum += w;
                }
                res = min(res, sum);

        } while (next_permutation(arr, arr + N));

        printf("%d", res);
        return 0;
}