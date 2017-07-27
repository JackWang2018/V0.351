// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogShowDeformed__
#define __DialogShowDeformed__

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <wx/wx.h>
#include <wx/slider.h>
#include "GuiBase/DialogShowDeformedBase.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"
#include "Struct.h"
#include "DeclareUserEvent.h"

using namespace std;


class DialogShowDeformed : public DialogShowDeformedBase
{
public:
	DialogShowDeformed(wxWindow* HandleIn, wxString PathIn, double *DeformArrIn, int *ScaleIn, int NodeNumIn, double *MaxDeformIn);
	virtual void OnCloseDialog(wxCloseEvent& event);
	void OnSelectResualtFile(wxCommandEvent& event);
	void DisplayDeform();
	void OnAutoPlay(wxCommandEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnStop(wxCommandEvent& event);
	void OnChangeCase(wxCommandEvent& event);
	void OnChangedSliderScale(wxScrollEvent& event);
	void OnChangedTextScale(wxUpdateUIEvent& event);
	void OnChangedSliderSpeed(wxScrollEvent& event);
	void OnChangedTextSpeed(wxUpdateUIEvent& event);
	void OnChangedTime(wxScrollEvent& event);
	void LoadData();
	void CheckStates();
	~DialogShowDeformed();

private:
	int *Scale;
	OSLiteConfig *Config;
	ComFunc F;
	vector< vector<double> > D;
	int NodeOfNum;
	wxWindow *Handle;
	int CntRow, CntCol, LineStart,LineEnd;
	double *DeformArr;
	vector<AnalysisCase>AnalysisCaseVec;
	double *MaxDeform;
	int TimeStep;
	int TimeSpeed;
	int LineIdx;
	int NumModes;
	wxString Path;
};

#endif
