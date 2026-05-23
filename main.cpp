#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Bici {
    int id;
    int x;
    int y;
    int autonomia;
    int stato; 
};


float calcolaDistanza(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
    
    
void stampaBici(Bici b, float d) {
    cout << "ID: " << b.id <<endl;
     cout     << " Distanza: " << d <<endl;
     cout    << " Autonomia: " << b.autonomia << " km" << endl;

}

int main() {
    srand(time(0));

    
    Bici elenco[5] = {
        {1, 2, 3, 20, 1},
        {2, 5, 2, 15, 0},
        {3, 1, 8, 30, 1},
        {4, 7, 1, 10, 1},
        {5, 3, 4, 25, 0}
    };

    int xUtente, yUtente;
    cout << "Inserisci X: "<<endl;
    cin >> xUtente;
    cout << "Inserisci Y: "<<endl;
    cin >> yUtente;
    float distanze[5];
    for (int i = 0; i < 5; i++) {
        distanze[i] = calcolaDistanza(elenco[i].x, elenco[i].y, xUtente, yUtente);
    }
for (int i=0; i<4; i++){
for (int j=0; j<4-i; j++){
if(distanze[j]>distanze[j + 1]) {
float tempD= distanze[j];
distanze[j] = distanze[j + 1];
distanze[j + 1]= tempD;
Bici tempB =elenco[j];
elenco[j]= elenco[j + 1];
elenco[j+1]=tempB;
}
}
}
cout<<" Bici disponibili vicine:"<<endl;
for(int i=0;i<5;i++){
if(elenco[i].stato==1){
stampaBici(elenco[i], distanze[i]);
}
}
int idScelto, pos;
    bool idValido =false;
    do{
cout<<"inserisci ID bici:"<<endl;
cin>>idScelto;
for(int i= 0; i<5;i++){
    if(elenco[i].id == idScelto && elenco[i].stato == 1){
            idValido = true;
            pos = i; 
            break;
    }
    }

    if(!idValido) {
        cout << "Errore, ID non valido , Riprova." << endl;
    }
} while(!idValido);

int kmDaFare;
do {
cout<<"Quanti km vuoi fare?"<<endl;
cin>>kmDaFare;
    if(kmDaFare > elenco[pos].autonomia){
    cout<<"Errore, i km inseriti superano l'autonomia ella bici, inserisci i km in base al autonomia"<<endl;
    } else if(kmDaFare <0) {
        cout<<"Errore, non puoi inserire dei km in negativo"<<endl;
    }
}while(kmDafare <elenco[pos].autonomia || kmDaFare <0);

int pos=0;
for(int i=0;i<5;i++){
if(elenco[i].id==idScelto){
pos =i;
}
}
int ritardo= rand()% 15+1;
float tempo=((float)kmDaFare/20*60)+
ritardo;
float costo= tempo* 0.20;

elenco[pos].autonomia=
elenco[pos].autonomia- kmDaFare;
cout<<"Minuti totali:"<<tempo<<endl;
cout<<"Costo:"<<costo<<"euro"<<endl;
cout<<"Nuova autonomia bici:"<<elenco[pos].autonomia<<"km"<<endl;

}

