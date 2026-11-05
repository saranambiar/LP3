#include <bits/stdc++.h>
using namespace std;

long long calls = 0;

long long fibRec(int n){
    calls++;
    if (n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

long long fibLoop(int n){
    if ( n <= 1) return n;
    long long a = 0, b = 1, next;
    for (int i = 2; i <= n; i++){
        long long next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;

    long long r1 = fibRec(n);
    long long r2 = fibLoop(n);

    cout << "Recursive : " << r1 << "  calls = " << calls << endl;
    cout << "Loop      : " << r2 << "  steps = " << n << endl;
}