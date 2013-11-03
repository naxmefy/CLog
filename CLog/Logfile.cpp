#include "Logfile.hpp"

CLogfile::CLogfile ()
{
	
}

CLogfile::~CLogfile ()
{
	Textout("<br><br><hr>End of logfile</font></body></html>");
	fclose(m_Logfile);
}

void CLogfile::CreateLogfile (const char *LogName)
{
	fopen_s (&m_Logfile, LogName, "w");
	Textout("<html><head><title>Logfile</title></head>");
	Textout("<body><font face='courier new'>");
	WriteTopic("LogFile", 3);

	#ifdef _DEBUG
		Textout("BUILD: DEBUG<br>");
	#else
		Textout("BUILD: Release<br>");
	#endif

	Textout("<a href='mailto:support@devmexx.com?subject=Logfile'>");
	Textout("Send E-Mail to our support</a><br>");

	fclose(m_Logfile);
	fopen_s(&m_Logfile, LogName, "a");
}

void CLogfile::WriteTopic (const char *Topic, int Size)
{
	Textout("<table cellspacing='0' cellpadding='0' width='100%%' ");
	if(Size == 2)
		Textout("style='margin-top: 15px' ");
	Textout("bgcolor='#DFDFE5'>\n<tr>\n<td>\n<font face='arial' ");
	fTextout("size='+%i'>\n",Size);
	Textout(Topic);
	Textout ("</font>\n</td>\n</tr>\n</table>\n<br>");
	fflush (m_Logfile);
}

void CLogfile::Textout (const char *Text)
{
	fprintf (m_Logfile, Text);
	fflush (m_Logfile);
}

void CLogfile::Textout (int Color, const char *Text)
{
	Textout (Color, false, Text);
}

void CLogfile::Textout (int Color, bool List, const char *Text)
{
	if (List == true)
		Textout ("<li>");

	switch (Color)
	{
		case BLACK:
			Textout ("<font color=black>"); break;
		case RED:
			Textout ("<font color=red>"); break;
		case GREEN:
			Textout ("<font color=green>"); break;
		case BLUE:
			Textout ("<font color=blue>"); break;
		case PURPLE:
			Textout ("<font color=purple>"); break;
	};

	Textout (Text);
	Textout ("</font>");

	if (List == false)
		Textout ("<br>");
	else
		Textout ("</li>");
}

void CLogfile::StdTextout (const char *Text)
{
	Textout(BLACK, false, Text);
}

void CLogfile::fTextout (const char *Text, ...)
{
	TCHAR buffer[MAX_BUFFER];
	va_list pArgList;
	va_start (pArgList, Text);
	vsprintf ((char*) &buffer, Text, pArgList);
	va_end (pArgList);
	Textout ((char*) &buffer);
}

void CLogfile::fTextout (int Color, const char *Text, ...)
{
	TCHAR buffer[MAX_BUFFER];
	va_list pArgList;

	va_start (pArgList, Text);
	vsprintf ((char*) &buffer, Text, pArgList);
	va_end (pArgList);

	Textout (Color, (char*) &buffer);
}

void CLogfile::fTextout (int Color, bool List,const char *Text, ...)
{
	TCHAR buffer[MAX_BUFFER];
	va_list pArgList;

	va_start (pArgList, Text);
	vsprintf ((char*) &buffer, Text, pArgList);
	va_end (pArgList);

	Textout (Color, List, (char*) &buffer);
}

void CLogfile::StdfTextout (const char *Text, ...)
{
	TCHAR buffer[MAX_BUFFER];
	va_list pArgList;
	va_start (pArgList, Text);
	vsprintf ((char*) &buffer, Text, pArgList);
	va_end (pArgList);
	StdTextout ((char*) &buffer);
}

void CLogfile::FunctionResult (const char *Name, bool Result)
{
	if (L_OK == Result)
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5' ");
		Textout("border='0' bgcolor='#C0C0C0'><tr><td bgcolor='#FFFFFF' ");
		fTextout("width='35%%'>%s</TD>", Name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color='green'>");
		Textout("OK</FONT></TD><td bgcolor='#FFFFFF' ");
		Textout("width='35%%'>-/-</TD></tr></table>");
	}
	else
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5' ");
		Textout("border='0' bgcolor='#C0C0C0'><tr><td bgcolor='#FFFFFF' ");
		fTextout("width='35%%'>%s</TD>", Name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color='red'>");
		Textout("ERROR</FONT></TD><td bgcolor='#FFFFFF' ");
		Textout("width='35%%'>-/-</TD></tr></table>");
	}
}