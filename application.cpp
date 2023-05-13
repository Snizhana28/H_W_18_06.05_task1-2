#include "child_/bit_string.h"
#include <vector>
int main()
{
	BitString s1("1010"), s2("0110"), s3;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;
	s3 = -s1;
	cout << "s3 = " << s3 << endl;
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	else
		cout << "s1 != s2" << endl;
	if (s1 != s2)
		cout << "s1 != s2" << endl;
	else
		cout << "s1 == s2" << endl;

	return 0;
}
