///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxHORIZONTAL);

	wx_drawingPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wx_drawingPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	bSizer2->Add(wx_drawingPanel, 1, wxEXPAND | wxALL, 5);


	bSizer1->Add(bSizer2, 3, wxEXPAND, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxVERTICAL);

	wx_startButton = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(wx_startButton, 0, wxALIGN_BOTTOM | wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wx_stopButton = new wxButton(this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(wx_stopButton, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wx_resetButton = new wxButton(this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(wx_resetButton, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
	
	wx_firstModeRadioButton = new wxRadioButton(this, wxID_ANY, wxT("Tryb 1"), wxDefaultPosition, wxDefaultSize, 0);
	wx_firstModeRadioButton->SetValue(true);

	bSizer10->Add(wx_firstModeRadioButton, 0, wxALIGN_CENTER | wxALL, 5);

	wx_secondModeRadioButton = new wxRadioButton(this, wxID_ANY, wxT("Tryb 2"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(wx_secondModeRadioButton, 0, wxALIGN_CENTER | wxALL, 5);

	wx_gridBox = new wxCheckBox(this, wxID_ANY, wxT("Siatka"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer10->Add(wx_gridBox, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer6->Add(bSizer10, 1, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxEXPAND | wxTOP, 5);


	bSizer5->Add(bSizer6, 1, wxALIGN_CENTER | wxEXPAND | wxTOP, 5);


	bSizer1->Add(bSizer5, 1, wxALIGN_CENTER | wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	wx_timer = new wxTimer(this, 1);
	wx_timer->Start(100);
	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame::OnExit));
	wx_startButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_start), NULL, this);
	wx_stopButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_stop), NULL, this);
	wx_resetButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_reset), NULL, this);

	wx_firstModeRadioButton->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode1), NULL, this);
	wx_secondModeRadioButton->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode2), NULL, this);
	wx_secondModeRadioButton->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode2), NULL, this);
	wx_gridBox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::wxCheckBox_grid), NULL, this);
	wx_drawingPanel->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::WxPanel_Repaint), NULL, this);
	Connect(wxEVT_TIMER, wxCommandEventHandler(MyFrame::OnTimer));

}

MyFrame::~MyFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame::OnExit));
	wx_startButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_start), NULL, this);
	wx_stopButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_stop), NULL, this);
	wx_resetButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::wxButton_reset), NULL, this);

	wx_firstModeRadioButton->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode1), NULL, this);
	wx_secondModeRadioButton->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode2), NULL, this);
	wx_secondModeRadioButton->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame::wxRadioButton_mode2), NULL, this);
	wx_gridBox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::wxCheckBox_grid), NULL, this);
	wx_drawingPanel->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::WxPanel_Repaint), NULL, this);
	Disconnect(wxEVT_TIMER, wxCommandEventHandler(MyFrame::OnTimer));

}
