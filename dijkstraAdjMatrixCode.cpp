#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n)
{
    int minVertex = -1; // initially no vertex
    // scan all array and keep the minimum one
    //  but to be the candidate of being minimum it should not have been visited

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            // for the first time whatever be the case we assign it, without comparision
            // otherwise compare
            minVertex = i;
        }
    }

    return minVertex;
}

void visualise(int i, int * distance)
{
    cout << i << distance[0];
}
void dijkstra(int **edges, int n)
{
    /*information we need to have, of every vertices
        1. Wether that vertex is visited or not
            array of boolean
        2. The distance of the vertex from the source
    */

    int *distance = new int[n]; // distance
    bool *visited = new bool[n];

    // initially every distance will be infinity
    // and every vertex not visited
    // except for the source vertex

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    int sourceVertex;
    cout << "Enter the Source Vertex : " ;
    cin >> sourceVertex; 
    distance[sourceVertex] = 0; // except for the source vertex

    // now we will pick the minimum and start exploring it

    for (int i = 0; i < n - 1; i++)
    { //(n-1) as there won't be neighbours to the last vertex

        int minVetex = findMinVertex(distance, visited, n); // finding the minimum vertex whose distance form source is min
        visited[minVetex] = true; // since we visited the minVertex
        // after we have the min vertex we will explore all its neighbours

        for (int j = 0; j < n; j++)
        {
            if (edges[minVetex][j] != 0 && !visited[j])
            {   // there is a edge and its not visited
                // then calculate the distance of this vertex via the min vertex
                int dist = distance[minVetex] + edges[minVetex][j];
                // now we will check if this distance is a better option for j or not
                if (dist < distance[j])
                {
                    distance[j] = dist; // better way to reach j
                }
            }
        }
    }
    cout << endl;
    cout << "############################# DISTANCE FROM THE SOURCE ##################" << endl << endl;
    for (int i = 0; i <n ; i++){
        cout << "Vertex " << i << " => " << distance[i] << " units" << endl;
        // i -> vertex no.
        // distance[i] -> the distance of the vertex;
    }

    cout << endl << "#########################################################################" << endl << endl;
    cout << endl;
    // visualising the Algorithm
    cout << "############################# VISUALISATION #############################" << endl << endl;
    for (int i = 0; i <n ; i++){
        int l = sourceVertex;
        cout << sourceVertex << " ";
        for (int k =0; k < distance[i]; k++){
            if(i == sourceVertex){
                break;
            }
            cout << "-->" ;
        }
        cout << " ";
        cout << i << " \n";
        
    }
    cout << endl << "#########################################################################" << endl << endl;
    delete []  visited;
    delete []  distance;
}
    int main()
    {
        cout << " " << endl;
        cout << "Enter the number of vertices follwed by number of edges" << endl;
        cout << "Followed by the f, s and weight of the corresponding graph  " << endl;
        cout << "For example :" << endl << endl;
        cout <<"5 7\n0 1 4\n0 2 8\n1 3 5\n1 2 2\n2 3 5\n2 4 9\n3 4 4\n" << endl <<endl;
        int n;
        int e;
        cin >> n >> e;

        // creating the adjacency matrix
        int **edges = new int *[n];
        for (int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < e; i++)
        {
            int f, s, weight;
            cin >> f >> s >> weight;
            edges[f][s] = weight;
            edges[s][f] = weight;
        }

        dijkstra(edges, n); // calling dijkstra on the adjacency matrix

        // deleting the memory
        for (int i = 0; i < n; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    }

/*
5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4
*/