#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

struct Tree
{
    int cost;

    vector <vector<int>> reducedMatrix;
    vector <int> visited;

    Tree *left;
    Tree *right;

};

Tree *root = NULL;

vector <vector <int>> adjMatrix =
{
        { INT_MAX, 10,  8,   9,   7 },
        { 10,  INT_MAX, 10,  5,   6 },
        { 8,   10,  INT_MAX, 8,   9 },
        { 9,   5,   8,   INT_MAX, 6 },
        { 7,   6,   9,   6,   INT_MAX }
};

Tree* create(int costOfNode)
{
    Tree *node = new Tree;

    node -> cost = costOfNode;
    node -> left = NULL;
    node -> right = NULL;
}

void display()
{
    for(int i=0; i<adjMatrix.size(); i++)
    {
        for(int j=0; j<adjMatrix.size(); j++)
        {
            cout<<adjMatrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void setInfinity(int nodeNumber, int row, int col)
{
//    for(int i=0; i<visited.size()-1; i++)
//    {
//        adjMatrix[nodeNumber][visited[i]] = INT_MAX;
//    }

    for(int j=0; j<row; j++)
    {
        adjMatrix[row][j] = INT_MAX;
    }

    for(int i=0; i<col; i++)
    {
        adjMatrix[i][col] = INT_MAX;
    }
}

int find_RowCol_Min()
{
    int minValue = INT_MAX;
    int rowMin = 0;
    int colMin = 0;

    for(int i=0; i<adjMatrix.size(); i++)
    {
        minValue = *min_element(adjMatrix[i].begin(),adjMatrix[i].end());

        if(minValue != 0 && minValue != INT_MAX)
        {
            for(int j=0; j<adjMatrix.size(); j++)
            {
                if(adjMatrix[i][j] != INT_MAX)
                {
                    adjMatrix[i][j] -= minValue;
                }
            }
        }
        else
        {
            minValue = 0;
        }

        rowMin += minValue;
    }

    for(int i=0; i<adjMatrix.size(); i++)
    {
        minValue = INT_MAX;

        for(int j=0; j<adjMatrix.size(); j++)
        {
            if(adjMatrix[j][i] < minValue)
            {
                minValue = adjMatrix[j][i];
            }
        }

        if(minValue != 0 && minValue != INT_MAX)
        {
            for(int j=0; j<adjMatrix.size(); j++)
            {
                if(adjMatrix[j][i] != INT_MAX)
                {
                    adjMatrix[j][i] -= minValue;
                }
            }
        }
        else
        {
            minValue = 0;
        }

        colMin += minValue;
    }

    return rowMin + colMin;
}

int main()
{
    int lowerBound = 0;

    display();

    cout<<find_RowCol_Min();



    return 0;
}
