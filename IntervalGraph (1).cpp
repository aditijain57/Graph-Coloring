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
    return 0;
   }
