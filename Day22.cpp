#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstElementToRepeatKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1; 
}

int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k (number of times element should repeat): ";
    cin >> k;

    int result = firstElementToRepeatKTimes(arr, k);
    cout << "Output: " << result << endl;

    return 0;
}
