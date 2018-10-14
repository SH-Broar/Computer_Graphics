//#include <GL/freeglut.h>
//#include <random>
//#include <time.h>
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
//
//void drawshape(int x,int y,int numberOfVertex)
//{
//	switch (numberOfVertex)
//	{
//	case 2:
//		glBegin(GL_LINES);
//		glVertex2f(x-20, y-15);
//		glVertex2f(x+20, y+15);
//		break;
//	case 3:
//		glBegin(GL_TRIANGLES);
//		glVertex2f(x+30, y - 25);
//		glVertex2f(x, y + 35);
//		glVertex2f(x - 25, y - 15);
//		break;
//	case 4:
//		glBegin(GL_QUADS);
//		glVertex2f(x - 20, y - 20);
//		glVertex2f(x + 20, y - 15);
//		glVertex2f(x + 15, y + 10);
//		glVertex2f(x - 22, y + 15);
//		break;
//	case 5:
//		glBegin(GL_POLYGON);
//		glVertex2f(x - 20, y - 20);
//		glVertex2f(x + 20, y - 15);
//		glVertex2f(x + 15, y + 10);
//		glVertex2f(x, y + 30);
//		glVertex2f(x - 22, y + 15);
//		break;
//	}
//	glEnd();
//
//
//}
//
//GLvoid drawScene(GLvoid)
//{
//	srand((unsigned int)time(NULL));
//	int x[3] = { 50, 150, 250 };
//	int y[3] = { 50, 150, 250 };
//	int shapeVertex = rand() % 4 + 2;
//	bool upper = true;
//
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // �������� 'blue' �� ����
//	glBegin(GL_LINES);
//	glVertex2f(100, 300);
//	glVertex2f(100, 0);
//	glVertex2f(200, 300);
//	glVertex2f(200, 0);
//	glVertex2f(300, 100);
//	glVertex2f(0, 100);
//	glVertex2f(300, 200);
//	glVertex2f(0, 200);
//	glEnd();
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			drawshape(x[j], y[i], shapeVertex);
//
//			if (shapeVertex >= 5)
//				upper = false;
//			if (shapeVertex <= 2)
//				upper = true;
//
//			if (upper == false && shapeVertex == 5)
//			{
//				shapeVertex--;
//			}
//			else if (upper == true && shapeVertex == 2)
//			{
//				shapeVertex++;
//			}
//			else if (upper)
//			{
//				shapeVertex++;
//			}
//			else
//			{
//				shapeVertex--;
//			}
//
//		}
//	}
//
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, 300.0, 0.0, 300.0, -1.0, 1.0);
//}