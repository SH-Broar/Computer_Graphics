#include <GL/freeglut.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);


void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ���
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(800, 600); // �������� ũ�� ����
	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
	glutMainLoop();
}
// ������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glRectf(-1.0f, 1.0f, -0.8f, 0.7f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glRectf(0.8f, 1.0f, 1.0f, 0.7f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glRectf(-1.0f, -0.7f, -0.8f, -1.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glRectf(0.8f, -1.0f, 1.0f, -0.7f);


	glColor4f(0.5f, 0.5f, 0.9f, 1.0f);

	glBegin(GL_LINES);
		glVertex2f(0, 1);
		glVertex2f(0, -1);
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
	glEnd();

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0.1);
	glVertex2f(-0.06, -0.02);
	glVertex2f(0.06, -0.02);
	glEnd();

	
	glFlush(); // ȭ�鿡 ����ϱ�
}
GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}