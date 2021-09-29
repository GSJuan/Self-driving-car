// AUTHOR: Juan García SVehicleos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Clase Universe que define la relacion entre hormiga y mundo

#include "finite_world.h"

#pragma once

class Universe {

    private:

    int max_iter;
    int curr_iter;
    Vehicle* vehicle;
    World *grid;

    public:

    Universe();
    Universe(int);
    Universe(World*, Vehicle*, int);
    ~Universe();

    int GetMaxIter(void); //devuelve el numero maximo de iteraciones
    int GetCurrIter(void); //devuelve el numero actual de iteraciones

    void SetMaxIter(int);
    void SetCurrIter(int);

    void Loop(void);
    void Sort(void);
    void PrintData(void);
};