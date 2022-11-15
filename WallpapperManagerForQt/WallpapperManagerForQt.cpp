// WallpapperManagerForQt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include<io.h>
using namespace std;
/*Ctrl+K+C批量注释 Ctrl+K+U批量解除注释*/
void savePath(string path)
{
	ifstream finforTxt;
	//string address = "D:\\SoftwareProjects\\WallpapperManager\\";
	//string address = "C:\\Users\user\\Desktop\\newproject\\WallpapperManager\\";
	string address = "..\\";
	string fileName = "TestSave.txt";
	string addFileName = address + fileName;//保证这个使用方法没问题
	ofstream fout;
	fout.open(addFileName, ios_base::app);
	if (fout.is_open())
	{
		fout << path << endl;
	}
	else
	{
		cout << "Go Fuck Yourself 以及打开TestSave.txt失败";
	}
	//写文件的时候的一些问题

}

void get_need_file(string path, vector<string>& file, string ext)
{
	intptr_t file_handle = 0;//与计算机系统有关的数据类型，专门用来存放指针的地址
	//用来表示文件句柄；在计算机系统中每一个文件都有一个唯一的编号（相当于我们每一个人都有一个唯一的身份证号码），不同的文件具有不同的句柄，依据这一个句柄计算机系统就能锁定其对应的那个唯一的文件。
	//因为文件句柄就是一个指向指针的指针，亦即指针的地址，因此我们就将其设定为intptr_t类型。
	struct _finddata_t file_info;//用来储存计算机系统中不同文件的各类信息
	string temp;//储存临时生成的文件路径
	if ((file_handle = _findfirst(temp.assign(path).append("/*" + ext).c_str(), &file_info)) != -1)
		//temp.assign(path)表示赋值给字符串temp .c_str()将temp转化为C语言格式
		//_findfirst在当前路径下，找到与第一个参数（在这里也就是转换好的C语言格式字符串）相匹配的第一个文件；如果能找到这个文件，那么其就返回该文件的句柄，
		//并将该文件的信息放入file_info；如果找不到这个文件，那么该函数就返回-1。
	{
		cout << "tempAddr:"<<temp << endl;
		do
		{
			cout << "tempAddrInDo:" << temp << endl;
			file.push_back(temp.assign(path).append("/").append(file_info.name));
			savePath(temp.assign(path).append("/").append(file_info.name));//存储文件名
		} while (_findnext(file_handle, &file_info) == 0);
		_findclose(file_handle);

	}
}
int main()
{
	ifstream finforTxt;
	//string address = R"(C:\Users\user\Desktop\newproject\WallpapperManager\)";//use R() to avoid escape character
	string address = R"(..\)";
	string fileName = "Test.txt";
	string picAddress = R"(pics\)";
	string addrpics = address + picAddress;//保证这个使用方法没问题
	cout << addrpics << endl;

	vector<string> my_files;
	string need_extension = ".jpg";
	get_need_file(addrpics, my_files, need_extension);
	for (int i = 0; i < my_files.size(); i++)
	{
		cout << "File" << i + 1 << "is:" << endl;
		cout << my_files[i] << endl;
	}
	if (my_files.size() == 0)
	{
		cout << "No file has been found!" << endl;
	}
	else
	{
		cout << endl << "FInd" << my_files.size() << "file(s)." << endl;
	}
	return 0;
}

//存储得到的文件的路径




void readTxt()
{
	ifstream finforTxt;
	//string address = "C:\\Users\user\\Desktop\\newproject\\WallpapperManager\\";
	string address = "..\\";
	string fileName = "Test.txt";
	string picAddress = "pics\\pics";
	string addFileName = address + fileName;//保证这个使用方法没问题
	cout << addFileName << endl;
	finforTxt.open(addFileName, ios_base::binary);
	if (finforTxt.is_open())
	{
		char ch;
	finforTxt >> ch;//读取一个字符
	cout << "ch:" << ch << endl;
	char buf[80];
	finforTxt >> buf;//读取一个单词
	finforTxt >> buf;
	cout << "buf:" << buf << endl;
	finforTxt.getline(buf, 80);//读取一行
	string line;
	getline(finforTxt, line);//要include string
	cout << "ch:" << line << endl;
	}

}
