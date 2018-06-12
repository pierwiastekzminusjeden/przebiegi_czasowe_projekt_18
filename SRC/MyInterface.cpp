#include "MyInterface.h"


MyInterface::MyInterface(wxWindow *parent): MyFrame(parent)
{
	wx_drawingPanel->GetSize(&m_width, &m_height);

	m_drawingClass = new DrawingClass(this);
	m_dataContainer = new DataContainer(1000);
	m_drawingFlag = false;
	m_gridFlag = false;
	m_secondModeFlag = false;
}


MyInterface::~MyInterface()
{
	delete m_dataContainer;
	delete m_drawingClass;
}


void MyInterface::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	 	Repaint();
}

void MyInterface::OnTimer(wxCommandEvent & event)
{
	if (m_dataContainer->getLastIndex() == 999) {
		delete m_dataContainer;
		m_dataContainer = new DataContainer(1000);
		Repaint();
		reset = 0;
	}

	if (m_drawingFlag)
		m_dataContainer->getData();
	Repaint(); 
}

void MyInterface::Repaint()
{
	wxClientDC dc1(wx_drawingPanel);
	wxBufferedDC dc(&dc1);
	wx_drawingPanel->GetSize(&m_width, &m_height);
	m_drawingClass->draw(&dc);

}
void MyInterface::OnExit(wxCloseEvent & event)
{
		Destroy();
		exit(0);
}

void MyInterface::wxButton_start(wxCommandEvent & event)
{
	m_drawingFlag = true;	
}

void MyInterface::wxButton_stop(wxCommandEvent & event)
{
	m_drawingFlag = false;
}

int MyInterface::reset = 1;
void MyInterface::wxButton_reset(wxCommandEvent & event)
{	
	delete m_dataContainer;
	m_dataContainer = new DataContainer(1000);
	Repaint();
	reset = 0;
}

void MyInterface::wxCheckBox_grid(wxCommandEvent & event)
{
	if (wx_gridBox->IsChecked())
		m_gridFlag = true;
	else
		m_gridFlag = false;
}

void MyInterface::wxRadioButton_mode1(wxCommandEvent & event)
{
	m_secondModeFlag = false;
}

void MyInterface::wxRadioButton_mode2(wxCommandEvent & event)
{
	m_secondModeFlag = true;
}


