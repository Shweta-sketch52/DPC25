#include <iostream>
#include <vector>
using namespace std;

int reduceGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2); 
}

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    for (int gap = reduceGap(m + n); gap > 0; gap = reduceGap(gap)) {
        int i, j;

        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        for (j = (gap > m) ? gap - m : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        for (j = 0; j + gap < n; j++) {
            if (arr2[j] > arr2[j + gap])
                swap(arr2[j], arr2[j + gap]);
        }
    }
}

int main() {
    int m, n;
    
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < m; i++) cin >> arr1[i];

    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n; i++) cin >> arr2[i];

    merge(arr1, arr2, m, n);

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
