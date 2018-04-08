#include <iostream>
 
using namespace std;
 
int fibonacci(int n){
    if(n == 1 || n == 0){
        return n;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

unsigned long long int fibonnaci_iterative(int n){
    if(n == 0) return 0;
    unsigned long long int prev = 0;
    unsigned long long int current = 1;
    unsigned long long int next = 1;
    for (int i = 1; i < n; ++i)
    {
        next = current + prev;
        prev = current;
        current = next;
    }
    return current;
}

int main(){
    long int n,i=0;
    cout << "Input the number of terms for Fibonacci Series: ";
    cin >> n;
    cout << "\nFibonacci Series is as follows\n";
 
    while(i<n){
        cout << fibonnaci_iterative(i) << " ";
        i++;
    }

    // cout << fibonacci(n);

    cout << endl;
 
    return 0;
}