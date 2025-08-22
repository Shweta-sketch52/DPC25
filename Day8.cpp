#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    string result = "";
    int n = s.size();
    int i = n - 1;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') 
        i--;

        if (i < 0) 
        break;

        int j = i;
        while (i >= 0 && s[i] != ' ') 
        i--;

        if (!result.empty())
         result += " ";

        result += s.substr(i + 1, j - i);
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Output: \"" << reverseWords(s) << "\"" << endl;
    return 0;
}
