//#include <GL/freeglut.h>
//#include <random>
//#include <time.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Mouse(int button, int state, int x, int y);
//GLvoid Timerfunction(int value);
//
//int total = 0;
//typedef struct _point
//{
//	double x;
//	double y;
//	double angle;
//	double r;
//}point;
//
//class fireworks
//{
//	int x;
//	int y;
//	bool spread;
//	point p[36];
//	fireworks* next;
//
//public:
//	fireworks()
//	{}
//	fireworks(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//		spread = true;
//		for (int i = 0; i < 36; i++)
//		{
//			p[i].x = x;
//			p[i].y = y;
//			p[i].r = 0;
//			p[i].angle = 2.0 * 3.14 / 36.0 * (double)i;
//		}
//		next = NULL;
//	}
//	fireworks* getNext()
//	{
//		return next;
//	}
//	bool getSpread()
//	{
//		return spread;
//	}
//	void setNext(fireworks* n)
//	{
//		next = n;
//	}
//
//	void anim()
//	{
//		if (spread)
//		{
//			for (int i = 0; i < 36; i++)
//			{
//				p[i].r += 3;
//			}
//		}
//		else
//		{
//			for (int i = 0; i < 36; i++)
//			{
//				p[i].r += 3;
//			}
//			if (p[0].r > 100)
//			{
//				for (int i = 0; i < 36; i++)
//				{
//					p[i].r = 0;
//				}
//			}
//		}
//	}
//
//	void rend()
//	{
//		glBegin(GL_POINTS);
//		for (int i = 0; i < 36; i++)
//		{
//			glVertex2i(p[i].x + p[i].r*cos(p[i].angle), p[i].y + p[i].r*sin(p[i].angle));
//		}
//		glEnd();
//	}
//};
//
//fireworks* boom;
//
//void main(int argc, char *argv[])
//{
//	srand((unsigned int)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
//	glutInitWindowPosition(100, 100); // �������� ��ġ����
//	glutInitWindowSize(800, 600); // �������� ũ�� ����
//	glutCreateWindow("Example"); // ������ ���� (������ �̸�)
//
//	glutDisplayFunc(drawScene); // ��� �Լ��� ����
//	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
//	glutMouseFunc(Mouse);
//	glutTimerFunc(100, Timerfunction, 1);
//
//	glutMainLoop();
//}
//
//
//// ������ ��� �Լ�
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // �������� 'blue' �� ����
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
//
//	glPointSize(10.0f);
//
//	fireworks* f;
//	for (f = boom; f != NULL; f = f->getNext())
//	{
//		if (f->getSpread())
//		{
//			glColor4f((rand() % 255) / (double)255 , (rand() % 255) / (double)255, (rand() % 255) / (double)255 , 1.0f);
//			f->rend();
//		}
//		else
//		{
//			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//			f->rend();
//		}
//	}
//
//	glFlush(); // ȭ�鿡 ����ϱ�
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
//}
//
//GLvoid Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		if (total == 0)
//		{
//			boom = new fireworks(x, 600-y);
//			total++;
//		}
//		else
//		{
//			fireworks* f;
//			for (f = boom; f->getNext() != NULL;f = f->getNext())
//			{}
//			f->setNext(new fireworks(x, 600 - y));
//			total++;
//		}
//	}
//}
//
//void Timerfunction(int value)
//{
//	if (value == 1)
//	{
//		fireworks* f;
//		for (f = boom; f != NULL; f = f->getNext())
//		{
//			f->anim();
//		}
//	}
//	glutPostRedisplay(); // ȭ�� �� ���
//	glutTimerFunc(10, Timerfunction, 1); // Ÿ�̸��Լ� �� ����
//}