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
		case '1'://ѧ�����
			cm.loginin(STUDENT_FILE, 1);
			break;
		case '2'://��ʦ���
			cm.loginin(TEACHER_FILE, 2);
			break;
		case '3'://����Ա���
			cm.loginin(ADMIN_FILE, 3);
			break;
		case '0'://�˳�ϵͳ
			cm.exit_sys();
			break;
		default://��������������������
			cout << "��������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}