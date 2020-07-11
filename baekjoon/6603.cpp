#include <cstdio>

void dfs(int n, int depth);

int input[16];
int lotto[6];
int num;

int main() {
        while (1) {
                scanf("%d", &num);
                if (num == 0) break;
                for (int i = 0; i < num; i++) 
                        scanf("%d", &input[i]);
               
                dfs(0, 0);
                putchar('\n');
        }
}

void dfs(int n, int depth) {
        if (depth == 6) {
                for (int i = 0; i < 6; i++)
                        printf("%d ", lotto[i]);
                putchar('\n');
                return;
        }

        for (int i = n; i < num; i++) {
                lotto[depth] = input[i];
                dfs(i + 1, depth + 1);
        }
}