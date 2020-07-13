#include <cstdio>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        vector<pair<int, int>> house, chicken;
        vector<int> v;
        int N, M, _min = INT_MAX;
        int arr[50][50]; 
        scanf("%d %d", &N, &M);
        
        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        scanf("%d", &arr[i][j]);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (arr[i][j] == 1)
                                house.push_back({i, j});
                        else if (arr[i][j] == 2)
                                chicken.push_back({i, j});
                }
        }

        for (int i = 0; i < M; i++) v.push_back(1);
        for (int i = M; i < chicken.size(); i++) v.push_back(0);

        do {
                vector<pair<int, int>> best;
                int chick_sum = 0;

                for (int i = 0; i < chicken.size(); i++)
                        if (v[i] == 1) 
                                best.push_back({chicken[i].first, chicken[i].second});

                for (int i = 0; i < house.size(); i++) {
                        int len, min_len = INT_MAX;
                        int x = house[i].first, y = house[i].second;
                        
                        for (int j = 0; j < M; j++) {
                                len = abs(best[j].first - x) + abs(best[j].second - y);
                                min_len = min(min_len, len);
                        }
                        chick_sum += min_len;
                }
                _min = min(_min, chick_sum);
        } while (prev_permutation(v.begin(), v.end()));

        printf("%d", _min);
        return 0;
}