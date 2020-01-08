/*
Student Name:
Student Number:
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    // IMPLEMENT ME!
}

void RestaurantOrganizer::heapUp(int index){
    // IMPLEMENT ME!
}

void RestaurantOrganizer::heapDown(int index){
    // IMPLEMENT ME!
}

void RestaurantOrganizer::printSorted(ofstream& outFile){
    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS

