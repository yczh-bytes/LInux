#include "student.h"
#include <iostream>
#include <string>
using namespace std;

student::student(string name,int age)
{
this->name=name;
this->age=age;
}

void student::show()const
{
    cout<<"name:"<<name<<"age:"<<age;
}