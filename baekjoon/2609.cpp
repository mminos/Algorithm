#include <cstdio>

int main(void) {
        int a, b;
        scanf("%d %d", &a, &b);
        int a1 = a, b1 = b;
        while (b != 0) {
                int r = a % b;
                a = b, b = r;
        }
        printf("%d\n%d", a, a1 * b1 / a);
        return 0;
}