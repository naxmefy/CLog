#ifndef __CLOGFILE
#define __CLOGFILE

#include <windows.h>
#include <stdio.h>
#include "Singleton.hpp"

#define MAX_BUFFER 1024
#define L_FAIL false
#define L_OK true
#define g_pLogfile CLogfile::Get ()

//Textcolors
enum FONTCOLORS
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	PURPLE
};

class CLogfile : public TSingleton<CLogfile>
{
public:
	CLogfile			();
	~CLogfile			();
	void CreateLogfile	(const char *LogName);
	void WriteTopic		(const char *Topic, int Size);
	void Textout		(const char *Text);
	void Textout		(int Color, const char *Text);
	void Textout		(int Color, bool List, const char *Text);
	void StdTextout		(const char *Text);
	void fTextout		(const char *Text, ...);
	void fTextout		(int Color, const char *Text, ...);
	void fTextout		(int Color, bool List, const char *Text, ...);
	void StdfTextout	(const char *Text, ...);
	void FunctionResult (const char *Name, bool Result);

private:
	FILE *m_Logfile;

};

#endif