#pragma once
#include <string>
using namespace std;

class Student
{
public:
	string name;
	int score;
	~Student();
	// ����С�����㷨,����Student֮��ıȽϷ�ʽ
	// ���������ȣ��������ֵ���ĸ������
	// ����������ȣ�������ߵĿ�ǰ
	bool operator<(const Student& otherStudent) {
		return score != otherStudent.score ?
			score > otherStudent.score : name < otherStudent.name;
	}

	// ����<<����, ����Studentʵ���Ĵ�ӡ�����ʽ
	// * �ܶ�ͬѧ���������C++�﷨, ͷ�ʹ���, ��������ͬѧ��ʾҪ����ѧϰC++����
	// * ��������γ�, ��ɲ��ء�C++���Բ���������γ̵��ص�,
	// * ���Ҳ��ȫ����ʹ���Լ��ķ�ʽ��д����, ����ֻҪ�ܹ���ӡ������ͺ���, ��������һ����Ա����, ����show()...
	// * �Ƽ�����Ķ������ʴ������ҷ����һ��ѧϰ�ĵ�: ��ѧϰ�ĵ÷�������ץ���С����Ҫ������C++���Ե��﷨ϸ��
	// * ����: http://coding.imooc.com/learn/questiondetail/4100.html
	friend ostream& operator<<(ostream &os, const Student &student) {

		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};

