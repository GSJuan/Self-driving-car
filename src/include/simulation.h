// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Clase Simulation que define la relacion entre taxi y entorno (clase world)
 
#include <chrono>

#include "finite_world.h"
 
#pragma once

class Simulation {

    private:

    int max_iter;
    int curr_iter;
    Vehicle* vehicle;
    World *grid;

    public:

    Simulation();
    Simulation(int);
    Simulation(World*, Vehicle*, int);
    ~Simulation();

    int GetMaxIter(void); //devuelve el numero maximo de iteraciones
    int GetCurrIter(void); //devuelve el numero actual de iteraciones

    void SetMaxIter(int);
    void SetCurrIter(int);

    void Loop(void);
    void Sort(void);
    void PrintData(void);

    std::vector<int> GetPath(int);
};