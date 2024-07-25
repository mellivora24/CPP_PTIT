#include <bits/stdc++.h>

using namespace std;

class Staff {
private:
    string staffID;
    string staffName;
    float  basicSalary, subSalary, coeSalary;

public:
    static float sumOfSalary;

    void inputSalary() {
        getline(cin, staffID);
        getline(cin, staffName);
        cin >> coeSalary >> basicSalary >> subSalary;
        cin.ignore();
    }

    static void calcSalary(Staff& employee) {
        sumOfSalary += employee.coeSalary*employee.basicSalary + employee.subSalary;
    }

    friend void printStaffInfor() {
        
    }
};

int main() {


    return 0;
}