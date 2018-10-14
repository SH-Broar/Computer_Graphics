#include "stdafx.h"
#include "MainFrame.h"

MainFrame* MainFrame::myself = nullptr;

MainFrame::MainFrame()
{
	myself = this;
}


MainFrame::~MainFrame()
{

}

GLvoid MainFrame::Draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glRecti(22, 22, 122, 122);

	glFlush();
	return GLvoid();
}

GLvoid MainFrame::Reshape(int w,int h)
{
	if (w > 0)
		m_nWidth = w;
	if (h > 0)
		m_nheight = h;

	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	return GLvoid();
}

GLvoid MainFrame::Resize(int w,int h)
{
	if (myself != nullptr)
		myself->Reshape(w, h);
	return GLvoid();
}

GLvoid MainFrame::DrawScene()
{
	if (myself != nullptr)
		myself->Draw();
	return GLvoid();
}
