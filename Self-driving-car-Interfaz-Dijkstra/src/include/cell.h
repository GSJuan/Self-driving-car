// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Pequeño struct para representar las celdas

#pragma once

struct Cell {
    bool value = false; //libre(false) u ocupado (true)
    char state = ' '; // X pasó por ahí, " " libre, O obstaculo.
};