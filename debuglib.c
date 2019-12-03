/* Michele Gusella 5AI
 * Libreria per testare i programma in corso di creazione
 * 
 * 5 Critical
 * 4 Error
 * 3 Warning
 * 2 Info
 * 1 Log
 * 
 * Lista funzioni:
 * 		filedebuglevel(nomefile)					Al posto che stampare l'errore in stderr, stamparlo in un file
 * 		printdebuglevel(livello, messaggio)			Stampa l'errore se il livello passato è >= del currentdebuglevel
 * 		setdebuglevel(lvl)							Cambia il currentdebuglevel
 * 		pushandsetdebuglevel(lvl)					Salva il livello corrente e lo cambia con quello passato in input
 * 		restoredebuglevel()							Ripristina il livello precedentemente salvato da un pushandsetdebuglevel, sempre se c'e ne uno
 */


#include <stdio.h>
#include <string.h>

// STAMPARE I MESSAGGI IN STDERR -> STANDARD ERROR
int currentdebuglevel = 4, salvato = -1;
char *nomefile = "";
FILE *file;

void filedebuglevel(char *ilfile);
void printdebuglevel(int lvl);
void setdebuglevel(int lvl);

void filedebuglevel(char *ilfile)
{
	nomefile = ilfile;
}

void printdebuglevel(int lvl, char *mesg)
{
	if(lvl >= currentdebuglevel)
	{
		if(nomefile == "")
			fprintf(stderr, mesg);
		else
		{
			file = fopen(nomefile, "w");
			fprintf(file, mesg);
			fclose(file);
		}
	}
}

void setdebuglevel(int lvl)
{
	currentdebuglevel = lvl;
}

void pushandsetdebuglevel(int lvl)
{
	
}

void restoredebuglevel()
{
	if(salvato != -1)
		currentdebuglevel = salvato;
	else
		printf("Attenzione! Il restore ha riscontrato un problema\n");
}
