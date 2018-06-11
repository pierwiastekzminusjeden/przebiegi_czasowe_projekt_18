#pragma once
#include <fstream>  

/**
*\ Klasa, ktorej obiekt reprezentujaca punkt (czas, parametr) pobrany z pliku. 
*/
class Data{
  
	public:
	
		/**
		* \ Konstruktor. Ustawia wartosc czasu oraz wartosc funkcji w danej chwili. Jezeli nie zostana podane rzadne parametry, wartocci zostana ustawione jako zera.
		*/
        Data(double Time=0.0, double Value=0.0){
			this->Time = Time;
			this->Value = Value;
        }
	
		/**
		*\ Metoda dostepowa zwracajaca wartosc czasu.
		*/
        double GetTime() const { return this->Time; }
	
		/**
		*\ Metoda dostepowa zwracajaca wartosc funkcji.
		*/
        double GetValue() const{ return this->Value; }
	
		/**
		*\ Metoda ustawiajaca wartosc czasu oraz wartosc funkcji.
		*/
        void SetData(double Time, double Value){
            this->Time = Time;
            this->Value = Value;
        }
	
		/**
		*\ Metoda pobierajaca danez pliku oraz zapisujaca je. 
		*/
		void GetDataFromFile(std::ifstream & pl) {
			double times, value;
			pl >> times;
			pl >> value;
			this->SetData(times, value);
		};
		
		/**
		*\ Destruktor
		*/
        ~Data(){};

    private:

		/**
		*\ Zmienna reprezentujaca czas wyrazony w sekundach.
		*/
		double Time;
		
		/**
		*\ Zmienna reprezentujaca wartosc funkcji w danej chwili czasowej.
		*/
		double Value;
      
};



