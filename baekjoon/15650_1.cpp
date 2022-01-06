#include <bits/stdc++.h>
using namespace std;

int arr[10];
int num[10];
int N, M;

int main(void)
{
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)num[i] = i + 1;
        for (int i = 0; i < M; i++)arr[i] = 1;

        do {
                for (int i = 0; i < N; i++) {
                        if (arr[i])
                                printf("%d ", num[i]);
                }
                putchar('\n');
        } while(prev_permutation(arr, arr + N));

        return 0;
}