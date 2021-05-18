#include <bits/stdc++.h>
using namespace std;

long long K, N;
long long arr[10000];

long long bSearch(long long end) {
        long long start = 0;
        long long sum = 0;
        long long len = (start + end) / 2;

        while (start <= end) {
                sum = 0;
                len = (start + end) / 2;
                if (len == 0) 
                        break;

                for (int i = 0; i < K; i++) {
                        sum += arr[i] / len;
                }

                if (sum < N) {
                        end = len - 1;
                }
                else {
                        start = len + 1;
                }
        }
        return end;
}

int main(void) 
{
        scanf("%lld %lld", &K, &N);
        for (int i = 0; i < K; i++)
                scanf("%lld", &arr[i]);
        
        sort(arr, arr + K);
        printf("%lld", bSearch(arr[K - 1]));
        return 0;
}