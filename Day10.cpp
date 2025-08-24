#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // sort to form the key
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &it : mp) {
        result.push_back(it.second);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> groups = groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n[\n";
    for (auto &group : groups) {
        cout << "  [ ";
        for (auto &word : group) {
            cout << "\"" << word << "\" ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}
