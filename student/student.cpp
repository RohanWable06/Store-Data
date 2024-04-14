#include <iostream>
#include "student.h"
using namespace std;
int main()
{
    student s;
    int choice;
    char name[20], city[20];
    int roll_no;
    string fileName;
    cout << "Enter File Name" << endl;
    cin >> fileName;
    do
    {
        cout << "\n\n\n\t1. Enter Student data \n\t2. For add in file \n\t3. Read All File Data \n\t4. Find Student \n\t0. Exit" << endl;
        cout << "Enter choice=" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data" << endl;
            cout << "Name \t Roll No \t City" << endl;
            cin >> name >> roll_no >> city;
            s.accept(name, roll_no, city);

            break;

        case 2:
            int continu;
            cout << "If you want to change file  Enter: 1 otherwise press any no: " << endl;
            cin >> continu;
            if (continu == 1)
            {
                cout << "Enter File Name" << endl;
                cin >> fileName;
            }
            writestudent(fileName, s);
            break;

        case 3:
            cout << "If you want to change file  Enter: 1  otherwise press any no:" << endl;
            cin >> continu;
            if (continu == 1)
            {
                cout << "Enter File Name" << endl;
                cin >> fileName;
            }
            cout << "We are reading students data" << endl;
            readAllstudent(fileName);
            break;
           
        case 4:
             int RollNo;
            cout << "Enter Student Roll no" << endl;
            cin >> RollNo;
            usingRollNo(fileName, RollNo);
            break;
        case 0:
            cout << "Application Terminated !" << endl;
            break;

        default:
            cout << "invalid choice!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}