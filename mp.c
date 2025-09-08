#include <stdio.h>

void saisirNotes();
void afficherNotes();
void calculerMoyenne();
void trouverMax();
void trouverMin();
void compterAdmis();
void compterNonAdmis();
void ajouterNote();
void modifierNote();
void supprimerNote();

float notes[100] ;
int count = 0;







int main(){

    int option;

    do
    {
            printf("\n\n----------MENU----------\n\n");
            printf("1) Saisir N notes\n");
            printf("2) Afficher les notes\n");
            printf("3) Statistiques (moyenne, max, min, admis/non admis)\n");
            printf("4) Ajouter une note\n");
            printf("5) Modifier une note (par index)\n");
            printf("6) Supprimer une note (par index)\n");
            printf("0) Quitter\n");
            printf("le choix : ");
            scanf("%d",&option);

        switch (option)
        {
        case 1:
            saisirNotes();
            break;
        
        case 2:
            afficherNotes();
            break;

        case 3 :
            calculerMoyenne();
            trouverMax();
            trouverMin();
            compterAdmis();
            compterNonAdmis();
            break;

        case 4:
            ajouterNote();
            break;

        case 5:
            modifierNote();
            break;

        case 6:
            supprimerNote();
            break;

        default:
            printf("Choix invalide, veuillez reessayer.\n");
            break;
        }


    } while (option!=0);
    

    printf("Merci d'avoir utilise le programme. Au revoir !\n");

    return 0;
}



void saisirNotes(){

    if (count>=100)
    {
        printf("!!!Plus de places disponibles!!!");
    }
    else{
    
    
    int N;

    printf("combien de notes (max 100) :");
    scanf("%d",&N);
    int c = N + count ;

    if (c>100)
    {
        printf("Vous avez depasse le nombre de places disponibles!!! \n");
    }
    else{

    for (int i = count; i < c; i++)
    {   do
    {
        
    
    
        printf("note numero %d :",i+1);
        scanf("%f",&notes[i]);
        

        if (notes[i]<0 || notes[i]>20)
        {
            printf("Valeur invalide : la note ne peut pas etre inferieure a 0 ni superieure a 20.\n");
        }
        
        } while (notes[i]<0 || notes[i]>20);
        count++;
    }
    }
    }

}


void afficherNotes(){

    if (count==0)
    {
        printf("Aucun note.\n");
    }
    
    for (int i = 0; i < count; i++)
    {
        printf("[%d] %.2f\n", i+1, notes[i]);
    }
    
    }

void calculerMoyenne(){
    float moyenne =0;
    for (int i = 0; i < count; i++)
    {
        moyenne = moyenne + (notes[i]/count);
    }

    printf("moyenne : %.2f \n",moyenne);
    
}

void trouverMax(){

    float max = notes[0];
    int w =0;
    for (int i = 0; i < count; i++)
    {
        if (max<notes[i])
        {
            max = notes[i];
            w=i+1;
        }
        
    }
    printf("Note max : [%d]  %.2f \n",w,max);
    

}


void trouverMin(){

    float min = notes[0];
    int q =1;
    for (int i = 0; i < count; i++)
    {
        if (min>notes[i])
        {
            min = notes[i];
            q=i+1;
        }
        
    }
    printf("Note min : [%d]  %.2f \n",q,min);
    

}





void ajouterNote(){
    if (count>=100)
    {
        printf("!!!Plus de places disponibles!!!\n");
    }
    else{
        do{
        printf("note numero %d :",count+1);
        scanf("%f",&notes[count]);

        if (notes[count]<0 || notes[count]>20)
        {
            printf("Valeur invalide : la note ne peut pas etre inferieure a 0 ni superieure a 20.\n");
        }
        
        } while (notes[count]<0 || notes[count]>20);
        count++;
    }
}

void modifierNote(){

    int n;

    do
    {
        
    
    
    printf("Choisissez la note a modifier :");
    scanf("%d",&n);

    if (n>count || n<=0)
    {
        printf("Indice invalide. Veuillez entrer un indice entre 0 et %d.\n",count);
    }
    } while (n>count || n<=0);

    
    do
    {
        printf("Modifier la note :");
        scanf("%f",&notes[n-1]);
    
        if (notes[n-1]<0 || notes[n-1]>20)
        {
            printf("Valeur invalide : la note ne peut pas être inferieure à 0 ni superieure a 20.");
        }
        
        } while (notes[n-1]<0 || notes[n-1]>20);
}


void supprimerNote(){
    int k;

    do{
        
        printf("Choisissez la note a supprimer :");
        scanf("%d",&k);
        if (k>count || k<=0)
        {
            printf("Indice invalide. Veuillez entrer un indice entre 0 et %d.\n",count);
        }


    } while (k>count || k<=0);


    for (int i = k-1; i < count-1; i++)
    {
        
        notes[i]=notes[i+1];
    }
    count--;

}

void compterAdmis(){
    int admis =0;

    for (int i = 0; i < count; i++)
    {
        if (notes[i]>=10)
        {
            admis++;
        }
        
    }
    printf("Nombre de notes admis : %d \n",admis);
}

void compterNonAdmis(){
    int non_admis =0;

    for (int i = 0; i < count; i++)
    {
        if (notes[i]<10)
        {
            non_admis++;
        }
        
    }
    printf("Nombre de notes non admis : %d \n",non_admis);
}