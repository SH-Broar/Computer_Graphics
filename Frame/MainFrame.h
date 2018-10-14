#pragma once
class MainFrame
{
private:
	static MainFrame *myself;

	int m_nWidth = 800;
	int m_nheight = 600;
public:
	MainFrame();
	~MainFrame();

	GLvoid Draw();
	GLvoid Reshape(int,int);
	static GLvoid Resize(int,int);
	static GLvoid DrawScene();

};

