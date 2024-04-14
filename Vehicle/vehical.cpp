#include <iostream>
#include "vehical.h"
using namespace std;
int main()
{
    Vehical data;
    string fileName;
    cout<<"Enter File Name=";
    cin>>fileName;

    int choice;
    do
    {
        cout << "\n\n\n1.Accept Data\n2.Add Data\n3.Read All Data\n4.Find Vehical Based on ID \"Vehical ID\" " << endl;
        cout << "Enter Choice=";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n Enter Vehical Information: " << endl;
            data.accept();
            cout<<"\n"<<endl;
            data.display();
            break;
        case 2:
            cout << "\n\n\nAdding Data..." << endl;
            addData(fileName, data);
            break;
        case 3:
            cout<<"\n\n Total Vehical Data:"<<endl;
            readData(fileName);
            break;
        case 4:
            int ID;
            cout<<"Enter ID=";
            cin>>ID;
            findVehical(fileName,ID);
            break;

        }
    } while (choice != 5);
}