#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class student
{
private:
string name;
int age;

public:
student(string name,int age);
void show()const;
};
#endif