//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//GLvoid Mouse(int button, int state, int x, int y);
//
//POINT circle[360];
//
//bool triangle;
//bool spin;
//int traceCircle;
//
//int rotateS = 0;
//
//int traceRoot;
//
//int ybool = 0;
//int y;
//
//bool drawDone = false;
//int drawCount = 0;
//int traceCount = 0;
//POINT arrLine[5];
//
//void drawInit()
//{
//	for (int i = 0; i < 360; i++)
//	{
//		circle[i].x = (double)cos((double)i / 180 * 3.14) * 100;
//		circle[i].y = (double)sin((double)i / 180 * 3.14) * 100;
//	}
//
//	traceRoot = 0;
//	triangle = true;
//	spin = true;
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
//	glutMouseFunc(Mouse);
//	glutKeyboardFunc(Keyboard);
//	glutTimerFunc(10, Timerfunction, 1);
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
//	glLoadIdentity();
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//
//	if (y)
//	{
//		glRotated(y, 0, 1, 0);
//	}
//	glBegin(GL_LINES);
//	{
//		glVertex2f(0.0 - 300, 300.0 - 300);
//		glVertex2f(600.0 - 300, 300.0 - 300);
//		glVertex2f(300.0 - 300, 0.0 - 300);
//		glVertex2f(300.0 - 300, 600.0 - 300);
//	}
//	glEnd();
//
//	switch (traceRoot)
//	{
//	case 0:
//		glutWireSphere(115, 23, 3);
//		if (triangle)
//		{
//			if (spin)
//			{
//				glTranslatef(circle[traceCircle].x, circle[traceCircle].y, 0.f);
//				glRotated(rotateS, 0, 0, 1);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 3, 3);
//			}
//			else
//			{
//				glTranslatef(circle[traceCircle].x, circle[traceCircle].y, 0.f);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 3, 3);
//			}
//		}
//		else
//		{
//			if (spin)
//			{
//				glTranslatef(circle[traceCircle].x, circle[traceCircle].y, 0.f);
//				glRotated(rotateS, 0, 0, 1);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 4, 3);
//			}
//			else
//			{
//				glTranslatef(circle[traceCircle].x, circle[traceCircle].y, 0.f);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 4, 3);
//			}
//		}
//		break;
//	case 1:
//		glBegin(GL_LINE_STRIP);
//		{
//			for (int i = 0; i < 360; i++)
//			{
//				glVertex2f(i - 180, circle[i].y);
//			}
//		}
//		glEnd();
//		if (triangle)
//		{
//			glTranslatef(traceCircle-180, circle[traceCircle].y, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 3, 3);
//		}
//		else
//		{
//			glTranslatef(traceCircle - 180, circle[traceCircle].y, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 4, 3);
//		}
//		break;
//	case 2:
//		glBegin(GL_LINE_STRIP);
//		{
//			for (int i = 0; i < 3600; i++)
//			{
//				glVertex2f((i/10) - 180 + circle[i%360].x, circle[i%360].y);
//			}
//		}
//		glEnd();
//		if (triangle)
//		{
//			glTranslatef((rotateS/10) - 180 + circle[rotateS%360].x, circle[rotateS%360].y, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 3, 3);
//		}
//		else
//		{
//			glTranslatef((rotateS / 10) - 180 + circle[rotateS % 360].x, circle[rotateS % 360].y, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 4, 3);
//		}
//		break;
//	case 3:
//		glBegin(GL_LINE_STRIP);
//		{
//			for (int i = 0; i < 21; i++)
//			{
//				glVertex2f(i*20-200.f, i%2 == 0 ? 100 : -100);
//			}
//		}
//		glEnd();
//		if (triangle)
//		{
//			glTranslatef(rotateS%400 - 200.f, (abs(rotateS*5 % 200 - 100)-50) * 2, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 3, 3);
//		}
//		else
//		{
//			glTranslatef(rotateS % 400 - 200.f, (abs(rotateS * 5 % 200 - 100) - 50) * 2, 0.f);
//			glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//			glutSolidSphere(25, 4, 3);
//		}
//		break;
//	case 4:
//		glBegin(GL_LINE_STRIP);
//		{
//			for (int i = 0; i < drawCount; i++)
//			{
//				glVertex2f(arrLine[i].x, arrLine[i].y);
//			}
//		}
//		glEnd();
//		if (drawDone)
//		{
//			glTranslated(arrLine[traceCount].x, arrLine[traceCount].y,1.f);
//			if (triangle)
//			{
//				glTranslatef((arrLine[traceCount+1].x - arrLine[traceCount].x) / 20 * rotateS, (arrLine[traceCount + 1].y - arrLine[traceCount].y) / 20 * rotateS, 0.f);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 3, 3);
//				if (rotateS % 20 == 0)
//					traceCount++;
//				if (traceCount > 3)
//					traceCount = 0;
//			}
//			else
//			{
//				glTranslatef((arrLine[traceCount + 1].x - arrLine[traceCount].x) / 20 * rotateS, (arrLine[traceCount + 1].y - arrLine[traceCount].y) / 20 * rotateS, 0.f);
//				glScalef(0.1f * abs(18 - (rotateS % 36)), 0.1f * abs(18 - (rotateS % 36)), 0.f);
//				glutSolidSphere(25, 4, 3);
//				if (rotateS % 20 == 0)
//					traceCount++;
//				if (traceCount > 3)
//					traceCount = 0;
//			}
//			rotateS %= 20;
//		}
//		break;
//	}
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
//	traceCircle++;
//	traceCircle %= 360;
//	rotateS++;
//
//	if (ybool == -1)
//	{
//		y--;
//	}
//	else if (ybool == 1)
//	{
//		y++;
//	}
//
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(10, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'p':
//		if (spin)
//			spin = false;
//		else
//			spin = true;
//		break;
//	case 'o':
//		if (triangle)
//			triangle = false;
//		else
//			triangle = true;
//		break;
//	case '0':
//		traceRoot = 0;
//		break;
//	case '1':
//		traceRoot = 1;
//		break;
//	case '2':
//		traceRoot = 2;
//		break;
//	case '3':
//		traceRoot = 3;
//		break;
//	case '4':
//		traceRoot = 4;
//		break;
//	case 'y':
//		if (ybool == 1)
//			ybool = 0;
//		else 
//			ybool = 1;
//		break;
//	case 'Y':
//		if (ybool == -1)
//			ybool = 0;
//		else
//			ybool = -1;
//		break;
//	}
//}
//
//GLvoid Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && traceRoot == 4)
//	{
//		if (drawCount < 5)
//		{
//			arrLine[drawCount].x = x - 300;
//			arrLine[drawCount].y = 600-y - 300;
//			drawCount++;
//		}
//		else
//		{
//			drawDone = true;
//			rotateS = 0;
//		}
//	}
//}