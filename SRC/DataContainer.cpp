#include "DataContainer.h"
#include <wx/math.h>
#include <fstream>


DataContainer::DataContainer(int size) : m_capacity(size), m_lastIndex(0)
{
	
	plik.open("dane.dat", std::fstream::in);
	if (!plik.is_open())
		exit(0);

	m_wxPointsArray_Time = new double[m_capacity];
	m_wxPointsArray_Value = new double[m_capacity];
}

DataContainer::~DataContainer()
{
	delete[] m_wxPointsArray_Time;
	delete[] m_wxPointsArray_Value;
}


void DataContainer::getData()
{
	
	if (m_lastIndex >= m_capacity)
		reset();


	if(!m_wxPointsArray_Time)
		m_wxPointsArray_Time = new double[m_capacity/2];

	if (!m_wxPointsArray_Value)
		m_wxPointsArray_Value = new double[m_capacity / 2];

	if (plik.eof()) {
			plik.clear();
			plik.seekg(0);
		}

	if (m_lastIndex < m_capacity) {
		//plik.clear();
		data.GetDataFromFile(plik);
		m_wxPointsArray_Time[m_lastIndex] = data.GetTime();
		m_wxPointsArray_Value[m_lastIndex]= data.GetValue();
	}
	
	m_lastIndex++;
}

void DataContainer::reset()
{
	delete[] m_wxPointsArray_Time;
	delete[] m_wxPointsArray_Value;
	m_wxPointsArray_Time = NULL;
	m_wxPointsArray_Value = NULL;

	m_lastIndex = 0;
	
}



