//#include <GL/freeglut.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//
//void main(int argc, char *argv[])
//{
//	//�ʱ�ȭ �Լ���
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 100); // �������� ��ġ����
//	glutInitWindowSize(600, 600); // �������� ũ�� ����
//	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutMainLoop();
//}
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	for (int j = 0; j < 20; j++)
//	{
//		for (int i = 0; i < 20; i++)
//		{
//			glColor4f(0.015f * (i+j), 0.04f * (i+j), 0.09f * (i + j),1.0f); //32 144 232
//			glRecti(i * 20 - 200, j * 20 - 200 , (i+1) * 20 - 200, (j+1) * 20 - 200);
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