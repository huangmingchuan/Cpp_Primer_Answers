#include <iostream>
#include <stdexcept>
using std::cin; using std::cout; using std::endl; using std::runtime_error;

int main(void)
{
	int i, j;
	cout << "please input tow numbers: " << endl;
	while (cin >> i >> j)
	{
		try
		{
			if (j == 0)
				throw runtime_error("divisor is 0");
			cout << i / j << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (c != 'y')
				break;
		}
		cout << "please input tow numbers: " << endl;
	}

	return 0;
}