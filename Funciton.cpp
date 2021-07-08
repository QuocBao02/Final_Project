#include "Header.h"
void Color(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
// Toa do 
void gotoxy(int x, int y) {
    HANDLE color;
    color = GetStdHandle;
    COORD coor = { x,y };
    SetConsoleCursorPosition(color, coor);
}
//To mau 
void Paint(int x, int y, string a, int color) {
    gotoxy(x, y);
    Color(color);
    cout << a;
}
// Dem phan tu cua danh sach hoc sinh
int countStu() {
    int count = 0;
    errno_t err;
    FILE* file;
    err = fopen_s(&file, "Students.csv", "r");
    if (file == NULL) {
        return 0;
    }
    else {
        while (!feof(file)) {
            char c;
            c = fgetc(file);
            if (c == ',') count++;
        }
    }
    return count / 8;
}

// chuyen chuoi sang so
int change(string s) {
    int n = s.length();
    int re = 0;
    for (int i = 0; i < n; i++) {
        switch (s[n - 1 - i]) {
        case '0': re += 0 * pow(10, i); break;
        case '1': re += 1 * pow(10, i); break;
        case '2': re += 2 * pow(10, i); break;
        case '3': re += 3 * pow(10, i); break;
        case '4': re += 4 * pow(10, i); break;
        case '5': re += 5 * pow(10, i); break;
        case '6': re += 6 * pow(10, i); break;
        case '7': re += 7 * pow(10, i); break;
        case '8': re += 8 * pow(10, i); break;
        case '9': re += 9 * pow(10, i); break;
        }
    }
    return re;
}
// doc file CSV cua sinh vien
void ReadStudent(Student*& S, int& n) {
    S = new Student[countStu()];
    ifstream file("Students.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
    string line;
    string SNo;
    string SSocialID;
    string SDate;
    string day;
    string month;
    string year;
    int i = 0;
    getline(file, line);
    while (file) {
        getline(file, SNo, ',');
        getline(file, S[i].StuID, ',');
        getline(file, S[i].Fname, ',');
        getline(file, S[i].Lname, ',');
        getline(file, S[i].Gen, ',');
        getline(file, day, '/');
        getline(file, month, '/');
        getline(file, year, ',');
        getline(file, SSocialID, ',');
        getline(file, S[i].Class, ',');
        getline(file, S[i].Pass);

        S[i].No = change(SNo);
        S[i].day = change(day);
        S[i].month = change(month);
        S[i].year = change(year);
        S[i].SocialID = change(SSocialID);
        i++;
    }
    n = i - 1;
    file.close();
}

// Dem phan tu cua danh sach giao vien
int countTech() {
    int count = 0;
    ifstream infile;
    infile.open("Teachers.csv");
    if (!infile.is_open()) {
        return 0;
    }
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, line);
        count++;
    }
    infile.close();
    return count;
}

// doc file CSV cua giao vien
void ReadTeacher(Teacher*& T, int& n) {
    T = new Teacher[countTech()];
    ifstream file("Teachers.csv");
    if (!file.is_open()) {
        cout << "Cannot open file." << endl;
        return;
    }
    string line;
    string SNo;
    string SSocialID;
    int i = 0;
    getline(file, line);
    while (file) {
        getline(file, SNo, ',');
        getline(file, T[i].TeID, ',');
        getline(file, T[i].Fname, ',');
        getline(file, T[i].Lname, ',');
        getline(file, T[i].Gen, ',');
        getline(file, SSocialID, ',');
        getline(file, T[i].Faculty, ',');
        getline(file, T[i].Pass);

        T[i].No = change(SNo);
        T[i].SocialID = change(SSocialID);
        i++;
    }
    n = i - 1;
    file.close();
}
// Xuat toan bo file sinh vien
void PrintStu(Student* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien." << endl;
        cout << "So thu tu: " << S[i].No << endl;
        cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
        cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
        cout << "CMND: " << S[i].SocialID << ". Lop: " << S[i].Class << endl;
    }
}
// Xuat 1 phan tu sinh vien
void PrintElementStu(Student* S, int i) {
    cout << "So thu tu: " << S[i].No << endl;
    cout << "MSSV: " << S[i].StuID << ". Ho ten: " << S[i].Fname << " " << S[i].Lname << endl;
    cout << "Gioi tinh: " << S[i].Gen << ". Nam sinh: " << S[i].day << "/" << S[i].month << "/" << S[i].year << endl;
    cout << "CMND: " << S[i].SocialID << ". Lop: " << S[i].Class << endl;
}

//---------------------------------------------Ma hoa mat khau khi dang nhap---------------------------------------
void encode(string& s) {
    char ch;
    int dem = 0;
    while ((ch = _getch()) != 13) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            cout << "*";
            s[dem++] = ch;

        }
        else
            if (ch == 8)
                if (dem > 0) {
                    cout << "\b \b";
                    dem--;
                }

    }
    s[dem] = 0;
    cout << s << endl;
}
// kiem tra tai khoan dang nhap sinh vien
bool CheckPassStu(Student* S, int n, int& pos, string user, string Pass) {
    for (int i = 0; i < n; i++) {
        pos = i;
        if (S[i].StuID == user && S[i].Pass == Pass)
            return true;
    }
    return false;
}

// kiem tra tai khoan dang nhap giao vien
bool CheckPassTech(Teacher* T, int m, int& pos, string user, string Pass) {
    for (int i = 0; i < m; i++) {
        pos = i;
        if (T[i].TeID == user && T[i].Pass == Pass)
            return true;
    }
    return false;
}

// Xuat toan bo file giao vien
void PrintTech(Teacher* T, int m) {
    for (int i = 0; i < m; i++) {
        cout << "Giao vien." << endl;
        cout << "So thu tu: " << T[i].No << endl;
        cout << "MSGV: " << T[i].TeID << ". Ho ten: " << T[i].Fname << " " << T[i].Lname << endl;
        cout << "Gioi tinh: " << T[i].Gen << ". CMND: " << T[i].SocialID << ". Khoa: " << T[i].Faculty << endl;
    }
}
// Xuat 1 phan tu giao vien
void PrintElementTech(Teacher* T, int i) {
    cout << "Giao vien." << endl;
    cout << "So thu tu: " << T[i].No << endl;
    cout << "MSGV: " << T[i].TeID << ". Ho ten: " << T[i].Fname << " " << T[i].Lname << endl;
    cout << "Gioi tinh: " << T[i].Gen << ". CMND: " << T[i].SocialID << ". Khoa: " << T[i].Faculty << endl;
}
// Dinh dang
void Format(string s) {
    system("cls");
    Color(14);
    cout << "\n\t\t\t ****************************" << endl;
    cout << "\t\t\t\t      ";
    Color(10);
    cout << s << endl;
    Color(14);
    cout << "\t\t\t ****************************" << endl;
}

// Nhap du lieu vao
void input(string& user, string& pass) {
    Paint(15, 20, "ID of User: ", 10);
    getline(cin, user);
    Paint(15, 20, "Password: ", 10);
    getline(cin, pass);
}
// cap nhat thong tin ca nhan giao vien
void UpdateInforTeach(Teacher*& T, int m, string ID) {
    Teacher Temp;
    Format("Update information");
    cin.ignore();
    cout << "+ Please, Input your personal information." << endl;
    cout << "Your ID: ";
    getline(cin, Temp.TeID);
    cout << "Your First name: ";
    getline(cin, Temp.Fname);
    cout << "Your Last name: ";
    getline(cin, Temp.Lname);
    cout << "Your Gender: ";
    getline(cin, Temp.Gen);
    cout << "Your Faculty: ";
    getline(cin, Temp.Faculty);
    cout << "Your Social id: ";
    cin >> Temp.SocialID;
    for (int i = 0; i < m; i++) {
        if (T[i].TeID == ID) {
            T[i].TeID = Temp.TeID;
            T[i].Fname = Temp.Fname;
            T[i].Lname = Temp.Lname;
            T[i].Gen = Temp.Gen;
            T[i].Faculty = Temp.Faculty;
            T[i].SocialID = Temp.SocialID;
        }
    }
}

void changepass(Teacher*& T, int m, string ID)
{
    Teacher Temp;
    cin.ignore();
    Paint(15, 20, "Enter your old password: ", 10);
    getline(cin, Temp.Pass);
    for (int i = 0; i < m; i++)
        if (T[i].TeID == ID)
        {
            if (Temp.Pass == T[i].Pass) {
                Paint(15, 20, "Enter new password: ", 10);
                getline(cin, Temp.Pass);
                T[i].Pass = Temp.Pass;
            }
            else {
                cout << "Your password is wrong.\n";
            }
        }
}

// ghi lai file sau khi cap nhap
void WriteAfterUdateTeach(Teacher* T, int m) {
    ofstream outfile;
    outfile.open("Teacher1.csv");
    if (!outfile.is_open()) {
        cout << "Can not open file" << endl;
        return;
    }
    outfile << "No" << "," << "Teacher ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Social ID" << "," << "Faculty" << "," << "Password" << endl;
    for (int i = 0; i < m; i++) {
        outfile << T[i].No << "," << T[i].TeID << "," << T[i].Fname << "," << T[i].Lname << "," << T[i].Gen << "," << T[i].SocialID << "," << T[i].Faculty << "," << T[i].Pass << endl;
    }
    outfile.close();
}
// Dem phan tu cua danh sach khoa hoc
int countCourses() {
    int count = 0;
    ifstream infile;
    infile.open("course.csv");
    if (!infile.is_open()) {
        return 0;
    }
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, line);
        count++;
    }
    infile.close();
    return count;
}

// doc file courses
void ReadCourses(Courses*& C, int& t) {
    t = countCourses();
    C = new Courses[t];
    ifstream infile;
    infile.open("course.csv");
    if (!infile.is_open()) {
        return;
    }
    int i = 0;
    string line;
    getline(infile, line);
    while (infile) {
        getline(infile, C[i].ID, ',');
        getline(infile, C[i].CName, ',');
        getline(infile, C[i].TName, ',');
        string tempCredit;
        getline(infile, tempCredit, ',');
        C[i].Credits = change(tempCredit);
        string tempMax;
        getline(infile, tempMax, ',');
        C[i].MaxMem = change(tempMax);
        string tempday1;
        getline(infile, tempday1, ',');
        C[i].day1 = change(tempday1);
        getline(infile, C[i].session1, ',');
        string tempday2;
        getline(infile, tempday2, ',');
        C[i].day2 = change(tempday2);
        getline(infile, C[i].session2, ',');
        string tempdaystart;
        getline(infile, tempdaystart, '/');
        C[i].daystart = change(tempdaystart);
        string tempmonthstart;
        getline(infile, tempmonthstart, ',');
        C[i].monthstart = change(tempmonthstart);
        string tempdayend;
        getline(infile, tempdayend, '/');
        C[i].dayend = change(tempdayend);
        string tempmonthend;
        getline(infile, tempmonthend);
        C[i].monthend = change(tempmonthend);

        i++;
    }
    t -= 1;
    infile.close();
}

void PrintCourses(Courses* C, int t) {
    for (int i = 0; i < t; i++) {
        cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName << endl;
    }
}

bool CheckTimeInput(int day, int month) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
        if (day > 31 || day < 1)
            return false;
    } break;
    case 4:
    case 6:
    case 9:
    case 11: {
        if (day > 30 || day < 1)
            return false;
    } break;
    case 2: {
        if (day > 39 || day < 1)
            return false;
    } break;
    }
    return true;
}


bool checkdate(Courses* C, int i, int day, int month) {
    if (month > C[i].monthstart && month < C[i].monthend) {
        return true;
    }
    else {
        if (month == C[i].monthstart) {
            if (day >= C[i].daystart)
                return true;
            else
                return false;
        }
        if (month == C[i].monthend) {
            if (day <= C[i].dayend)
                return true;
            else
                return false;
        }
    }
    return false;
}
void registerCourses(Courses* C, int t)
{
    int day = 0, month = 0, option = 0;
    cout << "Enter Current time to register Course" << endl;
    do {
        cout << "Day: "; cin >> day;
        cout << "Month: "; cin >> month;
    } while (CheckTimeInput(day, month) == false);
    bool check = true;
    while (check)
    {
        system("cls");
        Format("\tCourses Registration");
        cout << "\n\t1. View list of courses";
        cout << "\n\t2. Create a new course";
        cout << "\n\t3. Update course's information";
        cout << "\n\t4. Delete a course";
        cout << "\n\t0. Back forward";
        cout << "\n\t**************************************";
        cout << "\n\t Choose the option you wanna do: "; cin >> option;
        while ((option < 0) || (option > 4))
        {
            cout << "The number you enter isn't suitble\nPlease choose it again: "; cin >> option;
        }
        switch (option)
        {
        case 1:
        {
            cout << "\t List of courses existing: \n";
            cout << "Current Time: " << day << "/" << month << endl;
            for (int i = 0; i < t; i++) {
                if (checkdate(C, i, day, month)) {
                    cout << "Course ID: " << C[i].ID << ", Course Name: " << C[i].CName <<", Time start: " << C[i].daystart <<"/" << C[i].monthstart << ", Time end: " <<
                        C[i].dayend << "/" << C[i].monthend <<endl;
                }
            }
            system("pause");
        }break;
        case 2:
        {

        }break;
        case 3:
        {

        }break;
        case 4:
        {

        }break;
        case 0:
        {
            check = false;
        } break;
        }
    }
}