#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

bool visited[100001];
queue<pair<int, vector<int>>> q;
int n, k;

int main(void) 
{
        scanf("%d %d", &n, &k);

        if (n > k) {
                printf("%d\n", n - k);
                for (int i = n; i >= k; i--) printf("%d ", i);

                return 0;
        }

        q.push({n, {n}});
        visited[n] = true;

        while(!q.empty()) {
                auto a = q.front(); q.pop();
                int cur = a.first;
                vector<int> v = a.second;

                if (cur == k) {
                        int len = v.size();
                        printf("%d\n", len - 1);
                        for (int i = 0; i < len; i++)
                                printf("%d ", v[i]);
                        break;
                }

                int n1 = cur + 1;
                int n2 = cur - 1;
                int n3 = cur * 2;

                if (n1 <= MAX && visited[n1] == false) {
                        v.push_back(n1);
                        visited[n1] = true;
                        q.push({n1, v});
                        v.pop_back();
                }

                if (n2 >= 0 && visited[n2] == false) {
                        v.push_back(n2);
                        visited[n2] = true;
                        q.push({n2, v});
                        v.pop_back();
                }

                if (n3 <= MAX && visited[n3] == false) {
                        v.push_back(n3);
                        visited[n3] = true;
                        q.push({n3, v});
                        v.pop_back();
                }
        }
        return 0;        
}