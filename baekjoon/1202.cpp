#include <bits/stdc++.h>
using namespace std;

pair<int, int> jw[300000];
priority_queue<int, vector<int>, less<int> >pq;
int bag[300000];

int N, K;
long long res;

int main(void) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> K;
        
        for(int i = 0; i < N; i++) {
                cin >> jw[i].first >> jw[i].second;
        }
        for (int i = 0; i < K; i++) {
                cin >> bag[i];
        }

        sort(jw, jw + N);
        sort(bag, bag + K);

        int idx = 0;
        for (int i = 0; i < K; i++) {
                while (jw[idx].first <= bag[i] && idx < N) {
                        pq.push(jw[idx++].second);
                }

                if (!pq.empty()) {
                        res += pq.top();
                        pq.pop();
                }
        }

        cout << res;
        return 0;
}