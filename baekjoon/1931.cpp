#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100000];
int N, cnt, last;

bool comp(const pair<int, int> &a, const pair<int, int> &b) 
{
        if (a.second != b.second) {
                return a.second < b.second;
        }
        else {
                return a.first < b.first;
        }
}

int main(void)
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                int a, b;
                scanf("%d %d", &a, &b);
                arr[i] = make_pair(a, b);
        }

        sort(arr, arr + N, comp);
        
        for (int i = 0; i < N; i++) {
                if (i == 0) {
                        last = arr[i].second;
                        cnt++;
                        continue;
                }

                if (last > arr[i].first) continue;
                else {
                        last = arr[i].second;
                        cnt++;
                        continue;
                }
        }
        
        printf("%d", cnt);
        return 0;
}