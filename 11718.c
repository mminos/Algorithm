#include <stdio.h>
#include <string.h>


int main() {
    char a;
    a = getchar();

    while (a != EOF) {
        putchar(a);
        a = getchar();
    }

    return 0;
}
