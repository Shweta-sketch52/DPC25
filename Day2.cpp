#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>&arr, int n){
    int xorAll= 0, xorArr= 0;

    for(int i=1; i<=n; i++){
        xorAll ^= i;
    }

    for(int num : arr){
        xorArr ^= num;
    }

    return xorAll ^ xorArr;
}

int main(){
    int n;
    cout<< "Enter total number of elements including missing one: ";
    cin>>n;

    vector<int>arr(n-1);
    cout<<"Enter "<<n-1<<" elements of the array: ";
    for(int i=0; i<n-1; i++){
        cin>> arr[i];
    }

    cout<<"Missing number: "<<findMissingNumber(arr, n)<< endl;
    return 0;
}
