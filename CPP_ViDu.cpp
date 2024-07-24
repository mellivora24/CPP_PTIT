#include <bits/stdc++.h>

#include <utility>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string address;
    int score;

public:
    Student() : id(0), age(0), score(0) {}
    Student(int id, const string& name, int age, const string& address, int score) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->address = address;
        this->score = score;
    }

    void setID(int id) { this->id = id; }
    void setName(const string& name) { this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setAddress(const string& address) {
        this->address = address;
    }
    void setScore(int score) {
        this->score = score;
    }

    // Getters
    int getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    string getAddress() const {
        return address;
    }
    int getScore() const {
        return score;
    }
};

