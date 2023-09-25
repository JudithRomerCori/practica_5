// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 3

// Problema planteado:Realice un programa en C++ con funciones y estructuras para el estacionamiento delMulticine. Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de autos
//Piso 1 – 50 autos
//Piso 2 – 40 autos
//Piso 3 – 30 autos
//Piso 4 – 45 autos
//El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,
//automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del auto. Escribir un programa en C++ utilizando funciones y estructuras para:
//• Simular la entrada de vehículos, el programa debe pedir la cantidad de vehículos ingresados y el programa debe simular los tipos de vehículo, la marca, el modelo, el color y en que piso se han estacionado.
//• La simulación puede repetirse varias veces hasta que el usuario ingrese el valor de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se incremental.
//• Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en cada piso.
//• Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
//• Hacer un reporte por colores de autos, modelo y marca.
//• La simulación debe determinar cuando el parqueo se ha llenado.
//• La simulación debe determinar cuántos espacios libres queda.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para representar un vehículo
struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
};

// Función para simular la entrada de vehículos
void ingresarVehiculos(vector<vector<Vehiculo>>& pisos) {
    int cantidad;
    cout << "Ingrese la cantidad de vehículos a estacionar (0 para salir): ";
    cin >> cantidad;

    while (cantidad > 0) {
        string tipo;
        cout << "Ingrese el tipo de vehículo (vagoneta, camioneta, automovil, minivan, motocicleta): ";
        cin >> tipo;

        string marca;
        cout << "Ingrese la marca del vehículo: ";
        cin >> marca;

        string modelo;
        cout << "Ingrese el modelo del vehículo: ";
        cin >> modelo;

        string color;
        cout << "Ingrese el color del vehículo (uno de los 12 colores principales): ";
        cin >> color;

        Vehiculo vehiculo;
        vehiculo.tipo = tipo;
        vehiculo.marca = marca;
        vehiculo.modelo = modelo;
        vehiculo.color = color;

        // Determinar el piso donde estacionar el vehículo
        int piso = -1;
        if (tipo == "vagoneta" && pisos[0].size() < 50) {
            piso = 1;
        } else if (tipo == "camioneta" && pisos[1].size() < 40) {
            piso = 2;
        } else if (tipo == "automovil" && pisos[2].size() < 30) {
            piso = 3;
        } else if (tipo == "minivan" && pisos[2].size() < 30) {
            piso = 3;
        } else if (tipo == "motocicleta" && pisos[3].size() < 45) {
            piso = 4;
        }

        if (piso != -1) {
            pisos[piso - 1].push_back(vehiculo);
            cout << "Vehículo estacionado en el piso " << piso << endl;
        } else {
            cout << "No hay espacio disponible en ningún piso para este vehículo." << endl;
        }

        cantidad--;
    }
}

// Función para mostrar la cantidad de vehículos por tipo
void mostrarCantidadPorTipo(const vector<vector<Vehiculo>>& pisos) {
    int vagonetas = 0, camionetas = 0, automoviles = 0, minivans = 0, motocicletas = 0;

    for (const auto& piso : pisos) {
        for (const auto& vehiculo : piso) {
            if (vehiculo.tipo == "vagoneta") {
                vagonetas++;
            } else if (vehiculo.tipo == "camioneta") {
                camionetas++;
            } else if (vehiculo.tipo == "automovil") {
                automoviles++;
            } else if (vehiculo.tipo == "minivan") {
                minivans++;
            } else if (vehiculo.tipo == "motocicleta") {
                motocicletas++;
            }
        }
    }

    cout << "Cantidad de vagonetas: " << vagonetas << endl;
    cout << "Cantidad de camionetas: " << camionetas << endl;
    cout << "Cantidad de automóviles: " << automoviles << endl;
    cout << "Cantidad de minivans: " << minivans << endl;
    cout << "Cantidad de motocicletas: " << motocicletas << endl;
}

// Función para mostrar la cantidad de vehículos por color
void mostrarCantidadPorColor(const vector<vector<Vehiculo>>& pisos) {
    vector<string> colores{"rojo", "verde", "azul", "amarillo", "blanco", "negro", "gris", "naranja", "marrón", "rosado", "violeta", "plateado"};
    vector<int> cantidadPorColor(12, 0);

    for (const auto& piso : pisos) {
        for (const auto& vehiculo : piso) {
            for (int i = 0; i < 12; i++) {
                if (vehiculo.color == colores[i]) {
                    cantidadPorColor[i]++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        cout << "Cantidad de vehículos de color " << colores[i] << ": " << cantidadPorColor[i] << endl;
    }
}

int main() {
    vector<vector<Vehiculo>> pisos(4); // Inicializar los 4 pisos

    while (true) {
        ingresarVehiculos(pisos);

        cout << "\nCantidad de vehículos por tipo:" << endl;
        mostrarCantidadPorTipo(pisos);

        cout << "\nCantidad de vehículos por color:" << endl;
        mostrarCantidadPorColor(pisos);

        bool lleno = true;
        for (const auto& piso : pisos) {
            if (piso.size() < 50 && lleno) {
                lleno = false;
            }
        }

        if (lleno) {
            cout << "\nEl estacionamiento está lleno." << endl;
            break;
        }

        int espaciosLibres = 0;
        for (const auto& piso : pisos) {
            espaciosLibres += 50 - piso.size();
        }

        cout << "\nEspacios libres en el estacionamiento: " << espaciosLibres << endl;
    }

    return 0;
}
