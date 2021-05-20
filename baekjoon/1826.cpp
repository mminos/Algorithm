#include <bits/stdc++.h>
using namespace std;


priority_queue<int, vector<int>, less<int> >pq;
pair<int, int> fuel[10000];
int N, L, P, cnt;

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d %d", &fuel[i].first, &fuel[i].second);
        }
        sort(fuel, fuel + N);
        
        scanf("%d %d", &L, &P);

        int idx = 0;
        while (L > P) {
                while (fuel[idx].first <= P && idx < N)
                        pq.push(fuel[idx++].second);
                
                if (!pq.empty()) {
                        P += pq.top(), pq.pop();
                        cnt++;
                }
                else if (idx == N || fuel[idx].first > P) {
                        cnt = -1;
                        break;
                }
        }

        printf("%d", cnt);
        return 0;
}