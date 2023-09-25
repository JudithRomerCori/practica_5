// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 1

// Problema planteado:La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
//La información con que se cuenta es: nombre, ci, departamento y salario.
//Realizar un programa en C++ que lea un array de estructura de los datos de N empleados e imprima los siguiente:
//• Empleado con mayor salario
//• Empleado con menor salario
//• Promedio salarial
//• Promedio por departamento
//• Departamento con mayor salario en promedio
//• Departamento con menor salario en promedio

#include <iostream>
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    int ci;
    string departamento;
    double salario;
};

int main() {
    int N;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;

    Empleado empleados[N];

    // Leer datos de empleados
    for (int i = 0; i < N; i++) {
        cout << "Ingrese nombre del empleado " << i+1 << ": ";
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "Ingrese CI del empleado " << i+1 << ": ";
        cin >> empleados[i].ci;
        cout << "Ingrese departamento del empleado " << i+1 << ": ";
        cin.ignore();
        getline(cin, empleados[i].departamento);
        cout << "Ingrese salario del empleado " << i+1 << ": ";
        cin >> empleados[i].salario;
    }

    // Inicializar variables para cálculos
    Empleado empleadoMayorSalario = empleados[0];
    Empleado empleadoMenorSalario = empleados[0];
    double totalSalarios = empleados[0].salario;
    double salarioPromedio = empleados[0].salario;

    // Calcular empleado con mayor y menor salario, y sumar salarios
    for (int i = 1; i < N; i++) {
        if (empleados[i].salario > empleadoMayorSalario.salario) {
            empleadoMayorSalario = empleados[i];
        }
        if (empleados[i].salario < empleadoMenorSalario.salario) {
            empleadoMenorSalario = empleados[i];
        }
        totalSalarios += empleados[i].salario;
    }

    // Calcular promedio salarial
    salarioPromedio = totalSalarios / N;

    // Calcular promedio por departamento
    double totalSalariosPorDepartamento = 0.0;
    int contadorPorDepartamento = 0;
    double salarioPromedioPorDepartamento = 0.0;
    string departamentoConMayorPromedio;
    double mayorPromedio = 0.0;
    string departamentoConMenorPromedio;
    double menorPromedio = salarioPromedio;

    for (int i = 0; i < N; i++) {
        totalSalariosPorDepartamento = 0.0;
        contadorPorDepartamento = 0;

        for (int j = 0; j < N; j++) {
            if (empleados[j].departamento == empleados[i].departamento) {
                totalSalariosPorDepartamento += empleados[j].salario;
                contadorPorDepartamento++;
            }
        }

        salarioPromedioPorDepartamento = totalSalariosPorDepartamento / contadorPorDepartamento;

        if (salarioPromedioPorDepartamento > mayorPromedio) {
            mayorPromedio = salarioPromedioPorDepartamento;
            departamentoConMayorPromedio = empleados[i].departamento;
        }

        if (salarioPromedioPorDepartamento < menorPromedio) {
            menorPromedio = salarioPromedioPorDepartamento;
            departamentoConMenorPromedio = empleados[i].departamento;
        }
    }

    // Imprimir resultados
    cout << "\nEmpleado con mayor salario: " << empleadoMayorSalario.nombre << " (CI: " << empleadoMayorSalario.ci << ") - Salario: " << empleadoMayorSalario.salario << endl;
    cout << "Empleado con menor salario: " << empleadoMenorSalario.nombre << " (CI: " << empleadoMenorSalario.ci << ") - Salario: " << empleadoMenorSalario.salario << endl;
    cout << "Promedio salarial: " << salarioPromedio << endl;
    cout << "Promedio por departamento:" << endl;
    cout << "Departamento con mayor salario en promedio: " << departamentoConMayorPromedio << " - Promedio: " << mayorPromedio << endl;
    cout << "Departamento con menor salario en promedio: " << departamentoConMenorPromedio << " - Promedio: " << menorPromedio << endl;

    return 0;
}
