#include <bits/stdc++.h>

using namespace std;

struct Employee {
    string id;
    string name;
    double hs;
    double Icb;
    double pc;
};

void inputEmployees(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    vector<Employee> employees(10);
    for (int i = 0; i < 10; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> employees[i].id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, employees[i].name);
        cout << "Salary coefficient (hs): ";
        cin >> employees[i].hs;
        cout << "Basic salary (Icb): ";
        cin >> employees[i].Icb;
        cout << "Allowance (pc): ";
        cin >> employees[i].pc;

        outFile << employees[i].id << "," << employees[i].name << ","
                << employees[i].hs << "," << employees[i].Icb << ","
                << employees[i].pc << endl;
    }
    outFile.close();
}

vector<Employee> readEmployees(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return {};
    }

    vector<Employee> employees;
    Employee emp;
    string line;

    while (getline(inFile, line)) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = line.find(',')) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);

        if (tokens.size() == 5) {
            emp.id = tokens[0];
            emp.name = tokens[1];
            emp.hs = stod(tokens[2]);
            emp.Icb = stod(tokens[3]);
            emp.pc = stod(tokens[4]);
            employees.push_back(emp);
        }
    }
    inFile.close();
    return employees;
}

double calculateTotalSalary(const Employee& emp) {
    return emp.Icb * emp.hs + emp.pc;
}

void findMaxMinSalaryEmployee(const vector<Employee>& employees) {
    if (employees.empty()) return;

    double maxSalary = numeric_limits<double>::min();
    double minSalary = numeric_limits<double>::max();
    Employee maxSalaryEmp, minSalaryEmp;

    for (const auto& emp : employees) {
        double totalSalary = calculateTotalSalary(emp);
        if (totalSalary > maxSalary) {
            maxSalary = totalSalary;
            maxSalaryEmp = emp;
        }
        if (totalSalary < minSalary) {
            minSalary = totalSalary;
            minSalaryEmp = emp;
        }
    }

    cout << "Employee with the highest salary: " << endl;
    cout << "ID: " << maxSalaryEmp.id << ", Name: " << maxSalaryEmp.name
         << ", Total Salary: " << maxSalary << endl;

    cout << "Employee with the lowest salary: " << endl;
    cout << "ID: " << minSalaryEmp.id << ", Name: " << minSalaryEmp.name
         << ", Total Salary: " << minSalary << endl;
}

int main() {
    string filename = "NhanVien.txt";
    inputEmployees(filename);
    vector<Employee> employees = readEmployees(filename);

    for (const auto& emp : employees) {
        double totalSalary = calculateTotalSalary(emp);
        cout << "ID: " << emp.id << ", Name: " << emp.name
             << ", Total Salary: " << totalSalary << endl;
    }

    findMaxMinSalaryEmployee(employees);

    return 0;
}
