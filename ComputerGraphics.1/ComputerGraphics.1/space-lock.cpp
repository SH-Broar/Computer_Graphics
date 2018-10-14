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
//	//초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 설정
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
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
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
//	glutSwapBuffers(); // 화면에 출력하기
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
//	glutPostRedisplay(); // 화면 재 출력
//	glutTimerFunc(100, Timerfunction, 1); // 타이머함수 재 설정
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