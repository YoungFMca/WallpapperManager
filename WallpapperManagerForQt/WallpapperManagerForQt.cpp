// WallpapperManagerForQt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>
#include <io.h>
#include <math.h>
using namespace std;
/*Ctrl+K+C批量注释 Ctrl+K+U批量解除注释*/

ofstream openTxt2out(string path)//优化代码 每次打开一个输出流
{
	ofstream fout;
	fout.open(path,ios_base::trunc);//每一次读取全部消掉就ok
	if (fout.is_open())
	{
		return fout;
	}
	cout << "打开" + path + "失败" << endl;
	return fout;
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
		do
		{
			file.push_back(temp.assign(path).append("/").append(file_info.name));
		} while (_findnext(file_handle, &file_info) == 0);
		_findclose(file_handle);

	}
}
//将遍历到的文件名存储到相应路径的函数
void savePicPath(ofstream &fout, vector<string> filePaths,string savePath)
{
	fout.open(savePath, ios_base::trunc);
	for (int i = 0; i < filePaths.size(); i++)
	{
		fout << filePaths[i] << endl;
	}
	fout.close();
}
//显示函数
void disPlayFiles(vector<string> my_files)
{
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
		cout << endl << "Find " << my_files.size() << " file(s)." << endl;
	}
}
int main()
{
	string address = "..\\";
	//string address = R"(D:\SoftwareProjects\WallpapperManager\)";
	string fileName = "TestSave.txt";
	string picAddress = R"(pics\)";
	string addrpics = address + picAddress;//保证这个使用方法没问题
	string saveNamePath = address + fileName;
	//测试相对路径
	//ofstream ftest;
	//ftest.open(saveNamePath,ios_base::trunc);
	//ftest << "去你妈的";
	//ftest.close();
	//测试相对路径
	ofstream foutTxt;//文件输出流
	
	vector<string> my_files;
	string need_extension = ".jpg";
	//关于相对路径的试验代码
	vector<string> xiang_dui_lu_jing;
	xiang_dui_lu_jing.push_back(".\\");//当前目录
	xiang_dui_lu_jing.push_back("..\\");//上层目录
	xiang_dui_lu_jing.push_back("");//当前目录
	ofstream ffff;
	for (int i = 0; i < xiang_dui_lu_jing.size(); i++) 
	{
		switch (i)
		{
		case 0:
			ffff = openTxt2out(xiang_dui_lu_jing[i] + "这是当前目录.txt");
			ffff << "这才是当前目录";
			ffff.close();
			break;
		case 1:
			ffff = openTxt2out(xiang_dui_lu_jing[i] + "这是上一层目录.txt");
			ffff << "这才是上一层目录";
			ffff.close();
			break;
		case 2:
			ffff = openTxt2out(xiang_dui_lu_jing[i] + "这也可以是当前目录.txt");
			ffff << "这也可以是当前目录";
			ffff.close();
			break;
		default:
			break;
		}
	}
	ffff = openTxt2out(addrpics + "这是pics目录.txt");
	ffff << "这是图片目录";
	ffff.close();

	//关于相对路径的试验代码
	while (true)
	{
		cout << "请输入指令" << endl<<"查找图片：1 显示文件名：2 存储图片：3 结束：0"<<endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
			get_need_file(addrpics, my_files, need_extension);
			cout << "查找成功" << endl;
			break;
		case 2:
			disPlayFiles(my_files);
			cout << "显示完毕" << endl;
			break;
		case 3:
			savePicPath(foutTxt, my_files, saveNamePath);
			cout << "存储完毕" << endl;
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "请输入正确数字" << endl;
			break;
		}	
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
