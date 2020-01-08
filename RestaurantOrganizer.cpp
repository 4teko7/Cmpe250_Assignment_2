/*
Student Name:Bilal Tekin
Student Number:2017400264
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;
bool equality(int tableCapacity[],int &leftIndex,int &topIndex,int &rightIndex,int &leftChild,int &topChild,int &rightChild,int heap[]);
bool check(int tableCapacity[],int &leftIndex,int &topIndex,int &rightIndex,int heap[],int numTables);
void right(int tableCapacity[],int &index,int heap[]);
void left(int tableCapacity[],int &index,int heap[]);
RestaurantOrganizer::RestaurantOrganizer(const vector<int> &tableCapacityInput) {
    numberOfTables = tableCapacityInput.size();
    for (int i = 0; i < numberOfTables; i++) {
        tableCapacity[i] = tableCapacityInput[i];

        heap[i] = i;
        heapUp(i);
    }

}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream &outFile) {
    // IMPLEMENT ME!
    if (tableCapacity[0] < groupSize) {
        outFile << -1 << endl;
        return;
    } else {
        tableCapacity[0] = tableCapacity[0] - groupSize;
        outFile << heap[0] << endl;
        heapDown(0);
    }
}

void RestaurantOrganizer::heapUp(int index) {
    // IMPLEMENT ME!
    if (index == 0)
        return;

    while (index > 0) {
        int parentElement = (index - 1) / 2;
        if (tableCapacity[index] > tableCapacity[parentElement]) {
            int temp = tableCapacity[index];
            tableCapacity[index] = tableCapacity[parentElement];
            tableCapacity[parentElement] = temp;
            int tempIndex = heap[index];
            heap[index] = heap[parentElement];
            heap[parentElement] = tempIndex;
            index = parentElement;
        } else if (tableCapacity[index] == tableCapacity[parentElement]) {
            if (heap[index] > heap[parentElement]) {
                break;
            } else {
                int temp = tableCapacity[index];
                tableCapacity[index] = tableCapacity[parentElement];
                tableCapacity[parentElement] = temp;
                int tempIndex = heap[index];
                heap[index] = heap[parentElement];
                heap[parentElement] = tempIndex;
                index = parentElement;
            }
        } else {
            break;
        }
    }


}

void RestaurantOrganizer::heapDown(int index) {
    // IMPLEMENT ME!

    while (index * 2 + 1 < numberOfTables) {

        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;

        if(!check(tableCapacity, leftIndex, index, rightIndex, heap, numberOfTables)){
            return;
        }

    }
}

void RestaurantOrganizer::printSorted(ofstream &outFile) {
    // IMPLEMENT ME!

    for (int index = 0; index < numberOfTables; index++) {
        outFile << tableCapacity[0] << ' ';
        tableCapacity[0] = -1;
        heapDown(0);
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS

void right(int tableCapacity[],int &index,int heap[]){
    int temp = tableCapacity[index];
    tableCapacity[index] = tableCapacity[index * 2 + 2];
    tableCapacity[index * 2 + 2] = temp;
    int tempIndex = heap[index];
    heap[index] = heap[index * 2 + 2];
    heap[index * 2 + 2] = tempIndex;
    index = index * 2 + 2;
}
void left(int tableCapacity[],int &index,int heap[]){
    int temp = tableCapacity[index];
    tableCapacity[index] = tableCapacity[index * 2 + 1];
    tableCapacity[index * 2 + 1] = temp;
    int tempIndex = heap[index];
    heap[index] = heap[index * 2 + 1];
    heap[index * 2 + 1] = tempIndex;
    index = index * 2 + 1;
}
bool check(int tableCapacity[],int &leftIndex,int &topIndex,int &rightIndex,int heap[],int numTables){
    int leftChild = tableCapacity[leftIndex];
    int rightChild;
    if(rightIndex >= numTables){
        rightChild = -2;
    }else{
        rightChild = tableCapacity[rightIndex];
    }
    int topChild = tableCapacity[topIndex];
    if(topChild > leftChild && topChild > rightChild)
        return false;
    if(leftChild > topChild && leftChild > rightChild){
        left(tableCapacity,topIndex,heap);
    }else if(rightChild > topChild && rightChild > leftChild){
        right(tableCapacity,topIndex,heap);
    }else{

       return equality(tableCapacity,leftIndex,topIndex,rightIndex,leftChild,topChild,rightChild,heap);
    }
    return true;
}
bool equality(int tableCapacity[],int &leftIndex,int &topIndex,int  &rightIndex,int &leftChild,int &topChild,int &rightChild,int heap[]){
    if(topChild == leftChild && topChild == rightChild){
        if(heap[topIndex] < heap[rightIndex] && heap[topIndex] < heap[leftIndex]) return false;
        else if(heap[leftIndex] < heap[rightIndex]) left(tableCapacity,topIndex,heap);
        else if(heap[leftIndex] > heap[rightIndex]) right(tableCapacity,topIndex,heap);
    }else if(topChild == leftChild){
        if(heap[topIndex] < heap[leftIndex]) return false;
        else left(tableCapacity,topIndex,heap);
    }else if(topChild == rightChild){
        if(heap[topIndex] < heap[rightIndex]) return false;
        else right(tableCapacity,topIndex,heap);
    }else if(leftChild == rightChild){
        if(heap[leftIndex] < heap[rightIndex]) left(tableCapacity,topIndex,heap);
        else right(tableCapacity,topIndex,heap);
    }
    return true;
}
