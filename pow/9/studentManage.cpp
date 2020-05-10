#include <iostream>
#include <cstring>
using namespace std;
int len = 0;
struct student
{
    int ID;
    char name[13];
    int chinese;
    int math;
    int english;
    int total;
};
// if a>b return 1
// if a = b return 0
// if a<b return -1
int compare(student& a,student& b);

// every time add a student, len++
void add(student list[]);
void change(student list[]);

// actually there is no need to sort
// because there could not be two students with the same ID
void searchByID(student list[]);

// find all students whose names are specified and placed them to an array
// use bubble-sort to sort the array and print the information
void searchByName(student list[]);

// use bubble-sort to sort the array
void printByID(student list[]);
void printByTotal(student list[]);
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
    // erase the rest of the istream if not found.
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
int compare(student& a, student& b)
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
