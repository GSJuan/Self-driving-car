// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Especificaciones de la clase Simulation

#include "include/simulation.h"

//Constructores y destructor
Simulation::Simulation() {
    max_iter = 10;
    curr_iter = 0;
}

Simulation::Simulation(int iter){
    max_iter = iter;
    curr_iter = 0;
}

Simulation::Simulation(World* world, Vehicle* taxi, int iterations){
    max_iter = iterations;
    curr_iter = 0;
    vehicle = taxi;
    grid = world;
}

Simulation::~Simulation() {
}

int Simulation::GetMaxIter(void) {
    return max_iter;
}

int Simulation::GetCurrIter(void) {
    return curr_iter;
}

void Simulation::SetMaxIter(int iteration) {
    max_iter = iteration;
}
   
void Simulation::SetCurrIter(int iteration) {
    curr_iter = iteration;
}

void Simulation::Loop(void) {
    grid->PrintGrid(vehicle);
    std::cout << "Current iteration: " << GetCurrIter() << std::endl;
    PrintData();
    try {
        int x = vehicle->GetDestinationColumn(),    y = vehicle->GetDestinationRow();
        x += grid->GetRow() / 2,                    y += grid->GetColumn() / 2;
        int end = x + grid->GetRow() * y;

        std::vector<int> path = GetPath(end);

        int i = 0;
        for (int nodo : path) {
            system("cls");
            SetCurrIter(i + 1);
            grid->TryPosition(vehicle); //prueba el vehiculo a ver si esta fuera
            vehicle->Update(*grid, nodo);
            grid->PrintGrid(vehicle);
            std::cout << "Current iteration: " << GetCurrIter() << std::endl;
            PrintData();
            i++;
        }
    }
    catch (std::exception& e) {
        throw e;
    }
}

void Simulation::PrintData(void) {
        std::cout << "vehicle: X = " << vehicle->GetRow() << " Y = " << vehicle->GetColumn() << " Direction: " ;
        vehicle->PrintDirection();
        std::cout << std::endl;
}

std::vector<int> Simulation::GetPath(int end) {
    int x = vehicle->GetRow(),  y = vehicle->GetColumn();
    x += grid->GetRow() / 2,    y += grid->GetColumn() / 2;
    int source = x + grid->GetRow() * y;

    auto ruta = grid->Dijkstra(source);
    std::vector<int> path;

    for (int i = end; i != source;) {
        path.push_back(i);
        i = ruta.second[i];
    }

    for (unsigned int i = 0; i < path.size() / 2; i++) {
        int temp = path[i];
        path[i] = path[path.size() - 1 - i];
        path[path.size() - 1 - i] = temp;
    }

    return path;
}