#include <iostream>
#include "management.h"

using std::cin;
int len = 0;
int main()
{
    int T;
    cin >> T;
    student * list = new student[T];
    for (int i = 0;i<T;i++)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        add(list);
        break;
        case 2:
        change(list);
        break;
        case 3:
        searchByID(list);
        break;
        case 4:
        searchByName(list);
        break;
        case 5:
        printByID(list);
        break;
        case 6:
        printByTotal(list);
        break;
        }
    }
    delete [] list;
    return 0;
}