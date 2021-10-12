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
    col = 10;
    size = 100;
    world = Vector<Vector<Cell>> (-10,10);
    for(int i = 0; i < 10; i++) {
        world[i].resize(10);
    }
}

World::World(int row_, int col_) {

    row = row_, col = col_;

    if (row % 2 == 0) row_max = row / 2 - 1;
    else row_max = row / 2;
    row_min = row / -2;

    if (col % 2 == 0) col_max = col / 2 - 1;
    else col_max = col / 2;
    col_min = col / -2;

    size = row * col;
    world.resize(row);
    world.SetLowerLimit(row_min);
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(col);
        world[i].SetLowerLimit(col_min);
    }
}

World::World(int row_, int col_, int obstacle_percentage, bool automatic_obstacle){ // inicializamos un mundo con obstaculos colocados aleatoriamente
    
    row = row_, col = col_;

    if (row % 2 == 0) row_max = row / 2 - 1;
    else row_max = row / 2;
    row_min = row / -2;

    if (col % 2 == 0) col_max = col / 2 - 1;
    else col_max = col / 2;
    col_min = col / -2;

    size = row * col;
    world.resize(row);
    world.SetLowerLimit(row_min);
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++) {
        world[i].resize(col);
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
    try {
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
    col = column_;
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

std::pair<std::vector<int>, std::vector<int>> World::Dijkstra(int origen) {
    std::vector<std::vector<int>> graph = Adjacency_Graph_4();
    std::vector<int> dist(size, __INT_MAX__);
    std::vector<int> prev(size, 0);
    std::vector<bool> visit(size, false);
    
    dist[origen] = 0;
    
    for (int i = 0; i < size; i++) {
        int u = extraer_min(dist, visit);
        visit[u] = true;
        for (int v = 0; v < size; v++) {
            if (!visit[v] && graph[u][v] && dist[u] != __INT_MAX__
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    return std::pair<std::vector<int>, std::vector<int>> (dist, prev);
}

std::vector<std::vector<int>> World::Adjacency_Graph_4() {
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    
    for (int i = 0; i < size; i++) graph[i].resize(size);
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            graph[i][j] = 0;

    for (int i = 0; i < size; i++) {
        int x = i % row;
        int y = (i - x) / row;
        x -= row / 2;
        y -= col / 2;
        if (i + 1 < size && x + 1 <= row_max) if (!GetWorldValue(x + 1, y)) 
            graph[i][i + 1] = 1;
        if (i - 1 >= 0 && x - 1 >= row_min) if (!GetWorldValue(x - 1, y)) 
            graph[i][i - 1] = 1;
        if (i - row >= 0 && y - 1 >= col_min) if (!GetWorldValue(x, y - 1)) 
            graph[i][i - row] = 1;
        if (i + row < size && y + 1 <= col_max) if (!GetWorldValue(x, y + 1)) 
            graph[i][i + row] = 1;
    }

    return graph;
}

std::vector<std::vector<int>> World::Adjacency_Graph_8() {
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    
    for (int i = 0; i < size; i++) graph[i].resize(size);
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            graph[i][j] = 0;

    for (int i = 0; i < size; i++) {
        int x = i % row;
        int y = (i - x) / row;
        x -= row / 2;
        y -= col / 2;
        if (i + 1 < size && x + 1 <= row_max) if (!GetWorldValue(x + 1, y)) 
            graph[i][i + 1] = 1;
        if (i - 1 >= 0 && x - 1 >= row_min) if (!GetWorldValue(x - 1, y)) 
            graph[i][i - 1] = 1;
        if (i - row >= 0 && y - 1 >= col_min) if (!GetWorldValue(x, y - 1)) 
            graph[i][i - row] = 1;
        if (i + row < size && y + 1 <= col_max) if (!GetWorldValue(x, y + 1)) 
            graph[i][i + row] = 1;
        if (i + 1 + row < size && x + 1 <= row_max && y + 1 <= col_max) if (!GetWorldValue(x + 1, y + 1)) 
            graph[i][i + 1 + row] = 1;
        if (i - 1 + row < size && x - 1 >= row_min && y + 1 <= col_max) if (!GetWorldValue(x - 1, y + 1)) 
            graph[i][i - 1 + row] = 1;
        if (i + 1 - row >= 0 && x + 1 <= row_max && y - 1 <= col_min) if (!GetWorldValue(x + 1, y - 1)) 
            graph[i][i + 1 - row] = 1;
        if (i - 1 - row >= 0 && x - 1 <= row_min && y - 1 <= col_min) if (!GetWorldValue(x - 1, y - 1)) 
            graph[i][i - 1 - row] = 1;
    }

    return graph;
}

int World::extraer_min(std::vector<int> dist, std::vector<bool> visit) {
    int min = __INT_MAX__, min_index;
    for (unsigned int v = 0; v < dist.size(); v++) {
        if (dist[v] <= min && visit[v] == false)
            min = dist[v], min_index = v;
    }
    return min_index;
}