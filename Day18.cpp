#include <iostream>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) 
                count++;
            else 
                count += 2;
        }
    }
    return count;
}

int main() {
    int N;
    cout<<"Enter number: ";
    cin >> N;
    cout<<"No. of divisors are: ";
    cout << countDivisors(N) << endl;
    return 0;
}
