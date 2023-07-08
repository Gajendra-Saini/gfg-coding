#include <iostream>

using namespace std;

int callme(int n)
{
    if (n == 0)
    {
        return 1;
    }
     callme(n - 1);
    cout << n << endl;
}

int main()
{

    int n = 6;
    cout << "wha ia that " << endl;
    callme(n);
    cout << "this si " << callme(n) << endl;

    return 0;
}