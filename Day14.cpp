#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int atMostKDistinct(const string &s, int k) {
    int n = s.size();
    int left = 0, count = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        count += (right - left + 1);
    }
    return count;
}

int countExactlyKDistinct(const string &s, int k) {
    if (k == 0) return 0;
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << "Number of substrings with exactly " << k
         << " distinct characters = "
         << countExactlyKDistinct(s, k) << endl;

    return 0;
}
