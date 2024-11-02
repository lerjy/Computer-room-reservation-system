#include"teacher.h"

//���캯��
Teacher::Teacher() {

}

Teacher::Teacher(int id,string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->tea_id = id;
}

//�˵�����
void Teacher::I_menu() {
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::allorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��Ϣ  ";
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		cout << i + 1 << "�� ";
		cout << "����:��" << of.m_data[i]["date"] << " ";
		cout << " ʱ���:" << (of.m_data[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << " ѧ��:" << of.m_data[i]["stuid"] << " ";
		cout << " ѧ������:" << of.m_data[i]["stuname"] << " ";
		cout << " �������:" << of.m_data[i]["roomid"] << " ";
		cout << " ԤԼ״̬:";
		if (of.m_data[i]["status"] == "1") {
			cout << "�����" << endl;
		}
		else if (of.m_data[i]["status"] == "2") {
			cout << "ԤԼ�ɹ�" << endl;
		}
		else if (of.m_data[i]["status"] == "0") {
			cout << "ȡ��ԤԼ" << endl;
		}
		else {
			cout << "ԤԼʧ��" << endl;
		}
	}
}

//���ԤԼ
void Teacher::validorder() {
	this->allorder();
	int select = 0;
	OrderFile of;
	while (true) {
		cout << "��ѡ��(����0�˳�)��" << endl;
		cin >> select;
		if (select == 0) {
			return;
		}
		else if (select > 0 && select <= of.m_size) {
			if (of.m_data[select - 1]["status"] == "1") {
				cout << "��ѡ����˺�״̬��" << endl;
				cout << "1�����ͨ��" << endl;
				cout << "2�����δͨ��" << endl;
				int sel;
				cin >> sel;
				if (sel - 1) {
					of.m_data[select - 1]["status"] = "-1";
					of.updateorder();
					cout << "�����" << endl;
					break;
				}
				of.m_data[select - 1]["status"] = "2";
				of.updateorder();
				cout << "�����" << endl;
				break;
			}
			else {
				cout << "��������";
				system("pause");
			}
		}
		else {
			cout << "��������";
			system("pause");
		}
	}
}

//����ְ�����
void Teacher::setid(int id) {
	this->tea_id = id;
}

//��ȡְ�����
int Teacher::getid()const {
	return this->tea_id;
}

//��������
Teacher::~Teacher() {

}
