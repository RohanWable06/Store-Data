#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
// class Date
// {
//     int dd, mm, yy;

// public:
//     Date(int d, int m, int y)
//     {
//         dd = d;
//         mm = m;
//         yy = y;
//     }
//     void display()
//     {
//         cout << " In Date=" << dd << "/" << mm << "/" << yy << endl;
//     }
// };

class Vehical
{

    int n;
    char fueltype[20];
    char VehichalType[20];
    int id;
    char ModelName[20];
    double speed;
    //  int dd, mm, yy;

public:
    void accept()
    {

        cout << "Enter Information=" << endl;
        cout << "Vehical ID \t Name \t Speed \t Vehical Type \t Fuel Type(1. Petrol  2. Disel   3. CNG)" << endl;
        cin >> id >> ModelName >> speed >> VehichalType >> n;
        switch (n)
        {
        case 1:
            strcpy(fueltype, "Petrol");
            break;
        case 2:
            strcpy(fueltype, "Disel");
            break;
        case 3:
            strcpy(fueltype, "CNG");
            break;
        default:
            cout << "Invalid fuel ID" << endl;
            cout << "Enter valid id" << endl;
            exit(0);
        }
    }

    bool find(int ID)
    {
        if(ID==id)
        return 1;
        else {
        return 0;
        }
    }

    void display()
    {
        cout << "\n\nID=" << id << "\t Name=" << ModelName << "\t Speed=" << speed << "\t VehicalType=" << VehichalType << "\t Fuel Type=" << fueltype << endl;
    }
};

//  global function

void addData(string file_name, Vehical obj)
{
    ofstream writeData(file_name, ios::binary | ios::app);
    writeData.write((char *)&obj, sizeof(obj));
    obj.display();
    writeData.close();
    cout << "\n\nData Added Successfully ####" << endl;
}

void readData(string file_name)
{
    Vehical v;
    ifstream readData(file_name);
    readData.read((char *)&v, sizeof(v));
    while (!readData.eof())
    {
        v.display();
        readData.read((char *)&v, sizeof(v));
    }
    readData.close();
}


void findVehical(string file_name,int id)
{
    Vehical v;
    ifstream find(file_name);
    find.read((char*)&v,sizeof(v));
    while (!find.eof())
    {
        if(v.find(id))
        {
            v.display();
            break;
        }
        find.read((char*)&v,sizeof(v));
    }
    
}
