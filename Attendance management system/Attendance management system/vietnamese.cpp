#include "vietnamese.h"

vietnamese::vietnamese() {

}

vietnamese::~vietnamese() {

}

void vietnamese::run() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    while (1) {
        system("cls");
        wcout << L"\n\t Hệ thống quản lý điểm danh \n";
        wcout << "--------------------------------------\n";
        wcout << L"\n\t 1. Đăng nhập ở chế độ sinh viên\n";
        wcout << L"\n\t 2. Đăng nhập ở chế độ Admin\n";
        wcout << L"\n\t 0. Thoát\n";
        int choice;
        wcout << L"\n\t Mời bạn nhập lựa chọn: ";
        wcin >> choice;

        switch (choice){
        case 1:
            student_login();
            break;
        case 2:
            admin_login();
            break;
        case 0:
            while (1){
                system("cls");
                wcout << L"\n\t Bạn có muốn thoát chương trình không? (Y/N): ";
                wstring ex;
                wcin >> ex;
                if (ex == L"y" || ex == L"Y") {
                    exit(0);
                }
                else if (ex == L"n" || ex == L"N") {
                    break;
                }
                else{
                    wcout << L"\n\t Lựa chọn không hợp lệ !!!";
                    wcin.ignore();
                }
            }
            break;

        default:
            wcout << L"\n\t Lựa chọn không hợp lệ. Mời bạn nhập lại !!!";
            wcin.ignore();
        }
    }
}

int vietnamese::delay() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20000; j++) {
            for (int k = 0; k < 20000; k++) {

            }
        }
    }
    wcout << L"\n\t Đang thoát...";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20000; j++) {
            for (int k = 0; k < 20000; k++) {

            }
        }

    }

    return 0;
}

int vietnamese::admin_view() {
    int goBack = 0;
    while (1) {
        system("cls");
        wcout << L"\n\t 1 Đăng kí sinh viên";
        wcout << L"\n\t 2 Xóa tất cả sinh viên đã đăng kí";
        wcout << L"\n\t 3 Xóa sinh viên lần lượt";
        wcout << L"\n\t 4 Kiểm tra danh sách sinh viên đã đăng kí theo mã số sinh viên (username)";
        wcout << L"\n\t 5 Kiểm tra số lượng hiện diện của bất kỳ sinh viên nào theo danh sách";
        wcout << L"\n\t 6 Nhận danh sách sinh viên với số điểm tham dự của họ";
        wcout << L"\n\t 0 Quay lại <-\n";
        int choice;
        wcout << L"\n\t Nhập lựa chọn: ";
        wcin >> choice;

        wcout << L"\n\t Nhập lựa chọn một lần nữa để chắc chắn hơn: ";
        wcin >> choice;

        switch (choice){
            cin.ignore();
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
            wcout << L"\n Lựa chọn không hợp lệ. Mời bạn nhập lại !!!";
            getchar();
        }
        if (goBack == 1) {
            break;
        }
    }
    return 0;
}

int vietnamese::student_login() {
    system("cls");
    wcout << L"\n\t === Đăng nhập với tư cách sinh viên === ";
    student_view();
    delay();
    return 0;
}

int vietnamese::admin_login() {
    system("cls");
    wcout << L"\n\t === Đăng nhập với tư cách Admin  === ";
    wstring username, password;
    wcout << L"\n\t Nhập tên người dùng: ";
    wcin >> username;
    wcout << L"\n\t Nhập mật khẩu: ";
    wcin >> password;

    if (username == L"admin" && password == L"admin") {
        admin_view();
        //getchar();
        delay();
    }

    else {
        wcout << L"\n\t Lỗi, thông tin không hợp lệ...";
        wcout << L"\n\t Nhấn phím bất kì để quay lại menu ";
        wcin.ignore();
    }

    return 0;

}

int vietnamese::check_students_credentials(wstring username, wstring password) {
    wifstream read;
    read.open("db.dat");
    if (read) {
        int recordFound = 0;
        wstring line;
        wstring temp = username + password + L".dat";
        wcout << L"\n\t Tên file là: " << temp;
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

int vietnamese::get_all_students_by_name() {
    wcout << L"\n\t Danh sách tất cả sinh viên theo tên của họ\n";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::get_all_students_by_rollno() {
    wcout << L"\n\t Danh sách tất cả sinh viên theo danh sách của họ\n";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::delete_student_by_rollno() {
    wcout << L"\n\t Xóa bất kỳ sinh viên nào theo danh sách của họ \n";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::check_presence_count_by_rollno() {
    wcout << L"\n\t Kiểm tra số lượng hiện diện của bất kỳ sinh viên nào theo danh sách\n";
    wcout << L"\n\t Nhấn 2 lần phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::check_all_presence_count_by_rollno() {
    wcout << L"\n\t Kiểm tra số lượng hiện diện của tất cả sinh viên theo danh sách\n";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::student_view() {
    wcout << L" === Đăng nhập với tư cách sinh viên === ";
    wstring username, password;
    wcout << L"\n\t Nhập mã số sinh viên (tên người dùng): ";
    wcin >> username;
    wcout << L"\n\t Nhập mật khẩu do trường cấp: ";
    wcin >> password;

    int res = check_students_credentials(username, password);
    if (res == 0) {
        wcout << L"\n\t Thông tin không hợp lệ!!!";
        wcout << L"\n\t Nhấn phím bất kì để quay lại menu...";
        wcin.ignore();
        return 0;
    }
    int goBack = 0;
    while (1) {
        system("cls");
        wcout << L"\n\t 1 Đánh dấu điểm danh cho ngày hôm nay";
        wcout << L"\n\t 2 Đếm số lần điểm danh của tôi";
        wcout << L"\n\t 0. Quay lại <-\n";
        int choice;
        wcout << L"\n\t Nhập lựa chọn: ";
        wcin >> choice;

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
            wcout << L"\n\t Lựa chọn không hợp lệ, mời bạn nhập lại !!!";
            wcin.ignore();
        }
        if (goBack == 1) {
            break;
        }
    }
}

int vietnamese::mark_my_attendance(wstring username) {
    wcout << L"\n\t Đánh dấu điểm danh cho ngày hôm nay";
    wcout << L"\n\t Nhấn lần phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::count_my_attendance(wstring username) {
    wcout << L"\n\t Đếm số lần điểm danh của tôi";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::delete_all_students() {
    wcout << L"\n\t Đang xóa tất cả sinh viên !!!";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::check_list_of_all_students_registered() {
    wcout << L"\n\t Danh sách tất cả sinh viên đã đăng ký !!! ";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::get_list_of_students_with_their_presence_count() {
    wcout << L"\n\t Kiểm tra danh sách sinh viên đã đăng ký bằng mã số sinh viên, tên người dùng";
    ifstream read;
    read.open("db.dat");

    if (read) {
        int recordFound = 0;
        string line;
        while (getline(read, line)) {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            cout << "\n" << onlyname;
        }
        read.close();
    }
    else {
        wcout << L"\n\t Không tìm thấy bản ghi!!";
    }
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

int vietnamese::register_student() {
    wcin.ignore();
    wcout << L"\n\t === Biểu mẫu đăng ký sinh viên ===";
    wstring name, username, password, rollno, address, father, mother;
    wcout << L"\n\t Nhập họ tên: ";
    getline(wcin, name);
    wcout << L"\n\t Nhập tên người dùng: ";
    wcin >> username;
    wcout << L"\n\t Nhập mật khẩu: ";
    wcin >> password;
    wcout << L"\n\t Nhập rollno: ";
    wcin >> rollno;
    wcin.ignore();
    wchar_t add[100];
    wcout << L"\n\t Nhập địa chỉ: ";
    wcin.getline(add, 100);
    wcout << L"\n\t Nhập họ tên cha: ";
    getline(wcin, father);
    wcout << L"\n\t Nhập họ tên mẹ: ";
    getline(wcin, mother);

    wifstream read;
    read.open("db.dat");
    if (read) {
        int recordFound = 0;
        wstring line;
        while (getline(read, line)) {
            if (line == username + L".dat") {
                recordFound == 1;
                break;
            }
        }
        if (recordFound == 1) {
            wcout << L"\n\t Tên người dùng đã đăng ký. Hãy chọn một tên người dùng khác";
            wcin.ignore();
            delay();
            read.close();
            return 0;
        }
    }

    read.close();
    wofstream out;
    out.open("db.dat", ios::app);
    out << username + L".dat" << "\n";
    out.close();

    wofstream out1;
    wstring temp = username + L".dat";
    out1.open(temp.c_str());
    out1 << name << "\n"; out1 << username << "\n"; out1 << password << "\n";
    out1 << rollno << "\n"; out1 << add << "\n"; out1 << father << "\n";
    out1 << mother << "\n";
    out1.close();

    wcout << L"\n\t Sinh viên đã đăng ký thành công!!";
    wcout << L"\n\t Nhấn phím bất kì để tiếp tục...";
    wcin.ignore();
    return 0;
}

