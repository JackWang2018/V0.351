// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "ModelData.h"

ModelData::ModelData()
{
	NodeArr = vtkSmartPointer<vtkPoints>::New();
	ScalarsArr = vtkSmartPointer<vtkFloatArray>::New();

	LineArr = vtkSmartPointer<vtkCellArray>::New();
	ShellArr = vtkSmartPointer<vtkCellArray>::New();
	BrickArr = vtkSmartPointer<vtkCellArray>::New();
	Joint2DArr = vtkSmartPointer<vtkCellArray>::New();
	MasonPanArr = vtkSmartPointer<vtkCellArray>::New();
	RigidLinkArr = vtkSmartPointer<vtkCellArray>::New();
	EqualDofArr = vtkSmartPointer<vtkCellArray>::New();

	LinesPolyData = vtkSmartPointer<vtkPolyData>::New();
	ShellPolyData = vtkSmartPointer<vtkPolyData>::New();
	BrickPolyData = vtkSmartPointer<vtkPolyData>::New();
	Joint2DPolyData = vtkSmartPointer<vtkPolyData>::New();
	MasonPanPolyData = vtkSmartPointer<vtkPolyData>::New();
	RigidLinkPolyData = vtkSmartPointer<vtkPolyData>::New();
	EqualDofPolyData = vtkSmartPointer<vtkPolyData>::New();

	LinesMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	ShellMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	BrickMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	Joint2DMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	MasonPanMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	RigidLinkMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	EqualDofMapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	LinesActor = vtkSmartPointer<vtkActor>::New();
	ShellActor = vtkSmartPointer<vtkActor>::New();
	BrickActor = vtkSmartPointer<vtkActor>::New();
	Joint2DActor = vtkSmartPointer<vtkActor>::New();
	MasonPanActor = vtkSmartPointer<vtkActor>::New();
	RigidLinkActor = vtkSmartPointer<vtkActor>::New();
	EqualDofActor = vtkSmartPointer<vtkActor>::New();

	Renderer = vtkSmartPointer<vtkRenderer>::New();
	Axes = vtkSmartPointer<vtkAxesActor>::New();
	AxesWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();

	NodeNumArr = vtkSmartPointer<vtkPoints>::New();
	NodeNumPolyData = vtkSmartPointer<vtkPolyData>::New();
	NodeVert = vtkSmartPointer<vtkCellArray>::New();
	NodeNumActor = vtkSmartPointer<vtkActor2D>::New();
	PointSpheresMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	PointSpheresActor = vtkSmartPointer<vtkActor>::New();
	NodeLabels = vtkSmartPointer<vtkStringArray>::New();

	EleNumPolyData = vtkSmartPointer<vtkPolyData>::New();
	EleNumArr = vtkSmartPointer<vtkPoints>::New();
	EleNumActor = vtkSmartPointer<vtkActor2D>::New();
	EleLabels = vtkSmartPointer<vtkStringArray>::New();
}

void ModelData::Reset()
{
	NodeArr->Initialize();
	NodeArr->Modified();

	ScalarsArr->Initialize();
	ScalarsArr->Modified();

	LineArr->Initialize();
	LineArr->Modified();

	ShellArr->Initialize();
	ShellArr->Modified();

	BrickArr->Initialize();
	BrickArr->Modified();

	Joint2DArr->Initialize();
	Joint2DArr->Modified();

	MasonPanArr->Initialize();
	MasonPanArr->Modified();

	RigidLinkArr->Initialize();
	RigidLinkArr->Modified();

	EqualDofArr->Initialize();
	EqualDofArr->Modified();

	NodeNumArr->Initialize();
	NodeNumArr->Modified();

	NodeNumPolyData->Initialize();
	NodeNumPolyData->Modified();

	EleNumPolyData->Initialize();
	EleNumPolyData->Modified();

	NodeVert->Initialize();
	NodeVert->Modified();

	EleNumArr->Initialize();
	EleNumArr->Modified();

	NodeLabels->Initialize();
	NodeLabels->Modified();

	EleLabels->Initialize();
	EleLabels->Modified();

	LinesPolyData->Initialize();
	LinesPolyData->Modified();

	ShellPolyData->Initialize();
	ShellPolyData->Modified();

	BrickPolyData->Initialize();
	BrickPolyData->Modified();

	Joint2DPolyData->Initialize();
	Joint2DPolyData->Modified();

	MasonPanPolyData->Initialize();
	MasonPanPolyData->Modified();

	NodeLabels->SetName("NodeLabels");
	EleLabels->SetName("EleLabels");

	NodeMap.clear();
	MaxDeform = 0.0;
}

void ModelData::InitRenderer()
{
	LinesPolyData->SetPoints(NodeArr);
	LinesPolyData->SetLines(LineArr);
	LinesMapper->SetInputData(LinesPolyData);
	LinesActor->SetMapper(LinesMapper);
	Renderer->AddActor(LinesActor);

	ShellPolyData->SetPoints(NodeArr);
	ShellPolyData->SetLines(ShellArr);
	ShellPolyData->SetPolys(ShellArr);
	ShellMapper->SetInputData(ShellPolyData);
	ShellActor->SetMapper(ShellMapper);
	Renderer->AddActor(ShellActor);

	BrickPolyData->SetPoints(NodeArr);
	BrickPolyData->SetLines(BrickArr);
	BrickPolyData->SetPolys(BrickArr);
	BrickMapper->SetInputData(BrickPolyData);
	BrickActor->SetMapper(BrickMapper);
	Renderer->AddActor(BrickActor);

	Joint2DPolyData->SetPoints(NodeArr);
	Joint2DPolyData->SetLines(Joint2DArr);
	Joint2DMapper->SetInputData(Joint2DPolyData);
	Joint2DActor->SetMapper(Joint2DMapper);
	Renderer->AddActor(Joint2DActor);

	MasonPanPolyData->SetPoints(NodeArr);
	MasonPanPolyData->SetLines(MasonPanArr);
	MasonPanPolyData->SetPolys(MasonPanArr);
	MasonPanMapper->SetInputData(MasonPanPolyData);
	MasonPanActor->SetMapper(MasonPanMapper);
	Renderer->AddActor(MasonPanActor);

	RigidLinkPolyData->SetPoints(NodeArr);
	RigidLinkPolyData->SetLines(RigidLinkArr);
	RigidLinkMapper->SetInputData(RigidLinkPolyData);
	RigidLinkActor->SetMapper(RigidLinkMapper);
	Renderer->AddActor(RigidLinkActor);

	EqualDofPolyData->SetPoints(NodeArr);
	EqualDofPolyData->SetLines(EqualDofArr);
	EqualDofMapper->SetInputData(EqualDofPolyData);
	EqualDofActor->SetMapper(EqualDofMapper);
	Renderer->AddActor(EqualDofActor);

	NodeNumPolyData->SetPoints(NodeNumArr);
	NodeNumPolyData->SetVerts(NodeVert);
	PointSpheresMapper->SetInputData(NodeNumPolyData);
	PointSpheresActor->SetMapper(PointSpheresMapper);
	Renderer->AddActor(PointSpheresActor);

	//Renderer->RemoveActor2D(ScalarsBar);
	EleNumPolyData->SetPoints(EleNumArr);
}

void ModelData::SetLabelOn(bool T, wxString Name)
{
	if (T)
	{
		NodeNumPolyData->GetPointData()->AddArray(NodeLabels);
		EleNumPolyData->GetPointData()->AddArray(EleLabels);

		vtkSmartPointer<vtkTextProperty> TextProp = vtkSmartPointer<vtkTextProperty>::New();
		Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
		wxColor TextColor = Config->GetColor("TextColor");
		TextProp->SetColor((TextColor.Red()) / 255.0, (TextColor.Green()) / 255.0, (TextColor.Blue()) / 255.0);

		// Generate the label hierarchy.
		vtkSmartPointer<vtkPointSetToLabelHierarchy> PointSetToLabelHierarchyFilter = vtkSmartPointer<vtkPointSetToLabelHierarchy>::New();
		vtkSmartPointer<vtkLabelPlacementMapper> LabelMapper = vtkSmartPointer<vtkLabelPlacementMapper>::New();

		if (Name == "Node")
		{
			PointSetToLabelHierarchyFilter->SetInputData(NodeNumPolyData);
			PointSetToLabelHierarchyFilter->SetLabelArrayName("NodeLabels");
			PointSetToLabelHierarchyFilter->SetTextProperty(TextProp);
			PointSetToLabelHierarchyFilter->Update();
			LabelMapper->SetInputConnection(PointSetToLabelHierarchyFilter->GetOutputPort());
			NodeNumActor->SetMapper(LabelMapper);
			Renderer->AddActor(NodeNumActor);
		}
		else if (Name == "Element")
		{
			PointSetToLabelHierarchyFilter->SetInputData(EleNumPolyData);
			PointSetToLabelHierarchyFilter->SetLabelArrayName("EleLabels");
			PointSetToLabelHierarchyFilter->SetTextProperty(TextProp);
			PointSetToLabelHierarchyFilter->Update();
			LabelMapper->SetInputConnection(PointSetToLabelHierarchyFilter->GetOutputPort());
			EleNumActor->SetMapper(LabelMapper);
			Renderer->AddActor(EleNumActor);
		}
	}
	else
	{
		if (Name == "Node")
		{
			Renderer->RemoveActor(NodeNumActor);
		}
		else if (Name == "Element")
		{
			Renderer->RemoveActor(EleNumActor);
		}

	}
}

void ModelData::InsertNode(Node X)
{
	int Num = NodeArr->GetNumberOfPoints();
	NodeArr->InsertNextPoint(X.X, X.Y, X.Z);
	NodeMap[X.ID] = Num;

	Pid[0] = NodeNumArr->InsertNextPoint(X.X, X.Y, X.Z);
	NodeVert->InsertNextCell(1, Pid);
	NodeLabels->InsertNextValue(F.ToString(X.ID));

	ScalarsArr->SetNumberOfValues(Num + 1);
}

void ModelData::ModifyNode(NodeDeform X)
{
	int ID = NodeMap[X.ID];
	double D[3];
	D[0] = X.X;
	D[1] = X.Y;
	D[2] = X.Z;
	NodeArr->SetPoint(ID, D);
	NodeNumArr->SetPoint(ID, D);
}

void ModelData::ModifyScalars(NodeDeform X, bool IsRealTime, double MaxDeformIn)
{
	int ID = NodeMap[X.ID];
	double Deform = sqrt(X.X*X.X + X.Y*X.Y + X.Z*X.Z);
	if (IsRealTime)
	{
		if (Deform > MaxDeform)
		{
			MaxDeform = Deform;
		}
	}
	else
	{
		MaxDeform = MaxDeformIn;
	}
	ScalarsArr->SetValue(ID, 1 - Deform / MaxDeform);
	//ScalarsArr->SetValue(ID, Deform);
}

void ModelData::ModifyNode()
{
	LinesPolyData->GetPointData()->SetScalars(ScalarsArr);
	ShellPolyData->GetPointData()->SetScalars(ScalarsArr);
	BrickPolyData->GetPointData()->SetScalars(ScalarsArr);

	LinesMapper->ScalarVisibilityOn();
	LinesMapper->SetScalarModeToUsePointData();
	LinesMapper->SetColorModeToMapScalars();

	ShellMapper->ScalarVisibilityOn();
	ShellMapper->SetScalarModeToUsePointData();
	ShellMapper->SetColorModeToMapScalars();

	BrickMapper->ScalarVisibilityOn();
	BrickMapper->SetScalarModeToUsePointData();
	BrickMapper->SetColorModeToMapScalars();

	LinesPolyData->Modified();
	NodeNumPolyData->Modified();
	EleNumPolyData->Modified();
	ShellPolyData->Modified();
	BrickPolyData->Modified();
	Joint2DPolyData->Modified();
	RigidLinkPolyData->Modified();
	EqualDofPolyData->Modified();
}

void ModelData::InsertLine(Link X)
{
	auto ii = NodeMap.find(X.NodeA);
	if (ii != NodeMap.end())
	{
		int Nd0 = ii->second;
		ii = NodeMap.find(X.NodeB);
		if (ii != NodeMap.end())
		{
			int Nd1 = ii->second;
			vtkSmartPointer<vtkLine> Line = vtkSmartPointer<vtkLine>::New();
			Line->GetPointIds()->SetId(0, Nd0);
			Line->GetPointIds()->SetId(1, Nd1);
			LineArr->InsertNextCell(Line);

			double P0[3], P1[3];
			NodeArr->GetPoint(Nd0, P0);
			NodeArr->GetPoint(Nd1, P1);
			EleNumArr->InsertNextPoint(0.5 * (P0[0] + P1[0]), 0.5 * (P0[1] + P1[1]), 0.5 * (P0[2] + P1[2]));
			EleLabels->InsertNextValue(F.ToString(X.ID));
		}
	}
}

void ModelData::InsertShell(Shell X)
{
	bool T = true;
	vector<int>D;
	for (int i = 0; i < X.NumP; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D.push_back(ii->second);
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		vtkSmartPointer<vtkPolygon> ShellT = vtkSmartPointer<vtkPolygon>::New();
		ShellT->GetPointIds()->SetNumberOfIds(X.NumP);
		double P[3];
		double Cent[3];
		Cent[0] = Cent[1] = Cent[2] = 0.0;
		for (int i = 0; i < X.NumP; ++i)
		{
			ShellT->GetPointIds()->SetId(i, D[i]);
			NodeArr->GetPoint(D[i], P);
			Cent[0] += P[0];
			Cent[1] += P[1];
			Cent[2] += P[2];
		}
		ShellArr->InsertNextCell(ShellT);
		Cent[0] /= X.NumP;
		Cent[1] /= X.NumP;
		Cent[2] /= X.NumP;
		EleNumArr->InsertNextPoint(Cent[0], Cent[1], Cent[2]);
		EleLabels->InsertNextValue(F.ToString(X.ID));
	}
}

void ModelData::InsertShell9N(Shell9N X)
{
	bool T = true;
	vector<int>D;
	for (int i = 0; i < 9; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D.push_back(ii->second);
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		vtkSmartPointer<vtkPolygon> ShellT = vtkSmartPointer<vtkPolygon>::New();
		ShellT->GetPointIds()->SetNumberOfIds(8);
		ShellT->GetPointIds()->SetId(0, D[0]);
		ShellT->GetPointIds()->SetId(1, D[4]);
		ShellT->GetPointIds()->SetId(2, D[1]);
		ShellT->GetPointIds()->SetId(3, D[5]);
		ShellT->GetPointIds()->SetId(4, D[2]);
		ShellT->GetPointIds()->SetId(5, D[6]);
		ShellT->GetPointIds()->SetId(6, D[3]);
		ShellT->GetPointIds()->SetId(7, D[7]);

		double P[3];
		double Cent[3];
		Cent[0] = Cent[1] = Cent[2] = 0.0;
		for (int i = 0; i < 8; ++i)
		{
			NodeArr->GetPoint(D[i], P);
			Cent[0] += P[0];
			Cent[1] += P[1];
			Cent[2] += P[2];
		}
		ShellArr->InsertNextCell(ShellT);
		Cent[0] /= 8;
		Cent[1] /= 8;
		Cent[2] /= 8;
		EleNumArr->InsertNextPoint(Cent[0], Cent[1], Cent[2]);
		EleLabels->InsertNextValue(F.ToString(X.ID));
	}
}

void ModelData::InsertBrick8N(Brick8N X)
{
	bool T = true;
	vector<int>D;
	for (int i = 0; i < 8; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D.push_back(ii->second);
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		vtkSmartPointer<vtkPolygon> Shell0123 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell4567 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell0154 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell1265 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell2376 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell0374 = vtkSmartPointer<vtkPolygon>::New();

		Shell0123->GetPointIds()->SetNumberOfIds(4);
		Shell4567->GetPointIds()->SetNumberOfIds(4);
		Shell0154->GetPointIds()->SetNumberOfIds(4);
		Shell1265->GetPointIds()->SetNumberOfIds(4);
		Shell2376->GetPointIds()->SetNumberOfIds(4);
		Shell0374->GetPointIds()->SetNumberOfIds(4);

		Shell0123->GetPointIds()->SetId(0, D[0]);
		Shell0123->GetPointIds()->SetId(1, D[1]);
		Shell0123->GetPointIds()->SetId(2, D[2]);
		Shell0123->GetPointIds()->SetId(3, D[3]);
		BrickArr->InsertNextCell(Shell0123);

		Shell4567->GetPointIds()->SetId(0, D[4]);
		Shell4567->GetPointIds()->SetId(1, D[5]);
		Shell4567->GetPointIds()->SetId(2, D[6]);
		Shell4567->GetPointIds()->SetId(3, D[7]);
		BrickArr->InsertNextCell(Shell4567);

		Shell0154->GetPointIds()->SetId(0, D[0]);
		Shell0154->GetPointIds()->SetId(1, D[1]);
		Shell0154->GetPointIds()->SetId(2, D[5]);
		Shell0154->GetPointIds()->SetId(3, D[4]);
		BrickArr->InsertNextCell(Shell0154);

		Shell1265->GetPointIds()->SetId(0, D[1]);
		Shell1265->GetPointIds()->SetId(1, D[2]);
		Shell1265->GetPointIds()->SetId(2, D[6]);
		Shell1265->GetPointIds()->SetId(3, D[5]);
		BrickArr->InsertNextCell(Shell1265);

		Shell2376->GetPointIds()->SetId(0, D[2]);
		Shell2376->GetPointIds()->SetId(1, D[3]);
		Shell2376->GetPointIds()->SetId(2, D[7]);
		Shell2376->GetPointIds()->SetId(3, D[6]);
		BrickArr->InsertNextCell(Shell2376);

		Shell0374->GetPointIds()->SetId(0, D[0]);
		Shell0374->GetPointIds()->SetId(1, D[3]);
		Shell0374->GetPointIds()->SetId(2, D[7]);
		Shell0374->GetPointIds()->SetId(3, D[4]);
		BrickArr->InsertNextCell(Shell0374);

		double P[3];
		double Cent[3];
		Cent[0] = Cent[1] = Cent[2] = 0.0;
		for (int i = 0; i < 8; ++i)
		{
			NodeArr->GetPoint(D[i], P);
			Cent[0] += P[0];
			Cent[1] += P[1];
			Cent[2] += P[2];
		}
		Cent[0] /= 8;
		Cent[1] /= 8;
		Cent[2] /= 8;
		EleNumArr->InsertNextPoint(Cent[0], Cent[1], Cent[2]);
		EleLabels->InsertNextValue(F.ToString(X.ID));
	}
}

void ModelData::InsertBrick20N(Brick20N X)
{
	bool T = true;
	vector<int>D;
	for (int i = 0; i < 20; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D.push_back(ii->second);
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		vtkSmartPointer<vtkPolygon> Shell_0_8_1_9_2_10_3_11 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell_4_12_5_13_6_14_7_15 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell_0_8_1_18_5_12_4_16 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell_1_9_2_18_6_13_5_17 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell_2_10_3_19_7_14_6_18 = vtkSmartPointer<vtkPolygon>::New();
		vtkSmartPointer<vtkPolygon> Shell_0_11_3_19_7_15_4_16 = vtkSmartPointer<vtkPolygon>::New();

		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetNumberOfIds(8);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetNumberOfIds(8);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetNumberOfIds(8);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetNumberOfIds(8);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetNumberOfIds(8);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetNumberOfIds(8);

		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(0, D[0]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(1, D[8]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(2, D[1]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(3, D[9]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(4, D[2]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(5, D[10]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(6, D[3]);
		Shell_0_8_1_9_2_10_3_11->GetPointIds()->SetId(7, D[11]);
		BrickArr->InsertNextCell(Shell_0_8_1_9_2_10_3_11);

		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(0, D[4]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(1, D[12]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(2, D[5]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(3, D[13]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(4, D[6]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(5, D[14]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(6, D[7]);
		Shell_4_12_5_13_6_14_7_15->GetPointIds()->SetId(7, D[15]);
		BrickArr->InsertNextCell(Shell_4_12_5_13_6_14_7_15);

		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(0, D[0]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(1, D[8]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(2, D[1]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(3, D[17]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(4, D[5]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(5, D[12]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(6, D[4]);
		Shell_0_8_1_18_5_12_4_16->GetPointIds()->SetId(7, D[16]);
		BrickArr->InsertNextCell(Shell_0_8_1_18_5_12_4_16);

		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(0, D[1]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(1, D[9]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(2, D[2]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(3, D[18]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(4, D[6]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(5, D[13]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(6, D[5]);
		Shell_1_9_2_18_6_13_5_17->GetPointIds()->SetId(7, D[17]);
		BrickArr->InsertNextCell(Shell_1_9_2_18_6_13_5_17);

		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(0, D[2]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(1, D[10]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(2, D[3]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(3, D[19]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(4, D[7]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(5, D[14]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(6, D[6]);
		Shell_2_10_3_19_7_14_6_18->GetPointIds()->SetId(7, D[18]);
		BrickArr->InsertNextCell(Shell_2_10_3_19_7_14_6_18);

		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(0, D[0]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(1, D[11]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(2, D[3]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(3, D[19]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(4, D[7]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(5, D[15]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(6, D[4]);
		Shell_0_11_3_19_7_15_4_16->GetPointIds()->SetId(7, D[16]);
		BrickArr->InsertNextCell(Shell_0_11_3_19_7_15_4_16);

		double P[3];
		double Cent[3];
		Cent[0] = Cent[1] = Cent[2] = 0.0;
		for (int i = 0; i < 20; ++i)
		{
			NodeArr->GetPoint(D[i], P);
			Cent[0] += P[0];
			Cent[1] += P[1];
			Cent[2] += P[2];
		}
		Cent[0] /= 20;
		Cent[1] /= 20;
		Cent[2] /= 20;
		EleNumArr->InsertNextPoint(Cent[0], Cent[1], Cent[2]);
		EleLabels->InsertNextValue(F.ToString(X.ID));
	}
}

void ModelData::InsertJoint2D(Joint2D X)
{
	bool T = true;
	int D[4];
	for (int i = 0; i < 4; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D[i] = ii->second;
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		double P[5][3];
		NodeArr->GetPoint(D[0], P[1]);
		NodeArr->GetPoint(D[1], P[2]);
		NodeArr->GetPoint(D[2], P[3]);
		NodeArr->GetPoint(D[3], P[4]);

		P[0][0] = (P[1][0] + P[2][0] + P[3][0] + P[4][0]) / 4;
		P[0][1] = (P[1][1] + P[2][1] + P[3][1] + P[4][1]) / 4;
		P[0][2] = (P[1][2] + P[2][2] + P[3][2] + P[4][2]) / 4;

		int Num = NodeArr->GetNumberOfPoints();
		Node NA, NB, NC, ND;
		NA.ID = Num;
		NA.X = P[1][0] + P[4][0] - P[0][0];
		NA.Y = P[1][1] + P[4][1] - P[0][1];
		NA.Z = P[1][2] + P[4][2] - P[0][2];
		NodeArr->InsertPoint(NA.ID, NA.X, NA.Y, NA.Z);

		NB.ID = Num + 1;
		NB.X = P[1][0] + P[2][0] - P[0][0];
		NB.Y = P[1][1] + P[2][1] - P[0][1];
		NB.Z = P[1][2] + P[2][2] - P[0][2];
		NodeArr->InsertPoint(NB.ID, NB.X, NB.Y, NB.Z);

		NC.ID = Num + 2;
		NC.X = P[2][0] + P[3][0] - P[0][0];
		NC.Y = P[2][1] + P[3][1] - P[0][1];
		NC.Z = P[2][2] + P[3][2] - P[0][2];
		NodeArr->InsertPoint(NC.ID, NC.X, NC.Y, NC.Z);

		ND.ID = Num + 3;
		ND.X = P[3][0] + P[4][0] - P[0][0];
		ND.Y = P[3][1] + P[4][1] - P[0][1];
		ND.Z = P[3][2] + P[4][2] - P[0][2];
		NodeArr->InsertPoint(ND.ID, ND.X, ND.Y, ND.Z);

		vtkSmartPointer<vtkLine> Line1 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line2 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line3 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line4 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line5 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line6 = vtkSmartPointer<vtkLine>::New();

		Line1->GetPointIds()->SetId(0, D[0]);
		Line1->GetPointIds()->SetId(1, D[2]);
		Line2->GetPointIds()->SetId(0, D[1]);
		Line2->GetPointIds()->SetId(1, D[3]);
		Line3->GetPointIds()->SetId(0, NA.ID);
		Line3->GetPointIds()->SetId(1, NB.ID);
		Line4->GetPointIds()->SetId(0, NB.ID);
		Line4->GetPointIds()->SetId(1, NC.ID);
		Line5->GetPointIds()->SetId(0, NC.ID);
		Line5->GetPointIds()->SetId(1, ND.ID);
		Line6->GetPointIds()->SetId(0, ND.ID);
		Line6->GetPointIds()->SetId(1, NA.ID);

		Joint2DArr->InsertNextCell(Line1);
		Joint2DArr->InsertNextCell(Line2);
		Joint2DArr->InsertNextCell(Line3);
		Joint2DArr->InsertNextCell(Line4);
		Joint2DArr->InsertNextCell(Line5);
		Joint2DArr->InsertNextCell(Line6);
	}
}

void ModelData::InsertBeamColumnJoint(BeamColumnJoint X)
{
	bool T = true;
	int D[4];
	for (int i = 0; i < 4; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D[i] = ii->second;
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		double P[5][3];
		NodeArr->GetPoint(D[0], P[1]);
		NodeArr->GetPoint(D[1], P[2]);
		NodeArr->GetPoint(D[2], P[3]);
		NodeArr->GetPoint(D[3], P[4]);

		P[0][0] = (P[1][0] + P[2][0] + P[3][0] + P[4][0]) / 4;
		P[0][1] = (P[1][1] + P[2][1] + P[3][1] + P[4][1]) / 4;
		P[0][2] = (P[1][2] + P[2][2] + P[3][2] + P[4][2]) / 4;

		int Num = NodeArr->GetNumberOfPoints();
		Node NA, NB, NC, ND;
		NA.ID = Num;
		NA.X = P[1][0] + P[4][0] - P[0][0];
		NA.Y = P[1][1] + P[4][1] - P[0][1];
		NA.Z = P[1][2] + P[4][2] - P[0][2];
		NodeArr->InsertPoint(NA.ID, NA.X, NA.Y, NA.Z);

		NB.ID = Num + 1;
		NB.X = P[1][0] + P[2][0] - P[0][0];
		NB.Y = P[1][1] + P[2][1] - P[0][1];
		NB.Z = P[1][2] + P[2][2] - P[0][2];
		NodeArr->InsertPoint(NB.ID, NB.X, NB.Y, NB.Z);

		NC.ID = Num + 2;
		NC.X = P[2][0] + P[3][0] - P[0][0];
		NC.Y = P[2][1] + P[3][1] - P[0][1];
		NC.Z = P[2][2] + P[3][2] - P[0][2];
		NodeArr->InsertPoint(NC.ID, NC.X, NC.Y, NC.Z);

		ND.ID = Num + 3;
		ND.X = P[3][0] + P[4][0] - P[0][0];
		ND.Y = P[3][1] + P[4][1] - P[0][1];
		ND.Z = P[3][2] + P[4][2] - P[0][2];
		NodeArr->InsertPoint(ND.ID, ND.X, ND.Y, ND.Z);

		vtkSmartPointer<vtkLine> Line1 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line2 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line3 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line4 = vtkSmartPointer<vtkLine>::New();

		Line1->GetPointIds()->SetId(0, NA.ID);
		Line1->GetPointIds()->SetId(1, NB.ID);
		Line2->GetPointIds()->SetId(0, NB.ID);
		Line2->GetPointIds()->SetId(1, NC.ID);
		Line3->GetPointIds()->SetId(0, NC.ID);
		Line3->GetPointIds()->SetId(1, ND.ID);
		Line4->GetPointIds()->SetId(0, ND.ID);
		Line4->GetPointIds()->SetId(1, NA.ID);

		Joint2DArr->InsertNextCell(Line1);
		Joint2DArr->InsertNextCell(Line2);
		Joint2DArr->InsertNextCell(Line3);
		Joint2DArr->InsertNextCell(Line4);
	}
}

void ModelData::InsertRigidLink(Link X)
{
	auto ii = NodeMap.find(X.NodeA);
	if (ii != NodeMap.end())
	{
		int Nd0 = ii->second;
		ii = NodeMap.find(X.NodeB);
		if (ii != NodeMap.end())
		{
			int Nd1 = ii->second;
			vtkSmartPointer<vtkLine> Line = vtkSmartPointer<vtkLine>::New();
			Line->GetPointIds()->SetId(0, Nd0);
			Line->GetPointIds()->SetId(1, Nd1);
			RigidLinkArr->InsertNextCell(Line);
		}
	}
}

void ModelData::InsertEqualDof(Link X)
{
	auto ii = NodeMap.find(X.NodeA);
	if (ii != NodeMap.end())
	{
		int Nd0 = ii->second;
		ii = NodeMap.find(X.NodeB);
		if (ii != NodeMap.end())
		{
			int Nd1 = ii->second;
			vtkSmartPointer<vtkLine> Line = vtkSmartPointer<vtkLine>::New();
			Line->GetPointIds()->SetId(0, Nd0);
			Line->GetPointIds()->SetId(1, Nd1);
			EqualDofArr->InsertNextCell(Line);
		}
	}
}

void ModelData::InsertMasonPan(MasonPan X)
{
	bool T = true;
	int D[12];
	for (int i = 0; i < 12; ++i)
	{
		auto ii = NodeMap.find(X.Node[i]);
		if (ii != NodeMap.end())
		{
			D[i] = ii->second;
		}
		else
		{
			T = false;
			break;
		}
	}

	if (T)
	{
		vtkSmartPointer<vtkLine> Line1 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line2 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line3 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line4 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line5 = vtkSmartPointer<vtkLine>::New();
		vtkSmartPointer<vtkLine> Line6 = vtkSmartPointer<vtkLine>::New();
		
		Line1->GetPointIds()->SetId(0, D[1]);
		Line1->GetPointIds()->SetId(1, D[5]);

		Line2->GetPointIds()->SetId(0, D[0]);
		Line2->GetPointIds()->SetId(1, D[6]);

		Line3->GetPointIds()->SetId(0, D[11]);
		Line3->GetPointIds()->SetId(1, D[7]);

		Line4->GetPointIds()->SetId(0, D[2]);
		Line4->GetPointIds()->SetId(1, D[10]);

		Line5->GetPointIds()->SetId(0, D[3]);
		Line5->GetPointIds()->SetId(1, D[9]);

		Line6->GetPointIds()->SetId(0, D[4]);
		Line6->GetPointIds()->SetId(1, D[8]);

		MasonPanArr->InsertNextCell(Line1);
		MasonPanArr->InsertNextCell(Line2);
		MasonPanArr->InsertNextCell(Line3);
		MasonPanArr->InsertNextCell(Line4);
		MasonPanArr->InsertNextCell(Line5);
		MasonPanArr->InsertNextCell(Line6);


		//outline
		vtkSmartPointer<vtkPolygon> MasonPanShell = vtkSmartPointer<vtkPolygon>::New();
		MasonPanShell->GetPointIds()->SetNumberOfIds(4);

		MasonPanShell->GetPointIds()->SetId(0, D[0]);
		MasonPanShell->GetPointIds()->SetId(1, D[3]);
		MasonPanShell->GetPointIds()->SetId(2, D[6]);
		MasonPanShell->GetPointIds()->SetId(3, D[9]);
		MasonPanArr->InsertNextCell(MasonPanShell);

	}
}