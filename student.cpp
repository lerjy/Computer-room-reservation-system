#include"student.h"

//构造函数
Student::Student() {

}

Student::Student(int id, string name, string pwd) {
	//初始化角色信息
	this->m_name = name;
	this->m_pwd = pwd;
	this->stu_id = id;

	//初始化机房信息
	this->initcptrvector();
}

//菜单界面
void Student::I_menu() {
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;

}

//初始化机房信息
void Student::initcptrvector() {
	ifstream ifs(COMPUTER_FILE, ios::in);
	int id;
	int max;
	while (ifs >> id && ifs >> max) {
		this->v_cptr.push_back(Computerroom(id, max));
	}
	ifs.close();
}


//申请预约
void Student::applyorder() {
	int date = 0;//预约日期
	int interval = 0;//预约时间
	int room = 0;//预约机房id
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	//选择日期
	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误！请重新输入：";
	}
	//选择时间段
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (1) {
		cin >> interval;
		if (interval == 1 || interval == 2) {
			break;
		}
		cout << "输入有误！请重新输入：";
	}
	//选择机房
	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << v_cptr[0].m_max << endl;
	cout << "2号机房容量：" << v_cptr[1].m_max << endl;
	cout << "3号机房容量：" << v_cptr[2].m_max << endl;
	while (1) {
		cin >> room;
		if (room == 1 || room == 2 || room == 3) {
			break;
		}
		cout << "输入有误！请重新输入：";
	}
	cout << "预约成功！审核中" << endl;
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " interval:" << interval << " stuid:" << this->getid()
		<< " stuname:" << this->m_name << " roomid:" << room << " status:" << 1 << endl;
	ofs.close();
}

//查看自身预约
void Student::myorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约信息  ";
		return;
	}
	//记录自身预约数目
	int num = 0;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_data[i]["stuid"].c_str()) == this->getid()) {
			num++;
			cout << num << "、 ";
			cout << "日期:周" << of.m_data[i]["date"] << " ";
			cout << " 时间段:" << (of.m_data[i]["interval"] == "1" ? "上午" : "下午") << " ";
			//cout << " 学号:" << of.m_data[i]["stuid"] << " ";
			//cout << " 学生姓名:" << of.m_data[i]["stuname"] << " ";
			cout << " 机房编号:" << of.m_data[i]["roomid"] << " ";
			cout << " 预约状态:";
			if (of.m_data[i]["status"] == "1") {
				cout << "审核中" << endl;
			}
			else if (of.m_data[i]["status"] == "2") {
				cout << "预约成功" << endl;
			}
			else if (of.m_data[i]["status"] == "0") {
				cout << "取消预约" << endl;
			}
			else {
				cout << "预约失败" << endl;
			}
		}
	}
	if (!num) {
		cout << "无预约记录  ";
	}
}

//查看所有预约
void Student::allorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约信息  ";
		return;
	}
	for (int i = 0;i < of.m_size;i++) {
		cout << i + 1 << "、 ";
		cout << "日期:周" << of.m_data[i]["date"] << " ";
		cout << " 时间段:" << (of.m_data[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << " 学号:" << of.m_data[i]["stuid"] << " ";
		cout << " 学生姓名:" << of.m_data[i]["stuname"] << " ";
		cout << " 机房编号:" << of.m_data[i]["roomid"] << " ";
		cout << " 预约状态:";
		if (of.m_data[i]["status"] == "1") {
			cout << "审核中" << endl;
		}
		else if (of.m_data[i]["status"] == "2") {
			cout << "预约成功" << endl;
		}
		else if (of.m_data[i]["status"] == "0") {
			cout << "取消预约" << endl;
		}
		else {
			cout << "预约失败" << endl;
		}
	}
}

//取消预约
void Student::celorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约信息  ";
		return;
	}
	//输入选择
	int num = 0;
	//记录数据在最大容其中的下标
	vector<int> v;
	for (int i = 0;i < of.m_size;i++) {
		if (atoi(of.m_data[i]["stuid"].c_str()) == this->getid()) {
			num++;
			v.push_back(i);
			cout << num << "、 ";
			cout << "日期:周" << of.m_data[i]["date"] << " ";
			cout << " 时间段:" << (of.m_data[i]["interval"] == "1" ? "上午" : "下午") << " ";
			//cout << " 学号:" << of.m_data[i]["stuid"] << " ";
			//cout << " 学生姓名:" << of.m_data[i]["stuname"] << " ";
			cout << " 机房编号:" << of.m_data[i]["roomid"] << " ";
			cout << " 预约状态:";
			if (of.m_data[i]["status"] == "1") {
				cout << "审核中" << endl;
			}
			else if (of.m_data[i]["status"] == "2") {
				cout << "预约成功" << endl;
			}
			else if (of.m_data[i]["status"] == "0") {
				cout << "取消预约" << endl;
			}
			else {
				cout << "预约失败" << endl;
			}
		}
	}
	if (num == 0) {
		cout << "无预约信息 ";
		return;
	}
	while (true) {
		cout << "可取消审核中与预约成功的记录,请输入要取消的记录 (输入0返回)：" << endl;
		cin >> num;
		if (num == 0) {
			break;
		}
		else if (num > 0 && num <= v.size()) {
			//判断该条记录是否为 预约成功 或则 审核中
			if (of.m_data[v[num - 1]]["status"] == "1" || of.m_data[v[num - 1]]["status"] == "2") {
				//取消该条记录
				of.m_data[v[num - 1]]["status"] = "0";
				of.updateorder();
				cout << "取消成功 ";
				break;
			}
			else {
				cout << "该条记录不能取消！ ";
				system("pause");
			}
		}
		else {
			cout << "输入有误！";
			system("pause");
		}
	}
}

//设置学号
void Student::setid(int id) {
	this->stu_id = id;
}

//获取学号
int Student::getid() const {
	return this->stu_id;
}

//析构函数
Student::~Student() {

}



