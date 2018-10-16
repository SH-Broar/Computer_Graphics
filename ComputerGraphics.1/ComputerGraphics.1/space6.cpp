//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//GLvoid Mouse(int button, int state, int x, int y);
//GLvoid MouseMove(int x, int y);
//
//POINT circle[360];
//
//void init()
//{
//	for (int i = 0; i < 360; i++)
//	{
//		circle[i].x = (double)cos((double)(i + 1) / 180.f * 3.14) * 200;
//		circle[i].y = (double)sin((double)(i + 1) / 180.f * 3.14) * 200;
//	}
//}
//
//int xRotate = 0;
//int yRotate = 0;
//int zRotate = 0;
//
//double z = 0;
//int y = 0;
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 설정
//	init();
//	glutInitWindowPosition(100, 0); // 윈도우의 위치지정
//	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutKeyboardFunc(Keyboard);
//	glutMouseFunc(Mouse);
//	glutMotionFunc(MouseMove);
//	glutTimerFunc(100, Timerfunction, 1);
//	glutMainLoop();
//}
//
//int leftRotate = 0;
//int rightRotate = 0;
//int bothRotate = 0;
//int shape = 0;
//
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.f, 1.0, 1.f, 1000.f);
//	glTranslatef(0.f, 0.f, -500.f);
//	glRotatef(xRotate, 1.f, 0.f, 0.f);
//	glRotatef(yRotate, 0.f, 1.f, 0.f);
//	glRotatef(zRotate, 0.f, 0.f, 1.f);
//
//	gluLookAt(circle[y % 360].y, 3.f, circle[y % 360].x + z, 0.0f, -0.3 , -1.0, 0.0, 1.0, 0.0);
//
//	glMatrixMode(GL_MODELVIEW);
//
//	glPushMatrix();
//	{
//		glColor3f(0.8f, 0.8f, 0.f);
//		glTranslatef(0.f, -20.f, -50.f);
//		glScalef(1.f, 0.01f, 1.f);
//		glutSolidCube(450.f);
//	}glPopMatrix();
//
//	glPushMatrix();
//	{
//		glColor3f(1.f, 0.f, 0.f);
//		glTranslatef(20.f, 0.f, 0.f);
//		glScalef(10.f, 1.f, 1.f);
//		glutSolidCube(4);
//	}glPopMatrix();
//	glPushMatrix();
//	{
//		glColor3f(0.f, 1.f, 0.f);
//		glTranslatef(0.f, 20.f, 0.f);
//		glScalef(1.f, 10.f, 1.f);
//		glutSolidCube(4);
//	}glPopMatrix();
//	glPushMatrix();
//	{
//		glColor3f(0.f, 0.f, 1.f);
//		glTranslatef(0.f, 0.f, 20.f);
//		glScalef(1.f, 1.f, 10.f);
//		glutSolidCube(4);
//	}glPopMatrix();
//
//	glPushMatrix();
//	{
//		glColor3f(0.02f, 0.4f, 0.5f);
//		glTranslatef(0.f, 30.f, 0.f);
//		glRotatef(bothRotate, 0.f, 1.f, 0.f);
//		glTranslatef(-100.f, 0.f, 0.f);
//		glRotatef(leftRotate, 0.f, 1.f, 0.f);
//		switch (shape)
//		{
//		case 0:
//			glutSolidCube(50);
//			break;
//		case 1:
//			glutSolidSphere(50,18,18);
//			break;
//		case 2:
//			glutSolidCylinder(30,60,12,6);
//			break;
//		case 3:
//			glutSolidTeacup(50);
//			break;
//		}
//		
//	}glPopMatrix();
//
//	glPushMatrix();
//	{
//		glColor3f(0.4f, 0.02f, 0.5f);
//		glTranslatef(0.f, 30.f, 0.f);
//		glRotatef(bothRotate, 0.f, 1.f, 0.f);
//		glTranslatef(100.f, 0.f, 0.f);
//		glRotatef(rightRotate, 0.f, 1.f, 0.f);
//		switch (shape)
//		{
//		case 0:
//			glutWireCube(50);
//			break;
//		case 1:
//			glutWireSphere(50, 18, 18);
//			break;
//		case 2:
//			glutWireCylinder(30, 60, 12, 6);
//			break;
//		case 3:
//			glutWireTeacup(50);
//			break;
//		}
//
//	}glPopMatrix();
//
//	glutSwapBuffers(); // 화면에 출력하기
//}
//GLvoid Reshape(int w, int h)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.f, 1.0, 1.f, 1000.f);
//	glTranslatef(0.f, 0.f, -500.f);
//	gluLookAt(0.0, 0.3f, 0.0, 0.0, -0.3, -1.0, 0.0, 1.0, 0.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glutSwapBuffers();
//}
//
//void Timerfunction(int value)
//{
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(1000, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'x':
//		xRotate += 2;
//		break;
//	case 'y':
//		yRotate += 2;
//		break;
//	case 'z':
//		zRotate += 2;
//		break;
//	case 'X':
//		xRotate -= 2;
//		break;
//	case 'Y':
//		yRotate -= 2;
//		break;
//	case 'Z':
//		zRotate -= 2;
//		break;
//	case 'l':
//		leftRotate += 2;
//		break;
//	case 'L':
//		leftRotate -= 2;
//		break;
//	case 'r':
//		rightRotate += 2;
//		break;
//	case 'R':
//		rightRotate -= 2;
//		break;
//	case 'b':
//		bothRotate += 2;
//		break;
//	case 'B':
//		bothRotate -= 2;
//		break;
//	case 'i':
//		z += 0.5;
//		break;
//	case 'o':
//		z -= 0.5;
//		break;
//	case '+':
//		::y += 2;
//		break;
//	case '-':
//		if (::y > 1)
//		::y -= 2;
//		break;
//	case 'c':
//		shape = shape + 1 % 4;
//		break;
//	}
//	glutPostRedisplay();
//}
//
//GLvoid Mouse(int button, int state, int x, int y)
//{
//if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//  }
//}
//GLvoid MouseMove(int x, int y)
//{
//	
//}