#include <iostream>
using namespace std;

class point
{
	int x;
	int y;
	int z;
	float dist;

public:
	point()
	{}
	point(int a, int b, int c)
	{
		setPoint(a, b, c);
	}

	void print()
	{
		cout << x << " " << y << " " << z << " " << dist << endl;
	}
	void setPoint(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
		dister();
	}
	void dister()
	{
		dist = sqrt(x*x + y*y + z*z);
	}
	int getdister()
	{
		return dist;
	}
};

class Liszt
{
	int top = 0;
	int tail = 0;
	point list[10];

public:
	Liszt()
	{
	}

	void plus(int a, int b, int c)
	{
		list[top].setPoint(a, b, c);
		list[top].dister();

		top++;
		if (top == 11)
		{
			cout << "리스트의 상단 끝입니다." << endl;
			top--;
		}
	}
	void minus()
	{
		top--;
		if (top == -1)
		{
			cout << "더 이상 제거할 데이터가 없습니다" << endl;
			top++;
		}
	}

	void e(int a, int b, int c)
	{
		if (tail == 0)
		{
			for (int i = top - 1; i >= tail; i--)
			{
				memcpy(&list[i + 1], &list[i], sizeof(point));
			}
			top++;
			list[tail].setPoint(a, b, c);
			list[tail].dister();
			if (top == 11)
			{
				cout << "리스트가 넘쳤습니다!" << endl;
				top--;
			}
		}
		else
		{
			tail--;
			list[tail].setPoint(a, b, c);
			list[tail].dister();
		}
	}

	void d()
	{
		if (tail < top)
			tail++;
		else
			cout << "더이상 제거할 데이터가 없습니다" << endl;
	}

	void l()
	{
		cout << "리스트의 길이: " << top - tail << endl;
	}

	void c()
	{
		top = 0;
		tail = 0;
	}

	void m()
	{
		int findmax = 0;
		int finder = 0;

		if (top == tail)
		{
			cout << "출력할 정보가 없습니다" << endl;
			return;
		}
		for (int i = tail; i < top; i++)
		{
			if (list[i].getdister() > findmax)
			{
				findmax = list[i].getdister();
				finder = i;
			}
		}
		list[finder].print();
	}

	void n()
	{
		int findmin = INT_MAX;
		int finder = 0;

		if (top == tail)
		{
			cout << "출력할 정보가 없습니다" << endl;
			return;
		}

		for (int i = tail; i < top; i++)
		{
			if (list[i].getdister() < findmin)
			{
				findmin = list[i].getdister();
				finder = i;
			}
		}
		list[finder].print();
	}

	void print()
	{
		for (int i = top; i > tail; i--)
		{
			cout << i-1 << ". ";
			list[i-1].print();
		}
		for (int i = tail-1; i >= 0; i--)
		{
			cout << i << ". " << endl;
		}
	}
};

int main()
{
	char command;
	int a, b, c;
	Liszt listz;
	
	while (true)
	{
		cout << "명령어를 입력해주세요:";
		cin >> command;
		switch (command)
		{
		case '+':
			cin >> a >> b >> c;
			listz.plus(a, b, c);
			listz.print();
			break;
		case '-':
			listz.minus();
			listz.print();
			break;
		case 'e':
			cin >> a >> b >> c;
			listz.e(a, b, c);
			listz.print();
			break;
		case 'd':
			listz.d();
			listz.print();
			break;
		case 'l':
			listz.l();
			break;
		case 'c':
			listz.c();
			break;
		case 'm':
			listz.m();
			break;
		case 'n':
			listz.n();
			break;
		case 'q':
			exit(0);
			break;
		}
		fflush(stdin);
	}
}