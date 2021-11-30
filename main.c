/* La finalità del programma è quella di gestire i movimenti di 20 prodotti per 10 giorni. Nello specifico si vuole visualizzare
i prodotti, in un dato giorno, che sono sotto scorta e cioè la loro quantità di scorta <5. La scorta è il risultato della scorta
del giorno precedente, meno la quantità venduta, più la quantità ripristinata. Inoltre, si vuole visualizzare, dato un giorno,i
prodotti ordinati in base alla quantità venduta. In questo caso verrà effettuato un ordinamento per inserimento della quantità venduta
e di conseguenza dei prodotti che si sposteranno in base ai valori delle loro vendite. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Funzioni.h"
#define n_prodotti 20  //Costante indicante i 20 prodotti
#define n_giorni 10   //Costante indicante i 10 giorni

int main()
{
     printf("Gestione magazzino!\n\n");
//Di seguito la matrice di tipo Movimento che contiene tutti i movimenti anagrafici dei 20 prodotti nei 10 giorni
     Movimento magazzino[n_giorni][n_prodotti];
/*Dichiarazione variabile di selezione: se è 1 eseguirà la prima richiesta, se è 2 eseguirà la seconda richiesta; variabile 'giorno'
che avrà valore da 1 a 10 in base alle richieste dell'utente; variabile 'k' che permetterà di eseguire 3 volte le richieste della traccia.*/
     int selezione,giorno,k;
//Inizializzazione dell'array di tipo Prodotto dei 20 prodotti il primo giorno
     Prodotto ana_mag[n_prodotti]={     "01","Tablet       ","Display 8''   ",55,100.00,
                                        "02","Smartphone   ","Uso manuale   ",30,500.00,
                                        "03","Tv Smart     ","Top di gamma  ",47,900.00,
                                        "04","Palmare      ","Uso lavorativo",25, 99.99,
                                        "05","Monitor      ","Da gaming     ",32,260.00,
                                        "06","SSD          ","1 TB          ",25,147.00,
                                        "07","Alimentatore ","Corsair 650 W ",15, 50.00,
                                        "08","Stampante    ","Laser Samsung ",10, 60.00,
                                        "09","Smartwatch   ","Made in China ",13, 57.60,
                                        "10","Scheda video ","1080 Ti       ",15,200.00,
                                        "11","IPad         ","IOS 13        ",37,699.99,
                                        "12","RAM          ","DDR4 8GB      ",15, 90.20,
                                        "13","Dissipatore  ", "A liquido rgb ",10, 49.99,
                                        "14","Pasta termica","Cooler Master ",12,  7.04,
                                        "15","Penna USB    ","64 GB         ",50,  9.49,
                                        "16","Scheda SD    ","Philips 32 GB ",25, 34.00,
                                        "17","Joystick     ","Per Xbox e PC ",19, 70.79,
                                        "18","Mouse        ","Wireless      ",44, 45.99,
                                        "19","Scheda madre ","Asus z370a    ",15,200.45,
                                        "20","Cavo HDMI    ","Alta velocita'",24,  7.45,
                                };
    visualizzazione(ana_mag);
    inserimento_mov(magazzino,ana_mag);
    visualizzazione1(magazzino);
    //Ciclo for che permette di effettuare al massimo 3 simulazioni del programma per ogni richiesta
    for(k=0;k<6;k++)
    {
        do
            {
                printf("Digita 1 per visualizzare i prodotti sotto scorta, digita 2 per visualizzare i prodotti ordinati per quantita'. . .\n");
                scanf("%d",&selezione);
            }
        while(!((selezione==1)||(selezione==2)));
        do
            {
                printf("Inserisci il giorno che vuoi visualizzare (1-10). . . \n");
                scanf("%d",&giorno);
            }
        while(!((giorno>=1)&&(giorno<=10)));
        if(selezione==1)
            {
                selezione1(magazzino,ana_mag,giorno);
            }
        else
            {
                selezione2(magazzino,ana_mag,giorno);
            }
    }
    return 0;
}
