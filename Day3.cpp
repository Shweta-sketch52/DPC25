#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    int p1 = arr[0]; 
    int p2 = arr[0]; 

    do {
        p1 = arr[p1];          
        p2 = arr[arr[p2]];     
    } 
    while (p1 != p2);
    p1 = arr[0];

    while (p1 != p2) {
        p1 = arr[p1];
        p2 = arr[p2];
    }
    return p1;
}

int main() {
    int n;
    cout << "Enter n (range of numbers 1 to n): ";
    cin >> n;

    vector<int> arr(n + 1);
    cout << "Enter " << n + 1 << " elements: ";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
