//#include <GL/freeglut.h>
//
//GLvoid drawScene(GLvoid);
//GLvoid Reshape(int w, int h);
//
//void main(int argc, char *argv[])
//{
//	//초기화 함수들
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
//	glutInitWindowSize(600, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Example"); // 윈도우 생성 (윈도우 이름)
//	glutDisplayFunc(drawScene); // 출력 함수의 지정
//	glutReshapeFunc(Reshape); // 다시 그리기 함수의 지정
//	glutMainLoop();
//}
//// 윈도우 출력 함수
//GLvoid drawScene(GLvoid)
//{
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
//	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
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
//	glFlush(); // 화면에 출력하기
//}
//GLvoid Reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
//}