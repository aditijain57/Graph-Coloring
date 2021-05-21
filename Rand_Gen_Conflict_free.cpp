#include<iostream>
#include <list>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

class Chromatic{
private:
    int v;
    list <int> *adj;
public:
    Chromatic(int vertices){
    v=vertices;
    adj=new list<int>[v];
    }
    ~Chromatic(){
       delete []adj;
    }

    void addEdge(int p, int q);
    bool isUnique(vector<int>);
    int chromaticNumber();

};

   void Chromatic::addEdge(int p,int q){

        adj[p].push_back(q);
        adj[q].push_back(p);

   }

   bool Chromatic::isUnique(vector<int> vect){

       for(int i=0;i<vect.size(); i++) {
           int countr=0;
         for(int j=0;j<vect.size(); j++){

              if(vect[i]!=vect[j]){
                   countr++;
              }

         }
             if(countr==(vect.size()-1)){
                  return true;
             }

       }

        return false;
   }

   int Chromatic::chromaticNumber(){

           int answer[v];
           for(int i=0;i<v;i++){
               answer[i]=0;
           }
           bool availableColor[v];
           for(int i=0;i<v;i++){
            availableColor[i]=false;
           }
           for(int u=0;u<v;u++){

              list<int>::iterator i;
              vector<int> vect;
              vect.push_back(answer[u]);
            for(i = adj[u].begin(); i != adj[u].end(); ++i){
                vect.push_back(answer[*i]);
            }
            if(!isUnique(vect)){
                 list<int>::iterator j;
            for(j= adj[u].begin(); j != adj[u].end(); ++j){
                     availableColor[answer[*j]] = true;

            }
            int cr;
               for (cr = 0; cr < v; cr++){
                  if (availableColor[cr] == false)
                        break;
               }
               answer[u]=cr;
            }
             for (i = adj[u].begin(); i != adj[u].end(); ++i){
                availableColor[answer[*i]] = false;
             }

           }

           int maximum=0;

        for(int i=0;i<v;i++){
            if(answer[i]>maximum)
                maximum=answer[i];
        }
        return maximum;

   }
    int main(){
       int number;
        int N=6;
        Chromatic graph1(N);
  int arr[N][2];
   srand(time(0));
  for(int i=0;i<N;i++){
    int num1,num2;
    num1=(1+(rand()%10));
    num2=(1+(rand()%10));
    if(num1!=num2){
    num1=min(num1,num2);
    num2=max(num1,num2);
    arr[i][0]=num1;
    arr[i][1]=num2;
    }
    else if(num1==num2){
         i--;
    }
    }
     for(int i=0;i<N;i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
     }
        cout << "Set of Edges : " ;
     for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){
             if(i==j){
                continue;
             }
             else if(arr[i][0]<=arr[j][1] && arr[j][0]<=arr[i][1]){
                graph1.addEdge(i,j);
                cout << "(" << i << "," << j << ")" ;
             }


        }


     }
    number=graph1.chromaticNumber();
    cout<< endl;
    cout<<"Conflict free chromatic number of given graph is "<<number+1<<endl;
    return 0;
   }

