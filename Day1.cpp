#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>&arr){
  int low=0, mid=0, high=arr.size()-1;

  while(mid<=high){
     if(arr[mid]==0){
       swap(arr[low], arr[mid]);
       low++;
       mid++;
     }
     else if(arr[mid]==1){
       mid++;
     }
     else{
       swap(arr[mid], arr[high]);
       high--;
     }
   }
 }

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;

  vector<int> arr(n);
  cout<<"Enter array elements(only 0,1 and 2): ";
  for(int i=0; i<n; i++){
     cin>>arr[i];
  }

  sort(arr);

  cout<< "Sorted Array: ";
  for(int num : arr){
      cout<< num << " ";
  }
  return 0;
}
