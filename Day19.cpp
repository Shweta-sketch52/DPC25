#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(const string &expr) {
    stack<int> st;
    int n = expr.size();

    for (int i = 0; i < n; i++) {
        if (expr[i] == ' ') 
          continue;

        if (isdigit(expr[i]) || (expr[i] == '-' && i + 1 < n && isdigit(expr[i + 1]))) {
            int sign = 1, num = 0;
            if (expr[i] == '-') {
                sign = -1;
                i++;
            }
            while (i < n && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            st.push(sign * num);
        }

        else {
            if (st.size() < 2) {
                cout << "Error: Invalid postfix expression (not enough operands)." << endl;
                return 0;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (expr[i]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Error: Division by zero." << endl;
                        return 0;
                    }
                    st.push(a / b);
                    break;
                default:
                    cout << "Error: Unsupported operator '" << expr[i] << "'." << endl;
                    return 0;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Error: Invalid postfix expression (extra operands left)." << endl;
        return 0;
    }

    return st.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);

    int result = evaluatePostfix(expr);
    cout << "Result = " << result << endl;

    return 0;
}
