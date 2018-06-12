#include "DrawingClass.h"


DrawingClass::DrawingClass(MyInterface *obj): m_myInterfacePTR(obj){ 
}

int DrawingClass::start_plus_X = 0;
int DrawingClass::start_minus_X = -1;
int DrawingClass::ile_X = 0;

int DrawingClass::start_plus_Y = 0;
int DrawingClass::start_minus_Y = -1;
int DrawingClass::ile_Y = 0;

void DrawingClass::draw(wxDC * dc)
{
	int w = m_myInterfacePTR->getWidth();
	int h = m_myInterfacePTR->getHeight();

	dc->SetBackground(wxBrush(RGB(20, 20, 20)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	dc->SetClippingRegion(wxRect(0, 0, w, h));

	if (m_myInterfacePTR->m_gridFlag)
		drawGrid(dc);

	drawAxes(dc);

	drawData(dc);
	
	if (m_myInterfacePTR->reset == 0)
	{
		start_plus_X = 0;
		start_minus_X = -1;
		ile_X = 0;

		start_plus_Y = 0;
		start_minus_Y = -1;
		ile_Y = 0;

		m_myInterfacePTR->reset = 1;
		trans = 0;
		trans2 = 0.5;
	}
}

void DrawingClass::drawAxes(wxDC * dc)
{

	int w = m_myInterfacePTR->getWidth();
	int h = m_myInterfacePTR->getHeight();
	if (w % 2 != 0)
		w--;
	if (h % 2 != 0)
		h--;

	dc->SetPen(wxPen(*wxBLUE, 1));
	dc->SetTextForeground(*wxWHITE);
	dc->DrawLine(0, 0.5*h , w , 0.5*h );
	dc->DrawLine(0.5*w , 0 , 0.5*w , h );
	
	dc->DrawLine(w- 20, 0.5*h + 10, w , 0.5*h);
	dc->DrawLine(w - 20, 0.5*h - 10, w , 0.5*h);

	dc->DrawLine(0.5*w, 0, 0.5*w - 10, 30);
	dc->DrawLine(0.5*w, 0, 0.5*w + 10, 30);

	int i, j;
	int dens = 100;

	int big=0;
	int str_pl_X = start_plus_X;
	int str_mn_X = start_minus_X;
	ile_X = 0;

	int str_pl_Y = start_plus_Y;
	int str_mn_Y = start_minus_Y;
	ile_Y = 0;

	for (j = i = 0.5*w; i < w, j > 0; i += w / dens, j -= w / dens) {


		std::string plus = std::to_string(str_pl_X);
		std::string minus = std::to_string(str_mn_X);

		if (big%10 == 0)
		{
			dc->DrawLine(i, h / 2 - 12, i, h / 2 + 12);
			dc->DrawLine(j, h / 2 - 12, j, h / 2 + 12);

			dc->DrawText(minus, j - w/20 - 30, h / 2 + 15);
			if(str_pl_X!= str_pl_X+ile_X)
				dc->DrawText(plus, i - 2, h / 2 + 15);

			str_pl_X++;
			str_mn_X--;
			ile_X++;
		}
		else
		{
			dc->DrawLine(i, h / 2 - 6, i, h / 2 + 6);
			dc->DrawLine(j, h / 2 - 6, j, h / 2 + 6);
		}

		big++;

	}

	big = 0;
	dens = 200;
	for (j = i = 0.5*h; i < h, j > 0; i += h / dens, j -= h / dens) {


		std::string plus = std::to_string(str_pl_Y);
		std::string minus = std::to_string(str_mn_Y);

		if (big % 10 == 0)
		{
			dc->DrawLine(w/2-12, i, w/2+12, i);
			dc->DrawLine(w / 2 - 12, j, w / 2 + 12, j);

			if(str_pl_Y!=0)
				dc->DrawText(plus, w / 2 - 22 , j-6);
			dc->DrawText(minus, w / 2 - 30, i +h/20 - 10 );

			str_pl_Y=str_pl_Y+1;
			str_mn_Y = str_mn_Y - 1;
			ile_Y++;
		}
		big++;

	}
}

void DrawingClass::drawGrid(wxDC * dc)
{
	int w = m_myInterfacePTR->getWidth();
	int h = m_myInterfacePTR->getHeight();

	dc->SetPen(wxPen(RGB(192, 192, 192), 0.5, wxPENSTYLE_DOT));
	
	
	int i, j;
	//dens gestosc siatki
	int dens = 200;
	int here = 0;
	for (j = i =  0.5*w ; i < w, j > 0; i += w / dens, j-=w/dens) {
		if (here%10 == 0){
			dc->DrawLine(i, 0, i, h);
			dc->DrawLine(j, 0, j, h);
		}
		here++;
	}
	here = 0;
	for (j = i =  0.5*h; i < h, j > 0; i += h/dens, j-=h/dens) {
		if (here % 10 == 0){
			dc->DrawLine(0, i, w, i);
			dc->DrawLine(0, j, w, j);
		}
		here++;
	}
}


void DrawingClass::drawData(wxDC * dc) 
{
	
	int lastIndex = m_myInterfacePTR->m_dataContainer->getLastIndex();
	wxPoint *arr2 = m_myInterfacePTR->m_drawingClass->scaleTranslate(dc);
	int w = m_myInterfacePTR->getWidth();
	int size = 200;

	//Rysowanie zaleznie od wybranego modu pracy
	if (m_myInterfacePTR->m_secondModeFlag && lastIndex > 100) {
		dc->SetPen(wxPen(RGB(225, 20, 20), 0.2));
		dc->DrawLines(lastIndex, arr2, 0.5 * m_myInterfacePTR->getWidth(), 0.5 * m_myInterfacePTR->getHeight());
	
		dc->SetPen(wxPen(RGB(0, 255, 35), 0.2));
		dc->DrawLines(lastIndex - 100, arr2, 1.5*m_myInterfacePTR->getWidth(), 0.5 * m_myInterfacePTR->getHeight());		//Do skalowanej wersji
	}
	else {
		dc->SetPen(wxPen(RGB(225, 20, 20), 0.2));
		dc->DrawLines(lastIndex, arr2, 0.5 * m_myInterfacePTR->getWidth(), 0.5 * m_myInterfacePTR->getHeight());
	}
	
	wxMilliSleep(100);  
}


int DrawingClass::trans = 0;
int DrawingClass::trans2 = 0.5;

wxPoint* DrawingClass::scaleTranslate(wxDC * dc)
{
	double * arr_x = m_myInterfacePTR->m_dataContainer->getListPointer_Time();
	double * arr_y = m_myInterfacePTR->m_dataContainer->getListPointer_Value();
	int lastIndex = m_myInterfacePTR->m_dataContainer->getLastIndex();
	wxPoint * copy = new wxPoint[lastIndex];
	wxPoint * arr = new wxPoint[lastIndex];
	double * arr_x1 = new double[lastIndex];
	double * arr_y1 = new double[lastIndex];
	int w = m_myInterfacePTR->getWidth();
	int h = m_myInterfacePTR->getHeight();
	
	int i,j;

	for (i = 0; i < lastIndex; i++)
	{
		arr_x1[i] = arr_x[i];
		arr_y1[i] = arr_y[i];
	}

	//skalowanie
	for (i = 0; i < lastIndex; i++)
	{
		arr[i].x = arr_x[i] * (w / 10);
		arr[i].y = arr_y[i] * (-h / 20);

		if (arr_x1[i] == arr_x[i])
		{	
			copy[i].x = arr_x1[i] * (w / 10);
			arr_x1[i] = arr_x1[i + 1] * (w / 10);
		}
		if (arr_y1[i] == arr_y[i])
		{
			copy[i].y = arr_y1[i] * (-h / 20);
			arr_y1[i] = arr_y1[i] * (-h / 20);
		}
	}

	//przesuniecie
	for (i = 0; i < lastIndex; i++)
	{
		for (j = 0; j <= lastIndex; j = j + 2)
		{
			if (copy[i].x >= w / 2)
			{
				if (copy[j].x == arr[j].x)
				{
					if (trans != 0)
					{
						copy[j].x = copy[j].x - trans*w / 2;
						copy[j + 1].x = copy[j + 1].x - trans*w / 2;
					}
					if (copy[j].x  > w* trans2+w/2)
					{
						trans++;
						trans2 = trans2 + 0.5;
						start_plus_X = start_plus_X + ile_X;
						start_minus_X = start_minus_X + ile_X;
					}
				}
			}
		}
	}

	return copy;
}

