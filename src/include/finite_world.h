#include "world.h"
#pragma once
class FiniteWorld: public World 
{

using World::World;

virtual void ReSize(Vehicle* vehicle){

        while(VehicleOut(vehicle) == true){
            if(vehicle->GetRow() >= world.GetUpperLimit()){
            vehicle->SetRow(world.GetLowerLimit());
            }
            else if(vehicle->GetRow() < world.GetLowerLimit()) {
                vehicle->SetRow(world.GetUpperLimit());
            }
            else if (vehicle->GetColumn() >= world[0].GetUpperLimit()){
                vehicle->SetColumn(world[vehicle->GetRow()].GetLowerLimit());
            }
            else if(vehicle->GetColumn() < world[0].GetLowerLimit()){
                vehicle->SetColumn(world[vehicle->GetRow()].GetUpperLimit());
            }
        }
}

};