#include <iostream>
#include <cstring>
#include "management.h"

using namespace std;
extern int len;
void searchByID(student * list)
{
    int id;
    cin >> id;
    student temp[len];
    int j = 0;
    bool flag = false;
    for (int i = 0;i<len;i++)
    {
        if (list[i].ID == id)
        {
            flag = true;
            temp[j++] = list[i];
        }
    }
    if (!flag){
        cout << "Not found." << endl;
        return;
    }
    else{
        for (int a = 0;a<j;a++)
        {
            for (int b = 0;b<j-1-a;b++)
            {
                if (temp[b].ID>temp[b+1].ID){
                    auto t = temp[b];
                    temp[b] = temp[b+1];
                    temp[b+1] = t;
                }
            }
        }
        for (int a = 0;a<j;a++)
        {
            cout.width(4);
            cout << temp[a].ID;
            cout.width(16);
            cout << temp[a].name;
            cout.width(4);
            cout << temp[a].chinese;
            cout.width(4);
            cout << temp[a].math;
            cout.width(4);
            cout << temp[a].english;
            cout << endl;
        }
    }
}
void searchByName(student * list)
{
    int i;
    char test[13];
    cin >> test;
    int j = 0;
    bool flag = false;
    student temp[len];
    for (i = 0;i<len;i++)
    {
        if (strcmp(list[i].name,test) == 0){
            flag = true;
            temp[j++] = list[i];
        }
    }
    if (!flag){
        cout << "Not found." << endl;
        return;
    }
    else{
        for (int a = 0;a<j;a++)
        {
            for (int b = 0;b<j-1-a;b++)
            {
                if (temp[b].ID>temp[b+1].ID){
                    auto t = temp[b];
                    temp[b] = temp[b+1];
                    temp[b+1] = t;
                }
            }
        }
        for (int a = 0;a<j;a++)
        {
            cout.width(4);
            cout << temp[a].ID;
            cout.width(16);
            cout << temp[a].name;
            cout.width(4);
            cout << temp[a].chinese;
            cout.width(4);
            cout << temp[a].math;
            cout.width(4);
            cout << temp[a].english;
            cout << endl;
        }
    }
}