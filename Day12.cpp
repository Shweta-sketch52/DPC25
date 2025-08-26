#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

    if(s.empty()) 
      return true;

    if(s.size() % 2 != 0)
      return false;

    stack<char> st;
    for(char c : s) {
      
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else {
            
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();
          
            if((c == ')' && top != '(') || 
               (c == '}' && top != '{') || 
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
