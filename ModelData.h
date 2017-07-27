// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __ModelDate__
#define __ModelDate__

#include <iostream>
#include <map>
#include <vector>
#include <vtkFloatArray.h>
#include <vtkScalarBarActor.h>
#include <vtkScalarBarWidget.h>
#include <vtkLookupTable.h>
#include <vtkSmartPointer.h>
#include <vtkPointSource.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkPointSetToLabelHierarchy.h>
#include <vtkLabelPlacementMapper.h>
#include <vtkFreeTypeLabelRenderStrategy.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkDataSetMapper.h>
#include <vtkPolygon.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkActor2D.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkStringArray.h>
#include <vtkRenderer.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkProperty.h>
#include <vtkLabeledDataMapper.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkCamera.h>
#include "wxVTKRenderWindowInteractor.h"

#include "Struct.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"

using namespace std;

class ModelData
{
public:
	ComFunc F;
	OSLiteConfig *Config;
	ModelData();
	void Reset();
	void InitRenderer();

	void SetLabelOn(bool T, wxString Name);
	void InsertNode(Node X);
	void ModifyNode(NodeDeform X);
	void ModifyScalars(NodeDeform X, bool IsRealTime, double MaxDeformIn);
	void ModifyNode();
	void InsertLine(Link X);
	void InsertShell(Shell X);
	void InsertShell9N(Shell9N X);
	void InsertBrick8N(Brick8N X);
	void InsertBrick20N(Brick20N X);
	void InsertJoint2D(Joint2D X);
	void InsertBeamColumnJoint(BeamColumnJoint X);
	void InsertRigidLink(Link X);
	void InsertEqualDof(Link X);
	void InsertMasonPan(MasonPan X);

	map<int, int>NodeMap;

	double MaxDeform, MaxForce;

	vtkIdType Pid[1];
	vtkSmartPointer<vtkPoints>                      NodeArr;
	vtkSmartPointer<vtkFloatArray>					ScalarsArr;
	vtkSmartPointer<vtkScalarBarActor>				ScalarsBar;
	vtkSmartPointer<vtkLookupTable>					hueLut;
	vtkSmartPointer<vtkScalarBarWidget>				scalarBarWidget;

	vtkSmartPointer<vtkCellArray>                   LineArr;
	vtkSmartPointer<vtkCellArray>                   ShellArr;
	vtkSmartPointer<vtkCellArray>                   BrickArr;
	vtkSmartPointer<vtkCellArray>                   Joint2DArr;
	vtkSmartPointer<vtkCellArray>                   MasonPanArr;
	vtkSmartPointer<vtkCellArray>                   RigidLinkArr;
	vtkSmartPointer<vtkCellArray>                   EqualDofArr;

	vtkSmartPointer<vtkPolyData>                    LinesPolyData;
	vtkSmartPointer<vtkPolyData>                    ShellPolyData;
	vtkSmartPointer<vtkPolyData>                    BrickPolyData;
	vtkSmartPointer<vtkPolyData>                    Joint2DPolyData;
	vtkSmartPointer<vtkPolyData>                    MasonPanPolyData;
	vtkSmartPointer<vtkPolyData>                    RigidLinkPolyData;
	vtkSmartPointer<vtkPolyData>                    EqualDofPolyData;

	vtkSmartPointer<vtkPolyDataMapper>              LinesMapper;
	vtkSmartPointer<vtkPolyDataMapper>              ShellMapper;
	vtkSmartPointer<vtkPolyDataMapper>              BrickMapper;
	vtkSmartPointer<vtkPolyDataMapper>              Joint2DMapper;
	vtkSmartPointer<vtkPolyDataMapper>              MasonPanMapper;
	vtkSmartPointer<vtkPolyDataMapper>              RigidLinkMapper;
	vtkSmartPointer<vtkPolyDataMapper>              EqualDofMapper;

	vtkSmartPointer<vtkActor>                       LinesActor;
	vtkSmartPointer<vtkActor>                       ShellActor;
	vtkSmartPointer<vtkActor>                       BrickActor;
	vtkSmartPointer<vtkActor>                       Joint2DActor;
	vtkSmartPointer<vtkActor>                       MasonPanActor;
	vtkSmartPointer<vtkActor>                       RigidLinkActor;
	vtkSmartPointer<vtkActor>                       EqualDofActor;

	vtkSmartPointer<vtkRenderer>                    Renderer;

	vtkSmartPointer<vtkTextActor>                   LogoActor;
	vtkSmartPointer<vtkAxesActor>                   Axes;
	vtkSmartPointer<vtkOrientationMarkerWidget>     AxesWidget;

	vtkSmartPointer<vtkPoints>                      NodeNumArr;
	vtkSmartPointer<vtkCellArray>                   NodeVert;
	vtkSmartPointer<vtkPolyData>                    NodeNumPolyData;
	vtkSmartPointer<vtkActor2D>                     NodeNumActor;
	vtkSmartPointer<vtkPolyDataMapper>              PointSpheresMapper;
	vtkSmartPointer<vtkActor>                       PointSpheresActor;
	vtkSmartPointer<vtkStringArray>                 NodeLabels;

	vtkSmartPointer<vtkPoints>                      EleNumArr;
	vtkSmartPointer<vtkPolyData>                    EleNumPolyData;
	vtkSmartPointer<vtkActor2D>                     EleNumActor;
	vtkSmartPointer<vtkStringArray>                 EleLabels;
};

#endif //__ModelDate__
