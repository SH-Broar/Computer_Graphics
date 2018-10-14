//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//#include <time.h>
//#include <random>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//GLvoid Mouse(int button, int state, int x, int y);
//GLvoid MouseMove(int x, int y);
//
//int rotate = false;
//int ra = 0;
//
//class object
//{
//	int x;
//	int y;
//	int size;
//	int shape;
//	float r, g, b;
//public:
//	object() {};
//	void in(int x, int y, int size, int shape, float r, float g, float b)
//	{
//		this->x = x;
//		this->y = y;
//		this->size = size;
//		this->shape = shape;
//		this->r = r;
//		this->g = g;
//		this->b = b;
//	}
//	void out()
//	{
//		glLoadIdentity();
//		glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//
//		glColor3f(r/255, g/255, b/255);
//		glTranslated(x, y, 0);
//		glRotated(ra, 0.1, 1, 0.2);
//		switch (shape)
//		{
//		case 1:
//			glutWireSphere(size, 12, 12);
//			break;
//		case 2:
//			glutWireCone(size, size, 12, 12);
//			break;
//		case 3:
//			glutWireCube(size);
//			break;
//		case 4:
//			glutWireTorus(size/2, size, 12, 12);
//			break;
//		case 5:
//			glutWireTeapot(size);
//			break;
//		}
//	}
//	void c()
//	{
//		size = size - 10;
//		if (size < 0)
//			size = 0;
//	}
//};
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드 설정
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
//// 윈도우 출력 함수
//
//object arr[20];
//int total = 0;
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	glMatrixMode(GL_MODELVIEW);
//
//  glLoadIdentity();
//	glOrtho(-300.0, 300.0, -300.0, 300.0, -400.0, 400.0);
//	
//	for (int i = 0; i < total; i++)
//	{
//		arr[i].out();
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
//	if (rotate)
//		ra += 3;
//	else
//		ra -= 3;
//	for (int i = 0; i < total; i++)
//	{
//		arr[i].c();
//	}
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	if (key == 'r')
//		if (rotate)
//			rotate = 0;
//		else
//			rotate = 1;
//}
//
//GLvoid Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		arr[total%20].in(x - 300, 600-y - 300, 350, rand()%5 +1, rand() % 255, rand() % 255, rand() % 255);
//		total++;
//	}
//}
//
//GLvoid MouseMove(int x, int y)
//{
//	
//}