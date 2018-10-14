//#include <GL/freeglut.h>
//#include <random>
//#include <time.h>
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//
//
//
//void main(int argc, char *argv[])
//{
//	srand((unsigned int)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
//	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutMainLoop();
//}
//
//
//
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	//초기화 함수들
//	int x = rand() % 25 + 5;
//	int y = x;
//	double color = rand() % 10 + 1;
//
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	for (int j = 0; j < x; j++)
//	{
//		for (int i = 0; i < y; i++)
//		{
//			glColor4f(color/100.0f * (i+j), color/60.0f * (i+j), color/70.0f * (i + j),1.0f); //32 144 232
//			glRecti(i * (440/x) - 200, j * (440 / x) - 200 , (i+1) * (440 / x) - 200, (j+1) * (440 / x) - 200);
//		}
//	}
//
//	glFlush(); // 화면에 출력하기
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
//}