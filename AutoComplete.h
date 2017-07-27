// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __AutoComplete__
#define __AutoComplete__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <wx/wx.h>
#define MAXNODE 128

using namespace std;

class TrieTree
{
public:
	TrieTree();
	void Insert(const char *Str, TrieTree *Root);
	TrieTree* Query(const char *Str, TrieTree *Root);
	void InitSubTrie(TrieTree *Root, wxString TrieStr, bool Flag);
	wxString GetKeyList(TrieTree *Root, wxString TrieStr);
	bool IsAlpha(const char *Str);

private:
	TrieTree* Node[MAXNODE];
	wxString KeyWordList;
};

#endif
