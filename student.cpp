#include"student.h"

//���캯��
Student::Student() {

}

Student::Student(int id, string name, string pwd) {
	//��ʼ����ɫ��Ϣ
	this->m_name = name;
	this->m_pwd = pwd;
	this->stu_id = id;

	//��ʼ��������Ϣ
	this->initcptrvector();
}

//�˵�����
void Student::I_menu() {
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

}

//��ʼ��������Ϣ
void Student::initcptrvector() {
	ifstream ifs(COMPUTER_FILE, ios::in);
	int id;
	int max;
	while (ifs >> id && ifs >> max) {
		this->v_cptr.push_back(Computerroom(id, max));
	}
	ifs.close();
}


//����ԤԼ
void Student::applyorder() {
	int date = 0;//ԤԼ����
	int interval = 0;//ԤԼʱ��
	int room = 0;//ԤԼ����id
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	//ѡ������
	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "�����������������룺";
	}
	//ѡ��ʱ���
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (1) {
		cin >> interval;
		if (interval == 1 || interval == 2) {
			break;
		}
		cout << "�����������������룺";
	}
	//ѡ�����
	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << v_cptr[0].m_max << endl;
	cout << "2�Ż���������" << v_cptr[1].m_max << endl;
	cout << "3�Ż���������" << v_cptr[2].m_max << endl;
	while (1) {
		cin >> room;
		if (room == 1 || room == 2 || room == 3) {
			break;
		}
		cout << "�����������������룺";
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " interval:" << interval << " stuid:" << this->getid()
		<< " stuname:" << this->m_name << " roomid:" << room << " status:" << 1 << endl;
	ofs.close();
}

//�鿴����ԤԼ
void Student::myorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��Ϣ  ";
		return;
	}
	//��¼����ԤԼ��Ŀ
	int num = 0;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_data[i]["stuid"].c_str()) == this->getid()) {
			num++;
			cout << num << "�� ";
			cout << "����:��" << of.m_data[i]["date"] << " ";
			cout << " ʱ���:" << (of.m_data[i]["interval"] == "1" ? "����" : "����") << " ";
			//cout << " ѧ��:" << of.m_data[i]["stuid"] << " ";
			//cout << " ѧ������:" << of.m_data[i]["stuname"] << " ";
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
	if (!num) {
		cout << "��ԤԼ��¼  ";
	}
}

//�鿴����ԤԼ
void Student::allorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��Ϣ  ";
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

//ȡ��ԤԼ
void Student::celorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��Ϣ  ";
		return;
	}
	//����ѡ��
	int num = 0;
	//��¼��������������е��±�
	vector<int> v;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_data[i]["stuid"].c_str()) == this->getid()) {
			num++;
			v.push_back(i);
			cout << num << "�� ";
			cout << "����:��" << of.m_data[i]["date"] << " ";
			cout << " ʱ���:" << (of.m_data[i]["interval"] == "1" ? "����" : "����") << " ";
			//cout << " ѧ��:" << of.m_data[i]["stuid"] << " ";
			//cout << " ѧ������:" << of.m_data[i]["stuname"] << " ";
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
	if (num == 0) {
		cout << "��ԤԼ��Ϣ ";
		return;
	}
	while (true) {
		cout << "��ȡ���������ԤԼ�ɹ��ļ�¼,������Ҫȡ���ļ�¼ (����0����)��" << endl;
		cin >> num;
		if (num == 0) {
			break;
		}
		else if (num > 0 && num <= v.size()) {
			//�жϸ�����¼�Ƿ�Ϊ ԤԼ�ɹ� ���� �����
			if (of.m_data[v[num - 1]]["status"] == "1" || of.m_data[v[num - 1]]["status"] == "2") {
				//ȡ��������¼
				of.m_data[v[num - 1]]["status"] = "0";
				of.updateorder();
				cout << "ȡ���ɹ� ";
				break;
			}
			else {
				cout << "������¼����ȡ���� ";
				system("pause");
			}
		}
		else {
			cout << "��������";
			system("pause");
		}
	}
}

//����ѧ��
void Student::setid(int id) {
	this->stu_id = id;
}

//��ȡѧ��
int Student::getid() const {
	return this->stu_id;
}

//��������
Student::~Student() {

}



