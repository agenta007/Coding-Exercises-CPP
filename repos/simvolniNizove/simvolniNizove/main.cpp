#include <iostream>
#include <fstream>
using namespace std;
class Ristream {
	int lenstr;
	bool wsp;
public:
	Ristream(int l = 80, bool wsp = true) :lenstr(l), wsp(wsp) {}
	void setSpaces(bool w) { wsp = w; }
	void setLen(int n) { lenstr = n; }
	Ristream& operator>>(int& v) {
		v = rint(); return *this;
	}
	Ristream& operator>>(double& v) {
		v = rdbl(); return *this;
	}
	Ristream& operator>>(unsigned& v) {
		v = rand(); return *this;
	}
	Ristream& operator>>(char* v) {
		rstr(v); return *this;
	}
private:
	int rint() {
		int r = rand();
		return rand() % 2 == 0 ? r : -r;
	}
	double rdbl() {
		double d = rand(), p = d / RAND_MAX;
		return p * rint() * 100.;
	}

	void rstr(char* v) {
		char b[] = " abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < lenstr - 1; i++)
			if (wsp)v[i] = b[rand() % 27];
			else v[i] = b[1 + rand() % 26];
		v[lenstr - 1] = '\0';
	}
};
class Tst {
	double d; int n;
public:
	Tst(int n = 0, double d = 0.) :n(n), d(d) {}
	ostream& ins(ostream& os)const {
		os << n << " " << d;
		return os;
	}
};
ostream& operator<<(ostream& os, const Tst& t) {
	return t.ins(os);
}

void main() 
{
	int sz = sizeof(Tst);
	cout << sz << endl;
	const int N = 10;
	{
		Tst A[N];
		int n; double d;
		Ristream in;
		for (int i = 0; i < N; i++) 
		{
			in >> n >> d;
			A[i] = Tst(n, d);
		}
		ofstream bf("Tsts.bin");
		bf.write((char*)&N, sizeof(N));
		for (int i = 0; i < N; i++) {
			cout << A[i] << endl;
			bf.write((char*)&A[i], sz);
		}
	}
	cout << endl << endl;
	{
		Tst B[N];
		int n;
		ifstream ifb("Tsts.bin");
		ifb.read((char*)&n, sizeof(n));
		for (int i = 0; i < n; i++) {
			ifb.read((char*)&B[i], sz);
			cout << B[i] << endl;
		}
	}
}