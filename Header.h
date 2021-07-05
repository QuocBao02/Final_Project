#ifndef Header_h
#define Header_h
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <string.h>
#include <cmath>
#include <time.h>
using namespace std;
struct Teacher {
    int No;// so thu tu
    string TeID;
    string Fname;
    string Lname;
    string Gen;
    int SocialID; // CMND
    string Faculty;
    string Pass;
};

struct Student {
    int No;
    string StuID;
    string Fname;
    string Lname;
    string Gen;
    int day, month, year;
    int SocialID;
    string Class;
    string Pass;
};

struct Cours {

};
void Color(int i);
void gotoxy(int x, int y);
void Paint(int x, int y, string a, int color);
int change(string s);


int countStu();
void ReadStudent(Student*& S, int& n);
void PrintStu(Student* S, int n);
void PrintElementStu(Student* S, int i);


int countTech();
void ReadTeacher(Teacher*& T, int& n);
void PrintTech(Teacher* T, int m);
void PrintElementTech(Teacher* T, int i);


void encode(string& s);


bool CheckPassTech(Teacher* T, int m, int& pos, string user, string Pass);
bool CheckPassStu(Student* S, int n, int& pos, string user, string Pass);

// Cap nhat thong tin giao vien
void UpdateInforTeach(Teacher*& T, int m, string ID);
void WriteAfterUdateTeach(Teacher* T, int m);

void Format();
void input(string& user, string& pass);
// Doc file CSV va luu vao cau truc 







#endif
