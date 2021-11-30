//Struttura che contiene le caratteristiche dei prodotti
struct dati_magazzino
{
     char codice[20];
     char nome[20];
     char specifica[20];
     int quantita;
     int costo;
};
//Struttura che contiene i movimenti dei prodotti ogni giorno
struct mov_giorn
{
    int scorta;
    int venduto;
    int ordinato;
};
typedef struct dati_magazzino Prodotto;
typedef struct mov_giorn Movimento;
//Procedura per la visualizzazione delle caratteristiche dei 20 prodotti il primo giorno. Ha come unico parametro di ingresso l'array ana_mag
void visualizzazione(Prodotto[]);
/* Procedura per l'inserimento dei movimenti all'interno della matrice magazzino. Avrà come parametri di input la matrice magazzino e
l'array ana_mag */
void inserimento_mov(Movimento[][20],Prodotto[]);
/* Procedura per la visualizzazione dei movimenti dei 20 prodotti nei 10 giorni. Avrà come unico parametro di input la matrice
magazzino */
void visualizzazione1(Movimento[][20]);
/* Procedura che effettua la prima richiesta della traccia. Avrà come parametri di input la matrice magazzino, l'array ana_mag,e il
giorno desiderato. Come output saranno visualizzati i prodotti sotto scorta (<5) */
void selezione1(Movimento[][20],Prodotto[],int);
/*Procedura che effettua la seconda richiesta della traccia: ordinamento e successiva visualizzazione dei prodotti nel giorno
desiderato in relazione alla quantità venduta (in ordine crescente). I dati di input sono la matrice magazzino, l'array ana_mag e il giorno
desiderato. Come output avremo i prodotti ordinati per quantità vendute */
void selezione2(Movimento[][20],Prodotto[],int);
/*Procedura per l'ordinamento dei prodotti per quantità vendute. I parametri di input sono la matrice magazzino, l'array ana_mag,e il
giorno desiderato. L'ordinamento è per inserimento.*/
void ordinamento(Movimento[][20],Prodotto[],int);
