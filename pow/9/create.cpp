#include "management.h"
#include <iostream>
using namespace std;

extern int len;
void add(student * list)
{

    student temp;
    cin >> temp.ID >> temp.name >> temp.chinese >> temp.math >> temp.english;
    for (int i = 0;i<len;i++)
    {
        if (list[i].ID == temp.ID){
            cout << "Duplicate detected." << endl;
            return;
        }
    }
    len++;
    list[len-1] = temp;
}