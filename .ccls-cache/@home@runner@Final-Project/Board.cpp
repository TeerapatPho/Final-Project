#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

#include "Board.h"
#include "Function.h"

board::board(int map)
{
    // generate graph;
    //แก้ไขระยะห่างระหว่างสถานที่ แก้แค่เลขหลังสุดตัวเดียว
    //ถ้าอยากเพิ่มเหลี่ยมให้คนเดินลัดสนามหญ้าก็เพิ่มเอาได้เลย
    //การ addEdge ก็เหมือนเราเพิ่มถนนให้มัน ถ้าเราไม่ได้ต้องการถนนสายตรงไป 0-4 ก็ไม่ต้องมีก้ได้
    if (map == 1) {
        addEdge("Cluckers", "Gym", 1);
        addEdge("Gym", "Lousy Housing", 1);
        addEdge("Lousy Housing", "Market", 1);
        addEdge("Market", "Fancy Housing", 1);
        addEdge("Fancy Housing", "Bank", 1); //เช่น Fancy House-Bank ระยะทาง 1
        addEdge("Bank", "VexCorp", 1);
        addEdge("VexCorp", "Job Office", 1);
        addEdge("Job Office", "Culture Center", 1);
        addEdge("Culture Center", "University", 1);
        addEdge("University", "Appliance Store", 1);
        addEdge("Appliance Store", "Mall", 1);
        addEdge("Mall", "Cluckers", 1);
    }
    else if(map == 2) {
        
    }
    
   
}

board::~board()
{
    cout << "Destructed Board" << endl;
}

void board::addEdge(string u_name, string v_name, int distance)
{ //อันนี้ไว้สำหรับ สร้างแผนที่ในกราฟ
    int u = get_plIndex(u_name);
    int v = get_plIndex(v_name);

    graph[u].push_back(make_pair(v, distance));
    graph[v].push_back(make_pair(u, distance));
    // cout << graph[u].back().first << " " << graph[u].back().second;
    // cout << graph[v].back().first << " " << graph[v].back().second;
}
int **board::graph2matrix(vector<pair<int, int>> graph[])
{ //เปลี่ยนกราฟให้กลายเป็น matrix ทางคณิตศาสตร์
    int **arr = 0;
    arr = new int *[12];

    for (int v = 0; v < 12; ++v)
    {
        arr[v] = new int[12];
        for (int i = 0; i < 12; i++)
            arr[v][i] = 0;
        for (int i = 0; i < graph[v].size(); i++)
            arr[v][graph[v][i].first] = graph[v][i].second;
        // for(int i = 0; i < 12; i++)
        //     cout << arr[v][i] << " ";
        // cout << endl;
    }

    /* อันนี้หน้าตาตัวอย่าง matrix
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
{ // ส่วนอันนี้ใช้ Dijsktra's algorithm ในการคำนวณหาระยะทาง
    // Dijsktra's algorithm
    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/ อันนี้เว็บที่ก็อปมา
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
{ //ส่วนอันนี้ boilerplate เฉยๆ แค่จี้เกียจพิมพ์อันด้านล่างยาวๆอ่ะ
    return cal_distance(graph2matrix(graph), start, stop);
}

void board::print_board(string present_place, int energy)
{
    for (int i = 0; i < 110; i++)
        cout << "=";
    cout << endl;
    cout << "|     Cluckers     |          |       Gym        |          |   Lousy Housing  |          |      Market      |" << endl;
    if (present_place == "Cluckers")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "Gym")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "Lousy Housing")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "Market")
        cout << "|        x         |" << endl;
    else
        cout << "|                  |" << endl;
    for (int i = 0; i < 110; i++)
        cout << "=";
    cout << endl;
    cout << "|       Mall       |                         Energy : " << setw(3) << energy;
    cout << "                                 |   Fancy Housing  |" << endl;
    if (present_place == "Mall")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "                                                                      ";
    if (present_place == "Fancy Housing")
        cout << "|        x         |" << endl;
    else
        cout << "|                  |" << endl;
    cout << "====================                                                                      ====================" << endl;
    cout << "|  Appliance Store |                  Now you are at " << setw(20) << present_place;
    cout << "                 |       Bank       |" << endl;
    if (present_place == "Appliance Store")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "                                                                      ";
    if (present_place == "Bank")
        cout << "|        x         |" << endl;
    else
        cout << "|                  |" << endl;
    for (int i = 0; i < 110; i++)
        cout << "=";
    cout << endl;
    cout << "|    University    |          |  Culture Center  |          |    Job Office    |          |      VexCorp     |" << endl;
    if (present_place == "University")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "Culture Center")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "Job Office")
        cout << "|        x         |";
    else
        cout << "|                  |";
    cout << "          ";
    if (present_place == "VexCorp")
        cout << "|        x         |" << endl;
    else
        cout << "|                  |" << endl;
    for (int i = 0; i < 110; i++)
        cout << "=";
    cout << endl;
}
