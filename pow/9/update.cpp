#include "management.h"
#include <iostream>
extern int len;
using namespace std;
void change(student * list)
{
    int id;
    cin >> id;
    bool flag = false;
    for (int i = 0;i<len;i++)
    {
        if (list[i].ID == id){
            flag = true;
            char op[3];
            cin >> op;
            switch (op[0])
            {
            case 'N':
            cin >> list[i].name;
            break;
            case 'C':
            cin >> list[i].chinese;
            break;
            case 'M':
            cin >> list[i].math;
            break;
            case 'E':
            cin >> list[i].english;
            break;
            case 'I':
            cin >> list[i].ID;
            break;
            }
            break;
        }
    }
    if (!flag){
        cout << "Not found." << endl;
        char ch;
        cin.get(ch);
        while (ch!='\n'){
            cin.get(ch);
        }
        return;
    }
}