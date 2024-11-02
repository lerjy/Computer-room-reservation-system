#include"computermanager.h"

//构造函数
C_manager::C_manager() {

}

//打印角色选择菜单
void C_manager::show_menu() {
	cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << endl << "请输入您的身份：";
}

//登录操作
void C_manager::loginin(string Filename, int type) {
	//父类指针，用于指向子类
	//Identity* person = NULL;

	//打开对应文件
	ifstream ifs(Filename, ios::in);

	//判断文件是否打开
	if (ifs.is_open()) {
		string name;
		string pwd;
		int id = 0;
		if (type == 1) {
			//学生身份
			cout << "请输入你的学号：";
			cin >> id;
		}
		else if (type == 2) {
			//教师身份
			cout << "请输入你的职工编号：";
			cin >> id;
		}
		else {
			//管理员身份
		}
		cout << "请输入你的姓名：";
		cin >> name;
		cout << "请输入你的密码：";
		cin >> pwd;

		//扫描文件信息
		string fname;
		string fpwd;
		int fid;

		if (type != 3) {
			//判断角色登录
			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					ifs.close();
				}
			}
			if (type == 1) {
				//学生登录
				//登陆后操作
				system("cls");
				this->person = new Student(fid, fname, fpwd);
				//system("pause");
				this->student(this->person);
				return;
			}
			else if (type == 2) {
				//教师登录
				//登陆后操作
				system("cls");
				this->person = new Teacher(fid, fname, fpwd);
				this->teacher(this->person);
				//system("pause");
				return;
			}
		}

		else {
			//管理员登录
			while (ifs >> fname && ifs >> fpwd) {
				if (name == fname && pwd == fpwd) {
					cout << "验证登录成功！" << endl;
					ifs.close();
					//登陆后操作
					system("cls");
					this->person = new Manager(fname, fpwd);
					this->admin(this->person);
					//system("pause");

					return;
				}
			}
		}
		cout << "验证登录失败！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		ifs.close();
		cout << "文件打开失败！" << endl;
		system("pause");
		system("cls");
	}
}

//管理员操作功能
void C_manager::admin(Identity*& manager) {
	//用于接收用户输入
	int select = 0;
	while (1) {
		//打印管理员菜单
		manager->I_menu();
		Manager* man = (Manager*)manager;
		cin >> select;
		if (select == 1) {
			//添加账号
			man->addacount();
		}
		else if (select == 2) {
			//查看账号
			man->showacount();
		}
		else if (select == 3) {
			//查看机房
			man->showinfo();
		}
		else if (select == 4) {
			//清空预约
			man->allorder();
		}
		else if (select == 0) {
			//注销登录
			break;
		}
		else {
			cout << "输入有误！";
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

//学生操作功能
void C_manager::student(Identity*& student) {

	//记录输入
	int select = 0;
	//初始化学生变量
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
			cout << "欢迎下次使用！";
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误！";
			break;
		}
		system("pause");
		system("cls");
	}
}

//教师操作功能
void C_manager::teacher(Identity*& teacher) {
	//用于接收用户输入
	int select = 0;
	while (1) {
		//打印教师菜单
		teacher->I_menu();
		Teacher* man = (Teacher*)teacher;
		cin >> select;
		if (select == 1) {
			//查看所有预约
			man->allorder();
		}
		else if (select == 2) {
			//审核预约
			man->validorder();
		}
		else if (select == 0) {
			//注销登录
			break;
		}
		else {
			cout << "输入有误！";
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


////登录角色
//template<class T>
//void C_manager::perlogin() {
//	this->person = new T();
//}
//
//Identity* C_manager::getperson() {
//	return this->person;
//}

//退出系统
void C_manager::exit_sys() {
	cout << "欢迎下次使用！" << endl;
	exit(0);
}

//析构函数
C_manager::~C_manager() {
	if (person != NULL) {
		delete person;
		person = NULL;
	}
}
