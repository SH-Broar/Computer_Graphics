//#include <GL/freeglut.h>
//#include <Windows.h>
//#include <random>
//#include <time.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Mouse(int button, int state, int x, int y);
//GLvoid MouseMove(int x, int y);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//
//int total = 0;
//int speeder = 1;
//
//bool stop = false;
//
//class rec
//{
//public:
//	int x;
//	int y;
//	int tmpx;
//	int tmpy;
//
//	int dx;
//	int dy;
//	int dir;
//	int sdir; // 커지는지 작아지는지
//	int tdir = 0;
//	int num;
//	int Transformation = 0;
//
//	bool spin;
//	bool d = false;
//	double rgb[3];
//
//	rec()
//	{}
//
//	void init(int mx, int my)
//	{
//		x = mx;
//		y = 600 - my;
//		dx = 11;
//		dy = 11;
//		num = total;
//		spin = false;
//
//		if (total < 9)
//			total++;
//
//		dir = rand() % 4;
//		sdir = 0;
//
//		for (int i = 0; i < 3; i++)
//		{
//			rgb[i] = (rand() % 255) / 255;
//		}
//	}
//
//
//	void deltaColor()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			rgb[i] = (rand() % 255) / (double)255;
//		}
//	}
//
//	void deltaXY()
//	{
//		switch (dir)
//		{
//		case 0:
//			x -= 5;
//			y -= 5;
//			if (x < 15)
//				dir = 2;
//			if (y < 15)
//				dir = 1;
//			break;
//		case 1:
//			x -= 5;
//			y += 5;
//			if (x < 15)
//				dir = 3;
//			if (y > 585)
//				dir = 0;
//			break;
//		case 2:
//			x += 5;
//			y -= 5;
//			if (x > 785)
//				dir = 0;
//			if (y < 15)
//				dir = 3;
//			break;
//		case 3:
//			x += 5;
//			y += 5;
//			if (x > 785)
//				dir = 1;
//			if (y > 585)
//				dir = 2;
//			break;
//		}
//	}
//};
//
//rec shapes[9];
//bool right_button = false;
//int virx, viry;
//
//void main(int argc, char *argv[])
//{
//	srand((unsigned int)time(NULL));
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
//	glutInitWindowSize(800, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutMouseFunc(Mouse);
//	glutMotionFunc(MouseMove);
//	glutTimerFunc(100, Timerfunction, 1);
//	glutKeyboardFunc(Keyboard);
//
//	glutMainLoop();
//}
//
//
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	for (int i = 0; i < total; i++)
//	{
//		if (shapes[i].d)
//		{
//			glColor4f(shapes[i].rgb[0], shapes[i].rgb[1], shapes[i].rgb[2], 1.0f);
//			glBegin(GL_POLYGON);
//			if (shapes[i].Transformation < 10)
//			{
//				glVertex2i(shapes[i].x - shapes[i].dx + shapes[i].Transformation, shapes[i].y + shapes[i].dy);
//				glVertex2i(shapes[i].x + shapes[i].dx - shapes[i].Transformation, shapes[i].y + shapes[i].dy);
//				glVertex2i(shapes[i].x + shapes[i].dx + (shapes[i].Transformation * 2), shapes[i].y - shapes[i].dy - (shapes[i].Transformation * 2));
//				glVertex2i(shapes[i].x - shapes[i].dx - (shapes[i].Transformation * 2), shapes[i].y - shapes[i].dy - (shapes[i].Transformation * 2));
//			}
//			else
//			{
//				glVertex2i(shapes[i].x - shapes[i].dx + (20-shapes[i].Transformation), shapes[i].y + shapes[i].dy);
//				glVertex2i(shapes[i].x + shapes[i].dx - (20-shapes[i].Transformation), shapes[i].y + shapes[i].dy);
//				glVertex2i(shapes[i].x + shapes[i].dx + (40 - shapes[i].Transformation * 2), shapes[i].y - shapes[i].dy - (40 - shapes[i].Transformation * 2));
//				glVertex2i(shapes[i].x - shapes[i].dx - (40 - shapes[i].Transformation * 2), shapes[i].y - shapes[i].dy - (40 - shapes[i].Transformation * 2));
//			}
//			glEnd();
//		}
//		else
//		{
//			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//			glRecti(shapes[i].x - shapes[i].dx, shapes[i].y - shapes[i].dy, shapes[i].x + shapes[i].dx, shapes[i].y + shapes[i].dy);
//		}
//	}
//	if (right_button)
//	{
//		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//		glRecti(virx - 11, viry - 11, virx + 11, viry + 11);
//	}
//
//	glFlush(); // 화면에 출력하기
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
//		if (total < 9)
//		{
//			shapes[total].init(x, y);
//		}
//		else
//		{
//			for (int i = 0; i < 9; i++)
//			{
//				shapes[i] = shapes[i + 1];
//			}
//			shapes[8].init(x, y);
//		}
//		glutPostRedisplay();
//	}
//
//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//	{
//		if (right_button)
//			right_button = false;
//		else
//		{
//			right_button = true;
//			virx = x;
//			viry = 600 - y;
//		}
//	}
//}
//
//GLvoid MouseMove(int x, int y)
//{
//	if (right_button == true)
//	{
//		virx = x;
//		viry = 600 - y;
//
//		for (int i = 0; i < total; i++)
//		{
//			if (shapes[i].d == true)
//				continue;
//			RECT tmp;
//			RECT t1;
//			RECT t2;
//
//			t1.left = shapes[i].x - 11;
//			t1.right = shapes[i].x + 11;
//			t1.bottom = shapes[i].y + 11;
//			t1.top = shapes[i].y - 11;
//
//			t2.left = virx - 11;
//			t2.right = virx + 11;
//			t2.bottom = viry + 11;
//			t2.top = viry - 11;
//			
//			if (IntersectRect(&tmp, &t1, &t2))
//			{
//				shapes[i].d = true;
//				shapes[i].Transformation = 0;
//			}
//			// 사각형 충돌체크
//
//		}
//	}
//}
//
//void Timerfunction(int value)
//{
//	if (stop == false)
//	{
//		for (int i = 0; i < total + 1; i++)
//		{
//			if (shapes[i].d)
//			{
//				shapes[i].deltaColor();
//				shapes[i].deltaXY();
//				shapes[i].Transformation++;
//
//				if (shapes[i].Transformation > 20)
//					shapes[i].d = false;
//			}
//			else
//			{
//				shapes[i].deltaColor();
//				shapes[i].deltaXY();
//			}
//		}
//	}
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(50, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	if (key == '[')
//	{
//		speeder += 1;
//	}
//	if (key == ']')
//	{
//		if (speeder > -9)
//			speeder -= 1;
//	}
//	if (key == '0')
//	{
//		for (int i = 0; i < total; i++)
//		{
//			shapes[key - 48 + i].spin = true;
//			shapes[key - 48 + i].tmpx = shapes[key - 48 + i].x;
//			shapes[key - 48 + i].tmpy = shapes[key - 48 + i].y;
//		}
//
//	}
//	if (key >= '1' && key <= '9')
//	{
//		shapes[key - 49].spin = true;
//		shapes[key - 49].tmpx = shapes[key - 49].x;
//		shapes[key - 49].tmpy = shapes[key - 49].y;
//	}
//
//	if (key == 'p')
//	{
//		stop = true;
//	}
//	if (key == 's')
//	{
//		stop = false;
//	}
//}