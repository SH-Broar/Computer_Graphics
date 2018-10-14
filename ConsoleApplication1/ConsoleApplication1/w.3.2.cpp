//#include <iostream>
//#include <ctime>
//#include <Windows.h>
//using namespace std;
//
//class Maze
//{
//	int wall[25][25];
//	int direction;
//
//	int tick;
//
//	int x, y;
//
//	bool end = false;
//public:
//	Maze()
//	{
//		init();
//	}
//	void init()
//	{
//		direction = 2;
//
//		tick = 0;
//
//		x = 0, y = 0;
//		for (int i = 0; i < 25; i++)
//		{
//			for (int j = 0; j < 25; j++)
//			{
//				wall[i][j] = 1;
//			}
//		}
//
//		end = false;
//	}
//
//	void drag()
//	{
//		if (x < 0 || x > 24 || y < 0 || y > 24)
//			init();
//
//		{
//			int count = 0;
//
//			if (wall[y - 1][x] == 0) count++;
//			if (wall[y + 1][x] == 0) count++;
//			if (wall[y][x - 1] == 0) count++;
//			if (wall[y][x + 1] == 0) count++;
//
//			//cout << "\"" << count << "\"" << x << "\"" << y << endl;
//			if (count > 1)
//			{
//				init();
//				//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//			}
//		}
//
//		switch (direction)
//		{
//		case 0:
//			wall[y][x] = 0;
//			if (x > 0)
//				x--;
//
//			tick++;
//
//			if (tick > 1 && tick < 3)
//			{
//				int i = rand() % 4;
//				while (i == 2)
//				{
//					i = rand() % 4;
//				}
//				if (direction != i)
//					tick = 0;
//
//				direction = 3;
//
//			}
//			if (x == 0)
//			{
//				direction = 3;
//			}
//			if (tick >= 3)
//			{
//				direction = 3;
//				tick = 0;
//			}
//			break;
//		case 1:
//			wall[y][x] = 0;
//			if (y > 0)
//				y--;
//
//			tick++;
//
//			if (tick > 1 && tick < 4)
//			{
//				int i = rand() % 4;
//				while (i == 3)
//				{
//					i = rand() % 4;
//				}
//				if (direction != i)
//					tick = 0;
//				direction = 2;
//			}
//			if (y == 0)
//			{
//				direction = 2;
//			}
//			if (tick >= 4)
//			{
//				direction = 2;
//				tick = 0;
//			}
//			break;
//		case 2:
//			wall[y][x] = 0;
//			x++;
//
//			tick++;
//
//			if (tick > 2 && tick < 4)
//			{
//				int i = rand() % 4;
//				while (i == 0)
//				{
//					i = rand() % 4;
//				}
//				if (direction != i)
//					tick = 0;
//				direction = i;
//			}
//			if (x == 24)
//			{
//				direction = 3;
//			}
//			if (tick >= 4 || y == 0 && x == 4)
//			{
//				direction = 3;
//				tick = 0;
//			}
//			break;
//		case 3:
//			wall[y][x] = 0;
//			y++;
//
//			tick++;
//
//			if (tick > 1 && tick < 4)
//			{
//				int i = rand() % 4;
//				while (i == 1)
//				{
//					i = rand() % 4;
//				}
//				if (direction != i)
//					tick = 0;
//				direction = i;
//			}
//			if (y == 24)
//			{
//				direction = 2;
//			}
//			if (tick >= 4)
//			{
//				direction = 2;
//				tick = 0;
//			}
//			break;
//		}
//		if (x == y && x == 24)
//		{
//			wall[24][24] = 0;
//			end = true;
//		}
//		//-------------------------------------
//		
//		//--------------------------------------
//	}
//	bool isEnd()
//	{
//		return end;
//	}
//	void press()
//	{
//		for (int i = 0; i < 25; i++)
//		{
//			for (int j = 0; j < 25; j++)
//			{
//				cout << wall[i][j];
//			}
//			cout << endl;
//		}
//
//		//cout << x << " " << y << " " << tick << " " << direction;
//	}
//};
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	Maze meiro;
//	char a;
//	
//	while (true)
//	{
//		meiro.init();
//		while (meiro.isEnd() == false)
//		{
//			//system("cls");
//			meiro.drag();
//
//
//			//getchar();
//		}
//		meiro.press();
//		a = getchar();
//		system("cls");
//
//		if (a == 'q')
//			exit(0);
//	}
//}