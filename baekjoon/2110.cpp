#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int N, C;

int main(void)
{
        scanf("%d %d", &N, &C);
        for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr + N);

        // bsearch
        int start = 1, end = arr[N - 1] - arr[0];
        int res = 0;
        while (start <= end) {
                int mid = (start + end) / 2;
                int cnt = 1;
                int idx = 0;

                for (int i = 1; i < N; i++) {
                        int dis = arr[i] - arr[idx];
                        if (dis >= mid) {
                                idx = i;
                                cnt++;
                        }
                }

                if (cnt >= C) {
                        res = mid;
                        start = mid + 1;
                }
                else 
                        end = mid - 1;
        }
        printf("%d", res);      
        return 0;
}