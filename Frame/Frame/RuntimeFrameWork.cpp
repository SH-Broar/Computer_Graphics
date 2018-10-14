#include "stdafx.h"
#include "Camera.h"
#include "RuntimeFrameWork.h"

#define GL_PI 3.1415f

CRuntimeFrameWork* CRuntimeFrameWork::mySelf = nullptr;


CRuntimeFrameWork::CRuntimeFrameWork()
{
	m_pCamera = new CCamera();

	m_vRotate = Vector3D{ 0.0f, 0.0f, 0.0f };
	m_pCamera->CameraReset();
}

GLvoid CRuntimeFrameWork::Init()
{
	srand((unsigned)time(NULL));
	mySelf = this;
	::glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Display 모드 설정
	::glutIdleFunc(CRuntimeFrameWork::UpdateCallback); // Idle 상태일때 호출할 콜백 등록
	::glutDisplayFunc(CRuntimeFrameWork::RenderCallback); // Display 콜백 등록
	::glutKeyboardFunc(CRuntimeFrameWork::KeyBoardCallback);
	::glutSpecialFunc(CRuntimeFrameWork::SpecialKeyBoardCallback);
	::glutMouseFunc(CRuntimeFrameWork::MouseCallback);
	::glutPassiveMotionFunc(CRuntimeFrameWork::MouseMoveCallback);
	::glutReshapeFunc(CRuntimeFrameWork::ReshapeCallback);
	::glutKeyboardUpFunc(CRuntimeFrameWork::KeyBoardUpCallback);

	return GLvoid();
}

GLvoid CRuntimeFrameWork::Update()
{
	m_fCurrentTime = glutGet(GLUT_ELAPSED_TIME);
	m_nCurrentFrame++;

	if (m_fCurrentTime - m_fPrevTime > 1000 / FPS_PERSECOND)
	{

		m_fPrevTime = m_fCurrentTime;
		m_nCurrentFrame = 0;
		::glutPostRedisplay();
	}
	return GLvoid();
}

GLvoid CRuntimeFrameWork::Render()
{
	// GL상태변수 설정, 프레임 버퍼를 초기화
	// 초기화 될 색은 glutClearColor에서 사용된 색
	GLfloat centerx = 0, centery = 0, centerz = 0;
	GLfloat radius = 10, h = 5;
	GLfloat x, y;
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Gimbal lock 발생
	glPushMatrix();
	{
		glRotatef(m_vRotate.x, 1.0f, 0.0f, 0.0f);
		glRotatef(m_vRotate.y, 0.0f, 1.0f, 0.0f);
		glRotatef(m_vRotate.z, 0.0f, 0.0f, 1.0f);

		glPushMatrix();
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 10.0f, 0.1f);
			glutSolidCube(1.0f);
			glColor3f(0.1f, 0.1f, 0.1f);
			glutWireCube(1.0f);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(0.1f, 10.0f, 0.1f);
			glutSolidCube(1.0f);
			glColor3f(0.1f, 0.1f, 0.1f);
			glutWireCube(1.0f);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3f(0.0f, 0.0f, 1.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glScalef(0.1f, 10.0f, 0.1f);
			glutSolidCube(1.0f);
			glColor3f(0.1f, 0.1f, 0.1f);
			glutWireCube(1.0f);
		}
		glPopMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);
		glutWireSphere(1, 10, 10);
	}
	glPopMatrix();
	
	glFlush();
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessKeyBoard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w': case 'W':
			m_vRotate.x -= 5.0f;
			break;
		case 's': case 'S':
			m_vRotate.x += 5.0f;
			break;
		case 'd': case 'D':
			m_vRotate.z -= 5.0f;
			break;
		case 'a': case 'A':
			m_vRotate.z += 5.0f;
			break;
		case 'r': case 'R':
			m_vRotate = Vector3D{0.0f, 0.0f, 0.0f};
			m_pCamera->CameraReset();
			break;
	}
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessKeyUpBoard(unsigned char key, int x, int y)
{
	switch (key)
	{
		
	}
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessSpecialKeyBoard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		m_pCamera->CameraRotate(0);
		break;
	case GLUT_KEY_RIGHT:
		m_pCamera->CameraRotate(1);
		break;
	case GLUT_KEY_DOWN:
		m_pCamera->CameraRotate(2);
		break;
	case GLUT_KEY_UP:
		m_pCamera->CameraRotate(3);
		break;
	}
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessMouse(int button, int state, int x, int y)
{
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessMouseMove(int x, int y)
{
	return GLvoid();
}

GLvoid CRuntimeFrameWork::Reshape(int width, int height)
{
	if(width != 0)
		m_nViewPortWidth = width;
	if(height != 0)
		m_nViewPortHeight = height;

	glViewport(0, 0, m_nViewPortWidth, m_nViewPortHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, m_nViewPortWidth / m_nViewPortHeight, 1.0f, 1000.0f);
	
	Vector3D vRotate = m_pCamera->GetCameraRotate();
	Vector3D vEye = m_pCamera->GetCameraPos();
	Vector3D vLook = m_pCamera->GetCameraLook();
	Vector3D vUp = m_pCamera->GetCameraUp();

	gluLookAt(
		vEye.x, vEye.y, vEye.z,
		vLook.x, vLook.y, vLook.z,
		vUp.x, vUp.y, vUp.z);
	
	glRotatef(vRotate.x, 1.0f, 0.0f, 0.0f);
	glRotatef(vRotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(vRotate.z, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return GLvoid();
}
