#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, less<int> > pq1;
priority_queue<int, vector<int>, greater<int> > pq2;
int N, n;

int main(void) 
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d", &n);
                if (i == 0) {
                        pq1.push(n);
                        printf("%d\n", n);
                        continue;
                }
                else if (pq2.size() == 0) {
                        if (pq1.top() <= n) pq2.push(n);
                        else {
                                int tmp = pq1.top();
                                pq1.pop();
                                pq1.push(n);
                                pq2.push(tmp);
                        }
                        printf("%d\n", pq1.top());
                        continue;
                }

                int m1 = pq1.top(), m2 = pq2.top();
                int s1 = pq1.size(), s2 = pq2.size();

                if (n >= m1 && n <= m2) {
                        if (s1 == s2) {
                                pq1.push(n);
                        }
                        else if (s1 > s2) {
                                pq2.push(n);
                        }
                }
                else if (n < m1) {
                        if (s1 == s2) {
                                pq1.push(n);
                        }
                        else if (s1 > s2) {
                                int tmp = pq1.top();
                                pq1.pop();
                                pq1.push(n);
                                pq2.push(tmp);
                        }
                }
                else {// n > m2
                        if (s1 == s2) {
                                int tmp = pq2.top();
                                pq2.pop();
                                pq2.push(n);
                                pq1.push(tmp);
                        }
                        else if (s1 > s2) {
                                pq2.push(n);
                        }
                }
                printf("%d\n", pq1.top());
        }
        return 0;
}