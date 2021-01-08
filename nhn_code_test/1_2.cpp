#include <bits/stdc++.h>
using namespace std;

typedef struct _circle {
        int n;
        int x;
        int y;
        int r;
} _circle;

vector<struct _circle> circle;
vector<int> tree[101];
vector<int> path;
vector<int> solv;

int _map[101];
bool visited[101];
int N;
int from, to;

bool cmp(_circle a, _circle b) {
        return a.r > b.r;
}

int check_circle(int a, int b) {        // 0 = b가 a의 외부
                                        // 1 = b가 a의 외부 (동심원) / a가 b의 내부 / 나올 수 없음
                                        // 2 = b가 a의 내부
                                        // -1 = 만날 경우 입력 에러
        int x1 = circle[a].x, x2 = circle[b].x;
        int y1 = circle[a].y, y2 = circle[b].y;
        int r1 = circle[a].r, r2 = circle[b].r;
        int rsum_pow = pow(r1 + r2, 2);
        int rmin_pow = pow(r1 - r2, 2);
        int d_pow = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        
        if (d_pow == 0) {
                if (r1 == r2) return -1;
                else if (r1 < r2) return 1;
                else return 2;
        }
        if (d_pow >= rmin_pow && d_pow <= rsum_pow) return -1;
        else if (d_pow > rsum_pow) return 0;
        else return 2;
}

int get_parent(int cur_parent, int child) {
        int parent = cur_parent;
        int size = tree[cur_parent].size();

        if (size == 0) return cur_parent;
        
        for (int i = 0; i < size; i++) {
                int n = _map[tree[cur_parent][i]];
                int res = check_circle(n, child);

                if (res == -1) {
                        printf("-1");
                        exit(0);
                }
                else if (res == 0) continue;
                else if (res == 2) {
                        parent = get_parent(tree[cur_parent][i], child);
                }
        }
        return parent;
}

void dfs(int cur) {
        int size = tree[cur].size();
        visited[cur] = true;
        path.push_back(cur);

        if (cur == to) {
                int path_size = path.size();
                if (solv.size() == 0) {
                        solv.assign(path.begin(), path.end());
                }
                else if (path_size < solv.size()) {
                        solv.assign(path.begin(), path.end());
                }
                
        }
        if (size == 0) return;
        for (int i = 0; i < size; i++) {
                int next = tree[cur][i];
                if (visited[next] == false)
                        dfs(next);
        }
        visited[cur] = false;
        path.pop_back();
}


int main(void) {
        scanf("%d", &N);
        int check = 0;
        int cnt = 0;
        _circle tmp;

        for (int i = 0; i < N; i++) {
                scanf("%d %d %d %d", &tmp.n, &tmp.x, &tmp.y, &tmp.r);
                circle.push_back(tmp);
        }

        sort(circle.begin(), circle.end(), cmp);

        for (int i = 0; i < N; i++) {
                _map[circle[i].n] = i;
        }

        for (int i = 0; i < N; i++) {
                int parent = get_parent(0, i);
                tree[parent].push_back(circle[i].n);
        }

        for (int i = 0; i < 101; i++) {
                int size = tree[i].size();
                if (size == 0) continue;
       
                for(int j = 0; j < size; j++) {
                        int child = tree[i][j];
                        int c_size = tree[child].size();
                        int check = 0;
                        for (int k = 0; k < c_size; k++) {
                                if (tree[child][k] == i)
                                        check = 1;
                        } 
                        if (check == 0) tree[child].push_back(i);
                }

                       
        }

        scanf("%d %d", &from, &to);
        
        if (from == to) {
                printf("%d", from);
                return 0;
        }

        dfs(from);

        int size = solv.size();
        for (int i = 0; i < size; i++)
                printf("%d ", solv[i]);
        

        return 0;
}