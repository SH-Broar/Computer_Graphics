//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//
//POINT sine[360];
//POINT spring[360];
//POINT ribbon[5];
//POINT squares[16];
//
//int offsetZ;
//int rotateX;
//int spin;
//
//void drawInit()
//{
//	for (int i = 0; i < 360; i++)
//	{
//		sine[i].x = i + 300 - 180 - 300;
//		sine[i].y = (double)sin((double)i / 6) * 50 + 450 - 300;
//	}
//	for (int i = 0; i < 360; i++)
//	{
//		spring[i].x = (double)cos((double)i / 6) * 50 + i + 300 - 180 - 300;
//		spring[i].y = (double)sin((double)i / 6) * 50 + 300 - 300;
//	}
//
//	ribbon[0].x = 0 - 50;
//	ribbon[1].x = 0 - 50;
//	ribbon[2].x = 0;
//	ribbon[3].x = 0 + 50;
//	ribbon[4].x = 0 + 50;
//
//	ribbon[0].y = -100 - 10;
//	ribbon[1].y = -100 + 10;
//	ribbon[2].y = -100;
//	ribbon[3].y = -100 - 10;
//	ribbon[4].y = -100 + 10;
//
//	for (int i = 0; i < 4; i++)
//	{
//		squares[0 + i * 4].x = 300 - 120 + 60 * i - 300;
//		squares[0 + i * 4].y = 100 - 300;
//		squares[1 + i * 4].x = 300 - 120 + 60 * i - 300;
//		squares[1 + i * 4].y = 50 - 300;
//		squares[2 + i * 4].x = 300 - 70 + 60 * i - 300;
//		squares[2 + i * 4].y = 50 - 300;
//		squares[3 + i * 4].x = 300 - 70 + 60 * i - 300;
//		squares[3 + i * 4].y = 100 - 300;
//	}
//
//}
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들
//	glutInit(&argc, argv);
//	drawInit();
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 0); // 윈도우의 위치지정
//	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutKeyboardFunc(Keyboard);
//	glutTimerFunc(100, Timerfunction, 1);
//	glutMainLoop();
//}
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	glMatrixMode(GL_MODELVIEW);
//
//
//	glBegin(GL_LINES);
//	{
//		glVertex2f(0.0 - 300, 300.0 - 300);
//		glVertex2f(600.0 - 300, 300.0 - 300);
//		glVertex2f(300.0 - 300, 0.0 - 300);
//		glVertex2f(300.0 - 300, 600.0 - 300);
//	}
//	glEnd();
//
//	glBegin(GL_LINE_STRIP);
//	{
//		for (int i = 0; i < 360; i++)
//		{
//			glVertex2f(sine[i].x, sine[i].y);
//		}
//	}
//	glEnd();
//
//	glBegin(GL_LINE_STRIP);
//	{
//		for (int i = 0; i < 360; i++)
//		{
//			glVertex2f(spring[i].x, spring[i].y);
//		}
//	}
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	{
//		glVertex2f(ribbon[0].x, ribbon[0].y);
//		glVertex2f(ribbon[1].x, ribbon[1].y);
//		glVertex2f(ribbon[2].x, ribbon[2].y);
//
//		glVertex2f(ribbon[2].x, ribbon[2].y);
//		glVertex2f(ribbon[3].x, ribbon[3].y);
//		glVertex2f(ribbon[4].x, ribbon[4].y);
//	}
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			glVertex2f(squares[0 + i * 4].x, squares[0 + i * 4].y);
//			glVertex2f(squares[2 + i * 4].x, squares[2 + i * 4].y);
//			glVertex2f(squares[1 + i * 4].x, squares[1 + i * 4].y);
//			
//			glVertex2f(squares[3 + i * 4].x, squares[3 + i * 4].y);
//		}
//	}
//	glEnd();
//
//	glutSwapBuffers(); // 화면에 출력하기
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//}
//
//void Timerfunction(int value)
//{
//	if (spin == 1)
//	{
//		glRotated(5, 0, 0, 1);
//	}
//	else if (spin == 2)
//	{
//		glRotated(-5, 0, 0, 1);
//	}
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	if (key == 'x')
//	{
//		glTranslatef(10.f, 0.0, 0.0);
//	}
//	if (key == 'X')
//	{
//		glTranslatef(-10.f, 0.0, 0.0);
//	}
//	if (key == 'y')
//	{
//		glTranslatef(0.0, 10.f, 0.0);
//	}
//	if (key == 'Y')
//	{
//		glTranslatef(0.0, -10.f, 0.0);
//	}
//	if (key == 's')
//	{
//		glScalef(0.9f, 0.9f, 1.f);
//	}
//	if (key == 'S')
//	{
//		glScalef(1.1f, 1.1f, 1.f);
//	}
//	if (key == 'a')
//	{
//		spin = 1;
//	}
//	if (key == 'A')
//	{
//		spin = 2;
//	}
//	if (key == 'T')
//	{
//		spin = 0;
//	}
//	if (key == 'q')
//	{
//		exit(0);
//	}
//}