#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int size);

int n, r, c;
int res = 0;

int main(void) {
        scanf("%d %d %d", &n, &r, &c);
        int size = (1 << n);

        dfs(0, 0, size);
}

void dfs(int x, int y, int size) {
        if (x == r && y == c) {
                printf("%d", res);
                return;
        }

        if (r >= x && r < x + size &&c >= y && c < y + size) {
                dfs(x, y, size / 2);
                dfs(x, y + size / 2, size / 2);
                dfs(x + size / 2, y, size / 2);
                dfs(x + size / 2, y + size / 2, size / 2);
        }
        else {
                res += size * size;
        }
}