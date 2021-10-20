  
#ifndef F_HEURISTICAS_H
#define F_HEURISTICAS_H

#include <cmath>

class f_heuristica
{
public:
    f_heuristica();
    virtual ~f_heuristica();

    virtual int operator()(const Cell&, const Cell&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class d_euclidea : public f_heuristica
{
public:
    d_euclidea();
    int operator()(const Cell& i, const Cell& f) {
        return static_cast<int>(sqrt(pow((i.getX() - f.getX()),2) + pow((i.getY() - f.getY()), 2)));
    }
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class d_manhattan : public f_heuristica
{
public:
    d_manhattan();
    int operator()(const Cell& i, const Cell& f) {
        return static_cast<int>(fabs(static_cast<double>(i.getX() - f.getX())) + fabs(static_cast<double>(i.getY() - f.getY())));
    }
};

#endif // F_HEURISTICAS_H