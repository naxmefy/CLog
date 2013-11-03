#include <iostream>
#include "Logfile.hpp"

using namespace std;

int main()
{
	float Kontrolle = 123.456f;

	g_pLogfile->CreateLogfile ("Logfile.html");

	g_pLogfile->WriteTopic ("Unformatierter Text", 2);

	g_pLogfile->StdTextout ("Normaler, schwarter text");
	g_pLogfile->Textout (RED, "Farbiger Text");
	g_pLogfile->Textout (BLUE, "Farbiger Text in Liste (1)");
	g_pLogfile->Textout (BLUE, "Farbiger Text in Liste (2)");
	g_pLogfile->Textout (BLUE, "Farbiger Text in Liste (3)");

	g_pLogfile->WriteTopic("Formartierter Text", 2);

	g_pLogfile->StdfTextout("Kontrollvariable: %f", Kontrolle);
	g_pLogfile->fTextout(RED, "Kontrollevariable: %f", Kontrolle);
	g_pLogfile->fTextout(GREEN, true, "Liste Kontrollevariable: %f", Kontrolle);
	g_pLogfile->fTextout(GREEN, true, "Liste Kontrollevariable: %f", Kontrolle*2.0f);
	g_pLogfile->fTextout(GREEN, true, "Liste Kontrollevariable: %f", Kontrolle*4.0f);

	g_pLogfile->FunctionResult ("Funktion_Eins", L_OK);
	g_pLogfile->FunctionResult ("Funktion_Zwei", L_FAIL);

	g_pLogfile->Del ();

	return 0;
}