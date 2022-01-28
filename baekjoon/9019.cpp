#include <bits/stdc++.h>
using namespace std;

int D(int);
int S(int);
int L(int);
int R(int);

queue<pair<int, string>> q;
bool visited[10000];
int n, t;

int (*fp[4])(int);
string dslr[4] = {"D", "S", "L", "R"};

int main(void)
{
        scanf("%d", &t);

        fp[0] = D;
        fp[1] = S;
        fp[2] = L;
        fp[3] = R;

        while (t--) {
                int a, b;
                memset(visited, 0, sizeof(visited));
                scanf("%d %d", &a, &b);

                q.push({a, ""});
                visited[a] = true;

                while (!q.empty()) {
                        int cur = q.front().first;
                        string cur_s = q.front().second;
                        q.pop();

                        if (cur == b) {
                                printf("%s\n", cur_s.c_str());
                                break;
                        }

                        for (int i = 0; i < 4; i++) {
                                int ret = fp[i](cur);

                                if (!visited[ret]) {
                                        visited[ret] = true;
                                        q.push({ret, cur_s + dslr[i]});
                                }
                        }
                }
                while (!q.empty()) q.pop();
        }
}

int D (int n) {
        int ret = (n * 2) % 10000;
        return ret;
}

int S(int n) {
        int ret = n - 1;
        if (ret < 0) ret = 9999;

        return ret;
}

int L(int n) {
        int ret;
        ret = (n % 1000) * 10 + n / 1000;
        return ret;
}

int R(int n) {
        int ret;
        ret = n / 10 + (n % 10) * 1000;
        return ret;
}