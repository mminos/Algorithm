#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
        int N;
        int S[20][20];
        int _min = INT_MAX;
        int start_sum, link_sum;
        vector<int> v;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) 
                for(int j = 0; j < N; j++)
                        scanf("%d", &S[i][j]);
                        
        for (int i = 0; i < N/2; i++) v.push_back(0);
        for (int i = 0; i < N/2; i++) v.push_back(1);

        do {
                start_sum = 0, link_sum = 0;
                vector<int> start, link;
                for (int i = 0; i < N; i++) {
                        if (v[i] == 0) start.push_back(i);
                        else link.push_back(i);
                }

                for (int i = 0; i < N/2; i++) {
                        for (int j = i + 1; j < N/2; j++) {
                                if (i == j) continue;
                                start_sum += S[start[i]][start[j]] + S[start[j]][start[i]];
                                link_sum += S[link[i]][link[j]] + S[link[j]][link[i]];
                        }                       
                }
                _min = min(_min, abs(start_sum - link_sum));

        } while (next_permutation(v.begin(), v.end()));

        printf("%d", _min);
        return 0;
}