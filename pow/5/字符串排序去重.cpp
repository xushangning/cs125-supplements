#include <iostream>

using namespace std;

int main()
{
    bool count[128] = {};   // initialize the array to all 0s/false
    char c;
    // cin.get(c) returns cin, which evaluates to false on EOF
    while (cin.get(c))
        count[c] = true;

    // If the range of elements to be sorted is small, counting sort should be
    // your first choice.
    //
    // The idea is simple: count[i] records the number of times i appears in 
    // the array. To output sorted values, just iterate over the array and
    // print i for count[i] times.
    //
    // Since we wish to remove duplicates, count is just a bool array that
    // records the appearance of i.
    for (int i = 127; i >= 0; --i)
        if (count[i])
            cout << static_cast<char>(i);
    cout << '\n';
    return 0
}
