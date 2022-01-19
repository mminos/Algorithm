#include <bits/stdc++.h>
using namespace std;

#define MAX 200001
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[MAX];
int n, k;

int main(void) 
{
        scanf("%d %d", &n, &k);

        if (n > k) {
                printf("%d", n - k);
                return 0;
        }

        pq.push({0, n});
        visited[n] = true;

        while (!pq.empty()) {
                auto tmp = pq.top(); pq.pop();
                int cur = tmp.second, cnt = tmp.first;

                if (cur == k) {
                        printf("%d", cnt);
                        return 0;
                }

                int n1 = cur * 2;
                int n2 = cur + 1;
                int n3 = cur - 1;

                if (n1 <= MAX && !visited[n1]) {
                        pq.push({cnt, n1});
                        visited[n1] = true;
                }
                
                if (n2 <= MAX && !visited[n2]) {
                        pq.push({cnt + 1, n2});
                        visited[n2] = true;
                }

                if (n3 >= 0 && !visited[n3]) {
                        pq.push({cnt + 1, n3});
                        visited[n3] = true;
                }
        }
        return 0;
}