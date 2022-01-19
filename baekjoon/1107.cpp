#include <bits/stdc++.h>
using namespace std;

int n, m, res = INT_MAX, cnt;
bool broken[10];

bool check(int num) {
        string s = to_string(num);
        int len = s.length();
        
        for (int i = 0; i < len; i++)
                if (broken[s[i] - 48])
                        return false;
        
        return true;
}

int main(void) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
                int tmp;
                scanf("%d", &tmp);
                broken[tmp] = true;
        }

        string s = to_string(n);
        res = abs(n - 100);

        for (int i = 0; i <= 1000000; i++) {
                if (check(i)) {
                        int tmp = abs(n - i) + to_string(i).length();
                        res = min(res, tmp);
                }
        }       

        printf("%d", res);
        return 0;
}