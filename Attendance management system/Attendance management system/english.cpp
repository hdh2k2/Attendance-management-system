#include "english.h"

english::english() {

}

english::~english() {

}

void english::run() {
    while (1) {
        system("cls");
        cout << "\n\t Attendance Management System \n";
        cout << "--------------------------------------\n";
        cout << "\n\t 1.Student Login\n";
        cout << "\n\t 2. Admin Login\n";
        cout << "\n\t 0. Exit\n";
        int choice;
        cout << "\n\t Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            student_login();
            break;
        case 2:
            admin_login();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\n\t Are you sure, you want to exit? (Y/N): ";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                {
                    exit(0);
                }
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\n\t Invalid choice!!!";
                    getchar();
                }
            }
            break;

        default:
            cout << "\n\t Invalid choice. Enter again";
            getchar();
        }
    }
}

int english::delay(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 20000; j++){
            for (int k = 0; k < 20000; k++){

            }
        }
    }
    cout << "\n\t Exiting Now.....";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 20000; j++){
            for (int k = 0; k < 20000; k++){

            }
        }

    }

    return 0;
}

int english::admin_view() {
    int goBack = 0;
    while (1) {
        system("cls");
        cout << "\n\t 1 Register a student";
        cout << "\n\t 2 Delete all student name registered";
        cout << "\n\t 3 Delete student by roll number";
        cout << "\n\t 4 Check list of student registered by username";
        cout << "\n\t 5 Check presence count of any student by roll no";
        cout << "\n\t 6 Get list of student with their attendance count";
        cout << "\n\t 0 Go Back <-\n";
        int choice;
        cout << "\n\t Enter your choice: ";
        cin >> choice;

        cout << "\n\t Enter your choice, again: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            register_student();
            break;
        case 2:
            delete_all_students();
            break;
        case 3:
            delete_student_by_rollno();
            break;
        case 4:
            check_list_of_all_students_registered();
            break;
        case 5:
            check_presence_count_by_rollno();
            break;
        case 6:
            get_list_of_students_with_their_presence_count();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again";
            getchar();
        }
        if (goBack == 1){
            break;
        }
    }
    return 0;
}

int english::student_login() {
    system("cls");
    cout << "\n\t----------- Student Login ---------------";
    student_view();
    delay();
    return 0;
}

int english::admin_login() {
    system("cls");
    cout << "\n\t------------ Admin Login -------------";
    string username, password;
    cout << "\n\t Enter username: ";
    cin >> username;
    cout << "\n\t Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin@2") {
        admin_view();
        getchar();
        delay();
    }

    else {
        cout << "\n\t Error! Invalid Credentials....";
        cout << "\n\t Press any key for main menu ";
        getchar();
        getchar();
    }
    return 0;

}

int english::check_students_credentials(string username, string password) {
    ifstream read;
    read.open("db.dat");
    if (read) {
        int recordFound = 0;
        string line;
        string temp = username + password + ".dat";
        cout << "\n\t file name is: " << temp;
        while (getline(read, line)) {
            if (line == temp) {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 0)
            return 0;
        else
            return 1;
    }

    else {
        return 0;
    }

}

int english::get_all_students_by_name() {
    cout << "\n\t list of all students by their name\n";
    cout << "\n\t Please press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::get_all_students_by_rollno() {
    cout << "\n\t List of all students by their roll no\n";
    cout << "\n\t Please press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::delete_student_by_rollno() {
    cout << "\n\t Delete any student by their roll no \n";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::check_presence_count_by_rollno() {
    cout << "\n\t Check presence count of any student by roll no\n";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::check_all_presence_count_by_rollno() {
    cout << "\n\t Check presence count of all student by roll no\n";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::student_view(){
    cout << "-----------Student Login---------";
    string username, password;
    cout << "\n\t Enter username: ";
    cin >> username;
    cout << "\n\t Enter password: ";
    cin >> password;

    int res = check_students_credentials(username, password);
    if (res == 0){
        cout << "\n\t Invalid credentials!!";
        cout << "\n\t Press any key for main menu...";
        getchar();
        getchar();
        return 0;
    }
    int goBack = 0;
    while (1) {
        system("cls");
        cout << "\n\t 1 Marks Attendance for today";
        cout << "\n\t 2 Count My Attendance";
        cout << "\n\t 0. Go Back <-\n";
        int choice;
        cout << "\n\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            mark_my_attendance(username);
            break;
        case 2:
            count_my_attendance(username);
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n\t Invalid choice.. Enter again";
            getchar();
        }
        if (goBack == 1) {
            break;
        }
    }
}

int english::mark_my_attendance(string username) {
    cout << "\n\t Mark attendance for today";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::count_my_attendance(string username){
    cout << "\n\t Count my attendance for today";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::delete_all_students() {
    cout << "\n\t In delete all students!!";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::check_list_of_all_students_registered(){
    cout << "\n\t List of all students registered!! ";
    cout << "\n\t Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::get_list_of_students_with_their_presence_count(){
    cout << "\n\t Check list of student registered by username";
    ifstream read;
    read.open("db.dat");

    if (read){
        int recordFound = 0;
        string line;
        while (getline(read, line)){
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            cout << "\n" << onlyname;
        }
        read.close();
    }
    else{
        cout << "\n\t No Record Found!!";
    }
    cout << "\n\t \ Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int english::register_student(){
    cout << "\n\t -----------Form to Register Student-------------";
    string name, username, password, rollno, address, father, mother;
    cout << "\n\t Enter Name: ";
    cin >> name;
    cout << "\n\t Enter Username: ";
    cin >> username;
    cout << "\n\t Enter password: ";
    cin >> password;
    cout << "\n\t Enter rollno: ";
    cin >> rollno;
    getchar();
    char add[100];
    cout << "\n\t Enter Address: ";
    cin.getline(add, 100);
    cout << "\n\t Enter Father's name: ";
    cin >> father;
    cout << "\n\t Enter Mother's name: ";
    cin >> mother;

    ifstream read;
    read.open("db.dat");
    if (read){
        int recordFound = 0;
        string line;
        while (getline(read, line)){
            if (line == username + ".dat"){
                recordFound == 1;
                break;
            }
        }
        if (recordFound == 1){
            cout << "\n\t Username already registered. Please choose another username";
            getchar();
            getchar();
            delay();
            read.close();
            return 0;
        }
    }

    read.close();
    ofstream out;
    out.open("db.dat", ios::app);
    out << username + ".dat" << "\n";
    out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << name << "\n"; out1 << username << "\n"; out1 << password << "\n";
    out1 << rollno << "\n"; out1 << add << "\n"; out1 << father << "\n";
    out1 << mother << "\n";
    out1.close();

    cout << "\n\t Student Registered successfully!!";
    cout << "\n\t Press any key to continue..";
    getchar();
    getchar();
    return 0;
}

