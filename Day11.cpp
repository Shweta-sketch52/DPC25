#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (used[i])
         continue;

        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) 
         continue;

        used[i] = true;
        current.push_back(s[i]);
        backtrack(s, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<string> stringPermutations(string s) {
    sort(s.begin(), s.end());  
    vector<string> result;
    vector<bool> used(s.size(), false);
    string current;
    backtrack(s, used, current, result);
    return result;
}

int main() {
    string s;
    cout<<"Enter String:";
    cin >> s;

    vector<string> permutations = stringPermutations(s);
    cout << "Possible Combinations: ";
    for (auto &p : permutations) {
        cout << p << "\n";
    }

    return 0;
}
