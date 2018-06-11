#include <wx/wx.h>
#include <memory>
#include "MyInterFace.h"


class MyApp : public wxApp {

public:

 virtual bool OnInit();
 virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
 MyInterface *mainFrame = new MyInterface(NULL);
 mainFrame->Show(true);
 SetTopWindow(mainFrame);


 return true;
}



