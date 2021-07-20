#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class english{
private:
	int check_students_credentials(string username, string password);
	int check_all_presence_count_by_rollno();
	int get_all_students_by_name();
	int admin_view();
	int student_view();
	int student_login();
	int check_credentials(string username, string password);
	int get_all_students_by_rollno();
	int delete_all_students();
	int delete_student_by_rollno();
	int check_list_of_students_registered();
	int check_list_of_all_students_registered();
	int check_presence_count_by_rollno();
	int get_list_of_students_with_their_presence_count();
	int admin_login();
	int register_student();
	int mark_my_attendance(string username);
	int count_my_attendance(string username);
	int delay();
public:
	void run();
	english();
	~english();
};

