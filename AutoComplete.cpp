// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "AutoComplete.h"

TrieTree::TrieTree()
{
	for (int i = 0; i < MAXNODE; ++i)
	{
		Node[i] = NULL;
	}
}

void TrieTree::Insert(const char *Str, TrieTree *Root)
{
	if (IsAlpha(Str))
	{
		int i, c;
		for (i = 0; Str[i]; ++i)
		{
			c = Str[i];
			if (Root->Node[c] == NULL)
			{
				Root->Node[c] = new TrieTree();
			}
			Root = Root->Node[c];
		}
	}
}


TrieTree* TrieTree::Query(const char *Str, TrieTree *Root)
{
	if (!IsAlpha(Str))
	{
		return NULL;
	}

	int Ch;
	TrieTree *Ans = NULL;
	for (int i = 0; Str[i]; ++i)
	{
		Ch = Str[i];
		if (Root->Node[Ch] == NULL)
		{
			return NULL;
		}
		Ans = Root;
		Root = Root->Node[Ch];
	}
	return Ans;
}

void TrieTree::InitSubTrie(TrieTree *Root, wxString TrieStr, bool Flag)
{
	if (Flag)
	{
		KeyWordList.clear();
		Root = Root->Node[TrieStr.c_str()[TrieStr.Len() - 1]];
	}

	bool T = true;
	for (int i = 0; i < MAXNODE; ++i)
	{
		if (Root->Node[i] != NULL)
		{
			T = false;
			InitSubTrie(Root->Node[i], TrieStr + wxString(string(1, char(i))), false);
		}
	}

	if (T)
	{
		KeyWordList.append(TrieStr);
		KeyWordList.append(wxT("  "));
	}
}

wxString TrieTree::GetKeyList(TrieTree *Root, wxString TrieStr)
{
	InitSubTrie(Root, TrieStr, true);
	return KeyWordList;
}

bool TrieTree::IsAlpha(const char *Str)
{
	for (int i = 0; Str[i]; ++i)
	{
		if (Str[i] < 0 || Str[i] > 127) return false;
	}
	return true;
}
