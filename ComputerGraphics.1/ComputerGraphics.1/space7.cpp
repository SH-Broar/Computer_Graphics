#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Timerfunction(int value);
GLvoid Keyboard(unsigned char key, int x, int y);
GLvoid Mouse(int button, int state, int x, int y);
GLvoid MouseMove(int x, int y);

int xRotate = 0;
int yRotate = 0;
int zRotate = 0;

float x, y, z;

bool wire = false;
bool Trans = false;
POINT circle[360];

void init()
{
	for (int i = 0; i < 360; i++)
	{
		circle[i].x = (double)cos((double)(i + 1) / 180.f * 3.14) * 200;
		circle[i].y = (double)sin((double)(i + 1) / 180.f * 3.14) * 200;
	}
}
void main(int argc, char *argv[])
{
	//초기화 함수들
	glutInit(&argc, argv);
	init();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 설정
	glutInitWindowPosition(10, 0); // 윈도우의 위치지정
	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutTimerFunc(100, Timerfunction, 1);
	glutMainLoop();
}

int leftRotate = 0;
int rightRotate = 0;
int bothRotate = 0;
int timerTick = 0;

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기

	if (Trans)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glViewport(0, 0, 600, 800);
		glOrtho(-300.0, 300.0, -200.0, 400.0, -400.0, 400.0);
		glTranslatef(x * 100, y * 100, z * 100);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.f, 1.0, 1.f, 1000.f);
		glTranslatef(0.f, 0.f, -500.f);
		glTranslatef(x*100, y*100, z*100);
		glRotatef(xRotate, 1.f, 0.f, 0.f);
		glRotatef(yRotate, 0.f, 1.f, 0.f);
		glRotatef(zRotate, 0.f, 0.f, 1.f);

		gluLookAt(0.0, 0.3f, 0.0, 0.0, 0.1, -1.0, 0.0, 1.0, 0.0);
	}


	glMatrixMode(GL_MODELVIEW);

	if (wire)
		glutWireSphere(30, 12, 12);
	else
		glutSolidSphere(30, 12, 12);

	glColor3f(0.8f, 0.8f, 0.8f);

	

	glPushMatrix();
	{
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x, 0, circle[i].y);
			}
		}glEnd();
		glTranslatef(circle[timerTick%360].x, 0, circle[timerTick%360].y);
		if (wire)
			glutWireSphere(5, 12, 12);
		else
			glutSolidSphere(5, 12, 12);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x / 10, 0, circle[i].y / 10);
			}
		}glEnd();
		glTranslatef(circle[timerTick*2 % 360].x / 10, 0, circle[timerTick*2 % 360].y / 10);
		if (wire)
			glutWireSphere(2, 12, 12);
		else
			glutSolidSphere(2, 12, 12);
	}glPopMatrix();

	glPushMatrix();
	{
		glRotatef(45, 0.f, 0.f, 1.f);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x, 0, circle[i].y);
			}
		}glEnd();
		glTranslatef(circle[timerTick/2%360].x, 0, circle[timerTick/2%360].y);
		if (wire)
			glutWireSphere(5, 12, 12);
		else
			glutSolidSphere(5, 12, 12);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x / 10, 0, circle[i].y / 10);
			}
		}glEnd();
		glTranslatef(circle[timerTick % 360].x / 10, 0, circle[timerTick % 360].y / 10);
		if (wire)
			glutWireSphere(2, 12, 12);
		else
			glutSolidSphere(2, 12, 12);
	}glPopMatrix();

	glPushMatrix();
	{
		glRotatef(45, 0.f, 0.f, -1.f);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x, 0, circle[i].y);
			}
		}glEnd();
		glTranslatef(circle[timerTick/3%360].x, 0, circle[timerTick/3%360].y);
		if (wire)
			glutWireSphere(5, 12, 12);
		else
			glutSolidSphere(5, 12, 12);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < 360; i++)
			{
				glVertex3f(circle[i].x / 10, 0, circle[i].y / 10);
			}
		}glEnd();
		glTranslatef(circle[timerTick *3 % 360].x / 10, 0, circle[timerTick * 3 % 360].y / 10);
		if (wire)
			glutWireSphere(2, 12, 12);
		else
			glutSolidSphere(2, 12, 12);
	}glPopMatrix();

	glutSwapBuffers(); // 화면에 출력하기
}
GLvoid Reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.f, 1.0, 1.f, 1000.f);
	glTranslatef(0.f, 0.f, -500.f);
	gluLookAt(0.0, 0.3f, 0.0, 0.0, -0.3, -1.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSwapBuffers();
}

void Timerfunction(int value)
{
	timerTick++;
	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(10, Timerfunction, 1); // 타이머함수 재 설정
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
		xRotate += 2;
		break;
	case 'y':
		yRotate += 2;
		break;
	case 'z':
		zRotate += 2;
		break;
	case 'X':
		xRotate -= 2;
		break;
	case 'Y':
		yRotate -= 2;
		break;
	case 'Z':
		zRotate -= 2;
		break;
	case 'w':
		::y += 0.2f;
		break;
	case 'a':
		::x -= 0.2f;
		break;
	case 's':
		::y -= 0.2f;
		break;
	case 'd':
		::x += 0.2f;
		break;
	case '+':
		z += 0.02f;
		break;
	case '-':
		z -= 0.02f;
		break;
	case 'i':
		xRotate = 0;
		yRotate = 0;
		zRotate = 0;
		break;
	case 'c':
		if (Trans)
			Trans = false;
		else
			Trans = true;
		break;
	case '0':
		if (wire)
			wire = false;
		else
			wire = true;
		break;
	}
	glutPostRedisplay();
}

GLvoid Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
}
GLvoid MouseMove(int x, int y)
{

}