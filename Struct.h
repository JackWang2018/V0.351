// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __Struct__
#define __Struct__

typedef struct Node
{
	double X;
	double Y;
	double Z;
	int ID;
} Node;

typedef struct NodeDeform
{
	double Time;
	int ID;
	double X;
	double Y;
	double Z;
} NodeDeform;

typedef struct Link
{
	int ID;
	int NodeA;
	int NodeB;
} Link;

typedef struct Shell
{
	int ID;
	int NumP;
	int Node[100];
} Shell;

typedef struct Shell9N
{
	int ID;
	int Node[9];
} Shell9N;

typedef struct Brick8N
{
	int ID;
	int Node[8];
} Brick8N;

typedef struct Brick20N
{
	int ID;
	int Node[20];
} Brick20N;

typedef struct Joint2D
{
	int ID;
	int Node[4];
	int Ndc;
} Joint2D;

typedef struct MasonPan
{
	int ID;
	int Node[12];
} MasonPan;

typedef struct BeamColumnJoint
{
	int ID;
	int Node[4];
} BeamColumnJoint;

typedef struct AnalysisCase
{
	int ID;
	int LineStart;
	int LineEnd;
} AnalysisCase;

#endif // __Struct__
