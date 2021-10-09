// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Especificaciones de la clase mundo

#include "include/world.h"

//Constructores

World::World(){
    row = 10;
    column = 10;
    size = 100;
    world = Vector<Vector<Cell>> (-10,10);
    for(int i = 0; i < 10; i++) {
        world[i].resize(10);
    }
}
std::vector<int> a;
World::World(int row_size, int column_size){
    row = row_size;
    column = column_size;
    size = row * column;
    world.resize(row_size);
        for(int i = 0; i < column_size; i++){
        world[i].resize(column_size);
    }
}

World::World(int row_min, int row_max, int col_min, int col_max){
    row = row_max - row_min;
    column = col_max - col_min;
    size = row * column;
    world.resize(row);
    world.SetLowerLimit(row_min);
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(column);
        world[i].SetLowerLimit(col_min);
    }
}

World::World(int row_min, int row_max, int col_min, int col_max, int obstacle_percentage, bool automatic_obstacle){ // inicializamos un mundo con obstaculos colocados aleatoriamente
    row = row_max - row_min;
    column = col_max - col_min;
    size = row * column;
    world.resize(row);
    world.SetLowerLimit(row_min);
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(column);
        world[i].SetLowerLimit(col_min);
    }

    int obstacle_quantity = size * obstacle_percentage / 100;
    if(automatic_obstacle == true){
        srand(time(NULL)); 
        for(int i = 0; i < obstacle_quantity; i++) {

            int random_row = rand()%(world.GetUpperLimit() - world.GetLowerLimit()) + world.GetLowerLimit();
            int random_col = rand()%(world[random_row].GetUpperLimit() - world[random_row].GetLowerLimit()) + world[random_row].GetLowerLimit();

            SetWorldState('O', random_row, random_col);
            SetWorldValue(true, random_row, random_col);
        }
    }
    else {
        int x, y;
        for(int i = 0; i < obstacle_quantity; i++) {
            do {
                std::cout << "Introduzca la coordenada X del obstaculo " << i+1 << " : ";
                std::cin >> x;
                while ((x < 0) || (x > row_max * 2 - 1)) {
                    std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << row_max * 2 - 1 << std:: endl;
                std::cin >> x;
                }

                std::cout << "Introduzca la coordenada Y del obstaculo " << i+1 << " : ";
                std::cin >> y;
                while ((y < 0) || ( y > col_max * 2 - 1)) {
                    std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << col_max * 2 - 1 << std:: endl;
                    std::cin >> y;
                }
                
            } while (GetWorldValue(x, y) == true); //mientras la casilla ya esté ocupada

            x += row_min;
            y += col_min;
            SetWorldState('O', x, y);
            SetWorldValue(true, x, y);
        }
    }
}



//Destructor

World::~World(){
}


//Getters y Setters

char World::GetWorldState(int i, int j) {
    return world[i][j].state;
}

bool World::GetWorldValue(int i, int j) {
    try{
       return world[i][j].value; 
    }
    
    catch(...){
        throw std::exception();
    }
}

void World::SetRow(int row_) {
    row = row_;
}

void World::SetColumn(int column_) {
    column = column_;
}

void World::SetSize(int size_) {
    size = size_;
}

void World::SetWorldState(char state_, int i, int j) {
    world[i][j].state = state_;
}

void World::SetWorldValue(bool value_, int i, int j) {
    world[i][j].value = value_;
}

void World::ToggleWorldValue(int i, int j){
    
   if(world[i][j].value == false){
        world[i][j].value = true;
   }
   else {
        world[i][j].value = false;
   }  
}


void World::SetWorld(Vector<Vector<Cell>>& new_world){

    world.resize(new_world.GetSize());
    world.SetLowerLimit(new_world.GetLowerLimit());

    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(new_world[i].GetSize());
        world[i].SetLowerLimit(new_world[i].GetLowerLimit());
        for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++){
            world[i][j] = new_world[i][j];
        }
    }
}

void World::PrintWorld(void) {
    PrintHorizontalWall();
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++) {
        std::cout << "|";
        for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++) {
            std::cout <<  GetWorldState(i,j) ;
        }
        std::cout << "|" << std::endl;
    }
    PrintHorizontalWall();
}

void World::PrintHorizontalWall(void) {   
    for(int i = world[0].GetLowerLimit(); i < world[0].GetUpperLimit() + 2; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

/*void World::Update(std::vector<Vehicle>& vehicle) {

    for(int i = 0; i < vehicle.size(); i++) {
        if ((GetWorldValue(vehicle[i].GetRow(), vehicle[i].GetColumn())) == false){ // casilla blanca
            SetWorldValue(true, vehicle[i].GetRow(), vehicle[i].GetColumn());
        }
        else {
            SetWorldValue(false, vehicle[i].GetRow(), vehicle[i].GetColumn()); //casilla negra
        } 
    }
}
*/

void World::PrintGrid(Vehicle* vehicle){
    PrintHorizontalWall();
        for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++) {
            std::cout << "|";
            for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++) {
                if((i == vehicle->GetRow()) && (j == vehicle->GetColumn()))
                    vehicle->PrintDirection();
                else if ((i == vehicle->GetDestinationRow()) && (j == vehicle->GetDestinationColumn())){
                    std::cout << "\u2691";
                }
                else std::cout << GetWorldState(i,j);
            }
            std::cout << "|" << std::endl;
        }
    PrintHorizontalWall();
}

bool World::VehicleOut(Vehicle* vehicle) {
    bool condition = false;
    if((vehicle->GetRow() >= world.GetUpperLimit()) || (vehicle->GetColumn() >= world.GetUpperLimit()) || (vehicle->GetRow() < world.GetLowerLimit()) || (vehicle->GetColumn() < world.GetLowerLimit()))
        condition = true;
    return condition;
}

void World::TryPosition(Vehicle* vehicle){
    try{
        Cell temp;
        temp = GetCell(vehicle->GetRow(), vehicle->GetColumn());
    }
    catch(std::exception()){
        std::cout << "el taxi se ha salido del mundo!!!" << std::endl;
        throw(std::exception());
    }
}

std::vector<int> World::Dijkstra(int origen_x, int origen_y) {
    int size = GetSize();
    int** graph = Adjacency_Graph_4(size, GetRow());
    std::vector<int> dist, visitado;
    dist.resize(size);
    visitado.resize(size);
    int origen = origen_x + GetRow() * origen_y;
    int u = 0;
    for (int v = 0; v < size; v++) {
        dist[v] = INFINITY;
        visitado[v] = false;
    }
    dist[origen] = 0;
    for (int v = 0; v < size - 1; v++) {
        u = extraer_min(dist, visitado);
        visitado[u] = true;
        for (int v = 0; v < GetSize(); v++) {
            if (!visitado[v] && graph[u][v] && (dist[u] != INFINITY) && (dist[u] + graph[u][v < dist[v]])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int** World::Adjacency_Graph_4(int size, int width) {
    int** graph = new int * [size];
    for (int i = 0; i < size; i++)
        graph[i] = new int [size];
    
    for (int i = 0; i < size; i++) {
        graph[i][i] = 0;
        if (i + 1 < size) graph[i][i + 1] = 1;
        if (i - 1 >= 0) graph[i][i - 1] = 1;
        if (i - width >= 0) graph[i][i - width] = 1;
        if (i + width < size) graph[i][i + width] = 1;
    }
    return graph;
}

int World::extraer_min(std::vector<int> dist, std::vector<int> visit) {
    int min = INFINITY, min_index;
    for (int v = 0; v < dist.size(); v++) {
        if ((dist[v] < min) && (!visit[v])) 
            min = dist[v], min_index = v;
    }
    return min_index;
}