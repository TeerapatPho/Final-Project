class board
{
    int distance;
    vector<pair<int, int>> graph[12];
    int type;

    /* graph method (undirectional weight graph) */
    void addEdge(string, string, int);
    int **graph2matrix(vector<pair<int, int>> graph[]);
    int cal_distance(int **G, string, string);
    
public:
    board(int);
    int get_board() { return type; }
    
    int get_plIndex(string);
    int cal_distance_template(string, string);
    

    void print_board(string, int);
};

board::board(int map)
{
    // generate graph;
    type = map;
    if (map == 1)
    {
        addEdge("Cluckers", "Gym", 1);
        addEdge("Gym", "Lousy Housing", 1);
        addEdge("Lousy Housing", "Market", 1);
        addEdge("Market", "Fancy Housing", 1);
        addEdge("Fancy Housing", "Bank", 1);
        addEdge("Bank", "VexCorp", 1);
        addEdge("VexCorp", "Job Office", 1);
        addEdge("Job Office", "Culture Center", 1);
        addEdge("Culture Center", "University", 1);
        addEdge("University", "Appliance Store", 1);
        addEdge("Appliance Store", "Mall", 1);
        addEdge("Mall", "Cluckers", 1);
    }
    else if (map == 2)
    {
        addEdge("Cluckers", "Gym", 2);
        addEdge("Gym", "Lousy Housing", 2);
        addEdge("Lousy Housing", "Market", 2);
        addEdge("Market", "Fancy Housing", 2);
        addEdge("Fancy Housing", "Bank", 2);
        addEdge("Bank", "VexCorp", 2);
        addEdge("VexCorp", "Job Office", 2);
        addEdge("Job Office", "Culture Center", 2);
        addEdge("Culture Center", "University", 2);
        addEdge("University", "Appliance Store", 2);
        addEdge("Appliance Store", "Mall", 2);
        addEdge("Mall", "Cluckers", 2);
    }
    else if (map == 3)
    {
        addEdge("Cluckers", "Gym", 0);
        addEdge("Gym", "Lousy Housing", 0);
        addEdge("Lousy Housing", "Market", 0);
        addEdge("Market", "Fancy Housing", 0);
        addEdge("Fancy Housing", "Bank", 0);
        addEdge("Bank", "VexCorp", 0);
        addEdge("VexCorp", "Job Office", 0);
        addEdge("Job Office", "Culture Center", 0);
        addEdge("Culture Center", "University", 0);
        addEdge("University", "Appliance Store", 0);
        addEdge("Appliance Store", "Mall", 0);
        addEdge("Mall", "Cluckers", 0);
    }
    else if (map == 4)
    {
        addEdge("VexCorp", "Mall", 1);
        addEdge("Mall","Gym", 1);
        addEdge("Gym", "Market", 1);
        addEdge("Market", "Lousy Housing", 1);
        addEdge("Lousy Housing", "Bank", 1);
        addEdge("Bank", "Cluckers", 1);
        addEdge("Cluckers", "Job Office", 1);
        addEdge("Job Office", "Fancy Housing", 1);
        addEdge("Fancy Housing", "University", 1);
        addEdge("University", "Appliance Store", 1);
        addEdge("Appliance Store", "Culture Center", 1);
    }
}

void board::addEdge(string u_name, string v_name, int distance)
{
    int u = get_plIndex(u_name);
    int v = get_plIndex(v_name);

    graph[u].push_back(make_pair(v, distance));
    graph[v].push_back(make_pair(u, distance));
}
int **board::graph2matrix(vector<pair<int, int>> graph[])
{
    int **arr = 0;
    arr = new int *[12];

    for (int v = 0; v < 12; ++v)
    {
        arr[v] = new int[12];
        for (int i = 0; i < 12; i++)
            arr[v][i] = 0;
        for (int i = 0; i < graph[v].size(); i++)
            arr[v][graph[v][i].first] = graph[v][i].second;
    }

    /* matrix example
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    */
    return arr;
}
int board::get_plIndex(string name)
{
    vector<string> v;
    for (auto &itr : plList)
        v.push_back(itr->get_name());

    return checkIndex_vector<string>(name, v);
}
int board::cal_distance(int **G, string start, string stop)
{
    // Dijsktra's algorithm
    int src = get_plIndex(start);
    int V = 12;

    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = numeric_limits<int>::max(), sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int min = numeric_limits<int>::max(), min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        int u = min_index;
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && G[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + G[u][v] < dist[v])
                dist[v] = dist[u] + G[u][v];
    }
    return dist[get_plIndex(stop)];
}
int board::cal_distance_template(string start, string stop)
{     return cal_distance(graph2matrix(graph), start, stop);
}

void board::print_board(string present_place, int energy)
{
    if (type == 1 || type == 2 || type == 3)
    {
        for (int i = 0; i < 110; i++)
            cout << "=";
        cout << endl;
        cout << "|     Cluckers     |          |       Gym        |          |   Lousy Housing  |          |      Market      |" << endl;
        if (present_place == "Cluckers")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "Gym")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "Lousy Housing")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "Market")
            cout << "|        " << RED << "x" << reset << "         |\n";
        else
            cout << "|                  |" << endl;
        for (int i = 0; i < 110; i++)
            cout << "=";
        cout << endl;
        cout << "|       Mall       |                         " << YEL << "Energy : " << setw(3) << energy << reset;
        cout << "                                 |   Fancy Housing  |" << endl;
        if (present_place == "Mall")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "                                                                      ";
        if (present_place == "Fancy Housing")
            cout << "|        " << RED << "x" << reset << "         |\n";
        else
            cout << "|                  |" << endl;
        cout << "====================                                                                      ====================" << endl;
        cout << "|  Appliance Store |                  " << BLU << "Now you are at " << setw(20) << present_place << reset;
        cout << "                 |       Bank       |" << endl;
        if (present_place == "Appliance Store")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "                                                                      ";
        if (present_place == "Bank")
            cout << "|        " << RED << "x" << reset << "         |\n";
        else
            cout << "|                  |" << endl;
        for (int i = 0; i < 110; i++)
            cout << "=";
        cout << endl;
        cout << "|    University    |          |  Culture Center  |          |    Job Office    |          |      VexCorp     |" << endl;
        if (present_place == "University")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "Culture Center")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "Job Office")
            cout << "|        " << RED << "x" << reset << "         |";
        else
            cout << "|                  |";
        cout << "          ";
        if (present_place == "VexCorp")
            cout << "|        " << RED << "x" << reset << "         |\n";
        else
            cout << "|                  |" << endl;
        for (int i = 0; i < 110; i++)
            cout << "=";
        cout << endl;
    }
    else if(type == 4) {
     
        cout << "\n";
        cout << "<--------("; ((present_place=="VexCorp") ? (cout << RED << "x" << reset) : (cout << "1"));
        cout << ")--------("; ((present_place=="Mall") ? (cout << RED << "x" << reset) : (cout << "2"));
        cout << ")--------("; ((present_place=="Gym") ? (cout << RED << "x" << reset) : (cout << "3"));
        cout << ")--------("; ((present_place=="Market") ? (cout << RED << "x" << reset) : (cout << "4"));
        cout << ")--------("; ((present_place=="Lousy Housing") ? (cout << RED << "x" << reset) : (cout << "5"));
        cout << ")--------("; ((present_place=="Bank") ? (cout << RED << "x" << reset) : (cout << "6"));
        cout << ")--------("; ((present_place=="Cluckers") ? (cout << RED << "x" << reset) : (cout << "7"));
        cout << ")--------("; ((present_place=="Job Ofiice") ? (cout << RED << "x" << reset) : (cout << "8"));
        cout << ")--------("; ((present_place=="Fancy Housing") ? (cout << RED << "x" << reset) : (cout << "9"));
        cout << ")--------("; ((present_place=="University") ? (cout << RED << "x" << reset) : (cout << "10"));
        cout << ")--------("; ((present_place=="Appliance Store") ? (cout << RED << "x" << reset) : (cout << "11"));
        cout << ")--------("; ((present_place=="Culture Center") ? (cout << RED << "x" << reset) : (cout << "12"));
        cout << ")-------->" << endl <<YEL<< "Energy : " << energy <<reset << endl <<BLU << "Now you are at " << present_place << reset << endl ;

        
        cout << endl;
        cout << "(1)  VexCorp" << endl;
        cout << "(2)  Mall" << endl;
        cout << "(3)  Gym" << endl;
        cout << "(4)  Market" << endl;
        cout << "(5)  Lousy Housing" << endl;
        cout << "(6)  Bank" << endl;
        cout << "(7)  Cluckers" << endl;
        cout << "(8)  Job Office" << endl;
        cout << "(9)  Fancy Housing" << endl;
        cout << "(10) University" << endl;
        cout << "(11) Appliance Store" << endl;
        cout << "(12) Culture Center" << endl;
    }
}