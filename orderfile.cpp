#include"orderfile.h"

//构造函数
OrderFile::OrderFile() {
	//初始化容器
	this->readfile();
}

//文件读取
void OrderFile::readfile() {

	string date;	//预约日期
	string interval;//预约时间段
	string stuid;	//学生id
	string stuname;	//学生姓名
	string roomid;	//机房id
	string status;	//预约状态

	this->m_size = 0;
	ifstream ifs(ORDER_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> 
		stuid && ifs >> stuname && ifs >> roomid && ifs >> status) {
		//每条记录用map存储
		map<string, string> m;

		this->trunfile(date,m);
		this->trunfile(interval,m);
		this->trunfile(stuid,m);
		this->trunfile(stuname,m);
		this->trunfile(roomid,m);
		this->trunfile(status,m);

		//每条map数据在放入大号map
		this->m_data.insert(make_pair(m_size, m));
		this->m_size++;
	}
	ifs.close();
}

//文件转型
void OrderFile::trunfile(string str,map<string,string>& ma) {
	int where = str.find(":");
	if (where) {
		string key = str.substr(0, where);
		string value = str.substr(where + 1, str.size() - where - 1);
		ma.insert(make_pair(key, value));
	}
}


//更新容器数据
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

//析构函数
OrderFile::~OrderFile() {

}
