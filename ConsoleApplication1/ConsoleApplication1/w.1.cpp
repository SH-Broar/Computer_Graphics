#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Tmatrix
{
private:
	int aa; int ab; int ac;
	int ba; int bb; int bc;
	int ca; int cb; int cc;

public:
	Tmatrix()
	{
		init();
	}
	void init()
	{
		aa = rand() % 2;
		ab = rand() % 2;
		ac = rand() % 2;
		ba = rand() % 2;
		bb = rand() % 2;
		bc = rand() % 2;
		ca = rand() % 2;
		cb = rand() % 2;
		cc = rand() % 2;
	}
	void Multi(Tmatrix doMath)
	{
		Tmatrix result;
		this->init();
		doMath.init();

		getA();
		cout << "   ";
		doMath.getA();
		cout << "   ";

		result.aa = aa*doMath.aa + ab*doMath.ba + ac*doMath.ca;
		result.ab = aa*doMath.ab + ab*doMath.bb + ac*doMath.cb;
		result.ac = aa*doMath.ac + ab*doMath.bc + ac*doMath.cc;
		result.getA();
		cout << endl;
		
		getB();
		cout << " * ";
		doMath.getB();
		cout << " = ";

		result.ba = ba*doMath.aa + bb*doMath.ba + bc*doMath.ca;
		result.bb = ba*doMath.ab + bb*doMath.bb + bc*doMath.cb;
		result.bc = ba*doMath.ac + bb*doMath.bc + bc*doMath.cc;
		result.getB();
		cout << endl;

		getC();
		cout << "   ";
		doMath.getC();
		cout << "   ";

		result.ca = ca*doMath.aa + cb*doMath.ba + cc*doMath.ca;
		result.cb = ca*doMath.ab + cb*doMath.bb + cc*doMath.cb;
		result.cc = ca*doMath.ac + cb*doMath.bc + cc*doMath.cc;
		result.getC();
		cout << endl;
		
	}
	void Add(Tmatrix doMath)
	{
		this->init();
		doMath.init();

		getA();
		cout << "   ";
		doMath.getA();
		cout << "   ";

		aa += doMath.aa;
		ab += doMath.ab;
		ac += doMath.ac;

		getA();
		cout << endl;

		getB();
		cout << " + ";
		doMath.getB();
		cout << " = ";

		ba += doMath.ba;
		bb += doMath.bb;
		bc += doMath.bc;

		getB();
		cout << endl;

		getC();
		cout << "   ";
		doMath.getC();
		cout << "   ";

		ca += doMath.ca;
		cb += doMath.cb;
		cc += doMath.cc;

		getC();
		cout << endl;

	}
	void Minus(Tmatrix doMath)
	{
		this->init();
		doMath.init();

		getA();
		cout << "   ";
		doMath.getA();
		cout << "   ";

		aa -= doMath.aa;
		ab -= doMath.ab;
		ac -= doMath.ac;

		getA();
		cout << endl;

		getB();
		cout << " - ";
		doMath.getB();
		cout << " = ";

		ba -= doMath.ba;
		bb -= doMath.bb;
		bc -= doMath.bc;

		getB();
		cout << endl;

		getC();
		cout << "   ";
		doMath.getC();
		cout << "   ";

		ca -= doMath.ca;
		cb -= doMath.cb;
		cc -= doMath.cc;

		getC();
		cout << endl;

	}
	void Det()
	{
		int result = 0;
		this->init();

		result = aa*bb*cc + ab*bc*ca + ac*ba*cb	- ac*bb*ca - ab*ba*cc - aa*bc*cb;

		getA();
		cout << endl;
		getB();
		cout << " -> " << result << endl;
		getC();
		cout << endl;
	}
	void Expansion()
	{
		this->init();

		getA();
		cout << "    ";
		getA();
		cout << "0"<<endl;
		getB();
		cout << " -> ";
		getB();
		cout << "0" << endl;
		getC();
		cout << "    ";
		getC();
		cout << "0" << endl;
		cout << "       0001"<<endl;
	}

	void getA()
	{
		cout << aa << ab << ac;
	}
	void getB()
	{
		cout << ba << bb << bc;
	}
	void getC()
	{
		cout << ca << cb << cc;
	}
};

int main()
{
	srand((unsigned int)time(NULL));
	Tmatrix beMath, doMath;

	while (true)
	{
		string commander;
		cout << "명령어를 입력해주세요: ";
		//명령어 입력받기
		getline(cin, commander);

		if (commander.length() > 1)
		{
			cout << endl;
			continue;
		}
		switch (*commander.data())
		{
		case 'm':
		case 'M':
			beMath.Multi(doMath);
			break;
		case 'a':
		case 'A':
			beMath.Add(doMath);
			break;
		case 'd':
		case 'D':
			beMath.Minus(doMath);
			break;
		case 'r':
		case 'R':
			beMath.Det();
			break;
		case 'h':
		case 'H':
			beMath.Expansion();
			break;
		}
	}
}