#include <iostream>
using namespace std;

#include "pairStack.h"

int main()
{
	pairStack<int> st(10);

	for (int i = 0; i < 10; i++)
	{
		pair<int, int> p(i, i + 1);
		st.push(p);
	}
	cout << "after 10 x push(): " << endl;
	cout << st << endl << endl;

	cout << "getSize():" << endl;
	cout << st.getSize() << endl << endl;

	st.pop();
	cout << "after 1 x pop(): " << endl;
	cout << st << endl << endl;

	cout << "top: " << endl;
	cout << st.top() << endl << endl;

	cout << "isEmpty():" << endl;
	cout << st.isEmpty() << endl << endl;

	return 0;
}