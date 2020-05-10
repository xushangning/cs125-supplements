#include <iostream>
#include "management.h"

using namespace std;
extern int len;
void printByID(student * list)
{
    int i,j;
    for (i = 0;i<len;i++)
    {
        for (j = 0;j<len-1-i;j++)
        {
            if (list[j].ID>list[j+1].ID){
                auto t = list[j];
                list[j] = list[j+1];
                list[j+1] = t;
            }
        }
    }
    for (i = 0;i<len;i++)
    {
        cout.width(4);
        cout << list[i].ID;
        cout.width(16);
        cout << list[i].name;
        cout.width(4);
        cout << list[i].chinese;
        cout.width(4);
        cout << list[i].math;
        cout.width(4);
        cout << list[i].english;
        cout << endl;
    }
}
void printByTotal(student * list)
{
    int i,j;
    for (i = 0;i<len;i++) list[i].total = list[i].chinese+list[i].math+list[i].english;
    for (int i = 0;i<len;i++)
    {
        for (int j = 0;j<len-1-i;j++)
        {
            if (compare(list[j],list[j+1])<0){
                auto t = list[j];
                list[j] = list[j+1];
                list[j+1] = t;
            }
        }
    }
    for (i = 0;i<len;i++)
    {
        cout.width(4);
        cout << list[i].ID;
        cout.width(16);
        cout << list[i].name;
        cout.width(4);
        cout << list[i].chinese;
        cout.width(4);
        cout << list[i].math;
        cout.width(4);
        cout << list[i].english;
        cout << endl;
    }
}
int compare(student a, student b)
{
    if (a.total>b.total) return 1;
    else if (a.total<b.total) return -1;
    else
    {
        if (a.ID>b.ID) {
            return -1;
        }
        else if (a.ID<b.ID) {
            return 1;
        }
    }
    return 1;
}
