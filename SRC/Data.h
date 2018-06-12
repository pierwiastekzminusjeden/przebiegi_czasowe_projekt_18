#pragma once
#include <fstream>  

/**
*\ Klasa, ktorej obiekt reprezentuj¹ca punkt (czas, parametr) pobrany z pliku. 
*/
class Data{
  
	public:
	
		/**
		*  Konstruktor. Ustawia wartosc czasu oraz wartoœæ funkcji w danej chwili. Jezeli nie zostan¹ podane rzadne parametry, wartocci zostan¹ ustawione jako zera.
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
		* Metoda dostêpowa zwracaj¹ca wartosc funkcji.
		*/
        double GetValue() const{ return this->Value; }
	
		/**
		* Metoda ustawiaj¹ca wartosc czasu oraz wartosc funkcji.
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
		* Zmienna reprezentuj¹ca czas wyrazony w sekundach.
		*/
		double Time;
		
		/**
		* Zmienna reprezentuj¹ca wartosc funkcji w danej chwili czasowej.
		*/
		double Value;
      
};



