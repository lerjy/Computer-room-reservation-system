#include"computermanager.h"

//���캯��
C_manager::C_manager() {

}

//��ӡ��ɫѡ��˵�
void C_manager::show_menu() {
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << endl << "������������ݣ�";
}

//��¼����
void C_manager::loginin(string Filename, int type) {
	//����ָ�룬����ָ������
	//Identity* person = NULL;

	//�򿪶�Ӧ�ļ�
	ifstream ifs(Filename, ios::in);

	//�ж��ļ��Ƿ��
	if (ifs.is_open()) {
		string name;
		string pwd;
		int id = 0;
		if (type == 1) {
			//ѧ�����
			cout << "���������ѧ�ţ�";
			cin >> id;
		}
		else if (type == 2) {
			//��ʦ���
			cout << "���������ְ����ţ�";
			cin >> id;
		}
		else {
			//����Ա���
		}
		cout << "���������������";
		cin >> name;
		cout << "������������룺";
		cin >> pwd;

		//ɨ���ļ���Ϣ
		string fname;
		string fpwd;
		int fid;

		if (type != 3) {
			//�жϽ�ɫ��¼
			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					ifs.close();
				}
			}
			if (type == 1) {
				//ѧ����¼
				//��½�����
				system("cls");
				this->person = new Student(fid, fname, fpwd);
				//system("pause");
				this->student(this->person);
				return;
			}
			else if (type == 2) {
				//��ʦ��¼
				//��½�����
				system("cls");
				this->person = new Teacher(fid, fname, fpwd);
				this->teacher(this->person);
				//system("pause");
				return;
			}
		}

		else {
			//����Ա��¼
			while (ifs >> fname && ifs >> fpwd) {
				if (name == fname && pwd == fpwd) {
					cout << "��֤��¼�ɹ���" << endl;
					ifs.close();
					//��½�����
					system("cls");
					this->person = new Manager(fname, fpwd);
					this->admin(this->person);
					//system("pause");

					return;
				}
			}
		}
		cout << "��֤��¼ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		ifs.close();
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
	}
}

//����Ա��������
void C_manager::admin(Identity*& manager) {
	//���ڽ����û�����
	int select = 0;
	while (1) {
		//��ӡ����Ա�˵�
		manager->I_menu();
		Manager* man = (Manager*)manager;
		cin >> select;
		if (select == 1) {
			//����˺�
			man->addacount();
		}
		else if (select == 2) {
			//�鿴�˺�
			man->showacount();
		}
		else if (select == 3) {
			//�鿴����
			man->showinfo();
		}
		else if (select == 4) {
			//���ԤԼ
			man->allorder();
		}
		else if (select == 0) {
			//ע����¼
			break;
		}
		else {
			cout << "��������";
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

//ѧ����������
void C_manager::student(Identity*& student) {

	//��¼����
	int select = 0;
	//��ʼ��ѧ������
	Student* stu = (Student*)student;
	while (1) {
		stu->I_menu();
		cin >> select;
		switch (select) {
		case 1:
			stu->applyorder();
			break;
		case 2:
			stu->myorder();
			break;
		case 3:
			stu->allorder();
			break;
		case 4:
			stu->celorder();
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�";
			system("pause");
			system("cls");
			return;
		default:
			cout << "��������";
			break;
		}
		system("pause");
		system("cls");
	}
}

//��ʦ��������
void C_manager::teacher(Identity*& teacher) {
	//���ڽ����û�����
	int select = 0;
	while (1) {
		//��ӡ��ʦ�˵�
		teacher->I_menu();
		Teacher* man = (Teacher*)teacher;
		cin >> select;
		if (select == 1) {
			//�鿴����ԤԼ
			man->allorder();
		}
		else if (select == 2) {
			//���ԤԼ
			man->validorder();
		}
		else if (select == 0) {
			//ע����¼
			break;
		}
		else {
			cout << "��������";
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


////��¼��ɫ
//template<class T>
//void C_manager::perlogin() {
//	this->person = new T();
//}
//
//Identity* C_manager::getperson() {
//	return this->person;
//}

//�˳�ϵͳ
void C_manager::exit_sys() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	exit(0);
}

//��������
C_manager::~C_manager() {
	if (person != NULL) {
		delete person;
		person = NULL;
	}
}
