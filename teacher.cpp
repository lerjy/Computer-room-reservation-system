#include"teacher.h"

//构造函数
Teacher::Teacher() {

}

Teacher::Teacher(int id,string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->tea_id = id;
}

//菜单界面
void Teacher::I_menu() {
	cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::allorder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约信息  ";
		system("pause");
		system("cls");
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

//审核预约
void Teacher::validorder() {
	this->allorder();
	int select = 0;
	OrderFile of;
	while (true) {
		cout << "请选择(输入0退出)：" << endl;
		cin >> select;
		if (select == 0) {
			return;
		}
		else if (select > 0 && select <= of.m_size) {
			if (of.m_data[select - 1]["status"] == "1") {
				cout << "请选择审核后状态：" << endl;
				cout << "1、审核通过" << endl;
				cout << "2、审核未通过" << endl;
				int sel;
				cin >> sel;
				if (sel - 1) {
					of.m_data[select - 1]["status"] = "-1";
					of.updateorder();
					cout << "已审核" << endl;
					break;
				}
				of.m_data[select - 1]["status"] = "2";
				of.updateorder();
				cout << "已审核" << endl;
				break;
			}
			else {
				cout << "输入有误，";
				system("pause");
			}
		}
		else {
			cout << "输入有误，";
			system("pause");
		}
	}
}

//设置职工编号
void Teacher::setid(int id) {
	this->tea_id = id;
}

//获取职工编号
int Teacher::getid()const {
	return this->tea_id;
}

//析构函数
Teacher::~Teacher() {

}
