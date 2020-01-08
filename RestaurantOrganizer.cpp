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

    while ((index * 2 + 1 < numberOfTables) && (tableCapacity[index] <= tableCapacity[index * 2 + 1] ||
                                                tableCapacity[index] <= tableCapacity[index * 2 + 2])) {


        if(tableCapacity[index * 2 + 1] > tableCapacity[index] && tableCapacity[index*2+2] > tableCapacity[index]){

            if(tableCapacity[index*2+1] > tableCapacity[index*2+2]){
                left(tableCapacity,index,heap);
            }else if(tableCapacity[index*2+1] < tableCapacity[index*2+2]){
                right(tableCapacity,index,heap);
            }else{
                if(heap[index*2+1] < heap[index*2+2]){
                    left(tableCapacity,index,heap);
                }else{
                    right(tableCapacity,index,heap);
                }
            }
        }else if(tableCapacity[index*2+1] > tableCapacity[index] && tableCapacity[index*2+1] > tableCapacity[index * 2 + 2]) {
            left(tableCapacity,index,heap);
        }else if(tableCapacity[index*2+2] > tableCapacity[index] && tableCapacity[index*2+2] > tableCapacity[index * 2 + 1]){
            right(tableCapacity,index,heap);

        }else if(tableCapacity[index*2+1] == tableCapacity[index] || tableCapacity[index*2+2] == tableCapacity[index]){
            if(tableCapacity[index*2+1] == tableCapacity[index] && tableCapacity[index*2+2] == tableCapacity[index]){
                if(heap[index * 2 + 1] < heap[index * 2 + 2]){
                    if(heap[index * 2 + 1] < heap[index]){
                        left(tableCapacity,index,heap);
                    }else{
                        return;
                    }
                }else if(heap[index * 2 + 2] < heap[index * 2 + 1]){
                    if(heap[index*2+2] < heap[index]){
                        right(tableCapacity,index,heap);
                    }else{
                        return;
                    }
                }
            }else if(tableCapacity[index*2+1] == tableCapacity[index] && heap[index * 2 + 1] < heap[index]){
                left(tableCapacity,index,heap);
            }else if(tableCapacity[index*2+2] == tableCapacity[index] && heap[index * 2 + 2] < heap[index]){
                right(tableCapacity,index,heap);
            }else{
                return;
            }

        }else{
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