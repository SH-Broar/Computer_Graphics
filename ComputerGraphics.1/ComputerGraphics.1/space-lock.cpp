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
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ���
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 0); // �������� ��ġ����
//	glutInitWindowSize(600, 600); // �������� ũ�� ����
//	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutKeyboardFunc(Keyboard);
//	glutMouseFunc(Mouse);
//	glutMotionFunc(MouseMove);
//	glutTimerFunc(100, Timerfunction, 1);
//	glutMainLoop();
//}
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	glMatrixMode(GL_PROJECTION);
//	gluPerspective(60.f, 1 / 1.618, 1.0, 400.0);
//	glMatrixMode(GL_MODELVIEW);
//
//	glLoadIdentity();
//	glBegin(GL_QUADS);
//	{
//
//	}
//	glEnd();
//
//	glutSwapBuffers(); // ȭ�鿡 ����ϱ�
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	gluPerspective(60.f, 1 / 1.618, 1.0, 400.0);
//}
//
//void Timerfunction(int value)
//{
//
//	glutPostRedisplay(); // ȭ�� �� ���
//	glutTimerFunc(100, Timerfunction, 1); // Ÿ�̸��Լ� �� ����
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//
//}
//
//GLvoid Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//	}
//}
//GLvoid MouseMove(int x, int y)
//{
//
//}