// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "VtkWin.h"

BEGIN_EVENT_TABLE(VtkWin, wxPanel)
END_EVENT_TABLE()

VtkWin::VtkWin(wxPanel* VtkParent)
{
	vtkFileOutputWindow *Error = vtkFileOutputWindow::New();
	Error->SetFileName("Log.txt");
	vtkFileOutputWindow::SetInstance(Error);
	Error->Delete();

	vtkObject::GlobalWarningDisplayOff();

	Parent = VtkParent;
	VtkPanel = new wxVTKRenderWindowInteractor(Parent, -1);
	VtkPanel->UseCaptureMouseOn();
	SetDefaultSize();

	Model = new ModelData();
	TrackballCamera = vtkInteractorStyleTrackballCamera::New();
	VtkPanel->SetInteractorStyle(TrackballCamera);
	RenderWindow = vtkRenderWindow::New();
	RenderWindow = VtkPanel->GetRenderWindow();
	RenderWindow->AddRenderer(Model->Renderer);

	SetLogo();
}

VtkWin::~VtkWin()
{
	if (VtkPanel)
	{
		VtkPanel->Delete();
	}
}

void VtkWin::Render()
{
	RenderWindow->Render();
}

void VtkWin::ViewXYZ()
{
	Model->Renderer->GetActiveCamera()->SetPosition(-210000000, -210000000, 0);
	Model->Renderer->GetActiveCamera()->SetViewUp(1, 1, 1);
	ResetCamera();
	Render();
}

void VtkWin::ViewXZ()
{
	Model->Renderer->GetActiveCamera()->SetPosition(0, -210000000, 0);
	Model->Renderer->GetActiveCamera()->SetViewUp(0, 1, 0);
	ResetCamera();
	Render();
}

void VtkWin::ViewXY()
{
	Model->Renderer->GetActiveCamera()->SetPosition(0, 0, 210000000);
	Model->Renderer->GetActiveCamera()->SetViewUp(0, 1, -1);
	ResetCamera();
	Render();
}

void VtkWin::ViewYZ()
{
	Model->Renderer->GetActiveCamera()->SetPosition(210000000, 0, 0);
	Model->Renderer->GetActiveCamera()->SetViewUp(-1, 0, 1);
	ResetCamera();
	Render();
}

void VtkWin::SetAxes()
{
	Model->Axes->SetShaftTypeToCylinder();
	Model->AxesWidget->SetOutlineColor(1.0, 0.5, 0.0);
	Model->AxesWidget->SetOrientationMarker(Model->Axes);
	Model->AxesWidget->SetInteractor(VtkPanel);
	Model->AxesWidget->SetViewport(0.0, 0.0, 0.2, 0.2);
	Model->AxesWidget->EnabledOn();
	Model->AxesWidget->InteractiveOff();
}

void VtkWin::SetLogo()
{
	Model->LogoActor = vtkTextActor::New();
	Model->LogoActor->SetInput("OSLite");
	Model->LogoActor->SetPosition(5, 5);
	Model->LogoActor->GetTextProperty()->SetFontSize(20);
	Model->Renderer->AddActor2D(Model->LogoActor);
}

void VtkWin::SetScalarBar()
{
	Model->ScalarsBar->SetLookupTable(Model->ShellMapper->GetLookupTable());
	//ScalarsBar->UseBoundsOn();
	Model->ScalarsBar->SetTitle("Deform");
	Model->ScalarsBar->SetNumberOfLabels(8);
	Model->ScalarsBar->GetLabelTextProperty()->BoldOff();
	Model->ScalarsBar->GetLabelTextProperty()->ItalicOff();
	Model->ScalarsBar->GetLabelTextProperty()->ShadowOff();
	//ScalarsBar->SetLabelFormat("%+#6.2e");

	Model->hueLut->SetTableRange(0, Model->MaxDeform);
	Model->hueLut->SetHueRange(0, 1);
	Model->hueLut->SetSaturationRange(1, 1);
	Model->hueLut->SetValueRange(0.5, 1);
	Model->hueLut->Build();

	Model->ShellMapper->SetLookupTable(Model->hueLut);
	Model->ScalarsBar->SetLookupTable(Model->hueLut);

	Model->Renderer->AddActor2D(Model->ScalarsBar);




	//Model->
	Model->ScalarsBar = vtkSmartPointer<vtkScalarBarActor>::New();
	Model->hueLut = vtkSmartPointer<vtkLookupTable>::New();


	Model->scalarBarWidget->SetInteractor(VtkPanel);
	Model->scalarBarWidget->SetScalarBarActor(Model->ScalarsBar);
	Model->scalarBarWidget->On();
}

void VtkWin::ResetCamera()
{
	Model->Renderer->ResetCamera();
}

void VtkWin::SetDefaultSize()
{
	wxSize VtkSize = Parent->GetClientSize();
	VtkPanel->SetClientSize(VtkSize);
}

void VtkWin::ChangeColor()
{
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");

	double LineWidth;
	Config->GetValue("LineWidth").ToDouble(&LineWidth);

	wxColor BgColor = Config->GetColor("BgColor");
	Model->Renderer->SetBackground((BgColor.Red()) / 255.0, (BgColor.Green()) / 255.0, (BgColor.Blue()) / 255.0);

	wxColor PointColor = Config->GetColor("PointColor");
	Model->PointSpheresActor->GetProperty()->SetColor((PointColor.Red()) / 255.0, (PointColor.Green()) / 255.0, (PointColor.Blue()) / 255.0);

	double LineTrans;
	Config->GetValue("LineTrans").ToDouble(&LineTrans);
	wxColor LineColor = Config->GetColor("LineColor");
	Model->LinesActor->GetProperty()->SetColor((LineColor.Red()) / 255.0, (LineColor.Green()) / 255.0, (LineColor.Blue()) / 255.0);
	Model->LinesActor->GetProperty()->SetOpacity(LineTrans);

	wxColor EdgeColor = Config->GetColor("EdgeColor");
	double ShellTrans;
	Config->GetValue("ShellTrans").ToDouble(&ShellTrans);
	wxColor ShellColor = Config->GetColor("ShellColor");
	Model->ShellActor->GetProperty()->SetColor((ShellColor.Red()) / 255.0, (ShellColor.Green()) / 255.0, (ShellColor.Blue()) / 255.0);
	Model->ShellActor->GetProperty()->SetOpacity(ShellTrans);
	Model->ShellActor->GetProperty()->SetEdgeColor((EdgeColor.Red()) / 255.0, (EdgeColor.Green()) / 255.0, (EdgeColor.Blue()) / 255.0);
	Model->ShellActor->GetProperty()->SetLineWidth(0.5);
	Model->ShellActor->GetProperty()->SetEdgeVisibility(1);

	double SolidTrans;
	Config->GetValue("SolidTrans").ToDouble(&SolidTrans);
	wxColor SolidColor = Config->GetColor("SolidColor");
	Model->BrickActor->GetProperty()->SetColor((SolidColor.Red()) / 255.0, (SolidColor.Green()) / 255.0, (SolidColor.Blue()) / 255.0);
	Model->BrickActor->GetProperty()->SetOpacity(SolidTrans);
	Model->BrickActor->GetProperty()->SetEdgeColor((EdgeColor.Red()) / 255.0, (EdgeColor.Green()) / 255.0, (EdgeColor.Blue()) / 255.0);
	Model->BrickActor->GetProperty()->SetLineWidth(0.5);
	Model->BrickActor->GetProperty()->SetEdgeVisibility(1);

	double OtherTrans;
	Config->GetValue("OtherTrans").ToDouble(&OtherTrans);
	wxColor OtherColor = Config->GetColor("OtherColor");
	Model->MasonPanActor->GetProperty()->SetColor((OtherColor.Red()) / 255.0, (OtherColor.Green()) / 255.0, (OtherColor.Blue()) / 255.0);
	Model->MasonPanActor->GetProperty()->SetOpacity(OtherTrans);
	Model->MasonPanActor->GetProperty()->SetEdgeColor((EdgeColor.Red()) / 255.0, (EdgeColor.Green()) / 255.0, (EdgeColor.Blue()) / 255.0);
	Model->MasonPanActor->GetProperty()->SetLineWidth(LineWidth);
	Model->MasonPanActor->GetProperty()->SetEdgeVisibility(1);

	wxColor LinkColor = Config->GetColor("LinkColor");
	Model->Joint2DActor->GetProperty()->SetColor((LinkColor.Red()) / 255.0, (LinkColor.Green()) / 255.0, (LinkColor.Blue()) / 255.0);

	wxColor MpColor = Config->GetColor("MpColor");
	Model->RigidLinkActor->GetProperty()->SetColor((MpColor.Red()) / 255.0, (MpColor.Green()) / 255.0, (MpColor.Blue()) / 255.0);
	Model->EqualDofActor->GetProperty()->SetColor((MpColor.Red()) / 255.0, (MpColor.Green()) / 255.0, (MpColor.Blue()) / 255.0);

	double PointSize;
	Config->GetValue("PointSize").ToDouble(&PointSize);
	Model->PointSpheresActor->GetProperty()->RenderPointsAsSpheresOn();
	Model->PointSpheresActor->GetProperty()->SetPointSize(PointSize);


	Model->LinesActor->GetProperty()->SetLineWidth(LineWidth);
	Model->Joint2DActor->GetProperty()->SetLineWidth(LineWidth);

	Model->LogoActor->GetTextProperty()->SetColor(1.0 - BgColor.Red() / 255.0, 1.0 - BgColor.Green() / 255.0, 1.0 - BgColor.Blue() / 255.0);
}
