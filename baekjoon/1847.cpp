#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N, num, idx = 0;
    stack<int> st;
    vector<int> input, st_input;
    vector<char> output;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        input.push_back(num);
        st_input.push_back(i + 1);
    }
    st_input.push_back(-1);
    
    for (int i = 0; i < input[0]; i++) {
        st.push(st_input[idx++]);
        output.push_back('+');
    }

    st.pop();
    output.push_back('-');

    for (int i = 1; i < N; i++) {
        if (st.empty()) {
            st.push(st_input[idx++]);
            output.push_back('+');
        }

        if (input[i] == st.top()) {
            st.pop();
            output.push_back('-');
        }
        else if (input[i] > st.top()) {
            while (st_input[idx] <= input[i]) {
                st.push(st_input[idx++]);
                output.push_back('+');

                if (idx >= N) break;
            }

            st.pop();
            output.push_back('-');
        }
        else {
            printf("NO");
            return 0;
        }
    }
    for (auto c : output)
        printf("%c\n", c);

    return 0;
}