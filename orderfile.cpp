#include"orderfile.h"

//���캯��
OrderFile::OrderFile() {
	//��ʼ������
	this->readfile();
}

//�ļ���ȡ
void OrderFile::readfile() {

	string date;	//ԤԼ����
	string interval;//ԤԼʱ���
	string stuid;	//ѧ��id
	string stuname;	//ѧ������
	string roomid;	//����id
	string status;	//ԤԼ״̬

	this->m_size = 0;
	ifstream ifs(ORDER_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> 
		stuid && ifs >> stuname && ifs >> roomid && ifs >> status) {
		//ÿ����¼��map�洢
		map<string, string> m;

		this->trunfile(date,m);
		this->trunfile(interval,m);
		this->trunfile(stuid,m);
		this->trunfile(stuname,m);
		this->trunfile(roomid,m);
		this->trunfile(status,m);

		//ÿ��map�����ڷ�����map
		this->m_data.insert(make_pair(m_size, m));
		this->m_size++;
	}
	ifs.close();
}

//�ļ�ת��
void OrderFile::trunfile(string str,map<string,string>& ma) {
	int where = str.find(":");
	if (where) {
		string key = str.substr(0, where);
		string value = str.substr(where + 1, str.size() - where - 1);
		ma.insert(make_pair(key, value));
	}
}


//������������
void OrderFile::updateorder() {
	ofstream ofs(ORDER_FILE, ios::out|ios::trunc);
	if (m_size == 0) {
		return;
	}
	int i = 0;
	while (i < m_size) {
		ofs << "date:" << this->m_data[i]["date"] << " ";
		ofs << "interval:" << this->m_data[i]["interval"] << " ";
		ofs << "stuid:" << this->m_data[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_data[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_data[i]["roomid"] << " ";
		ofs << "status:" << this->m_data[i]["status"] << " ";
	}
	ofs.close();
}

//��������
OrderFile::~OrderFile() {

}
