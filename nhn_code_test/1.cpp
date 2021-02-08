#include <bits/stdc++.h>
using namespace std;

vector<int> tree[101];
int circle[101][4];     // n, x, y, r
int N, res;

int check_circle(int a, int b) {        // 0 = b가 a의 외부
                                        // 1 = b가 a의 외부 (동심원) / a가 b의 내부
                                        // 2 = b가 a의 내부
                                        // -1 = 만날 경우 입력 에러
        int x1 = circle[a][1], x2 = circle[b][1];
        int y1 = circle[a][2], y2 = circle[b][2];
        int r1 = circle[a][3], r2 = circle[b][3];
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

int main(void) {        
        scanf("%d", &N);
        int check = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
                scanf("%d %d %d %d", &circle[i][0], &circle[i][1], &circle[i][2], &circle[i][3]);
                cnt = 0;
                for(int j = 0; j < i; j++) {
                        res = check_circle(j, i);
                        if (res == -1) check++;
                        else if (res == 0) {

                        }
                        else if (res == 1) {
                                cnt++;
                                
                        }
                        else if (res == 2) {

                        }
                }
        }
}