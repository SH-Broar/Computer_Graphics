#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

class Maze
{
	int wall[25][25] = { 0 };
	int direction = 0;
	int bdirection = 1;

	int tick = 0;
	int btick = 0;

	int x = 0,y = 0;
	int dx = 24, dy = 24;

	bool end = false;
public:
	Maze()
	{
		init();
	}
	void init()
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				wall[i][j] = 1;
			}
		}
	}

	void drag()
	{
		switch (direction)
		{
		case 0:
			if (x >= 24)
			{
				direction = 3;
			}
			else
			{
				if (wall[x][y] == 2)
					end = true;
				else
				{
					wall[x][y] = 0;
					x++;
				}
			}
			break;
		case 1:
			if (x < 1)
			{
				direction = 3;
			}
			else
			{

				if (wall[x][y] == 2)
					end = true;
				else
				{
					wall[x][y] = 0;
					x--;
				}
			}
			break;
		case 2:
			if (y >= 24)
			{
				direction = 1;
			}
			else
			{

				if (wall[x][y] == 2)
					end = true;
				else
				{
					wall[x][y] = 0;
					y++;
				}
			}
			break;
		case 3:
			if (y < 1)
			{
				direction = 1;
			}
			else
			{

				if (wall[x][y] == 2)
					end = true;
				else
				{
					wall[x][y] = 0;
					y--;
				}
			}
			break;
		}
		switch (bdirection)
		{
		case 0:
			if (dx >= 24)
			{
				bdirection = 3;
			}
			else
			{
				if (wall[dx][dy] == 0)
					end = true;
				else
				{
					wall[dx][dy] = 2;
					dx++;
				}
			}
			break;
		case 1:
			if (dx < 1)
			{
				bdirection = 3;
			}
			else
			{
				if (wall[dx][dy] == 0)
					end = true;
				else
				{
					wall[dx][dy] = 2;
					dx--;
				}
			}
			break;
		case 2:
			if (dy >= 24)
			{
				bdirection = 1;
			}
			else
			{
				if (wall[dx][dy] == 0)
					end = true;
				else
				{
					wall[dx][dy] = 2;
					dy++;
				}
			}
			break;
		case 3:
			if (dy < 1)
			{
				bdirection = 1;
			}
			else
			{
				if (wall[dx][dy] == 0)
					end = true;
				else
				{
					wall[dx][dy] = 2;
					dy--;
				}
			}
			break;
		}
		turn();
		bturn();
	}

	void turn()
	{
		if (tick > 1)
		{
			int tmp;
			tmp = rand() % 4;
			if (rand() % 10 > 4)
			{
				if (direction != tmp)
					tick = 0;
				
				direction = tmp;
			}
		}

		if (tick == 4)
		{
			direction += 1;
			if (direction == 4)
				direction = 0;
			tick = 0;
		}
		tick++;
	}
	void bturn()
	{
		if (btick > 1)
		{
			int tmp;
			tmp = rand() % 4;
			if (rand() % 10 > 7)
			{
				if (bdirection != tmp)
					btick = 0;
				bdirection = tmp;
			}
		}
		if (btick == 4)
		{
			bdirection -= 1;
			if (bdirection == -1)
				bdirection = 3;
			btick = 0;
		}
		btick++;
	}
	bool isEnd()
	{
		return end;
	}
	void press()
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cout << wall[i][j];
			}
			cout << endl;
		}

		cout << x << " " << y << endl;
	}
};

int main()
{
	srand((unsigned int)time(NULL));
	Maze meiro;

	meiro.init();

	while (meiro.isEnd() == false)
	{
		//system("cls");
		meiro.drag();
		
	}
	Sleep(10);
	meiro.press();
}