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
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 100); // �������� ��ġ����
//	glutInitWindowSize(600, 600); // �������� ũ�� ����
//	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutMainLoop();
//}
//
//
//
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	//�ʱ�ȭ �Լ���
//	int x = rand() % 25 + 5;
//	int y = x;
//	double color = rand() % 10 + 1;
//
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
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
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
//}