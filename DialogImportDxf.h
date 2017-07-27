// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogImportDxf__
#define __DialogImportDxf__

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <float.h>
#include <stdlib.h>
#include <ctype.h>
#include <wx/wx.h>
#include "GuiBase/DialogImportDxfBase.h"
#include "DxfData.h"
#include "Struct.h"
#include "ComFunc.h"

using namespace std;

class DialogImportDxf : public DialogImportDxfBase
{
public:
	DialogImportDxf(wxWindow* parent);
	~DialogImportDxf();
	wxString GetData();
	ComFunc F;

protected:
	// protected event handlers
	virtual void OnClose(wxCloseEvent& event);
	virtual void OnOpenClick(wxCommandEvent& event);
	virtual void OnOKClick(wxCommandEvent& event);
	virtual void OnCancelClick(wxCommandEvent& event);
	// class to store file read:
	dx_data fData;
	vector<Node> NodeArr;
	vector<Link> LinkArr;
	vector<Shell> ShellArr;
	int GetNodeID(double X, double Y, double Z);
	bool CheckLink(int IDA, int IDB);
	bool CheckQuad(int IDI, int IDJ, int IDK, int IDL);
	wxString NodesData;
	wxString LinksData;
	wxString QuadsData;
};

#endif //__DialogImportDxf__
