#include <bits/stdc++.h>
using namespace std;

struct cmp {
        bool operator()(int a, int b) {
                if (abs(a) == abs(b))
                        return a > b;
                else
                        return abs(a) > abs(b);
        }
};
priority_queue<int, vector<int>, cmp> pq;
int N, x;

int main(void)
{
        scanf("%d", &N);
        while (N--) {
                scanf("%d", &x);
                if (x == 0) {
                        if (pq.empty()) printf("0\n");
                        else {
                                printf("%d\n", pq.top());
                                pq.pop();
                        }
                }
                else {
                        pq.push(x);
                }
        }
        return 0;
}