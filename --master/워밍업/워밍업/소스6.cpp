//#include <stdio.h>
//#include <Windows.h>
//int main()
//{
//	char table[30][30];
//	int shape;
//	int Rect[4];
//	char command = '\0';
//	
//	while (true)
//	{
//		system("cls");
//		printf("input coord value : ");
//		scanf("%d %d %d %d %d", &shape, &Rect[0], &Rect[1], &Rect[2], &Rect[3]);
//
//		while (command != 'r')
//		{
//			system("cls");
//			for (int i = 0; i < 30; i++)
//			{
//				for (int j = 0; j < 30; j++)
//				{
//					if (j >= Rect[0] && j <= Rect[2] && i >= Rect[1] && i <= Rect[3])
//					{
//						printf("%2c", '0');
//					}
//					else
//					{
//						printf(" .");
//					}
//				}
//				printf("\n");
//			}
//		P:
//			printf("command : ");
//			scanf(" %c", &command);
//
//			switch (command)
//			{
//			case 'x':
//				if (Rect[2] < 29)
//				{
//					Rect[0]++; Rect[2]++;
//				}
//				break;
//			case 'X':
//				if (Rect[0] > 0)
//				{
//					Rect[0]--; Rect[2]--;
//				}
//				break;
//			case 'y':
//				if (Rect[3] < 29)
//				{
//					Rect[3]++; Rect[1]++;
//				}
//				break;
//			case 'Y':
//				if (Rect[1] > 0)
//				{
//					Rect[1]--; Rect[3]--;
//				}
//				break;
//			case 's':
//				if (Rect[0] > 0 && Rect[1] > 0 && Rect[2] < 29 && Rect[3] < 29)
//				{
//					Rect[0]--; Rect[1]--; Rect[2]++; Rect[3]++;
//				}
//				break;
//			case 'S':
//				if (Rect[0] < Rect[2] && Rect[1] < Rect[3])
//				{
//					Rect[0]++; Rect[1]++; Rect[2]--; Rect[3]--;
//				}
//				break;
//			case 'i':
//				if (Rect[0] > 0 && Rect[2] < 29)
//				{
//					Rect[0]--; Rect[2]++;
//				}
//				break;
//			case 'j':
//				if (Rect[0] < Rect[2])
//				{
//					Rect[0]++; Rect[2]--;
//				}
//				break;
//			case 'k':
//				if (Rect[1] > 0 && Rect[3] < 29)
//				{
//					Rect[1]--; Rect[3]++;
//				}
//				break;
//			case 'l':
//				if (Rect[1] < Rect[3])
//				{
//					Rect[1]++; Rect[3]--;
//				}
//				break;
//			case 'r':
//
//				break;
//			default:
//				printf("\n");
//				goto P;
//				break;
//			}
//		}
//	}
//}