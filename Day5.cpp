#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1];

    leaders.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(arr[i]);
        }
    }

    for (int i = 0, j = leaders.size() - 1; i < j; i++, j--) {
        int temp = leaders[i];
        leaders[i] = leaders[j];
        leaders[j] = temp;
    }

    return leaders;
}

int main() {
    int n;
    cout<<"Enter size of array:";
    cin >> n;
    vector<int> arr(n);
    
    cout<<"Enter elements of array:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findLeaders(arr);
    
    cout<<"Leaders are: ";
    for (int leader : result) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
