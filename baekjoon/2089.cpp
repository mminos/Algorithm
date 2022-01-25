#include <bits/stdc++.h>
using namespace std;

int main(void)
{
        int n;
        deque<int> dq;

        scanf("%d", &n);

        while (n) {
                if (n % -2 == 0) {
                        dq.push_front(0);
                        n /= -2;
                }
                else {
                        dq.push_front(1);
                        n = (n - 1) / -2;
                }
        }

        if (dq.size() == 0) {
                printf("0");
                return 0;
        }

        for (int i : dq) {
                printf("%d", i);
        }
        return 0;
}