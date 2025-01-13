/*
Carlos Ernesto Soto Alarcón A01747990
Karime Itzel Ruvalcaba Pérez A01656188
Sergio Alfonso Casillas Santoyo A01424863
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
/*

Implementación del algoritmo avaro para calcular el número mínimo de monedas necesarias para el cambio.

coins: Vector con que se representan las diferentes denominaciones disponibles de las monedas.
P: precio de un producto dado
Q: billete o moneda con el que se paga dicho producto

complejidad:
Ordenar las monedas: O(n log n), donde n es el tamaño del vector de monedas.
Iterar sobre las monedas para calcular el cambio: O(n).
Complejidad total: O(n log n).
*/
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

/*
Lee los datos para el formato txt y los procesa para el algoritmo avaro.

El formato de entrada debe incluir el número de denominaciones de monedas, los valores
de las monedas, el precio del producto "P" y la cantidad pagada "Q". Se pueden procesar múltiples casos de prueba.

complejidad:
Leer las líneas de entrada: O(m), donde m es el número total de líneas en la entrada.
Procesar cada caso de prueba: O(k * n log n), donde k es el número de casos de prueba y n el número promedio de denominaciones.
 */
void ForTxt() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }

        int n = stoi(line); 
        vector<int> coins(n);

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            coins[i] = stoi(line);
        }

        int P, Q;
        getline(cin, line);
        P = stoi(line); 
        getline(cin, line);
        Q = stoi(line); 

        Greedy(coins, P, Q);

        cout << endl;
    }
}

/*
Permite la entrada manual de las denominaciones de monedas, el precio del producto "P" y la cantidad pagada "Q". 
complejidad:
Leer los datos de entrada: O(n), donde n es el número de denominaciones de monedas.
Procesar el algoritmo avaro: O(n log n).
*/

void Manual() {
    int n, P, Q;
    cout << "Ingrese el número de denominaciones de monedas: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Ingrese las denominaciones de las monedas, una por línea: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese la cantidad pagada: ";
    cin >> Q;

    Greedy(coins, P, Q);
}

/*
Punto de entrada del programa. Determina el modo de entrada (manual o desde archivo txt).
Si la entrada es desde un terminal, activa el modo manual. De lo contrario, los datos
se leen desde la entrada para el archivo txt.
complejidad:
Dependiendo del modo de entrada:
 - Modo manual: O(n log n).
 - Modo basado en archivos txt: O(k * n log n), donde k es el número de casos de prueba.
 
*/
int main() {
    // Para ingresar los valores manualmente
    if (isatty(fileno(stdin))) {
        Manual();
    } else {
        // Para archivos txt
        ForTxt();
    }

    return 0;
}