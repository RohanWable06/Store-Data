#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class student
{
public:
    int roll_no;
    char name[20];
    char city[20];

    void accept(char *name, int rollNo, char *city)
    {
        this->roll_no = rollNo;
        strcpy(this->name, name);
        strcpy(this->city, city);
    }
    void display()
    {
        cout << "\t Roll No=" << roll_no << "\t name=" << name << "\t City=" << city << endl;
    }
    bool find_sutdent(student &obj, int rollNo)
    {
        if (obj.roll_no == rollNo)
            return 1;
        else
            return 0;
    }
   
};

void writestudent(string name, student &obj)
{
    ofstream datastud(name, ios::binary | ios::app);

    datastud.write((char *)&obj, sizeof(student));
    cout << "-------Data entered-------" << endl;

    datastud.close();
}

void readAllstudent(string name)
{
    student s1;
    ifstream readstud(name, ios::binary);
    readstud.read((char *)&s1, sizeof(student));
    while (!readstud.eof())
    {
        s1.display();
        readstud.read((char *)&s1, sizeof(student));
    }
    readstud.close();
}

void readSingleStudent(string name)
{
    student s1;
    ifstream readstd(name);
    // readstd.read((char*)&s1,sizeof(s1));
    if (readstd)
    {
        readstd.read((char *)&s1, sizeof(s1));
        s1.display();
    }

    readstd.close();
}

void usingRollNo(string name, int roll_no)
{
    
    student s1;// = new student();
    ifstream readstud(name, ios::binary);
    readstud.read((char *)&s1, sizeof(student));
    // s1.display();
    while (!readstud.eof())
    {
        
           if(s1.find_sutdent(s1,roll_no))
           {
                cout << " Yes ";
                s1.display();
                break;
           }
        
        readstud.read((char *)&s1, sizeof(student));
    }
    readstud.close();
}