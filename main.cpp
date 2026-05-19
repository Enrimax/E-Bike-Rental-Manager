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
    cout << "ID: " << b.id 
         << " - Distanza: " << d 
         << " - Autonomia: " << b.autonomia << " km" << endl;

}

int main() {
    srand(time(0));

    // Array con i dati delle 5 bici (alcune disponibili, alcune no)
    Bici elenco[5] = {
        {1, 2, 3, 20, 1},
        {2, 5, 2, 15, 0},
        {3, 1, 8, 30, 1},
        {4, 7, 1, 10, 1},
        {5, 3, 4, 25, 0}
    };

    int xUtente, yUtente;
    cout << "Inserisci X: ";
    cin >> xUtente;
    cout << "Inserisci Y: ";
    cin >> yUtente;

    
    float distanze[5];
    for (int i = 0; i < 5; i++) {
        distanze[i] = calcolaDistanza(elenco[i].x, elenco[i].y, xUtente, yUtente);
    }