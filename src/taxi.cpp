// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Especificaciones de la clase taxi

#include "include/taxi.h"
#include "include/world.h"

//Constructores
Vehicle::Vehicle(){
    row_pos = 0;
    column_pos = 0;
    direction = 1;
    destination_row = 4;
    destination_col = 7;
}

Vehicle::Vehicle(int i, int j, int direction_, int row_destination, int col_destination){
    row_pos = i;
    column_pos = j;
    direction = direction_;
    destination_row = row_destination;
    destination_col = col_destination;
}

//Destructor
Vehicle::~Vehicle(){
}

//Getters y setters
int Vehicle::GetRow(void) {
    return row_pos;
}

int Vehicle::GetColumn(void) {
    return column_pos;
}

int Vehicle::GetDestinationRow(void) {
    return destination_row;
}

int Vehicle::GetDestinationColumn(void) {
    return destination_col;
}

int Vehicle::GetDirection(void) {
    return direction;
}

void Vehicle::SetRow(int row) {
    row_pos = row;
}

void Vehicle::SetColumn(int column) {
    column_pos = column;
}

void Vehicle::SetDirection(int next_direction) {
    direction = next_direction;
}

void Vehicle::Update(World& grid) {
    try{
       Turn45(grid.GetWorldValue(GetRow(), GetColumn()));
    grid.ToggleWorldValue(GetRow(), GetColumn());
    grid.SetWorldState('X', GetRow(), GetColumn());
    Move(); 
    }
    catch (std::exception& e){
        throw e;
    }
}

void Vehicle::PrintDirection(void){
    int direction = GetDirection();
    switch(direction){
        case 1: std::cout << "\u2191";
        break;

        case 2: std::cout << "\u2197";
        break;

        case 3: std::cout << "\u2192";
        break;

        case 4: std::cout << "\u2198";
        break;

        case 5: std::cout << "\u2193";
        break;

        case 6: std::cout << "\u2199";
        break;

        case 7: std::cout << "\u2190";
        break;

        case 8: std::cout << "\u2196";
        break;
    }
}