// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "TclInterFace.h"

wxArrayString TclInterFace::Result = wxArrayString();

TclInterFace::TclInterFace(string FileName)
{
	Tcl_Interp *Interp = Tcl_CreateInterp();
	Result.Clear();
	CreatCommand(Interp);
	int Res = Tcl_EvalFile(Interp, FileName.c_str());
	const char *Detail = Tcl_GetStringResult(Interp);
	if (Res != TCL_OK)
	{
		wxMessageBox(Detail);
	}

	Tcl_DeleteInterp(Interp);
}

wxArrayString TclInterFace::GetResult()
{
	return Result;
}

int TclInterFace::EmptyFunc(ClientData CData, Tcl_Interp * Interp, int Argc, Tcl_Obj * const * Argv)
{
	//do nothing
	Tcl_AppendResult(Interp, "1", NULL);
	return TCL_OK;
}

int TclInterFace::GetEigen(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string NodeTmp = string(Tcl_GetString(Argv[1]));
	ComFunc F;
	int Num = F.StrToInt(NodeTmp);
	NodeTmp = "";
	for (int i = 1; i <= Num; ++i)
	{
		NodeTmp += string(" ") + F.ToString(i);
	}

	Tcl_AppendResult(Interp, NodeTmp.c_str(), NULL);

	return TCL_OK;
}

int TclInterFace::GetClock(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	Tcl_AppendResult(Interp, "1", NULL);
	return TCL_OK;
}

int TclInterFace::GetNode(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string NodeTmp;
	string  STmp;
	NodeTmp = string(Tcl_GetString(Argv[0])) + " " + Tcl_GetString(Argv[1]);
	ComFunc F;
	double Coord;
	for (int i = 2; i < Argc && i < 5; ++i)
	{
		STmp = string(Tcl_GetString(Argv[i]));
		Coord = F.StrToDouble(STmp);
		NodeTmp += string(" ") + F.ToString(Coord);
	}
	if (Argc < 5)
	{
		NodeTmp += string(" 0.0");
	}
	Result.push_back(NodeTmp);

	return TCL_OK;
}

int TclInterFace::GetElement(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string StrTmp = Tcl_GetString(Argv[1]);
	if (StrTmp == "tri31" || StrTmp == "Tri31")
	{
		if (Argc >= 6)
		{
			StrTmp = "element D2N3 " + StrTmp;
			for (int i = 2; i < 6; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (
		StrTmp == "quad" ||
		StrTmp == "ShellMITC4" ||
		StrTmp == "ShellDKGQ" ||
		StrTmp == "ShellNLDKGQ" ||
		StrTmp == "bbarQuad" ||
		StrTmp == "enhancedQuad" ||
		StrTmp == "bbarQuadUP" ||
		StrTmp == "quadUP" ||
		StrTmp == "SSPquad" ||
		StrTmp == "SSPbrick" ||
		StrTmp == "SurfaceLoad" ||
		StrTmp == "VS3D4" ||
		StrTmp == "AV3D4" ||
		StrTmp == "SimpleContact3D" ||
		StrTmp == "BeamContact2D" ||
		StrTmp == "BeamContact3D" ||
		StrTmp == "BeamEndContact3D" ||
		StrTmp == "quadWithSensitivity"
		)
	{
		if (Argc >= 7)
		{
			StrTmp = "element D2N4 " + StrTmp;
			for (int i = 2; i < 7; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (StrTmp == "ShellNL" || StrTmp == "9_4_QuadUP")
	{
		if (Argc >= 12)
		{
			StrTmp = "element D2N9 " + StrTmp;
			for (int i = 2; i < 12; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (
		StrTmp == "stdBrick" ||
		StrTmp == "bbarBrick" ||
		StrTmp == "SSPbrick" ||
		StrTmp == "brickUP" ||
		StrTmp == "bbarBrickUP" ||
		StrTmp == "SSPbrickUP" ||
		StrTmp == "Brick8N" ||
		StrTmp == "bbarBrickUP" ||
		StrTmp == "SSPbrickUP" ||
		StrTmp == "AC3D8" ||
		StrTmp == "Brick8N_u_p_U" ||
		StrTmp == "ASI3D8"
		)
	{
		if (Argc >= 11)
		{
			StrTmp = "element D3N8 " + StrTmp;
			for (int i = 2; i < 11; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (
		StrTmp == "Masonpan12" ||
		StrTmp == "Masonpan3D" ||
		StrTmp == "MasonpanS" ||

		StrTmp == "masonpan12" ||
		StrTmp == "masonpan3D" ||
		StrTmp == "masonpanS" ||

		StrTmp == "MasonPan12" ||
		StrTmp == "MasonPan3D" ||
		StrTmp == "MasonPanS" ||

		StrTmp == "masonPan12" ||
		StrTmp == "masonPan3D" ||
		StrTmp == "masonPanS"
		)
	{
		if (Argc >= 15)
		{
			StrTmp = "element D3N12 " + StrTmp;
			for (int i = 2; i < 15; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (StrTmp == "Brick20N" || StrTmp == "20_8_BrickUP" || StrTmp == "TLFD20nBrick")
	{
		if (Argc >= 23)
		{
			StrTmp = "element D3N20 " + StrTmp;
			for (int i = 2; i < 23; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (StrTmp == "Joint2D")
	{
		if (Argc >= 8)
		{
			StrTmp = "element Joint2D " + StrTmp;
			for (int i = 2; i < 8; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else if (StrTmp == "beamColumnJoint")
	{
		if (Argc >= 7)
		{
			StrTmp = "element beamColumnJoint " + StrTmp;
			for (int i = 2; i < 7; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	else
	{
		if (Argc >= 5)
		{
			StrTmp = "element D3N2 " + StrTmp;
			for (int i = 2; i < 5; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	return TCL_OK;
}

int TclInterFace::GetRigidLink(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string StrTmp = Tcl_GetString(Argv[1]);
	if (StrTmp == "bar" || StrTmp == "beam")
	{
		if (Argc == 4)
		{
			StrTmp = string("rigidLink ") + StrTmp;
			for (int i = 2; i < 4; ++i)
			{
				StrTmp += string(" ") + Tcl_GetString(Argv[i]);
			}
			Result.push_back(StrTmp);
		}
	}
	return TCL_OK;
}

int TclInterFace::GetEqualDOF(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string StrTmp = Tcl_GetString(Argv[0]) + string(" ") + Tcl_GetString(Argv[1]) + string(" ") + Tcl_GetString(Argv[2]);
	Result.push_back(StrTmp);
	return TCL_OK;
}

int TclInterFace::GetRigidDiaphragm(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	Tcl_AppendResult(Interp, "1", NULL);
	return TCL_OK;
}

int TclInterFace::GetFix(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

int TclInterFace::GetFixX(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

int TclInterFace::GetFixY(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

int TclInterFace::GetFixZ(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

int TclInterFace::GetAnalysis(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

int TclInterFace::GetLoadConst(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv)
{
	string Tmp = string(Tcl_GetString(Argv[0]));
	for (int i = 1; i < Argc; ++i)
	{
		Tmp += string(" ") + string(Tcl_GetString(Argv[i]));
	}
	Result.push_back(Tmp);
	return TCL_OK;
}

void TclInterFace::CreatCommand(Tcl_Interp *Interp)
{
	Tcl_CreateObjCommand(Interp, "eigen", &GetEigen, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "clock", &GetClock, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "node", &GetNode, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "element", &GetElement, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "rigidLink", &GetRigidLink, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "equalDOF", &GetEqualDOF, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "rigidDiaphragm", &GetRigidDiaphragm, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "fix", &GetFix, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "fixX", &GetFixX, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "fixY", &GetFixY, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "fixZ", &GetFixZ, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "analyze", &GetAnalysis, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);
	Tcl_CreateObjCommand(Interp, "loadConst", &GetLoadConst, (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL);


	vector<string> OsKey;
	//OsKey.push_back( "open" );
	OsKey.push_back("close");
	OsKey.push_back("file");
	OsKey.push_back("mkdir");


	//OsKey.push_back("eigen");
	OsKey.push_back("Pinching4");
	OsKey.push_back("RCsection");
	OsKey.push_back("oldputs");
	OsKey.push_back("puts");
	OsKey.push_back("pset");
	OsKey.push_back("wipe");
	OsKey.push_back("wipeAnalysis");
	OsKey.push_back("reset");
	OsKey.push_back("initialize");
	//OsKey.push_back("loadConst");
	OsKey.push_back("setTime");
	OsKey.push_back("getTime");
	OsKey.push_back("getLoadFactor");
	OsKey.push_back("build");
	//OsKey.push_back("analyze");
	OsKey.push_back("print");
	OsKey.push_back("printA");
	OsKey.push_back("printB");
	OsKey.push_back("printGID");
	OsKey.push_back("analysis");
	OsKey.push_back("system");
	OsKey.push_back("numberer");
	OsKey.push_back("constraints");
	OsKey.push_back("algorithm");
	OsKey.push_back("test");
	OsKey.push_back("testNorms");
	OsKey.push_back("testIter");
	OsKey.push_back("integrator");
	OsKey.push_back("recorder");
	OsKey.push_back("algorithmRecorder");
	OsKey.push_back("database");
	OsKey.push_back("video");
	OsKey.push_back("remove");
	OsKey.push_back("eleForce");
	OsKey.push_back("localForce");
	OsKey.push_back("eleDynamicalForce");
	OsKey.push_back("eleResponse");
	OsKey.push_back("nodeDisp");
	OsKey.push_back("setNodeDisp");
	OsKey.push_back("nodeReaction");
	OsKey.push_back("nodeUnbalance");
	OsKey.push_back("nodeEigenvector");
	OsKey.push_back("nodeVel");
	OsKey.push_back("setNodeVel");
	OsKey.push_back("nodeAccel");
	OsKey.push_back("setNodeAccel");
	OsKey.push_back("nodeResponse");
	OsKey.push_back("reactions");
	OsKey.push_back("nodeCoord");
	OsKey.push_back("setNodeCoord");
	OsKey.push_back("updateElementDomain");
	OsKey.push_back("eleNodes");
	OsKey.push_back("nodeMass");
	OsKey.push_back("nodePressure");
	OsKey.push_back("nodeBounds");
	OsKey.push_back("start");
	OsKey.push_back("stop");
	OsKey.push_back("rayleigh");
	OsKey.push_back("modalDamping");
	OsKey.push_back("modalDampingQ");
	OsKey.push_back("setElementRayleighDampingFactors");
	OsKey.push_back("region");
	OsKey.push_back("logFile");
	OsKey.push_back("setPrecision");
	OsKey.push_back("exit");
	OsKey.push_back("quit");
	OsKey.push_back("findNodeWithID");
	OsKey.push_back("getNP");
	OsKey.push_back("getPID");
	OsKey.push_back("barrier");
	OsKey.push_back("send");
	OsKey.push_back("recv");
	OsKey.push_back("partition");
	OsKey.push_back("searchPeerNGA");
	OsKey.push_back("domainChange");
	OsKey.push_back("record");
	OsKey.push_back("metaData");
	OsKey.push_back("defaultUnits");
	OsKey.push_back("neesUpload");
	OsKey.push_back("stripXML");
	OsKey.push_back("convertBinaryToText");
	OsKey.push_back("convertTextToBinary");
	OsKey.push_back("getEleTags");
	OsKey.push_back("getNodeTags");
	OsKey.push_back("getParamTags");
	OsKey.push_back("getParamValue");
	OsKey.push_back("sectionForce");
	OsKey.push_back("sectionDeformation");
	OsKey.push_back("sectionStiffness");
	OsKey.push_back("sectionFlexibility");
	OsKey.push_back("sectionLocation");
	OsKey.push_back("sectionWeight");
	OsKey.push_back("basicDeformation");
	OsKey.push_back("basicForce");
	OsKey.push_back("basicStiffness");
	OsKey.push_back("InitialStateAnalysis");
	OsKey.push_back("totalCPU");
	OsKey.push_back("solveCPU");
	OsKey.push_back("accelCPU");
	OsKey.push_back("numFact");
	OsKey.push_back("numIter");
	OsKey.push_back("systemSize");
	OsKey.push_back("version");
	OsKey.push_back("setParameter");
	OsKey.push_back("setMaxOpenFiles");
	OsKey.push_back("wipeReliability");
	OsKey.push_back("reliability");
	OsKey.push_back("computeGradients");
	OsKey.push_back("sensitivityAlgorithm");
	OsKey.push_back("sensitivityIntegrator");
	OsKey.push_back("sensNodeDisp");
	OsKey.push_back("sensLambda");
	OsKey.push_back("sensNodeVel");
	OsKey.push_back("sensNodeAccel");
	OsKey.push_back("sensSectionForce");
	OsKey.push_back("sensNodePressure");
	OsKey.push_back("optimization");
	OsKey.push_back("save");
	OsKey.push_back("restore");
	OsKey.push_back("uniaxialMaterial");
	OsKey.push_back("UniaxialMaterial");
	OsKey.push_back("testUniaxialMaterial");
	OsKey.push_back("Steel02");
	OsKey.push_back("Concrete04");
	OsKey.push_back("setStrain");
	OsKey.push_back("getStrain");
	OsKey.push_back("getStress");
	OsKey.push_back("getTangent");
	OsKey.push_back("model");
	OsKey.push_back("parameter");
	OsKey.push_back("addToParameter");
	OsKey.push_back("updateParameter");
	OsKey.push_back("PFEM2D");
	OsKey.push_back("PFEM3D");
	OsKey.push_back("mesh");
	OsKey.push_back("remesh");
	OsKey.push_back("background");
	OsKey.push_back("beamIntegration");
	OsKey.push_back("limitCurve");
	OsKey.push_back("nDMaterial");
	OsKey.push_back("section");
	OsKey.push_back("yieldSurface_BC");
	OsKey.push_back("ysEvolutionModel");
	OsKey.push_back("plasticMaterial");
	OsKey.push_back("cyclicModel");
	OsKey.push_back("damageModel");
	OsKey.push_back("pattern");
	OsKey.push_back("timeSeries");
	OsKey.push_back("load");
	OsKey.push_back("eleLoad");
	OsKey.push_back("mass");
	//OsKey.push_back("fix");
	//OsKey.push_back("fixX");
	//OsKey.push_back("fixY");
	//OsKey.push_back("fixZ");
	OsKey.push_back("sp");
	OsKey.push_back("imposedMotion");
	OsKey.push_back("imposedSupportMotion");
	OsKey.push_back("groundMotion");
	//OsKey.push_back("equalDOF");
	OsKey.push_back("equalDOF_Mixed");
	//OsKey.push_back( "rigidLink" );
	OsKey.push_back("rigidDiaphragm");
	OsKey.push_back("mp");
	OsKey.push_back("PySimple1Gen");
	OsKey.push_back("TzSimple1Gen");
	OsKey.push_back("ShallowFoundationGen");
	OsKey.push_back("block2D");
	OsKey.push_back("block3D");
	OsKey.push_back("patch");
	OsKey.push_back("layer");
	OsKey.push_back("fiber");
	OsKey.push_back("Hfiber");
	OsKey.push_back("geomTransf");
	OsKey.push_back("frictionModel");
	OsKey.push_back("stiffnessDegradation");
	OsKey.push_back("unloadingRule");
	OsKey.push_back("strengthDegradation");
	OsKey.push_back("hystereticBackbone");
	OsKey.push_back("updateMaterialStage");
	OsKey.push_back("updateMaterials");
	OsKey.push_back("loadPackage");
	OsKey.push_back("setElementRayleighFactors");
	OsKey.push_back("setMaterial");
	OsKey.push_back("setStrain");
	OsKey.push_back("getStress");
	OsKey.push_back("getTangent");
	OsKey.push_back("sectionTest");
	OsKey.push_back("strainSection");
	OsKey.push_back("stressSection");
	OsKey.push_back("tangSection");
	OsKey.push_back("uniaxialTest");
	OsKey.push_back("strainUniaxialTest");
	OsKey.push_back("stressUniaxialTest");
	OsKey.push_back("tangUniaxialTest");
	OsKey.push_back("designVariable");
	OsKey.push_back("designVariablePositioner");
	OsKey.push_back("constraintFunction");
	OsKey.push_back("objectiveFunction");
	OsKey.push_back("runSNOPTAnalysis");
	OsKey.push_back("randomVariable");
	OsKey.push_back("correlate");
	OsKey.push_back("correlateGroup");
	OsKey.push_back("correlationStructure");
	OsKey.push_back("cutset");
	OsKey.push_back("performanceFunction");
	OsKey.push_back("gradPerformanceFunction");
	OsKey.push_back("modulatingFunction");
	OsKey.push_back("filter");
	OsKey.push_back("spectrum");
	OsKey.push_back("findDesignPoint");
	OsKey.push_back("startPoint");
	OsKey.push_back("rootFinding");
	OsKey.push_back("functionEvaluator");
	OsKey.push_back("gradientEvaluator");
	OsKey.push_back("stepSizeRule");
	OsKey.push_back("searchDirection");
	OsKey.push_back("hessianEvaluator");
	OsKey.push_back("meritFunctionCheck");
	OsKey.push_back("reliabilityConvergenceCheck");
	OsKey.push_back("probabilityTransformation");
	OsKey.push_back("findCurvatures");
	OsKey.push_back("randomNumberGenerator");
	OsKey.push_back("runFORMAnalysis");
	OsKey.push_back("runFOSMAnalysis");
	OsKey.push_back("runGFunVizAnalysis");
	OsKey.push_back("runOutCrossingAnalysis");
	OsKey.push_back("runSORMAnalysis");
	OsKey.push_back("runSystemAnalysis");
	OsKey.push_back("runImportanceSamplingAnalysis");
	OsKey.push_back("printReliability");
	OsKey.push_back("getMean");
	OsKey.push_back("getStdv");
	OsKey.push_back("betaFORM");
	OsKey.push_back("gammaFORM");
	OsKey.push_back("alphaFORM");
	OsKey.push_back("getPDF");
	OsKey.push_back("getStdNormalPDF");
	OsKey.push_back("getCDF");
	OsKey.push_back("getStdNormalCDF");
	OsKey.push_back("getInverseCDF");
	OsKey.push_back("getStdNormalInverseCDF");
	OsKey.push_back("getRVTags");
	OsKey.push_back("getLSFTags");
	OsKey.push_back("getCutsetTags");
	OsKey.push_back("getCutsetComponents");
	OsKey.push_back("analyzer");
	OsKey.push_back("initialstaticanalysis");
	OsKey.push_back("initialpoint");
	OsKey.push_back("crossingrateanalyzer");
	OsKey.push_back("foseries");
	OsKey.push_back("firstpassage");
	OsKey.push_back("randomvibrationsimulation");
	OsKey.push_back("randomvibrationanalysis");
	OsKey.push_back("runMonteCarloResponseAnalysis");
	OsKey.push_back("updateParameterValue");
	OsKey.push_back("runOrthogonalPlaneSamplingAnalysis");
	OsKey.push_back("computeHessian");
	OsKey.push_back("runMultiDimVisualPrinPlane");
	OsKey.push_back("transformXtoU");
	OsKey.push_back("transformUtoX");
	OsKey.push_back("runDP_RSM_SimTimeInvariantAnalysis");
	OsKey.push_back("runDP_RSM_SimTimeVariantAnalysis");
	OsKey.push_back("vrp");
	OsKey.push_back("vpn");
	OsKey.push_back("vup");
	OsKey.push_back("viewWindow");
	OsKey.push_back("plane");
	OsKey.push_back("projection");
	OsKey.push_back("fill");
	OsKey.push_back("prp");
	OsKey.push_back("port");
	OsKey.push_back("display");
	OsKey.push_back("clearImage");
	OsKey.push_back("saveImage");
	OsKey.push_back("play");
	//OsKey.push_back("clock");
	for (auto ii = OsKey.begin(); ii != OsKey.end(); ++ii)
	{
		Tcl_CreateObjCommand(Interp, (*ii).c_str(), &EmptyFunc, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);
	}
}
