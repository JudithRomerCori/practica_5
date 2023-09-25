// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 24/09/2023

// Fecha modificaci�n: 24/09/2023

// N�mero de ejericio: 2

// Problema planteado:De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y nos devuelva el pa�s que mayor n�mero de medallas ha ganado.
#include <iostream>
#include <cstring>

using namespace std;

struct Datos {
    char nombre[40];
    char pais[25];
};

struct Atleta {
    char deporte[30];
    Datos pers;
    int nmedallas;
};

Atleta atletas[30];

int main() {
    int N;

    cout << "Ingrese el n�mero de atletas (N): ";
    cin >> N;

    // Leer datos de atletas
    for (int i = 0; i < N; i++) {
        cout << "Atleta " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(atletas[i].pers.nombre, sizeof(atletas[i].pers.nombre));
        cout << "Pa�s: ";
        cin.getline(atletas[i].pers.pais, sizeof(atletas[i].pers.pais));
        cout << "Deporte: ";
        cin.getline(atletas[i].deporte, sizeof(atletas[i].deporte));
        cout << "N�mero de medallas: ";
        cin >> atletas[i].nmedallas;
    }

    // Determinar el pa�s con m�s medallas
    char paisConMasMedallas[25];
    int mayorNumeroMedallas = 0;

    for (int i = 0; i < N; i++) {
        if (atletas[i].nmedallas > mayorNumeroMedallas) {
            mayorNumeroMedallas = atletas[i].nmedallas;
            strcpy(paisConMasMedallas, atletas[i].pers.pais);
        }
    }

    // Imprimir el pa�s con m�s medallas
    cout << "\nEl pa�s con el mayor n�mero de medallas es: " << paisConMasMedallas << " con " << mayorNumeroMedallas << " medallas." << endl;

    return 0;
}
