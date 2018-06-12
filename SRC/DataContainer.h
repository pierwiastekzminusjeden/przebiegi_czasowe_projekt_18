#pragma once
#include "MyInterFace.h"
#include "Data.h"

/**
* Klaasa bêd¹ca kontenerem na dane wczytywane z pliku. Obs³uguje ca³¹ prace z surowymi danymi. W kontenerze przechowywane jest ostatnie 100s danych.
*/
class DataContainer
{
	public:

		/**
		* Konstruktor. Pobiera rozmiar pojemnosci wstepnej tablicy wxPoints, ktore beda rysowane.
		*/
		DataContainer(int partCapacity);

		/**
		* Destruktor. Dealokuje pamiec przydzielona na listy
		*/
		~DataContainer();

		/**
		* Zwraca rozmiar listy glownej
		*/
		int getListSize() const{ return m_capacity; }
		
		/**
		* Zwraca wskaznik do listy glownej wartosci czasu
		*/
		double * getListPointer_Time() const { return m_wxPointsArray_Time; };

		/**
		* Zwraca wskaznik do listy glownej wartosci funckji
		*/
		double * getListPointer_Value() const { return m_wxPointsArray_Value; };

		/**
		* Pobiera dane z pliku
		*/
		void getData();
	
		/**
		* Zwraca ostatni index listy glownej
		*/
		int getLastIndex() const { return m_lastIndex; }

	private:

		/**
		* Tablica wczytanych kolejnych czasow
		*/
		double * m_wxPointsArray_Time;

		/**
		* Tablica wczytanych kolejnych parametrow
		*/
		double * m_wxPointsArray_Value;
		
		/**
		* Pojemnosc kontenera
		*/
		int m_capacity;

		/**
		* Indeks ostatniej zapisanej wartosc w tablicach
		*/
		int m_lastIndex;


		std::ifstream plik;

		Data data;
	
		/**
		* Metoda przymusowo resetujaca historie
		*/
		void reset();
};

