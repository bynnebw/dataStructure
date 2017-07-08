#ifndef _ARRAY_H_
#define _ARRAY_H_
class Array
{
private:
	int mLength;
	int* mSpace;

public:
	Array(int length);
	Array(const Array& obj);
	int Length();
	void setData(int index,int value);
	int getData(int index);
	~Array();
	int& operator[](int i);		//注意这里为什么一定是返回引用类型。因为返回引用类型后，才能作为左值进行幅值，
};								//如果不是引用类型，不能作为左值进行运算。

#endif