// Tuter_OpenGL_GimbalLock.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include "RuntimeFrameWork.h"

int main(int argc, char** argv) {
	CRuntimeFrameWork runtimeFrameWork;
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600); // ������ ũ�� ���� 
	glutCreateWindow("Tutering"); // ���ڷ� �ѱ� ���ڿ��� �̸��� ���� ������ ����
	runtimeFrameWork.Init();
	
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutMainLoop(); // �̺�Ʈ ���� ����
	return 0;
}