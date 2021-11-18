#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>


// constantes globales:
#define NBMAX     20     // NOMBRE MAXIMUM DU TABLEAU
#define success    100
#define erreur   	33

typedef struct{
	char id[30];
	char nom[30];
	char emplacement[30];
	char etat[30];
	
}catalogue;

//variables globales
catalogue c[NBMAX];
int nEf = 0; // Nombre Effectif par default = 0



//Fonction pour chercher un fichier:
int rechercher_fichier(char id[], char nom[])
{
	int i=0;
	bool found = false;
	while(i<nEf && found == false)
	{
		if(strcmp(nom,c[i].nom) == 0)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if(found == true)
	{
		return i; // on retourne I pour pouvoir changer le nom (Dans la fonction changement_fichier
	}
	else
	{
		return erreur;
	}
}


//Fonction ajouter un fichier:
int ajout_fichier(char ide[], char name[], char emp[], char et[])
{
	if(rechercher_fichier(ide,name) != erreur)
	{
		return erreur;
	}
		strcpy(c[nEf].nom,name);
		strcpy(c[nEf].emplacement,emp);
		strcpy(c[nEf].etat,et);
		
		return success; // Dès on retourne success, On incremente nEf++

}


//Fonction changer le nom du fichier:
int changement_fichier(char id[], char nom[],char newnom[])
{
	int a;
	a = rechercher_fichier(id,nom);
	if(a == erreur)
	{
		return erreur;
	}
	if(strcmp(c[a].nom,nom) != 0)
	{
		return erreur;
	}
	strcpy(c[a].nom,newnom);
	return success;
}


//Fonction pour supprimer un fichier:
int suppression_fichier(char id[], char nom[])
{
	int i,j;
	for(i=0;i<nEf;i++)
	{
		if(strcmp(nom,c[i].nom) == 0)
		{
			for(j=i;j<nEf;j++)
			{
				c[j] = c[j+1];
				nEf--;
			}
			return success;
		}

	}
}

//Fonction pour rendre un fichier prive a un fichier public:
int partage_fichier(char id[], char nom[])
{
	int indice = rechercher_fichier(id,nom);
	if(indice == erreur)
	{
		return erreur;
	}
	if(strcmp(c[indice].etat,"prive") == 0)
	{
		strcpy(c[indice].etat,"public");
		return success;
	}
	
}


//Fonctionpour rendre un fichier public a un fichier prive:
int retrait_fichier(char id[], char nom[])
{
	int indice = rechercher_fichier(id,nom);
	if(indice == erreur)
	{
		return erreur;
	}
	if(strcmp(c[indice].etat,"public") == 0)
	{
		strcpy(c[indice].etat,"prive");
		return success;
	}
}


//Fonction afficher les fichiers:
int affichage_fichier(char id[])
{
	int i;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("- 					AFFICHAGE DES UTILISATEURS	            	  			 	-\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("					[NOM] 	[EMPLACEMENT] 	[ETAT]\n\n");
	for(i=0;i<nEf;i++)
	{
		printf("					[%s] 	[@%s] 		[%s]\n",c[i].nom,c[i].emplacement,c[i].etat);
	}
}


void menu()
{
		system("CLS");
		printf("					# Bienvenue dans votre espace ! #\n");
		printf("\t\t		| - [1]  - Rechercher un fichier	-| \n");
		printf("\t\t		| - [2]  - Ajouter un fichier		-|\n");
		printf("\t\t		| - [3]  - Changer un nom d'un fichier	-|\n");
		printf("\t\t		| - [4]  - Suppression d'un fichier	-|\n");
		printf("\t\t		| - [5]  - Rendre le fichier public	-|\n");
		printf("\t\t		| - [6]  - Rendre le fichier prive	-|\n");
		printf("\t\t		| - [7]  - Affichage des fichier	-|\n");
		printf("\t\t		|----------------------------------------|\n");
		printf("\t\t		| - [0]  - Se deconnecter		-|\n");
		printf("\n					  |- Votre choix : ");


}

main()
{
	
	
	char identif[30];
	char nom[10],newnom[10];
	char emplacement[30];
	char etat[30];
	int choix;
	
	
	printf("Entrer votre identifiant : ");
	fflush(stdin);
	gets(identif);
	do{

		menu();
		scanf("%d",&choix);
		system("CLS");	
		switch(choix)
		{
			
			// FONCTION POUR RECHERCHER UN FICHIER
			case 1:
				printf("Entrer le nom a rechercher : ");
				fflush(stdin);
				gets(nom);
				if(rechercher_fichier(identif,nom) != erreur)
				{
					printf("FICHIER EXISTE");
				}
				else
				{
					printf("FICHIER INTROUVABLE ");
				}
				printf("\n \n \n");
				system("pause");
				break;
			
			
			
			// FONCTION POUR AJOUTER UN FICHIER	
			case 2:
				printf("Entrer le nom du fichier :");
				fflush(stdin);
				gets(nom);
				strcpy(emplacement,nom);
				printf("Entrer l'etat du fichier :");
				fflush(stdin);
				gets(etat);
				
				if(ajout_fichier(identif,nom,emplacement,etat) == erreur)
				{
					printf("erreur d'ajout");
				}
				else
				{
					printf(" FICHIER AJOUTE AVEC SUCCESS -\n");
					nEf++;
				}
				printf("\n \n \n");
				system("pause");
				break;
			
			
			
			// FONCTION POUR CHANGER UN NOM DUFICHIER
			case 3:
				printf("Entrer le nom du fichier : "); scanf("%s",&nom);
				printf("Entrer le nouveau nom du fichier : "); scanf("%s",&newnom);
				if(changement_fichier(identif,nom,newnom) == erreur)
				{
					printf("ERREUR DE MODIFICATION");
				}
				else
				{
					printf("NOM DU FICHIER MODIFIER AVEC SUCCESS !");
				}
				printf("\n \n \n");
				system("pause");
				break;
			
			
			
			// FONCTION POUR SUPPRIMER UN FICHIER
			case 4:
				printf("Le nom du fichier a supprimer : "); scanf("%s",&nom);
				if(suppression_fichier(identif,nom) == success)
				{
					printf("SUPPRESSION DU FICHIER AVEC SUCCESS");
				}
				else
				{
					printf("ERREUR DE SUPPRESSION");
				}

				printf("\n \n \n");
				system("pause");
				break;		
			
			
			
			// FONCTION POUR RENDRE UN FICHIER PUBLIC (ETAT)		
			case 5:
				printf("Entrer le nom du fichier a rendre public : "); scanf("%s",&nom);
				if(partage_fichier(identif,nom) == success)
				{
					printf("PARTAGE DU FICHIER AVEC SUCCESS");
				}
				else
				{
					printf("ERREUR DU PARTAGE");
				}
				printf("\n \n \n");
				system("pause");
				break;
			
			
			
			// FONCTION POUR RENDRE UN FICHIER PRIVE (ETAT)					
			case 6:
				printf("Entrer le nom du fichier a rendre prive : "); scanf("%s",&nom);
				if(retrait_fichier(identif,nom) == success)
				{
					printf("RETRAIT DU FICHIER AVEC SUCCESS");
				}
				else
				{
					printf("ERREUR DU RETRAIT");
				}
				printf("\n \n \n");
				system("pause");
				break;		
			
				
			case 7:
				affichage_fichier(identif);
				printf("\n \n \n");
				system("pause");
				break;
				
			case 0:
				choix = 9;
				break;
				
		}
	
	}while(choix >= 1 && choix <=8 );
	
					printf("Fin du programme");

	
	
}
