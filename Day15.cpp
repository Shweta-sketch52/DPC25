#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int lastIndex[256];          
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (lastIndex[(unsigned char)s[i]] >= start) {
            start = lastIndex[(unsigned char)s[i]] + 1;
        }
        lastIndex[(unsigned char)s[i]] = i; 
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;  
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
