//// Frame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
////
//#include "stdafx.h"
//#include "MainFrame.h"
//
//int main(int argc, char *argv[])
//{
//	MainFrame CMainFrame;
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
//	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
//	glutInitWindowSize(800, 600); // 윈도우의 크기 지정
//	glutCreateWindow("Frame"); // 윈도우 생성 (윈도우 이름)
//
//	glutDisplayFunc(CMainFrame.DrawScene); // 출력 함수의 지정
//	glutReshapeFunc(CMainFrame.Resize);
//
//	glutMainLoop();
//}