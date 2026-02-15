#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string Name;
    int Age;
public:
    Student(string name, int age) {
        Name = name;
        Age = age;
    }
    void setAge(int age) {
        Age = age;
    }
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    int getAge() {
        return Age;
    }
    void printStudentInfo() {
        cout<<"Student "<<Name<<" Age "<<Age<<endl;
    }
};

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            string name;
            int age;
            cout<<"Student name ?"<<endl;
            cin>>name;
            cout <<"Student age ?"<< endl;
            cin >> age;
            Student newStudent(name,age);
            studentList.push_back(newStudent);
            break;
        }
        case 1:
        {
            for(int i=0;i<studentList.size();i++)
            {
                studentList[i].printStudentInfo();
            }
            break;
        }
        case 2:
        {
            sort(studentList.begin(), studentList.end(), [](Student a, Student b)
                 {
                     return a.getName() < b.getName();
                 });

            for (Student &s : studentList) {
                s.printStudentInfo();
            }
            break;
        }
        case 3:
        {
            sort(studentList.begin(), studentList.end(), [](Student a, Student b) {
                return a.getAge() < b.getAge();
            });
            for(int i=0; i < studentList.size(); i++) {
                studentList[i].printStudentInfo();
            }
            break;
        }
        case 4:
        {
            string searchName;
            cout <<"Student to be found name = ?" <<endl;
            cin>>searchName;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [searchName](Student s) {
                                  return s.getName() == searchName;
                              });
            if(it != studentList.end())
            {
                cout<<"Student found:"<<endl;
                it->printStudentInfo();
            }
            else
            {
                cout <<"Student not found."<<endl;
            }
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }
    while(selection < 5);

    return 0;
}
