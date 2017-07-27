// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __TclInterFace__
#define __TclInterFace__

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <tcl.h>
#include "ComFunc.h"
using namespace std;

class TclInterFace
{
public:
	TclInterFace(string FileName);
	wxArrayString GetResult();
	static int EmptyFunc(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetEigen(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetClock(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetNode(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetElement(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetRigidLink(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetEqualDOF(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetRigidDiaphragm(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetFix(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetFixX(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetFixY(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetFixZ(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetAnalysis(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	static int GetLoadConst(ClientData CData, Tcl_Interp *Interp, int Argc, Tcl_Obj* const *Argv);
	void CreatCommand(Tcl_Interp *Interp);
private:
	static wxArrayString Result;
};

#endif
