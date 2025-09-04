#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    
    int topElement = st.top();
    st.pop();
    
    reverseStack(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    cout << topElement << " "; 
    printStack(st);            
    
    st.push(topElement);      
}

int main() {
    stack<int> st;
    int n, val;

    cout << "Enter number of elements in the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        st.push(val);
    }

    cout << "Original Stack (top to bottom): ";
    printStack(st);
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);
    cout << endl;

    return 0;
}
