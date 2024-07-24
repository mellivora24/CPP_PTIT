#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    string email;

public:
    string id;
    string classroom;

    Student() {
        id = "";
        name = "";
        classroom = "";
        email = "";
    }

    void GetInformation() {
        getline(cin, id);
        getline(cin, name);
        getline(cin, classroom);
        getline(cin, email);
    }

    void PrintInformation() {
        cout << id << " ";
        cout << name << " ";
        cout << classroom << " ";
        cout << email << endl;
    }
};

bool cmp(Student &A, Student &B) {
    if (A.classroom > B.classroom) return false;
    if (A.classroom < B.classroom) return true;
    if (A.id > B.id) return false;
    return true;
}

int main() {
    int numOfStudent, temp;
    cin >> numOfStudent; cin.ignore();
    temp = numOfStudent;

    Student SV[numOfStudent+1];
    while (numOfStudent--) SV[numOfStudent-1].GetInformation();

    sort(SV, SV+temp, cmp);

    for (int i=0; i<temp; i++) SV[i].PrintInformation();

    return 0;
}