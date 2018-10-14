//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int vec1[3];
//	int vec2[3];
//	char command;
//	cout << "input vector1 :";
//	cin >> vec1[0] >> vec1[1] >> vec1[2];
//	cout << "input vector2 :";
//	cin >> vec2[0] >> vec2[1] >> vec2[2];
//
//	while (true)
//	{
//		cin >> command;
//
//		switch (command)
//		{
//		case '+':
//			cout << vec1[0]<<", " << vec1[1] << ", " << vec1[2] << " + " << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << " = " << vec1[0]+vec2[0] << ", " << vec1[1] + vec2[1] << ", " << vec1[2] + vec2[2] << endl;
//			break;
//		case '-':
//			cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << " - " << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << " = " << vec1[0] - vec2[0] << ", " << vec1[1] - vec2[1] << ", " << vec1[2] - vec2[2] << endl;
//			break;
//		case 'd':
//			cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << " * " << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << " = " << vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2] << endl;
//			break;
//		case 'c':
//			cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << " x " << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << " = " << vec1[1]*vec2[2] - vec1[2]*vec2[1] << ", " << vec1[2] * vec2[0] - vec1[0] * vec2[2] << ", " << vec1[0] * vec2[1] - vec1[1] * vec2[0] << endl;
//			break;
//		case 'l':
//			cout << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << " => " << sqrt(vec1[0] + vec1[1] + vec1[2]) << "  " << vec2[0] << ", " << vec2[1] << ", " << vec2[2] << " => " << sqrt(vec2[0] + vec2[1] + vec2[2]) << endl;
//			break;
//		}
//	}
//}
