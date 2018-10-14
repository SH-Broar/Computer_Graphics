//#include <GL/freeglut.h>
//#include <math.h>
//#include <stdio.h>
//#include <time.h>
//
//time_t now;
//struct tm curr_time;
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//GLvoid Timerfunction(int value);
//GLvoid Keyboard(unsigned char key, int x, int y);
//GLvoid Mouse(int button, int state, int x, int y);
//GLvoid MouseMove(int x, int y);
//
//class num
//{
//	int d;
//	int mask = 0;
//public:
//	num(){}
//	num(int d)
//	{
//		this->d = d;
//	}
//	void attach(int d)
//	{
//		this->d = d;
//	}
//	void rend(int x,int y)
//	{
//		glPushMatrix();
//		glTranslated(x, y, 0);
//
//		glColor3f(0.f, 1.f, 0.f);
//		mask = 0;
//		switch (d)
//		{
//		case 0:
//			mask = mask | 0x77;
//			break;
//		case 1:
//			mask = mask | 0x11;
//			break;
//		case 2:
//			mask = mask | 0x3E;
//			break;
//		case 3:
//			mask = mask | 0x3B;
//			break;
//		case 4:
//			mask = mask | 0x59;
//			break;
//		case 5:
//			mask = mask | 0x6B;
//			break;
//		case 6:
//			mask = mask | 0x6F;
//			break;
//		case 7:
//			mask = mask | 0x71;
//			break;
//		case 8:
//			mask = mask | 0x7F;
//			break;
//		case 9:
//			mask = mask | 0x7B;
//			break;
//		default:
//			PostQuitMessage(0);
//		}
//		printNum();
//
//		glColor3f(0.1f, 0.1f, 0.1f);
//		initNum();
//
//		glPopMatrix();
//	}
//	void initNum()
//	{
//		glPushMatrix();
//		{
//			glTranslated(-70, 70, 0);
//			glScalef(0.2f, 1.f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(0, 140, 0);
//			glScalef(1.f, 0.2f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(70, 70, 0);
//			glScalef(0.2f, 1.f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(0, 0, 0);
//			glScalef(1.f, 0.2f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(-70, -70, 0);
//			glScalef(0.2f, 1.f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(0, -140, 0);
//			glScalef(1.f, 0.2f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//		glPushMatrix();
//		{
//			glTranslated(70, -70, 0);
//			glScalef(0.2f, 1.f, 0.2f);
//			glutWireCube(135);
//		}
//		glPopMatrix();
//	}
//	void printNum()
//	{
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(70, -70, 0);
//				glScalef(0.2f, 1.f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask>>1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(0, -140, 0);
//				glScalef(1.f, 0.2f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask >> 1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(-70, -70, 0);
//				glScalef(0.2f, 1.f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask >> 1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(0, 0, 0);
//				glScalef(1.f, 0.2f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask >> 1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(70, 70, 0);
//				glScalef(0.2f, 1.f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask >> 1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(0, 140, 0);
//				glScalef(1.f, 0.2f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//		mask = mask >> 1;
//		if (mask % 2 == 1)
//		{
//			glPushMatrix();
//			{
//				glTranslated(-70, 70, 0);
//				glScalef(0.2f, 1.f, 0.2f);
//				glutSolidCube(120);
//			}
//			glPopMatrix();
//		}
//	}
//};
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 0); // 윈도우의 위치지정
//	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutKeyboardFunc(Keyboard);
//	glutMotionFunc(MouseMove);
//	glutMouseFunc(Mouse);
//	glutTimerFunc(100, Timerfunction, 1);
//	glEnable(GL_DEPTH_TEST);
//
//	glutMainLoop();
//}
//
//num timez[6];
//int com = 0;
//int l = 0;
//int r = 0;
//
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
//
//	glMatrixMode(GL_MODELVIEW);
//
//	 glLoadIdentity();
//	glOrtho(-700.0, 700.0, -700.0, 700.0, -700.0, 700.0);
//	glRotatef(l, 0.f, 1.f, 0.f);
//	glRotatef(r, 0.5f, 0.f, 0.5f);
//	glRotatef(com, 0.1f, 1.f, 0.1f);
//	glRotated(30, 1, 1, 0);
//
//	timez[0].attach(curr_time.tm_sec % 10);
//	timez[1].attach(curr_time.tm_sec / 10);
//	timez[2].attach(curr_time.tm_min % 10);
//	timez[3].attach(curr_time.tm_min / 10);
//	timez[4].attach(curr_time.tm_hour % 10);
//	timez[5].attach(curr_time.tm_hour / 10);
//
//	timez[0].rend(510,0);
//	timez[1].rend(330,0);
//	timez[2].rend(100,0);
//	timez[3].rend(-100,0);
//	timez[4].rend(-330,0);
//	timez[5].rend(-510,0);
//
//	glutSwapBuffers(); // 화면에 출력하기
//}
//GLvoid Reshape(int w, int h)
//{
//
//	glViewport(0, 0, w, h);
//	glOrtho(-700.0, 700.0, -700.0, 700.0, -700.0, 700.0);
//}
//
//void Timerfunction(int value)
//{
//	now = time(0);
//	localtime_s(&curr_time, &now);
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, Timerfunction, 1); // 타이머함수 재 설정
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	if (key == 'y')
//	{
//		com += 3;
//	}
//	if (key == 'Y')
//	{
//		com -= 3;
//	}
//}
//
//bool mDown = false;
//GLvoid Mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		mDown = true;
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		mDown = false;
//	}
//}
//
//GLvoid MouseMove(int x, int y)
//{
//	if (mDown)
//	{
//		l = x;
//		r = y;
//	}
//}