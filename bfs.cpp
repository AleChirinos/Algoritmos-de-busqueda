#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() 
{ 
    input; 
    int nodos,aristas; 
    cin>>nodos>>aristas;
    vector<int> grafo[nodos+1];

    for(int i=0;i<aristas;i++) {
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
   
   //Mostrar el grafo
    
    for(int i=1;i<=nodos;i++) {
        cout<<"{"<<(i)<<"}=>";
        for(int j=0;j<grafo[i].size();j++) {
            cout<<"["<<grafo[i][j]<<"]";
        }
        cout<<endl;
    }

    //Recorrido por BFS

    vector<bool> visitados(nodos);
    queue<int> colita;
    // O(V+E) 
    // O(V^2)
    int nodoActual = 1;
    visitados[nodoActual] = true; 
    colita.push(nodoActual);
    vector<int> level(nodos);
    level[nodoActual] = 0;
    while(!colita.empty()){
        int nodoActual = colita.front();
        colita.pop(); 
        for(int i=0;i<grafo[nodoActual].size();i++) {
            int nodoAVisitar = grafo[nodoActual][i];  
            if(!visitados[nodoAVisitar]) {
                colita.push(nodoAVisitar);
                visitados[nodoAVisitar] = true;
                level[nodoAVisitar] = level[nodoActual] + 1;
            }
        }
    }

    for(int i = 0 ; i<= nodos; i++  ) {
        cout<<"[" << visitados[i] <<"]" ;
    }

    if(visitados[7]){
        cout<<level[7]<<endl;
        cout<<"Coincidio"<<endl;
    } 
    else{
        cout<<"No coincidio"<<endl;
    }
    
    return 0; 
} 