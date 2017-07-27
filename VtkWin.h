// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __VtkWin__
#define __VtkWin__

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

#include <wx/wxprec.h>
#include <wx/wx.h>

#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkFileOutputWindow.h>

#include "wxVTKRenderWindowInteractor.h"
#include "ModelData.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"
#include "Struct.h"

class VtkWin : public wxPanel
{
public:
	VtkWin(wxPanel* VtkParent);
	~VtkWin();

	ModelData *Model;
	void SetDefaultSize();
	void ChangeColor();
	void Render();
	void ViewXYZ();
	void ViewXZ();
	void ViewXY();
	void ViewYZ();
	void SetAxes();
	void SetLogo();
	void SetScalarBar();
	void ResetCamera();
private:

	ComFunc F;
	OSLiteConfig *Config;

	wxVTKRenderWindowInteractor        *VtkPanel;
	vtkRenderWindow                    *RenderWindow;
	vtkInteractorStyleTrackballCamera  *TrackballCamera;
	wxPanel *Parent;

	DECLARE_EVENT_TABLE()
};



#endif
