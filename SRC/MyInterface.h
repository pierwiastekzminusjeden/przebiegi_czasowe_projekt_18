#pragma once
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <memory>


#include "GUI.h"
#include "DrawingClass.h"
#include "DataContainer.h"

class DataContainer;

/**
* Klasa MyInterface dziedziczaca po klasie MyFrame. Zawiera implementacje metod eventow klasy bazowej. Laczy caly program. Zawiera wskazniki na 
* obiekt klasy DataContainer oraz klasy rysuj¹cej DrawingClass.
*/
class MyInterface: public MyFrame
{
		/**
		* Zaprzyjazniona klasa DDrawingClass w celu dostepu do prywatnych flag, ktore maja byc dostepne wylacznie dla tej klasy.
		*/
		friend class DrawingClass;
	public:
		/**
		* Konstruktor konwerujacy. Alokuje pamiec na obiekty kontenerowe oraz obiekt klasy DrawingClass.
		*/
		MyInterface(wxWindow * parent);
		/**
		* Destruktor. Zwalnia pamiec zaalokowana w konstruktorze na obiekt kontenerowy DataContainer oraz obiekt klasy aDrawingClass
		*/
		~MyInterface();
		/**
		* Zwraca szerokosc panelu wx_drawingPanel dziedziczonego po MyFrame.
		*/
		int getWidth() { return m_width; }
		/**
		* Zwraca wysokosc panelu wx_drawingPanel dziedziczonego po MyFrame.
		*/
		int getHeight() { return m_height; }
		
	protected:
		
		/**
		* Zmienna do zerowania Osi OX i OY
		*/
		static int reset;
		/**
		* Podstawowa metoda odpowiadajaca za rysowanie obrazu na wx_drawingPanel.
		*/
		void Repaint();

		/**
		* Obsluga eventu zamkniecia okna
		*/
		virtual void OnExit(wxCloseEvent & event);

		/**
		* Obsluga eventu przycisku start. Inicjuje odczyt danych z pliku oraz rysowanie ich na panelu wx_drawingPanel.
		*/
		virtual void wxButton_start(wxCommandEvent & event);

		/**
		*  Obsluga eventu przycisku stop. Zatrzymuje odczyt oraz rysowanie danych. 
		*/
		virtual void wxButton_stop(wxCommandEvent & event);
		/**
		* Obsluga eventu przycisku reset. Resetuje wczytana historie danych.
		*/
		virtual void wxButton_reset(wxCommandEvent& event);

		/**
		* Obsluga eventu checkBoxa "siatka" . Po zaznaczeniu odpowiedniego checkBoxa w menue pozwala naklada siatke pomocnicza na wx_drawingPanel.
		*/
		virtual void wxCheckBox_grid(wxCommandEvent & event);

		/**
		* Przelacza na tryb 1 wyswietlania. Wylacznie bierzace 10s wykresu. Domyslnie wlaczone.
		*/
		virtual void wxRadioButton_mode1(wxCommandEvent & event);

		/**
		* Przelacza na tryb 2 wyswietlania. Wykres aktualnych i poprzednich 10s. Domyslnie wylaczone. Uruchamia sie po kliknieciu automatycznie po pierwszych 10s. Wczesniej
		*\ Wykres wyglada tak samo jak dla trybu 1.
		*/
		virtual void wxRadioButton_mode2(wxCommandEvent & event);

		/**
		* Odswiezanie ekranu w przypadku akcji w oknie programu. 
		*/
		virtual void WxPanel_Repaint(wxUpdateUIEvent& event);

		/**
		* Obsluga eventu timera. Uruchamia wczytywanie nowych danych co 0.1s.  
		*/
		virtual void OnTimer(wxCommandEvent & event);


	private: 
		/**
		* Wskasnik na obiekt klasy odpowiadajacej za rysowanie poszczegolnych elementow na ekranie.
		*/
		DrawingClass * m_drawingClass;

		/**
		* Wskaznik na kontener z danymi. 
		*/
		DataContainer * m_dataContainer;

		int m_width, m_height;
		bool m_drawingFlag;
		bool m_gridFlag;
		bool m_secondModeFlag;	
};

