// Bilibili BV to AV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
using namespace std;

string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
int s[6] = { 11, 10, 3, 8, 4, 6 };
int xor_value = 177451812;
long long add = 8728348608;

int find(char ch)
{
	for (int i = 0; i < 58; i++) {
		if (ch == table[i]) {
			return i;
		}
	}
}

long long decode(string x)
{
	long long r = 0;
	for (int i = 0; i < 6; i++) {
		r += find(x[s[i]]) * pow(58, i);
	}
	return (r - add) ^ xor_value;
}

string encode(long long x)
{
	x = (x ^ xor_value) + add;
	string r = "BV1  4 1 7  ";
	for (int i = 0; i < 6; i++) {
		long long pow_value = pow(58, i);
		r[s[i]] = table[(x / pow_value) % 58];
	}
	return r;
}

int main()
{
	cout << "Bilibili BV to AV Encode/Decode" << endl;
	cout << "composed by Kuroneko on March 25,2020" << endl << endl;
	cout << "input av or BV code:" << endl;

	while (true) {
		string input;
		cin >> input;
		if (input[0] == 'B' && input[1] == 'V') {
			if (input.size() == 12) {
				cout << "av" << decode(input) << endl << endl;
			}
			else {
				cout << "ERROR BV" << endl << endl;
			}
		}
		else if (input[0] == 'a' && input[1] == 'v') {
			string av_str;
			for (int i = 0; i < input.size() - 2; i++) {
				av_str += input[i + 2];
			}
			long long av_code = atoi(av_str.c_str());
			cout << encode(av_code) << endl << endl;
		}
		else {
			cout << "ERROR INPUT" << endl << endl;
		}
	}
	return 0;
}
