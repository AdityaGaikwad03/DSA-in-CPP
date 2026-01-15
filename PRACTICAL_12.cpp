// C++ program to find factorial of a number using recursion
#include <iostream>
using namespace std;

// Define a function to calculate factorial
// recursively
long long factorial(int n)
{
    // Base case - If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case - Return n multiplied by
    // factorial of (n-1)

    return n*(factorial(n-1));
}

int main()
{
    int num;
    cout<<"Enter number   ";
    cin>>num;
    // printing the factorial
    cout << "Factorial of " << num << " is "
         << factorial(num) << endl;

    return 0;
}