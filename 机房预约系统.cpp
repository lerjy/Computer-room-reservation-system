#include<iostream>
using namespace std;
#include"computermanager.h"

int main() {
	C_manager cm;
	char select;
	while (1) {
		cm.show_menu();
		//Identity* person = NULL;
		cin >> select;
		switch (select) {
		case '1'://学生身份
			cm.loginin(STUDENT_FILE, 1);
			break;
		case '2'://老师身份
			cm.loginin(TEACHER_FILE, 2);
			break;
		case '3'://管理员身份
			cm.loginin(ADMIN_FILE, 3);
			break;
		case '0'://退出系统
			cm.exit_sys();
			break;
		default://输入有误清屏重新输入
			cout << "输入有误!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}