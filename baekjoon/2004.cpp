#include <bits/stdc++.h>
using namespace std;

int n, m, two, five;

int get_two(int num) {
        int cnt = 0;
        while (num) {
                cnt += num / 2;
                num /= 2;
        }
        return cnt;
}

int get_five(int num) {
        int cnt = 0;
        while (num) {
                cnt += num / 5;
                num /= 5;
        }
        return cnt;
}

int main(void)
{
        scanf("%d %d", &n, &m);

        two += get_two(n);
        five += get_five(n);
        two -= get_two(n - m);
        five -= get_five(n - m);
        two -= get_two(m);
        five -= get_five(m);

        printf("%d", min(two, five));
        return 0;
}