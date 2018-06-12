#pragma once
#include "MyInterface.h"
#include <iostream>
#include <memory>

class MyInterface;

/**
* Klasa odpowiadajaca za operacje graficzne wykonywane na panelu @MyFrame::drawing_panel
*/
class DrawingClass
{
	public:
	
		/**
		* Konstruktor klasy drawingPanel.
		*/
		DrawingClass(MyInterface *obj);
		
		/**
		* Publiczna metoda wywolywana w metodzie MyInterface::Repaint(). Rysuje na panelu poszczegolne elementy oraz wykres. Korzysta z prywatnych metod pomocniczych.
		*/
		void draw(wxDC *dc);

	private:

		/**
		* zmienna pomocnicza do przesuwania wykresu
		*/
		static int trans;

		/**
		* zmienna pomocnicza aby program wiedzial kiedy ma przesunac wykres
		*/
		static int trans2;

		/**
		* zmienna pomocnicza do podpisywania osi X pod dodatniej stronie wykresu
		*/
		static int start_plus_X;

		/**
		* zmienna pomocnicza do podpisywania osi X po ujemnej stronie wykresu
		*/
		static int start_minus_X;

		/**
		* zmienna pomocnicza do podpisywania osi, zeby program wiedzial o ile ma przesunac oœ X (czyli jaki jest maksymalna podzia³ka widoczna)
		*/
		static int ile_X;

		/**
		* zmienna pomocnicza do podpisywania osi Y pod dodatniej stronie wykresu
		*/
		static int start_plus_Y;

		/**
		* zmienna pomocnicza do podpisywania osi Y po ujemnej stronie wykresu
		*/
		static int start_minus_Y;

		/**
		* zmienna pomocnicza do podpisywania osi, zeby program wiedzial o ile ma przesunac oœ Y (czyli jaki jest maksymalna podzia³ka widoczna)
		*/
		static int ile_Y;

		/**
		* Metoda pomocnicza odpowiadajaca za wyrysowanie na panelu osi oraz podzialki. 
		*/
		void drawAxes(wxDC* dc);

		/**
		* Metoda pomocnicza odpowiadajaca za wyrysowanie siatki pomocniczej.
		*/
		void drawGrid(wxDC * dc);

		/**
		* Metoda pomocnicza testowa odpowiadajaca za wyrysowanie danych.
		*/
		void drawData(wxDC * dc);

		/**
		* Metoda pomocnicza odpowiadajaca za scalowanie i przesuniecie wykresu
		*/
		wxPoint* scaleTranslate(wxDC * dc);

		/**
		* Wskaznik na obiekt klasy @MyInterface
		*/
		MyInterface * m_myInterfacePTR;

};
