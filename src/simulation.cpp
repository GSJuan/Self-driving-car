// AUTHOR: Juan García Svehicleos
// DATE: 21/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AEDA
// PRACTICE Nº: 4
// Compilation: make
// Execution: ./langton
// Especificaciones de la clase Universe

#include "include/simulation.h"

//Constructores y destructor
Universe::Universe() {
    max_iter = 10;
    curr_iter = 0;
}

Universe::Universe(int iter){
    max_iter = iter;
    curr_iter = 0;
}

Universe::Universe(World* world, Vehicle* taxi, int iterations){
    max_iter = iterations;
    curr_iter = 0;
    vehicle = taxi;
    grid = world;
}

Universe::~Universe() {
}

int Universe::GetMaxIter(void) {
    return max_iter;
}

int Universe::GetCurrIter(void) {
    return curr_iter;
}

void Universe::SetMaxIter(int iteration) {
    max_iter = iteration;
}
   
void Universe::SetCurrIter(int iteration) {
    curr_iter = iteration;
}

void Universe::Loop(void) {
   grid->PrintGrid(vehicle);
    std::cout << "Current iteration: " << GetCurrIter() << std::endl;
    PrintData();
    try {
        for (int i = 0; i < GetMaxIter(); i++){
            SetCurrIter(i +1);
            vehicle->Update(*grid);
            grid->TryPosition(vehicle); //prueba las hormigas a ver si estan fuera
            grid->PrintGrid(vehicle);
            std::cout << "Current iteration: " << GetCurrIter() << std::endl;
            PrintData();
        }
    }
    catch (std::exception e) {
        throw e;
    }
}

void Universe::PrintData(void) {
        std::cout << "vehicle: X = " << vehicle->GetRow() << " Y = " << vehicle->GetColumn() << " Direction: " ;
        vehicle->PrintDirection();
        std::cout << std::endl;
}