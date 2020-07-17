#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9][9], x[9], y[9], z[9];
vector<pair<int, int>> v;

void dfs(int cnt) {
        if (cnt == v.size()) {
                for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) printf("%d ", arr[i][j]);
                        putchar('\n');
                }
                exit(0);
        }

        auto blank = v[cnt];

        for (int i = 0; i < 9; i++) {
                x[i] = arr[blank.first][i];
                y[i] = arr[i][blank.second];         
        }
        for (int k = 0, i = (blank.first / 3) * 3; i < (blank.first / 3) * 3 + 3; i++) 
                for (int j = (blank.second / 3) * 3; j < (blank.second / 3) * 3 + 3; j++) 
                        z[k++] = arr[i][j];
        
        int check[10] = {0, };
        for (int i = 0; i < 9; i++) {
                check[x[i]]++, check[y[i]]++, check[z[i]]++;
        }
        for (int i = 1; i < 10; i++) {
                if (check[i] == 0) {
                        int temp[9][9];
                        memcpy(temp, arr, sizeof(temp));
                        arr[blank.first][blank.second] = i;
                        dfs(cnt + 1);
                        memcpy(arr, temp, sizeof(arr));
                }
        }
}

int main(void) {
        for (int i =0; i < 9; i++) 
                for (int j = 0; j < 9; j++) {
                        scanf("%d", &arr[i][j]);
                        if (arr[i][j] == 0) v.push_back({i, j});
                }
        dfs(0);
}