#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(vector<int>& a, vector<int>& b)
{
	int size1 = a.size();
	int size2 = b.size();

	vector<int> result;
	result.resize(size1 + size2 - 1, 0);

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			result[i + j] += a[i] * b[j];
		}
	}

	return result;
}

void addTo(vector<int>& a, vector<int>& b, int k)
{
	int size = max(b.size() + k, a.size());

	a.resize(size, 0);
	b.resize(size, 0);

	for (int i = 0; i < size - k; i++)
	{
		a[i + k] += b[i];
	}
}

void subtractFrom(vector<int>& a, vector<int>& b)
{
	int size = max(a.size(), b.size());

	a.resize(size, 0);
	b.resize(size, 0);

	for (int i = 0; i < size; i++)
	{
		a[i] -= b[i];
	}
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
	int an = a.size();
	int bn = b.size();

	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());

	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(b0, b0);
	
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	
	subtractFrom(z1, z0);
	subtractFrom(z1, z2);

	vector<int> result;
	
	addTo(result, z0, 0);
	addTo(result, z1, half);
	addTo(result, z2, half + half);

	return result;
}

int hugs(const string& members, const string& fans)
{
	int n = members.size();
	int m = fans.size();

	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		b[i] = 0;
	}

	for (int i = 0; i < n; i++) a[i] = (members[i] == 'M');
	for (int i = 0; i < m; i++) b[m - i - 1] = (fans[i] == 'M');

	vector<int> c = karatsuba(a, b);

	int count = 0;
	for (int i = n - 1; i < m; i++)
	{
		if (c[i] == 0) count++;
	}

	return count;
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> members;
	vector<string> fans;

	for (int i = 0; i < n; i++)
	{
		string member, fan;
		cin >> member >> fan;

		members.push_back(member);
		fans.push_back(fan);
	}

	for (int i = 0; i < n; i++)
	{
		cout << hugs(members[i], fans[i]) << endl;
	}
}
