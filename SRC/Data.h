#pragma once
#include <fstream>  

/**
*\ Klasa, ktorej obiekt reprezentuj�ca punkt (czas, parametr) pobrany z pliku. 
*/
class Data{
  
	public:
	
		/**
		*  Konstruktor. Ustawia wartosc czasu oraz warto�� funkcji w danej chwili. Jezeli nie zostan� podane rzadne parametry, wartocci zostan� ustawione jako zera.
		*/
        Data(double Time=0.0, double Value=0.0){
			this->Time = Time;
			this->Value = Value;
        }
	
		/**
		* Metoda dostepowa zwracajaca wartosc czasu.
		*/
        double GetTime() const { return this->Time; }
	
		/**
		* Metoda dost�powa zwracaj�ca wartosc funkcji.
		*/
        double GetValue() const{ return this->Value; }
	
		/**
		* Metoda ustawiaj�ca wartosc czasu oraz wartosc funkcji.
		*/
        void SetData(double Time, double Value){
            this->Time = Time;
            this->Value = Value;
        }
	
		/**
		* Metoda pobierajaca danez pliku oraz zapisujaca je. 
		*/
		void GetDataFromFile(std::ifstream & pl) {
			double times, value;
			pl >> times;
			pl >> value;
			this->SetData(times, value);
		};
		
	
    private:

		/**
		* Zmienna reprezentuj�ca czas wyrazony w sekundach.
		*/
		double Time;
		
		/**
		* Zmienna reprezentuj�ca wartosc funkcji w danej chwili czasowej.
		*/
		double Value;
      
};



