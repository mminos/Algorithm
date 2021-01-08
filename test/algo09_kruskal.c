#include <stdio.h>
#include <limits.h>
#include <string.h>

#define SIZE 8
#define INF INT_MAX

typedef struct edge {
        int v1, v2, weight;
}edge;

edge edges[14] = {      //과제의 그래프의 edge들의 집합 (정점1, 정점2, 비용)
        {1,  2, 11},
        {1,  3,  9},
        {1,  4,  8},
        {2,  3,  3},
        {2,  5,  8},
        {2,  6,  8},
        {3,  4, 15},
        {3,  6, 12},
        {3,  7,  1},
        {4,  7, 10},
        {5,  6,  7},
        {5,  8,  4},
        {6,  8,  5},
        {7,  8,  2}
};

int parent[SIZE + 1];   // n번째 정점의 루트 (집합의 대표)


int merge(int i, int j);
int find(int n);

int main(void) {
        int edge_num = 14;
        int cnt = 0;
        int idx = 0;

        for (int i = edge_num - 1; i > 0; i--) {                //edge들을 가중치를 기준으로 버블정렬
                for (int j = 0; j < i; j++) {
                        if (edges[j].weight > edges[j+1].weight) {
                                edge tmp = edges[j];
                                edges[j] = edges[j + 1];
                                edges[j + 1] = tmp;
                        }
                }
        }

        while (cnt != SIZE - 1) {               //edge들을 n-1개 선택하여 최소 신장 트리가 될때까지 loop
                if (idx == edge_num) {          //모든 edge들을 탐색했지만 최소 신장 트리를 만들지 못했을 경우 에러 출력
                        printf("can't make MST with edges\n");
                        return 0;
                }

                edge e = edges[idx++];          //idx번째 edge 저장

                int res = merge(e.v1, e.v2);    //두 정점을 합병 시도 ==> 실패 시 0리턴, 성공 시 1 리턴
                if (res == 1) cnt++;
        }

        return 0;
}

int merge(int i, int j) {
        int u = find(i);        //정점 i가 속해있는 집합의 대표 정점 구하기
        int v = find(j);        //정점 v가 속해있는 집합의 대표 정점 구하기

        if (u == v) return 0;   //두 정점이 같은 집합에 속해 있다면 0(실패) 리턴

        parent[u] = v;          //두 정점이 다른 집합이라면 u를 합병한 0집합의 대표로 설정
        printf("connect V%d and V%d\n", i, j);  //두 정점을 연결했으므로 출력
        return 1;               //1 (성공) 리턴
}

int find(int n) {
        if (!parent[n]) return n;       //n이 집합의 대표 정점이라면 n 리턴

        return parent[n] = find(parent[n]);     //아니라면 다시 탐색
}