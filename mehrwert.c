/* Mehrwert.c							  *

 * Mehrwert setzt die neue und alte Mehrwertsteuer ins Verhältnis */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float summe,prozent,netto,netto_7,netto_19,mehrwert;

int main(long argc,char **argv)
{
  char waehrung[5]="Euro";
  char *endptr;
  if(argc<2)
  {
    printf("Das Programm wird mit\n%s Zahl Währung(optional) Prozentsatz(optional)\naufgerufen!\n",argv[0]);
    return(0);
  }
  else if(argc == 3)
   {
      if (strtof(argv[2], &endptr) && *endptr == '\0')
         prozent = atof(argv[2]);
      else
      {
         strcpy(waehrung, argv[2]);
         prozent = 16.0;
      }
   }
  else if(argc == 4)
  {
   strcpy(waehrung, argv[2]);
   prozent = atof(argv[3]);
  }
  else
   prozent = 16.0;
  sscanf(argv[1], "%f", &summe);
  netto_7 = 100 * summe / 107;
  netto_19 = 100 * summe / 119;
  mehrwert = summe * prozent / 100;
  netto = 100 * summe / (100 + prozent);

  printf("\n\t\t%6.2f %%\t%6.2f %%\t%6.2f %%\t%6.2f %%\n",
     7.0, 19.0, prozent, prozent);
  printf("----------------------------------------------------------------------------\n");
  printf("Netto\t\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n",
     netto_7, waehrung, netto_19, waehrung, summe, waehrung, netto, waehrung);
  printf("Mehrwertsteuer\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n",
     netto_7 * 7/100, waehrung, netto_19 * 19/100, waehrung, mehrwert, waehrung, netto * prozent / 100, waehrung);
  printf("Brutto\t\t%8.2f %s\t%8.2f %s\t%8.2f %s\t%8.2f %s\n\n",
     summe, waehrung, summe, waehrung, summe + mehrwert, waehrung, summe, waehrung);
  return(0);
}
