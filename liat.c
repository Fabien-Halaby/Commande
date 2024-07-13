#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liat.h"

/******************README**********************/ 
///$gcc -o liat -c liat.c
///$./liat -n [nombre de ligne] [nom du fichier]
/**********************************************/
int main(int argc,char *argv[])
{
	int n = atoi(argv[2]);
	if(argc == 4 || strcmp(argv[1],"-n") == 0)
	{
		tail(argv[3],n);
	}
	else
	{
		printf("Il y a de(s) erreur(s) dans l'argument.\n");
	}
	return 0;
}


void tail(char *file,int n)
{
	///Declaration des variables
	FILE *fichier = NULL;
	FILE *gichier = NULL;
	char ligne[1000];
	char **contenu = NULL;
	
	int compteur = 0;
	
	///Ouverture des fichiers
	fichier = fopen(file,"r");
	gichier = fopen(file,"r");
	
	if(fichier == NULL || gichier == NULL)
	{
		printf("Erreur d'ouverture du fichier.\n");
	}
	else
	{
		///Compte le nombre de ligne
		while(fgets(ligne,sizeof(ligne),fichier) && !feof(fichier))
		{
			compteur++;
		}
		
		contenu = (char **)malloc(compteur*sizeof(char *));
		///Lire chaque ligne
		for(int i=0;i<=compteur;i++)
		{
			contenu[i] = (char *)malloc(10000*sizeof(char));
			fscanf(gichier," %[^\n]s",contenu[i]);
		}
		
		for(int i=compteur-n;i<compteur;i++)
		{
			printf("%s\n",contenu[i]);
		}
		///Liberation
		free(contenu);
		///Fermeture des fichiers
		fclose(fichier);
		fclose(gichier);
	}
}
