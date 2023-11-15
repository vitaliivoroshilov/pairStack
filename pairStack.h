#pragma once
#include <iostream>
using namespace std;

template <class T>
class pairStack
{
public:
	pair<T, int>* begin;
	pair<T, int>* end;
	int size;
	pairStack()
	{
		size = 100;
		begin = new pair<T, int>[size];
		end = begin;
	}
	pairStack(int _n)
	{
		if (_n < 0)
			throw("");
		size = _n;
		begin = new pair<T, int>[size];
		end = begin;
	}
	pairStack(const pairStack& s) : size(s.size)
	{
		begin = new pair<T, int>[size];
		for (int i = 0; i < size; i++)
			begin[i] = s.begin[i];
		end = begin + (s.end - s.begin);
	}
	~pairStack()
	{
		delete[] begin;
	}
	void push(pair<T, int> p)
	{
		if (end - begin == size)
		{
			size = 1.3 * size;
			pair<T, int>* tmp = new pair<T, int>[size];
			for (int i = 0; i < (end - begin); i++)
				tmp[i] = begin[i];
			end = tmp + (end - begin);
			delete[] begin;
			begin = tmp;
		}
		*end = p;
		end++;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return begin == end;
	}
	T top()
	{
		if (begin == end)
			throw("");
		else
			return *(--end);
	}
	void pop()
	{
		if (begin == end)
			throw("");
		else
			end--;
	}
	bool operator==(const pairStack& s)
	{
		if (s.end - s.begin != end - begin)
			return false;
		else
		{
			for (int i = 0; i < end - begin; i++)
				if (begin[i] != s.begin[i])
					return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& out, const pairStack& s)
	{
		for (int i = 0; i < (s.end - s.begin); i++)
			out << s.begin[i] << " ";
		return out;
	}
};