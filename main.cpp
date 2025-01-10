#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Greedy(vector<int> &coins, int P, int Q){

    if (Q < P){
        cout << "Falta dinero para pagar ese producto" << endl;
        return;
    }
    if (Q == P){
        cout << "No hay cambio por dar" << endl;
        return;
    }

    int change = Q - P;
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> coinCount(coins.size(), 0);

    for (int i=0; i < coins.size(); ++i){
        if (change >= coins[i]){
            coinCount[i] = change / coins[i];
            change -= coinCount[i] * coins[i];
        }
    }

    // Calculo del cambio
    for (int i=0; i < coins.size(); ++i){
        cout << coinCount[i] << " moneda(s) de " << coins[i] << endl;
    }
}

int main(){
    
    int n, P, Q;
    cout << "Ingrese el número de denominaciones de monedas: " << endl;
    cin >> n;

    vector<int> coins(n);
    cout << "Ingrese las denominaciones de las monedas, una por línea: " << endl;
    for (int i=0; i<n; ++i){
        cin >> coins[i];
    }

    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese la cantidad pagada: ";
    cin >> Q;

    Greedy(coins, P, Q);

    return 0;

}