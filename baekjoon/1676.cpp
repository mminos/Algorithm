#include <bits/stdc++.h>
using namespace std;

int get_cnt(int n1, int n2) {
        int cnt = 0;

        while (n1) {
                cnt += n1 / n2;
                n1 /= n2;
        }
        return cnt;
}

int main(void) {
        int n;
        scanf("%d" ,&n);

        int two = get_cnt(n, 2);
        int five = get_cnt(n, 5);

        printf("%d", min(two, five));
        return 0;
}