// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Este programa simula el comportamiento del taxi autonomo en un formto de texto.
//chcp.com 65001 arregla el encoding

#include "include/simulation.h"

int main( void /* int argc, char* argv[]*/ ) {
    int row_min, row_max, col_min, col_max, iterations, direction, vehicle_row, vehicle_col, menu, vehicle_type, destination_row, destination_col, obstacle_percentage, randomize;
    std::cout << "¿Desea el comportamiento por defecto del mundo(0), o personalizar la experiencia(1)?" << std::endl << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while((menu != 0) && (menu != 1)){
        std::cin >> menu;
        if((menu != 0) && (menu != 1)){
            std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        }
    }

if (menu == 0){
    row_min = -10;
    row_max = 10;
    col_min = -10;
    col_max = 10;
    iterations = 30;
    obstacle_percentage = 30;
}
else if(menu == 1) {
    
    std::cout << "Introduzca el indice menor de las filas del mundo (se aceptan indices negativos ;D ): ";
    std::cin >> row_min;
    while (row_min >= 0){
        std::cout << "Eso era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice menor de las filas del mundo(menor que 0): " << std:: endl;
        std::cin >> row_min;
    }
    std::cout << std::endl <<"Introduzca el indice mayor de las filas del mundo(mayor o igual que 0): " << std:: endl;
    std::cin >> row_max;
    while (row_max < 0){
        std::cout << "Eso no era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice mayor de las filas del mundo(mayor o igual que 0): " << std:: endl;
        std::cin >> row_max;
    }

    std::cout << "Introduzca el indice menor de las columna del mundo (se aceptan indices negativos ;D): ";
    std::cin >> col_min;
    while (col_min >= 0){
        std::cout << "Eso era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice menor de las columnas del mundo(menor que 0): " << std:: endl;
        std::cin >> col_min;
    }

    std::cout << std::endl << "Introduzca el indice mayor de las columnas del mundo(mayor o igual que 0): " << std:: endl;
    std::cin >> col_max;
    while (col_max < 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice mayor de las columnas del mundo(mayor o igual que 0): " << std:: endl;
        std::cin >> col_max;
    }

    std::cout << "Introduzca el porcentaje de obstaculos (entre 0 y 100): " << std:: endl;
    std::cin >> obstacle_percentage;
    while ((obstacle_percentage < 0) || (obstacle_percentage > 100)){
        std::cout << "Eso no estaba entre 0 y 100. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero de iteraciones(entre 0 y 100): " << std:: endl;
        std::cin >> obstacle_percentage;
    }

    std::cout << "Introduzca el numero de iteraciones(mayor que 0): " << std:: endl;
    std::cin >> iterations;
    while (iterations <= 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero de iteraciones(mayor que 0): " << std:: endl;
        std::cin >> iterations;
    }
}

World* pWorld;
pWorld = new FiniteWorld(row_min, row_max, col_min, col_max, obstacle_percentage);

Vehicle *pvehicle;

    std::cout << "Introduzca la coordenada X del taxi: ";
    std::cin >> vehicle_row;
    while ((vehicle_row < row_min) || (vehicle_row > row_max)) {
        std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << row_min << " y " << row_max << std:: endl;
    std::cin >> vehicle_row;
    }

    std::cout << "Introduzca la coordenada Y del taxi: ";
    std::cin >> vehicle_col;
    while ((vehicle_col < col_min) || (vehicle_col > col_max)) {
        std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << col_min << " y " << col_max << std:: endl;
        std::cin >> vehicle_col;
    }
    
    std::cout << "Introduzca la dirección inicial del taxi (entre estas: 1, 2, 3, 4, 5, 6, 7, 8) " << std:: endl;
    std::cin >> direction;
    while ((direction < 1) || (direction > 8)) {
        std::cout << "carácter de dirección incorrecto" << std::endl;
        std::cout << "Introduzca la dirección inicial del taxi (entre estas: 1, 2, 3, 4, 5, 6, 7, 8) " << std:: endl;
        std::cin >> direction;
    }

    do {
        std::cout << "Introduzca la coordenada X de destino: ";
        std::cin >> destination_row;
        while ((destination_row < row_min) || (destination_row > row_max)) {
            std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
            std::cout << "Introduzca una coordenada entre " << row_min << " y " << row_max << std:: endl;
        std::cin >> destination_row;
        }

        std::cout << "Introduzca la coordenada Y de destino: ";
        std::cin >> destination_col;
        while ((destination_col < col_min) || (destination_col > col_max)) {
            std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
            std::cout << "Introduzca una coordenada entre " << col_min << " y " << col_max << std:: endl;
            std::cin >> destination_col;
        }
    } while ((pWorld->GetWorldValue(destination_row, destination_col)) == true); //mientras la direccion de origen esté ocupada por un obstaculo se repite el proceso de instertar direccion de origen

/*

Implement manual and automatic obstacle addition

*/
pvehicle = new Taxi(vehicle_row, vehicle_col, direction, destination_row, destination_row);
Simulation universe(pWorld, pvehicle, iterations);
universe.Loop();

return 0;
}

//blanca = false = " "
//negra = true = "X"