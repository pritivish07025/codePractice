#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int sum = 0;

    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    cout << "Sum of prime numbers up to " << N << " is: " << sum << endl;

    return 0;
}