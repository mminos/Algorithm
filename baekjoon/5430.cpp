#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int main(void) {
        int tc;
        
        scanf("%d", &tc);
        while (tc--) {
                char p[100001];
                int n, x, length;
                bool path = true;
                bool check = true;
                deque<int> dq;

                scanf("%s", p);
                scanf("%d", &n);
                getchar(), getchar();
                
                if (n) {
                        for (int i = 0; i < n - 1; i++) {
                                scanf("%d,", &x);
                                dq.push_back(x);
                        }
                        scanf("%d]", &x);
                        dq.push_back(x);
                }
                getchar();
                
                length = strlen(p);
                for (int i = 0; i < length; i++) {
                        switch (p[i]) {
                        case 'R' : 
                                path ^= true;
                                break;
                        case 'D' :
                                if (dq.empty()) {
                                        check = false;
                                        break;
                                } 
                                
                                if (path) dq.pop_front();
                                else dq.pop_back();
                                break;
                        }
                }

                if (!check) {
                        puts("error");
                        continue;
                }

                putchar('[');
                while (!dq.empty()) {
                        int n2;
                        
                        if (path) {
                                n2 = dq.front();
                                dq.pop_front();
                        }
                        else {
                                n2 = dq.back();
                                dq.pop_back();
                        }

                        printf("%d", n2);

                        if (dq.empty()) break;
                        else putchar(',');
                }
                printf("]\n");
        }
        return 0;
}