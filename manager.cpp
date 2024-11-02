#include"manager.h"
//���캯��
Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ��ѧ������ʦ����
	this->initvector();

	//��ʼ��������Ϣ����
	this->cptrinitvector();
}

//�˵�����
void Manager::I_menu() {
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "ѧ��������" << this->v_stu.size() << endl;
	cout << "��ʦ������" << this->v_tea.size() << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//����˺�
void Manager::addacount() {
	cout << "��ѡ������˺����ͣ�" << endl;
	cout << "1��ѧ���˺�" << endl;
	cout << "2����ʦ�˺�" << endl;
	cout << "3������Ա�˺�" << endl;
	int select = 0;
	ofstream ofs;
	string name, pwd, filename;
	int id = 0;
	cin >> select;
	if (select == 1) {
		//���ѧ���˺�
		filename = STUDENT_FILE;
		cout << "������ѧ�ţ�";
	}
	else if (select == 2) {
		//��ӽ�ʦ�˺�
		filename = TEACHER_FILE;
		cout << "������ְ����ţ�";
	}
	else if (select == 3) {
		//��ӹ���Ա�˺�
		filename = ADMIN_FILE;
		bool isexit = false;
		cout << "������������";
		cin >> name;
		cout << "���������룺";
		cin >> pwd;
		//�ж������Ƿ��ظ�
		ifstream ifs;
		string fname, fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname) {
				cout << "�ù���Ա�Ѵ��ڣ������ظ���ӣ�";
				ifs.close();
				isexit = true;
				break;
			}
		}
		//���������ظ���д���ĵ�
		if (!isexit) {
			ifs.close();
			ofs.open(filename, ios::out | ios::app);
			ofs << endl << name << " " << pwd << endl;
			cout << "��ӳɹ���";
			ofs.close();
			return;
		}
	}
	else {
		cout << "��������";
		return;
	}
	//�жϱ���Ƿ��ظ� ���ظ�����������
	while (1) {
		cin >> id;
		if (!(this->checkrepeat(id, select))) {
			ofs.open(filename, ios::out | ios::app);
			ofs << id << " ";
			break;
		}
		cout << "���������룺";
	}
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	ofs << name << " " << pwd << endl;
	cout << "��ӳɹ���";
	ofs.close();
	this->initvector();
}

//��ʼ������
void Manager::initvector() {
	//�������
	v_stu.clear();
	v_tea.clear();

	int fid = 0;
	string fname, fpwd;

	//��ȡ�ļ��е���Ϣ������������
	ifstream ifs;

	//��ʼ��ѧ������
	ifs.open(STUDENT_FILE, ios::in);
	//if (!ifs.is_open()) {
	//	cout << "�ļ������ڻ�Ϊ�գ�";
	//	system("pause");
	//	system("cls");
	//}
	while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
		v_stu.push_back(Student(fid, fname, fpwd));
	}
	ifs.close();
	//cout << "ѧ��������" << v_stu.size() << endl;

	//��ʼ����ʦ����
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
		v_tea.push_back(Teacher(fid, fname, fpwd));
	}
	//cout << "��ʦ������" << v_tea.size() << endl;
}

//��ʼ����������
void Manager::cptrinitvector() {
	this->v_cptr.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	int id, max;
	while (ifs >> id && ifs >> max) {
		this->v_cptr.push_back(Computerroom(id, max));
	}
	ifs.close();
}

//����ظ�ѧ�����ʦ
bool Manager::checkrepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::const_iterator it = this->v_stu.begin();it != this->v_stu.end();it++) {
			if (it->getid() == id) {
				cout << "ѧ���ظ���";
				return true;
			}
		}
	}
	else if (type == 2) {
		for (vector<Teacher>::const_iterator it = this->v_tea.begin();it != this->v_tea.end();it++) {
			if (it->getid() == id) {
				cout << "ְ������ظ���";
				return true;
			}
		}
	}
	return false;
}


//��ӡ������
void Stuprint(Student & person) {
	cout << "ѧ�ţ�" << person.getid() << " ������" << person.m_name << " ���룺" << person.m_pwd << endl;
}
void Teaprint(Teacher & person) {
	cout << "ְ����ţ�" << person.getid() << " ������" << person.m_name << " ���룺" << person.m_pwd << endl;
}
void Cptrprint(Computerroom& room) {
	cout << "�����ţ�" << room.m_id << "   ����������" << room.m_max << endl;
}

//�鿴�˺�
void Manager::showacount() {
	//��ʼ������
	this->initvector();
	cout << "��ѡ��鿴�˺����ͣ�" << endl;
	cout << "1��ѧ���˺�" << endl;
	cout << "2����ʦ�˺�" << endl;
	cout << "3������Ա�˺�" << endl;
	int select = 0;
	cin >> select;
	if (select == 1 || select ==2) {
		//�鿴ѧ���ͽ�ʦ�˺�
		if (select == 1) {
			for_each(this->v_stu.begin(), this->v_stu.end(), Stuprint);
			//for_each(this->v_stu.begin(), this->v_stu.end(), &print<Student>);
		}
		else {
			for_each(this->v_tea.begin(), this->v_tea.end(), Teaprint);
		}
	}
	else if(select == 3){
		//�鿴����Ա�˺�
		ifstream ifs;
		string fname, fpwd;
		ifs.open(ADMIN_FILE, ios::in);
		while (ifs >> fname && ifs >> fpwd) {
			cout << "������" << fname << " ���룺******" << endl;
		}
		ifs.close();
		cout << "����������أ�����0��ʾ����" << endl;
		char in = '1';
		cin >> in;
		if (in == '0') {
			ifs.open(ADMIN_FILE, ios::in);
			while (ifs >> fname && ifs >> fpwd) {
				cout << "������" << fname << " ���룺" << fpwd << endl;
			}
			ifs.close();
		}
	}
	else {
		cout << "��������";
		system("pause");
	}
}


//�鿴������Ϣ
void Manager::showinfo() {
	this->cptrinitvector();
	for_each(this->v_cptr.begin(), this->v_cptr.end(), Cptrprint);
}

//���ԤԼ��Ϣ
void Manager::allorder() {
	cout << "��ȷ���Ƿ��������ԤԼ��Ϣ��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		ofs.close();
		cout << "���������ԤԼ��Ϣ";
	}
	else {
		cout << "ȡ������";
	}
}

//��������
Manager::~Manager() {

}
