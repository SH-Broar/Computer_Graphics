//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//
//typedef struct _P
//{
//	float x;
//	float y;
//}POINTf;
//
//int yRotate = 0;
//int yScale = 1;
//
//POINTf triPoint[3];
//int triTurn = 0;
//int lineNum = 0;
//
//
//void main(int argc, char *argv[])
//{
//	triPoint[0].x = -100;
//	triPoint[0].y = -70;
//	triPoint[1].x = 100;
//	triPoint[1].y = -70;
//	triPoint[2].x = 0;
//	triPoint[2].y = 100;
//	//�ʱ�ȭ �Լ���
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 0); // �������� ��ġ����
//	glutInitWindowSize(600, 600); // �������� ũ�� ����
//	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutKeyboardFunc(Keyboard);
//	glutTimerFunc(100, Timerfunction, 1);
//	glutMainLoop();
//}
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//
//	glRotated(yRotate, 0, 1, 0);
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
//
//	glScaled(1.0 / yScale, 1.0 / yScale, 1.f);
//
//	glPushMatrix();
//	{
//		switch (lineNum)
//		{
//		case 0:
//			glTranslatef(0.f, 100.f, 0.f);
//			glTranslatef((triPoint[0].x - triPoint[2].x) / 36.f * triTurn, (triPoint[0].y - triPoint[2].y) / 36.f * triTurn, 1.f);
//			break;
//		case 1:
//			glTranslatef(-100.f, -70.f, 0.f);
//			glTranslatef((triPoint[1].x - triPoint[0].x) / 36.f * triTurn, (triPoint[1].y - triPoint[0].y) / 36.f * triTurn, 1.f);
//			break;
//		case 2:
//			glTranslatef(100.f, -70.f, 0.f);
//			glTranslatef((triPoint[2].x - triPoint[1].x) / 36.f * triTurn, (triPoint[2].y - triPoint[1].y) / 36.f * triTurn, 1.f);
//			break;
//		}
//		glRotated(triTurn * 10, 0, 1, 0);
//		glutWireSphere(25 * yScale, 3, 3);
//	} glPopMatrix();
//
//	glPushMatrix();
//	{
//		glRotated(90, 0, 1, 0);
//		switch (lineNum)
//		{
//		case 0:
//			glTranslatef(0.f, 100.f, 0.f);
//			glTranslatef((triPoint[0].x - triPoint[2].x) / 36.f * triTurn, (triPoint[0].y - triPoint[2].y) / 36.f * triTurn, 1.f);
//			break;
//		case 1:
//			glTranslatef(-100.f, -70.f, 0.f);
//			glTranslatef((triPoint[1].x - triPoint[0].x) / 36.f * triTurn, (triPoint[1].y - triPoint[0].y) / 36.f * triTurn, 1.f);
//			break;
//		case 2:
//			glTranslatef(100.f, -70.f, 0.f);
//			glTranslatef((triPoint[2].x - triPoint[1].x) / 36.f * triTurn, (triPoint[2].y - triPoint[1].y) / 36.f * triTurn, 1.f);
//			break;
//		}
//		glRotated(triTurn * 10, 0, 1, 0);
//		glutWireSphere(25 * yScale, 3, 3);
//	} glPopMatrix();
//
//	glBegin(GL_LINE_STRIP);
//	{
//		glVertex2f(triPoint[0].x, triPoint[0].y);
//		glVertex2f(triPoint[1].x, triPoint[1].y);
//		glVertex2f(triPoint[2].x, triPoint[2].y);
//		glVertex2f(triPoint[0].x, triPoint[0].y);
//	}
//	glEnd();
//	glRotated(90, 0, 1, 0);
//	glBegin(GL_LINE_STRIP);
//	{
//		glVertex2f(triPoint[0].x, triPoint[0].y);
//		glVertex2f(triPoint[1].x, triPoint[1].y);
//		glVertex2f(triPoint[2].x, triPoint[2].y);
//		glVertex2f(triPoint[0].x, triPoint[0].y);
//	}
//	glEnd();
//
//	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//}
//
//void Timerfunction(int value)
//{
//	triTurn++;
//	if (triTurn > 36)
//	{
//		triTurn %= 36;
//		lineNum++;
//		if (lineNum > 2)
//			lineNum = 0;
//	}
//	
//
//
//	glutPostRedisplay(); // ȭ�� �� ���
//	glutTimerFunc(100, Timerfunction, 1); // Ÿ�̸��Լ� �� ����
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'y':
//		yRotate += 4;
//		break;
//	case 'Y':
//		yRotate -= 4;
//		break;
//	case 's':
//		yScale += 1;
//		break;
//	case 'S':
//		yScale -= 1;
//		break;
//	}
//}