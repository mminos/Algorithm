#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    int num;
    unordered_map <int, int> umap;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        umap[num]++;
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        printf("%d ", umap[num]);
    }
    
    return 0;
}