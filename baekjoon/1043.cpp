#include <bits/stdc++.h>
using namespace std;

int root[51];
vector<int> v[51];
int n, m, p, tmp, check, res;

int _find(int a) {
        if (root[a] == a) 
                return a;
        else
                return root[a] = _find(root[a]);
}

void _union(int a, int b) {
        a = _find(a);
        b = _find(b);

        if (a >= b) 
                root[a] = b;
        else
                root[b] = a;
}

int main(void)
{
        for (int i = 0; i < 51; i++) {
                root[i] = i;
        }

        scanf("%d %d", &n, &m);

        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
                scanf("%d", &p);
                v[0].push_back(p);
        }
        
        for (int i = 0; i < (int)v[0].size() - 1; i++) {
                _union(v[0][i], v[0][i + 1]);
        }

        for (int i = 1; i <= m; i++) {
                scanf("%d", &p);
                
                for (int j = 0; j < p; j++) {
                        scanf("%d", &tmp);
                        v[i].push_back(tmp);
                }

                for (int j = 0; j < (int)v[i].size() - 1; j++) {
                        _union(v[i][j], v[i][j + 1]);
                }
        }

        if (n == 0) {
                printf("%d", m);
                return 0;
        }

        for (int i = 1; i <= m; i++) {
                check = 0;

                for (int j : v[i]) {
                        if (_find(v[0][0]) == _find(j)) check++;
                }

                if (check == 0) res++;
        }

        printf("%d", res);
        return 0;
}