/* Mehrwert.c							  *

 * Mehrwert setzt die neue und alte Mehrwertsteuer ins Verh�ltnis */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float Summe1,Prozent,Netto1,Netto2,Netto3,Netto4;

int main(long argc,char **argv)
{
  char Waehrung[5]="Euro";
  char *endptr;
  if(argc<2)
  {
    printf("Das Programm wird mit\n%s Zahl Währung(optional) Prozentsatz(optional)\naufgerufen!\n",argv[0]);
    return(0);
  }
  else if(argc == 3)
   {
      if (strtof(argv[2], &endptr) && *endptr == '\0')
         Prozent = atof(argv[2]);
      else
      {
         strcpy(Waehrung, argv[2]);
         Prozent = 19.0;
      }
   }
  else if(argc == 4)
  {
   strcpy(Waehrung, argv[2]);
   Prozent = atof(argv[3]);
  }
  else
   Prozent = 19.0;
  sscanf(argv[1],"%f",&Summe1);
  Netto1=100 * Summe1 / 116;
  Netto2=100 * Summe1 / 115;
  Netto3=100 * Summe1 / 107;
  Netto4=100 * Summe1 / (100 + Prozent);
  printf("\n\t\t%6.2f %%\t%6.2f %%\t%6.2f %%\t%6.2f %%\n",
     7.0, 16.0, 15.0, Prozent);
  printf("----------------------------------------------------------------------------\n");
  printf("Netto\t\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n",
     Netto3, Waehrung, Netto1, Waehrung, Netto2, Waehrung, Netto4, Waehrung);
  printf("Mehrwertsteuer\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n",
     Netto3*7/100, Waehrung, Netto1*16/100, Waehrung, Netto2*15/100, Waehrung, Netto4 * Prozent / 100, Waehrung);
  printf("Brutto\t\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n\n",
     Summe1, Waehrung, Summe1, Waehrung, Summe1, Waehrung, Summe1, Waehrung);
  return(0);
}
