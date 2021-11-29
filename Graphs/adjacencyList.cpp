#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj_list[], const int& node1, const int& node2){
    
    // We need to add an edge b/w node1 & node2
    adj_list[node1].push_back(node2);
    adj_list[node2].push_back(node1);

}

void displaySingleList(const vector<int> list){

    for(auto i=list.begin() ; i!=list.end() ; i++){

        if(i != list.end() - 1) cout << *i << " -> ";
        else cout << *i << "\n"; 
    }
}

void displayList(const vector<int> adj_list[], const int& nodeCount){

    for(int i=0 ; i<nodeCount ; i++){
        cout << i << ": ";
        displaySingleList(adj_list[i]);
    }
}

int main()
{
    int nodeCount;
    cout << "Number of nodes in the graph: ";
    cin >> nodeCount;

    // we need an array of vectors
    vector<int>* adj_list = new vector<int>[nodeCount];

    char input;
    
    do{
        int node1, node2;
        cin >> node1 >> node2;
        addEdge(adj_list, node1, node2);
        cout << "Do you want to add another edge? (Y/N): ";
        cin >> input;

    }while(input == 'Y' | input == 'y');

    displayList(adj_list, nodeCount);
}