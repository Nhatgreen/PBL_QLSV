#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    string sex;
    string date;
    string cohort;
    string major;
    string ID;
    string Email;
};

void nhapThongTin(Student &student) {
    cout << "----- Enter Student Information -----" << endl;

    cout << "Enter student name: ";
    getline(cin, student.name);

    cout << "Enter student sex: ";
    getline(cin, student.sex);

    cout << "Enter student date of birth: ";
    getline(cin, student.date);

    cout << "Enter student cohort: ";
    getline(cin, student.cohort);

    cout << "Enter major: ";
    getline(cin, student.major);
}

void luuSinhVien(const Student &student) {
    string className = student.major + student.cohort;
    ofstream outFile(className + ".txt", ios::app);

    if (!outFile) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    outFile << student.name << "|"
            << student.sex << "|"
            << student.date << "|"
            << student.cohort << "|"
            << student.major << endl;

    outFile.close();
    cout << "Student information saved to " << className << ".txt" << endl;
}

void nhapThongTinVaLuu() {
    Student student;
    nhapThongTin(student);
    luuSinhVien(student); 
}
int main() {
    nhapThongTinVaLuu();
    return 0;
}
