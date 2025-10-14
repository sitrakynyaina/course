#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int partition(vector<int> &arr,int startPos,int endPos){
    int pivot = arr[startPos];
    int currentPos = startPos;
    int temp;
    for(int i = startPos + 1;i <= endPos;i++){
        if (arr[i] < pivot){
            currentPos += 1 ;
            temp = arr[i];
            arr[i] = arr[currentPos];
            arr[currentPos] = temp;
        }
    }
    temp = arr[currentPos];
    arr[currentPos] = arr[startPos];
    arr[startPos] = temp;
    return currentPos;
}

int quickSort(vector<int> &arr,int startPos,int endPos){
    if(startPos < endPos){

        int pivotPos = partition(arr,startPos,endPos);
        quickSort(arr,startPos,pivotPos - 1);
        quickSort(arr,pivotPos + 1,endPos);
    }
}

int minDiff(vector<int> &arr,int length){
    quickSort(arr,0,length - 1);
    int j = 0;
    int minDist = abs(arr[0] - arr[1]);
    for(int i = 0;i < length - 1;i++){
        int currentDist = abs(arr[i] - arr[i + 1]);
        j = minDist >  currentDist ?  i:j;
        minDist = minDist >  currentDist ?  currentDist:minDist;
    }
    return minDist;

}

int main(int argc,char** argv){
    int N;
    vector<int> powers;
    //if input testcase is in file.Put the filepath as argument of the script
    if(argv[1] != NULL){
        ifstream input(argv[1]);
        if(input){
            string nb;
            int i = 0;
            getline(input,nb);
            N = stoi(nb);
            cout<<"N = "<<N<<endl;
            while(i < N){
                getline(input,nb);
                powers.push_back(stoi(nb));
                i++;
            }
            cout<<minDiff(powers,N);
        }
        else{
            cout<<"Erreur de l'ouverture du fichier";
        }
    }
    else{
        cout<<"Entrez le nombre de test"<<endl;
        cin>>N;
        for(int i = 0;i < N;i++){
            int input;
            cout<<"Entrer la valeur de la force:"<<endl;
            cin>>input;
            powers.push_back(input);
        }
        cout<<minDiff(powers,powers.size());
    }
}
