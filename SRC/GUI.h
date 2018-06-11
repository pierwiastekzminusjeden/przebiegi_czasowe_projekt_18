///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/tglbtn.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/timer.h>

//Dodatkowe
//#include <wx/intl.h>
//#include <wx/stattext.h>
//#include <wx/textctrl.h>
//#include <wx/valtext.h>
//#include <wx/scrolbar.h>
//#include <wx/choice.h>


///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
/**
* Klasa odpowiadajaca za budowe GUI. Klasa bazowa dla klasy MyInterface.
*/
class MyFrame : public wxFrame 
{
	public:
		/**
		* Konstruktor klasy, ustawia podstawowe parametry takie jak wielkosc okna, tytu³ okna, nazwy przycisków i ich rozmieszczenie itd.
		*/
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Przebiegi czasowe"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 698,525 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		/**
		* Dekonstruktor klasy
		*/
		~MyFrame();

	protected:

		/**
		*Obiekt klasy wxToggleButton sluzocy do rozpoczêcia pobierania dancyh z pliku i rysowania ich w uk³adzie wspolrzednych
		*/
		wxButton* wx_startButton;

		/**
		* Obiekt klasy wxButton sluzacy do zatrzymania pobierania dancyh z pliku i rysowania ich w uk³adzie wspolrzednych
		*/
		wxButton* wx_stopButton;

		/**
		* Obiekt klasy wxButton resetuj¹cy dane i usuwajacy historie wczytanych danych
		*/
		wxButton* wx_resetButton;

		/**
		* Obiekt klasy wxRadioButton s³uzacy do wybrania pierwszego trybu pracy (wybrany domyslnie)
		*/
		wxRadioButton* wx_firstModeRadioButton;
		
		/**
		* Obiekt klasy wxRadioButton s³u¿¹cy do wybrania drugieo trybu pracy 
		*/
		wxRadioButton* wx_secondModeRadioButton;

		/**
		* Obiekt klasy wxCheckBox s³u¿¹cy narysowania siatki uk³adu wspolrzednych
		*/
		wxCheckBox* wx_gridBox;

		/**
		*  Obiekt klasy wxPanel s³u¿¹cy do narysowania uk³adu wspolrzednych oraz danych pobranych z oscyloskopu
		*/
		wxPanel* wx_drawingPanel;

		/**
		* Timer pozwala na cykliczne wczytywanie danych z pliku i wyswietlanie ich na panelu.
		*/
		wxTimer *wx_timer;
	
		/**
		* Virtual event handlers, overide them in your derived class
		*/
		virtual void wxButton_start(wxCommandEvent& event) { event.Skip(); }
		virtual void wxButton_stop( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxButton_reset(wxCommandEvent& event) { event.Skip(); }

		virtual void wxRadioButton_mode1(wxCommandEvent& event) { event.Skip(); }
		virtual void wxRadioButton_mode2(wxCommandEvent& event) { event.Skip(); }
		virtual void wxCheckBox_grid(wxCommandEvent& event) { event.Skip(); }
		virtual void OnExit(wxCloseEvent& event) { event.Skip(); }
		virtual void WxPanel_Repaint(wxUpdateUIEvent& event) { event.Skip(); }
		virtual void OnTimer(wxCommandEvent & event) { event.Skip(); }
};

