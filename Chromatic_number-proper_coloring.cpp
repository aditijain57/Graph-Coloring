#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;

/* The following code calculates the chromatic number of a given graph using Greedy's approach.
This program only works for undirectional graphs given in a specific order, if the order changes the result may  vary from its original value.
In this program, control visits every vertex and checks if the any neighboring node has a different color than that node, if not it changes the color i.e
increase the value to another minimum number available(Greedy's approach).
*/


    class Graph //graph class containing the functions
    {
        int V;// V denotes the total number of the vertices in the graph
        list<int> *adj; // list to store the adjacent vertices
    public:

        Graph(int V)// constructor for intializing
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void Edges(int v, int w);// function to add more edges by giving a set of vertices(x,y)
        void greedyColoring();//function to color the vertices
    };

    void Graph::Edges(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void Graph::greedyColoring()
    {
        //the program initially gives all its vertices say, 0,1,2,3...one color that is say,1 from 1,2,3,4,... and then increases the number as we go
        //to different vertices according to the adjacency list. if say a vertex initially has 0 and we start and go to the next one,
        //we will (due to current situation) have 2 vertices of the same color. now we need to change the color of all the other vertices(except current).
        //Therefore now color of the arriving vertices is 1.We use a boolean function to see if color are same,if not bool value will come true else false
        //if false we assign new color to all the vertices by checking which is minimum next number starting with 1.
        //We repeat this process for all vertices.
        //Result compiling: This is done by creating an array 'result', where the index works like the vertex name and the element will have
        //the color number like 1,2,3... which when taken maximum of, will give the chromatic number of the graph.
        //Colors are taken from 1,2,3... and not from 0,1,2... because even for null graph minimum chromatic number is 1.
        int result[V];//result array
        for (int k = 0; k < V; k++)
            result[k] = 0;

        bool color[V];//false means that color is already assigned to an adjacent vertex
        for (int c = 0; c < V; c++)
            color[c] = false;


        for (int a = 1; a < V; a++)//Assigning next order color to the rest of the graph(V-1 vertices)
        {
            list<int>::iterator i;
            for (i = adj[a].begin(); i != adj[a].end(); ++i)
                if (result[*i] != 0)
                    color[result[*i]] = true;


            int cr;// checking if 1 is valid or not, if not, the new incremented value is assigned
            for (cr = 1; cr < V; cr++)
                if (color[cr] == false)
                    break;
            result[a] = cr;//assigning next order color

            for (i = adj[a].begin(); i != adj[a].end(); ++i)//setting value false to all for the loop
                if (result[*i] != 0)
                    color[result[*i]] = false;
        }
        //result compiling
        // finding the chromatic number by sorting the list into increasing order and finding the maximum value.
        int n = sizeof(result)/sizeof(result[0]);
        sort(result, result+n);
        cout<<*max_element(result,result + n)<<endl;
    }

    int main()
    {   //given graph
        //can add more edges and more objects of the class
        Graph graph(5);//graph with 5 vertices
        graph.Edges(0, 1);
        graph.Edges(1, 2);
        graph.Edges(1, 3);
        graph.Edges(2, 3);
        graph.Edges(2, 4);
        cout << "Chromatic number of graph 1 \n";
        graph.greedyColoring();

        return 0;
    }
