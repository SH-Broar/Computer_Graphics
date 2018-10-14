//#include <iostream>
//using namespace std;
//
//
//
//void collid(int* Rect, int* Circle)
//{
//
//	if (sqrt((Circle[0] - Rect[0])*(Circle[0] - Rect[0]) +(Circle[1] - Rect[1])*(Circle[1] - Rect[1])) <= Circle[2]
//		|| sqrt((Circle[0] - Rect[0])*(Circle[0] - Rect[0]) +(Circle[0] - Rect[3])*(Circle[0] - Rect[3])) <= Circle[2]
//		|| sqrt((Circle[0] - Rect[2])*(Circle[0] - Rect[2]) +(Circle[1] - Rect[1])*(Circle[1] - Rect[1])) <= Circle[2]
//		|| sqrt((Circle[0] - Rect[2])*(Circle[0] - Rect[2]) +(Circle[0] - Rect[3])*(Circle[0] - Rect[3])) <= Circle[2])
//	{
//		cout << "Shape 1 & 2 Collided!" << endl;
//	}
//	else if ((Circle[0]-Circle[2] >= Rect[0] && Circle[1] >= Rect[1] && Circle[0] - Circle[2] <= Rect[2] && Circle[1] <= Rect[3]) ||
//		(Circle[0] >= Rect[0] && Circle[1] - Circle[2] >= Rect[1] && Circle[0] <= Rect[2] && Circle[1] - Circle[2] <= Rect[3]) ||
//		(Circle[0] + Circle[2] >= Rect[0] && Circle[1] >= Rect[1] && Circle[0] + Circle[2] <= Rect[2] && Circle[1] <= Rect[3]) ||
//		(Circle[0] >= Rect[0] && Circle[1] + Circle[2] >= Rect[1] && Circle[0] <= Rect[2] && Circle[1] + Circle[2] <= Rect[3]) )
//	{
//		cout << "Shape 1 & 2 Collided!" << endl;
//	}
//}
//
//int main()
//{
//	int Rect[4]; //x1,y1,x2,y2;
//	int Circle[3]; //x,y,rad;
//	char command;
//	cout << "Rectangle X Circle" << endl << endl;
//
//	cout << "Shape1 (Rect x1,y1,x2,y2) : ";
//	cin >> Rect[0] >> Rect[1] >> Rect[2] >> Rect[3];
//	cout << "Shape2 (Circle x,y,rad) : ";
//	cin >> Circle[0] >> Circle[1] >> Circle[2];
//
//	while (true)
//	{
//		cin >> command;
//
//		switch (command)
//		{
//		case 'a':
//			Circle[0] -= 20;
//			break;
//		case 'd':
//			Circle[0] += 20;
//			break;
//		case 's':
//			Circle[1] += 20;
//			break;
//		case 'w':
//			Circle[1] -= 20;
//			break;
//		default:
//			cout << "error" << endl;
//			continue;
//			break;
//		}
//
//		cout << "Shape 1 (Rect) : " << Rect[0] << " " << Rect[1] <<" " <<" " << Rect[2] << " " << Rect[3] << endl;
//		cout << "Shape 2 (Circle) : " << Circle[0] << " " << Circle[1] << " " << Circle[2] << endl;
//
//		collid(Rect, Circle);
//	}
//}