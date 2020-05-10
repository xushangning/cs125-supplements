#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_
struct student
{
    int ID;
    char name[13];
    int chinese;
    int math;
    int english;
    int total;
};
int compare(student a,student b);
void add(student list[]);
void change(student list[]);
void searchByID(student list[]);
void searchByName(student list[]);
void printByID(student list[]);
void printByTotal(student list[]);
#endif