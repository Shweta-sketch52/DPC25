#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element) {
    if (st.empty() || element < st.top()) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

void sortStack(stack<int> &st) {
    if (st.empty()) 
    return;

    int topElement = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, topElement);
}

int main() {
    stack<int> st;
    int n, val;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        st.push(val);
    }

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
