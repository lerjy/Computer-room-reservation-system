#include"manager.h"
//构造函数
Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	//初始化管理员信息
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化学生、教师容器
	this->initvector();

	//初始化机房信息容器
	this->cptrinitvector();
}

//菜单界面
void Manager::I_menu() {
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "学生数量：" << this->v_stu.size() << endl;
	cout << "教师数量：" << this->v_tea.size() << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： ";
}

//添加账号
void Manager::addacount() {
	cout << "请选择添加账号类型：" << endl;
	cout << "1、学生账号" << endl;
	cout << "2、教师账号" << endl;
	cout << "3、管理员账号" << endl;
	int select = 0;
	ofstream ofs;
	string name, pwd, filename;
	int id = 0;
	cin >> select;
	if (select == 1) {
		//添加学生账号
		filename = STUDENT_FILE;
		cout << "请输入学号：";
	}
	else if (select == 2) {
		//添加教师账号
		filename = TEACHER_FILE;
		cout << "请输入职工编号：";
	}
	else if (select == 3) {
		//添加管理员账号
		filename = ADMIN_FILE;
		bool isexit = false;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入密码：";
		cin >> pwd;
		//判断姓名是否重复
		ifstream ifs;
		string fname, fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname) {
				cout << "该管理员已存在，请勿重复添加！";
				ifs.close();
				isexit = true;
				break;
			}
		}
		//若姓名不重复则写入文档
		if (!isexit) {
			ifs.close();
			ofs.open(filename, ios::out | ios::app);
			ofs << endl << name << " " << pwd << endl;
			cout << "添加成功，";
			ofs.close();
			return;
		}
	}
	else {
		cout << "输入有误！";
		return;
	}
	//判断编号是否重复 若重复则重新输入
	while (1) {
		cin >> id;
		if (!(this->checkrepeat(id, select))) {
			ofs.open(filename, ios::out | ios::app);
			ofs << id << " ";
			break;
		}
		cout << "请重新输入：";
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	ofs << name << " " << pwd << endl;
	cout << "添加成功，";
	ofs.close();
	this->initvector();
}

//初始化容器
void Manager::initvector() {
	//清空容器
	v_stu.clear();
	v_tea.clear();

	int fid = 0;
	string fname, fpwd;

	//读取文件中的信息并放入容器中
	ifstream ifs;

	//初始化学生容器
	ifs.open(STUDENT_FILE, ios::in);
	//if (!ifs.is_open()) {
	//	cout << "文件不存在或为空！";
	//	system("pause");
	//	system("cls");
	//}
	while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
		v_stu.push_back(Student(fid, fname, fpwd));
	}
	ifs.close();
	//cout << "学生数量：" << v_stu.size() << endl;

	//初始化教师容器
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
		v_tea.push_back(Teacher(fid, fname, fpwd));
	}
	//cout << "教师数量：" << v_tea.size() << endl;
}

//初始化机房容器
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

//检测重复学生或教师
bool Manager::checkrepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::const_iterator it = this->v_stu.begin();it != this->v_stu.end();it++) {
			if (it->getid() == id) {
				cout << "学号重复！";
				return true;
			}
		}
	}
	else if (type == 2) {
		for (vector<Teacher>::const_iterator it = this->v_tea.begin();it != this->v_tea.end();it++) {
			if (it->getid() == id) {
				cout << "职工编号重复！";
				return true;
			}
		}
	}
	return false;
}


//打印函数体
void Stuprint(Student & person) {
	cout << "学号：" << person.getid() << " 姓名：" << person.m_name << " 密码：" << person.m_pwd << endl;
}
void Teaprint(Teacher & person) {
	cout << "职工编号：" << person.getid() << " 姓名：" << person.m_name << " 密码：" << person.m_pwd << endl;
}
void Cptrprint(Computerroom& room) {
	cout << "机房号：" << room.m_id << "   机房容量：" << room.m_max << endl;
}

//查看账号
void Manager::showacount() {
	//初始化容器
	this->initvector();
	cout << "请选择查看账号类型：" << endl;
	cout << "1、学生账号" << endl;
	cout << "2、教师账号" << endl;
	cout << "3、管理员账号" << endl;
	int select = 0;
	cin >> select;
	if (select == 1 || select ==2) {
		//查看学生和教师账号
		if (select == 1) {
			for_each(this->v_stu.begin(), this->v_stu.end(), Stuprint);
			//for_each(this->v_stu.begin(), this->v_stu.end(), &print<Student>);
		}
		else {
			for_each(this->v_tea.begin(), this->v_tea.end(), Teaprint);
		}
	}
	else if(select == 3){
		//查看管理员账号
		ifstream ifs;
		string fname, fpwd;
		ifs.open(ADMIN_FILE, ios::in);
		while (ifs >> fname && ifs >> fpwd) {
			cout << "姓名：" << fname << " 密码：******" << endl;
		}
		ifs.close();
		cout << "按任意键返回，输入0显示密码" << endl;
		char in = '1';
		cin >> in;
		if (in == '0') {
			ifs.open(ADMIN_FILE, ios::in);
			while (ifs >> fname && ifs >> fpwd) {
				cout << "姓名：" << fname << " 密码：" << fpwd << endl;
			}
			ifs.close();
		}
	}
	else {
		cout << "输入有误！";
		system("pause");
	}
}


//查看机房信息
void Manager::showinfo() {
	this->cptrinitvector();
	for_each(this->v_cptr.begin(), this->v_cptr.end(), Cptrprint);
}

//清空预约信息
void Manager::allorder() {
	cout << "请确认是否清空所有预约信息：" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		ofs.close();
		cout << "已清空所有预约信息";
	}
	else {
		cout << "取消操作";
	}
}

//析构函数
Manager::~Manager() {

}
