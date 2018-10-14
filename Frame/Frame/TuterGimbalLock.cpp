// Tuter_OpenGL_GimbalLock.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "RuntimeFrameWork.h"

int main(int argc, char** argv) {
	CRuntimeFrameWork runtimeFrameWork;
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600); // 윈도우 크기 설정 
	glutCreateWindow("Tutering"); // 인자로 넘긴 문자열의 이름을 가진 윈도우 생성
	runtimeFrameWork.Init();
	
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutMainLoop(); // 이벤트 루프 실행
	return 0;
}