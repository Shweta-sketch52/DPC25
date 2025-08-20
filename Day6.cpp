#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int, int>> result;
    unordered_map<int, vector<int>> prefixMap;
    int prefixSum = 0;
  
    prefixMap[0].push_back(-1);

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIdx : prefixMap[prefixSum]) {
                result.push_back({startIdx + 1, i});
            }
        }

        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout << "No subarray with zero sum found.\n";
    } else {
        cout << "Subarrays with zero sum:\n";
        for (auto &p : subarrays) {
            cout << "(" << p.first << ", " << p.second << ")\n";
        }
    }

    return 0;
}
