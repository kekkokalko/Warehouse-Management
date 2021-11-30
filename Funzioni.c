#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define n_prodotti 20
#define n_giorni 10
struct dati_magazzino
{
     char codice[20];
     char nome[20];
     char specifica[20];
     int quantita;
     int costo;
};
struct mov_giorn
{
    int scorta;
    int venduto;
    int ordinato;
};
typedef struct dati_magazzino Prodotto;
typedef struct mov_giorn Movimento;
void visualizzazione(Prodotto ana_mag[])
{
         int j;
         printf("Step 1: Visualizzazione dei %d dati il primo giorno:\n",n_prodotti);
         for (j=0;j<n_prodotti;j++)
            {
                printf("Cod.%s",ana_mag[j].codice);
                printf("  Nome:%s",ana_mag[j].nome);
                printf("  Specifica:%s",ana_mag[j].specifica);
                printf("  Quantita':%d",ana_mag[j].quantita);
                printf("  Costo: $%d",ana_mag[j].costo);
                printf("\n");
            }
         printf("\n");
}
void inserimento_mov(Movimento magazzino[][20],Prodotto ana_mag[])
{
    printf("Step 2: Inseriemnto delle vendite e degli ordini dei prodotti nei 10 giorni:\n");
    int i,j;
    srand(time(NULL));
    for (i=0;i<n_prodotti;i++)
        {
            magazzino[0][i].scorta=ana_mag[i].quantita;
            magazzino[0][i].venduto=rand()%magazzino[0][i].scorta;
            magazzino[0][i].ordinato=1+rand()%magazzino[0][i].scorta;;
        }
    srand(time(NULL));
    //Calcolo dei moviemnti anagrafici dal 2° al 10° giorno
    for (j=1;j<n_giorni;j++)
    {
        for (i=0;i<n_prodotti;i++)
        {
        //La scorta è data dalla scorta del giorno precedente meno la quantità venduta più la quantità ordinata
        magazzino[j][i].scorta=magazzino[j-1][i].scorta-magazzino[j-1][i].venduto+magazzino[j-1][i].ordinato;
        //La quantità di vendite è data da un numero casuale che va da 0 al valore della scorta
        magazzino[j][i].venduto=rand()%magazzino[j][i].scorta;
        //La quantità di ripristino è data da un numero casuale che va da 1 al valore della scorta
        magazzino[j][i].ordinato=1+rand()%magazzino[j][i].scorta;
        }
    }
}
void visualizzazione1(Movimento magazzino[][20])
{
    int giorno=1,j,i;
    for (j=0;j<n_giorni;j++)
        {
            printf("Situazione del giorno %d:\n",giorno);
            for (i=0;i<n_prodotti;i++)
                {
                    printf("Scorta:%d",magazzino[j][i].scorta);
                    printf("\tVenduto:%d",magazzino[j][i].venduto);
                    printf("\tOrdinato:%d\n",magazzino[j][i].ordinato);
                }
                printf("\n");
            giorno++;
        }
    printf("\n\n");
}
void selezione1(Movimento magazzino[][20],Prodotto ana_mag[],int giorno)
{
    //La variabile num_prodotti ci permette di capire quanti prodotti sono sotto scorta
    int num_prodotti=0,i;
    for (i=0;i<n_prodotti;i++)
        {
            if(magazzino[giorno-1][i].scorta<5)
            {
                                printf("Cod.%s\t",ana_mag[i].codice);
                                printf("Nome:%s\t",ana_mag[i].nome);
                                printf("Specifica:%s\t",ana_mag[i].specifica);
                                printf("Quantita':%d\t",magazzino[giorno-1][i].scorta);
                                printf("Costo: $%d\n",ana_mag[i].costo);
                                num_prodotti++;
            }
        }
    //Se il numero di prodotti sotto scorta è uguale a 0 verrà visualizzata una frase...
    if(num_prodotti==0)
        {
            printf("Attenzione! Nessun prodotto e' sotto scorta!\n");
        }
}
void selezione2(Movimento magazzino[][20],Prodotto ana_mag[],int giorno)
{
    ordinamento(magazzino,ana_mag,giorno);
}
void ordinamento(Movimento magazzino[][20],Prodotto ana_mag[],int giorno)
{
    /*El_da_ins_i e el_da_ins sono variabili che si riferiscono rispettivamente alla posizione e alla quantità di vendite del
    prodotto esaminato che deve essere inserito nella giusta posizione.*/
    int i,j,el_da_ins,el_da_ins_i;
    /*Struttura temporanea di appoggio che contiene la posizione e la quantità di vendite dei prodotti nel giorno scelto.
    Viene usata per evitare problematiche nell'ordinamento durante il passaggio di una selezione di un giorno ad un altro.*/
    struct temp{
        int pos;
        int venduto;
        };
    struct temp dati_temp[20];
    for(i=0;i<20;i++)
        {
            dati_temp[i].pos=i;
            dati_temp[i].venduto=magazzino[giorno-1][i].venduto;
        }
    for(i=1;i<20;i++)
        {
            el_da_ins=dati_temp[i].venduto;
            el_da_ins_i=dati_temp[i].pos;
            j=i-1;
            while((j>=0)&&(el_da_ins<dati_temp[j].venduto))
            {
                dati_temp[j+1].venduto=dati_temp[j].venduto;
                dati_temp[j+1].pos=dati_temp[j].pos;
                j--;
            }
            dati_temp[j+1].venduto=el_da_ins;
            dati_temp[j+1].pos=el_da_ins_i;
        }
    for(j=0;j<20;j++)
        {
            printf("Cod.%s\t",ana_mag[dati_temp[j].pos].codice);
            printf("Nome:%s\t",ana_mag[dati_temp[j].pos].nome);
            printf("Specifica:%s\t",ana_mag[dati_temp[j].pos].specifica);
            printf("Quantita':%d\t",magazzino[giorno-1][dati_temp[j].pos].scorta);
            printf("Vendite:%d\t",magazzino[giorno-1][dati_temp[j].pos].venduto);
            printf("Costo: $%d\n",ana_mag[dati_temp[j].pos].costo);
        }
}
