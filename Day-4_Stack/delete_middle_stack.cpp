#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st, int k) {
    if (k == 1) {
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    solve(st, k - 1);
    st.push(top);
}

void deleteMiddle(stack<int>& st, int size) {
    int k = (size / 2) + 1;
    solve(st, k);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    deleteMiddle(st, st.size());

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}