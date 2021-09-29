// AUTHOR: Juan García SVehicleos
// DATE: 21/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 2.0
// SUBJECT: AEDA
// PRACTICE Nº: 4
// Clase Hormiga que contiene las características de la hormiga de langton

class World;

#include <iostream>
#include "stdio.h"
#pragma once

class Vehicle {

    protected:

    int row_pos;
    int column_pos;
    int direction;

    virtual void Turn45(bool) = 0;
    virtual void Turn45(char) = 0;

    virtual void Move(void) = 0; //Hace que la hormiga avance su posición una casilla en función de su dirección

    public:

    Vehicle();
    Vehicle(int, int, int);
    ~Vehicle();

    int GetRow(void); //devulve la fila en la que se encuentra la hormiga
    int GetColumn(void); //devulve la columna en la que se encuentra la hormiga
    int GetDirection(void); //devuelve la dirección que tiene la hormiga

    void SetRow(int);
    void SetColumn(int);
    void SetDirection(int);

    virtual void Update(World&); //hace el giro y el movimiento en funcion de la casilla

    void PrintDirection(void);
    
   /* void Turn90R(void); //cambia la dirección de la hormiga 90 grados a la derecha
    void Turn90L(void); //cambia la dirección de la hormiga 90 grados a la izquierda

    void Turn45R(void);
    void Turn45L(void); */

};