#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node {
    string countryName;
    bool visited;
    vector<string> adj;
};
int main(){
    cout << "HOW MANY COUNTRY DO YOU WISH TO ENTER : \n";
    int number;
    cin >> number;
    vector<Node> countryList;
    cout << "ENTER COUNTRY:\n";
    int tempNumber = number;
    while(tempNumber--){
        string name; cin >> name;
        Node country;
        country.countryName = name;
        country.visited=1;
        countryList.push_back(country);
    }
    tempNumber = number;
    cout << "How many relations are there:\n";
    int tempnumber;
    cin >> tempnumber;
    cout << "Enter the pair of relations:\n";
    for(int i = 0;i< tempnumber;i++){
        string name_a,name_b;
        cin >> name_a>>name_b;
        for(int k=0;k<number;k++){
            if(name_a==countryList[k].countryName){
                countryList[k].adj.push_back(name_b);
            }
            if(name_b==countryList[k].countryName){
                countryList[k].adj.push_back(name_a);
            }
        }
    }
    cout << "CHOOSE THE COUNTRY FROM WHERE YOU WANT TO START YOUR JOURNEY\n";
    string chosenCountry;
    cin >> chosenCountry;
    /*
    for(int i =0; i<number ; i++){
        cout << countryList[i].countryName <<endl;
        for(int j = 0;j<countryList[i].adj.size();j++){
            cout << countryList[i].adj[j] << " ";
        }
        cout << endl;
    }*/
    queue<Node> queueNodes;
    for( int i=0 ; i < number;i++){
        if(chosenCountry == countryList[i].countryName) {
            countryList[i].visited = 0;
            queueNodes.push(countryList[i]);
            break;
        }
    }
    while(!queueNodes.empty()){
        Node temp;
        temp = queueNodes.front();
        queueNodes.pop();
        int k =0;
        for( k=0;k<tempNumber;k++){
            if(countryList[k].countryName == temp.countryName) {
                break;
            }
        }
        int size = countryList[k].adj.size();

        for( int l = 0; l < size ;l++){
            for(int p = 0; p<tempNumber ; p++){
                if(countryList[p].visited !=0){
                    if(countryList[p].countryName == countryList[k].adj[l]){
                        countryList[p].visited = 0;
                        queueNodes.push(countryList[p]);
                    }
                }
            }
        }
    }
    cout << "List of connected countries are :\n";
    for(int i=0;i<tempNumber;i++) {
        if (countryList[i].visited == 0 && countryList[i].countryName != chosenCountry)
            cout << countryList[i].countryName << endl;
    }
    return 1;
}
/*
10
Greenland
China
India
Pakistan
Iran
Bangladesh
Turkey
USA
Canada
Thailand
8
India China
Bangladesh Thailand
Pakistan India
USA Canada
Turkey Iran
Pakistan Iran
Pakistan Turkey
Bangladesh India
*/