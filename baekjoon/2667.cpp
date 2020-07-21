#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> result;
char arr[26][26];
bool visited[26][26];
int n;
int cnt;

int main(void) {
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++)
                        scanf("%c", &arr[i][j]);
                getchar();
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (arr[i][j] == '1' && visited[i][j] == false) {
                                queue<pair<int, int>> bfs;
                                int check = 0;
                                cnt++;

                                bfs.push({i, j});
                                while (!bfs.empty()) {
                                        auto q = bfs.front();
                                        bfs.pop();

                                        if (visited[q.first][q.second] == true) continue;
                                        else {
                                                check ++, visited[q.first][q.second] = true;
                                        }

                                        if (arr[q.first + 1][q.second] == '1') bfs.push({q.first + 1, q.second});
                                        if (arr[q.first][q.second + 1] == '1') bfs.push({q.first, q.second + 1});
                                        if (q.first > 0 && arr[q.first - 1][q.second] == '1') bfs.push({q.first - 1, q.second});
                                        if (q.second > 0 && arr[q.first][q.second - 1] == '1') bfs.push({q.first, q.second - 1});
                                }

                                if (check > 0) result.push_back(check);
                        }
                }
        }
        sort(result.begin(), result.end());

        printf("%d\n", cnt);
        for (int i = 0; i < result.size(); i++) 
                printf("%d\n", result[i]);
        
        return 0;
}