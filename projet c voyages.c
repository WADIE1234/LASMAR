#include<stdio.h>
struct voyage{
int ID;
char date[30];
int dispo;
char distination[30];
};typedef struct voyage voy;
struct Travel_Manager{
voy *data;
struct Travel_Manager* suiv;
};typedef struct Travel_Manager tm;
tm *tete;
// l'ajout d'un voyage
void ajouter(tm *tete, voy *element)
{

   tm *nouveau = malloc(sizeof(*nouveau));
    if (tete == NULL || nouveau == NULL)
    {
        exit("error");
    }
    nouveau->data = element;

    // Insertion de l'élément au début de la liste
    nouveau->suiv = tete;
    tete = nouveau;
};


//parcours de la liste travel manager
tm *parcours(tm *tete , int donnee){
 tm *aux;
 if (tete == NULL )
    {
        exit("error");
    }
 aux=tete;
 if (aux->data->ID==donnee){return aux ;}
 while (aux->suiv != NULL){
 if (aux->suiv->data->ID==donnee){return aux;}
   else aux=aux->suiv;}
};
// supprimer pour une position donnee
void supprimer (tm *tete , int del){
tm *c;
tm *aux=parcours(tete , del);
c=aux->suiv;
aux=c->suiv;
free(c);
};
//affichage d'un voyage
void affiche(tm *tete, int ID){
    tm *aux=parcours(tete ,ID);
    aux=aux->suiv;
    voy *c=aux->data;
    printf("la date de voyage est %s:  ,distination %s: ,disponibilitee:%d",c->date,c->distination,c->dispo);
};
//recherche de la liste travel manager
tm *recherche(tm *tete , char d[30]){
 tm *aux;
 if (tete == NULL )
    {
        exit("error");
    }
 aux=tete;
 if (aux->data->date==d){return aux ;}
 while (aux->suiv != NULL){
 if (aux->suiv->data->date==d){return aux;}
   else aux=aux->suiv;}
};
main(){
//case0
voy *element;
//case1
int ID;
//case 4
char recher[30];
int choix;
printf("choisir l'operation en tappant le numero adequat:\n Ajouter un voyage :0 \n");
printf(" Afficher la description d'un voyage:1\n");
printf(" Supprimer un voyage:2\n");
printf(" Modifier un voyage:3\n");
printf(" Recherche des voyages disponibles selon des dates precises:4\n");
scanf("%d",&choix);
if (choix==0){
      printf("donner l'ID");
      scanf("%d",&element->ID);
      printf("donner la date de voyage sous la forme jj,mm,aaaa");
      scanf("%s",&element->date);
      printf("donner distination de voyage ");
      scanf("%s",&element->distination);
      printf("donner la disponibilite de voyage 1, 0 si non ");
      scanf("%s",&element->dispo);
      ajouter(tete, element);
}
if (choix==1){printf("donner l'ID");
      scanf("%d",&ID);
      affiche(tete, ID);
}
if (choix==2){printf("donner l'ID");
      scanf("%d",&ID);
      supprimer (tete , ID);
}
if (choix==3){printf("donner l'ID");
       scanf("%d",&ID);
      tm *elt=parcours(tete ,ID);
      voy *el=elt->suiv->data;
       printf("donner la nouvelle date du voyage sous la forme jj,mm,aaaa");
      scanf("%s",&el->date);
      printf("donner distination de voyage ");
      scanf("%s",&el->distination);
      printf("donner la disponibilite de voyage 1, 0 si non ");
      scanf("%s",&el->dispo);
}
if (choix==4){printf("donner la date de voyage sous la forme jj,mm,aaaa");
      scanf("%s",&recher);
      tm *r=recherche(tete , recher);
      int Id=r->data->ID;
      affiche(tete, Id);
      }
 printf("merci pour votre attention");
return 0;
}
