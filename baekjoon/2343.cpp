#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int N, M, res;

int main(void)
{
        int low, high, mid;
        int maxLen = 0;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
                scanf("%d", &arr[i]);
                maxLen = max(arr[i], maxLen);
        }

        low = maxLen;        
        high = maxLen * (N / M + 1);

        while (low <= high) {
                mid = (low + high) / 2;
                
                int cnt = 1;
                int sum = 0;

                for (int i = 0; i < N; i++) {
                        sum += arr[i];
                        if (sum > mid) {
                                i--;
                                cnt++;
                                sum = 0;
                        }
                }

                if (cnt <= M) {
                        res = mid;
                        high = mid - 1;
                }
                else
                        low = mid + 1;
        }
        printf("%d\n", res);
        return 0;
}