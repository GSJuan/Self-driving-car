// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
//herencia del vehiculo en la clase taxi

#include "vehicle.h"
#pragma once
class Taxi: public Vehicle
{

using Vehicle::Vehicle;

virtual void Turn45(char colour) {
    if(colour == ' '){ //si la casilla es blanca
        if((direction <= 8) && (direction > 1)) //giro a la izquierda
            direction--;
        else if(direction == 1)
            direction = 8;
        else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
    }
    else if(colour == 'X') { //si la casilla es negra, grio a la derecha
        if((direction >= 1) && (direction < 8))
            direction++;
        else if (direction == 8)
            direction = 1;
        else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
    }
}

virtual void Turn45(bool colour){
    if(colour == false){ // si la casilla es blanca... 
        if((direction <= 8) && (direction > 1)) //giro a la izquierda
            direction--;
        else if(direction == 1)
            direction = 8;
        else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
    }
    else { //giro a la derecha
        if((direction >= 1) && (direction < 8))
            direction++;
        else if (direction == 8)
            direction = 1;
        else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
    }
}

virtual void Move(void) {
    if(direction == 1)
        row_pos += -1;
    else if(direction == 2) {
        row_pos += -1;
        column_pos += 1;
    }
    else if (direction == 3)
        column_pos += 1;
    else if(direction == 4) {
        row_pos += 1;
        column_pos += 1;
    }
    else if(direction == 5)
        row_pos += 1;
    else if(direction == 6) {
        row_pos += 1;
        column_pos += -1;
    }
    else if(direction == 7)
        column_pos += -1;
    else if(direction == 8) {
        row_pos += -1;
        column_pos += -1;
    }
    else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;

}

virtual void PrintDirection(void){
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

};