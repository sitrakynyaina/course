#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int startPos, int endPos)
{
    int pivot = arr[startPos];
    int currentPos = startPos;
    int temp;
    for (int i = startPos + 1; i <= endPos; i++)
    {
        if (arr[i] < pivot)
        {
            currentPos += 1;
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

int quickSort(vector<int> &arr, int startPos, int endPos)
{
    if (startPos < endPos)
    {

        int pivotPos = partition(arr, startPos, endPos);
        quickSort(arr, startPos, pivotPos - 1);
        quickSort(arr, pivotPos + 1, endPos);
    }
}

int minDiff(vector<int> &arr, int length)
{
    if arr.size()  < 2:
        return 0;
    quickSort(arr, 0, length - 1);
    int j = 0;
    int minDist = abs(arr[0] - arr[1]);
    for (int i = 0; i < length - 1; i++)
    {
        int currentDist = abs(arr[i] - arr[i + 1]);
        j = minDist > currentDist ? i : j;
        minDist = minDist > currentDist ? currentDist : minDist;
    }
    return minDist;
}

int main()
{
    int N;
    vector<int> powers;
    cout << "Entrez le nombre de test" << endl;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cout << "Entrer la valeur de la force:" << endl;
        cin >> input;
        powers.push_back(input);
    }
    cout << minDiff(powers, powers.size());
}
