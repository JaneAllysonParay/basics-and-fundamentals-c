/* Paray, Jane Allyson L. | IT2C | Inteprog
This program is all about the Exercise: Basics and Fundamentals of C++*/

#include <iostream> // Header file for input and output in C++
#include <limits> // Limits the number being accepted
#include <string> // For string manipulation 
using namespace std; // For convenience and easy use of 'cin','cout', and other names 

// Validation for user's input (empty or not a digit)
bool isNumber(const string& input){
    if (input.empty()) {
        return false;}
    for(int i = 0; i < input.length(); i++){ // 
        if(!isdigit(input[i])){
            return false;
        }
    }
    return true;
}

// Validation for user's input (number)
int validElement(){
    string element;
    while(true){
        cin >> element;
        if(isNumber(element)){
            return stoi(element); // string to integer conversion to be able to read the string type number as integer
        }
        else{
           cout << "Invalid input! Enter a valid integer (numbers only): ";
        }
    }
}

// Validation for user's input (number of elements between 1 to 10)
int validSize(){
    string sizeStr;
    while(true){
        cin >> sizeStr;
        if(isNumber(sizeStr)){
            int size = stoi(sizeStr); // string to integer conversion to be able to read the string type number as integer
            if (size >=1 && size <= 10){
                return size;
            }
        }
        
           cout << "Invalid input! Enter a number between 1 and 10 only: ";
           cin.clear(); // Clears the input buffer
           cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores wrong input dynamically
        
    }
}

// Function for merging arrayss
void mergedArray(int size1, int size2, int mergedArr[], int arr1[], int arr2[]){
    //First array 
    for(int i = 0; i < size1; i++){
        mergedArr[i] = arr1[i];
    }
    //First array merged with second array
    for(int i = 0; i < size2; i++){
        mergedArr[size1 + i] = arr2[i];
    }

}

//Function for sorting the merged array (descending order)
void sortArray(int mergedSize, int mergedArr[]){
        for(int i = 0; i < mergedSize - 1; i++){
        for(int j = 0; j < (mergedSize - i - 1); j++){
             if(mergedArr[j] < mergedArr[j+1]){
                int temp = mergedArr[j];
                mergedArr[j] = mergedArr[j+1];
                mergedArr[j+1] = temp;
            }
        } 
    }

}

// Function for displaying arrays
void displayArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main (){
    char choice; //Initialization for repeating of program

    do{
    int size1, size2; // Initialization of size of elements
    int arr1[10], arr2[10], mergedArr[20]; // Initialization of arrays
    
    // Program Name
    cout << "\n\t\t\t Sorted Merged Arrays \n\n";

    cout << "Enter the number of element(s) for first array (between 1 and 10): ";
    size1 = validSize(); // Calls the function validSize for inputting of element sizes for 1st array

    //Allows users to input elements for the 1st array
    cout << " \nEnter " << size1 << " element(s) for first array";
    for(int i = 0; i < size1; i++){ 
        cout << "\nElement " << i+1 << ": "; 
        arr1[i] = validElement();
    }

    cout << "\nEnter the number of element(s) for second array: ";
    size2 = validSize(); // Calls the function validSize for inputting of element sizes for 2nd array

    
    //Allows users to input elements for the 2nd array
    cout << "\nEnter " << size2 << " element(s) for second array";
    for(int i = 0; i < size2; i++){ 
        cout << "\nElement " << i+1 << ": "; 
        arr2[i] =  validElement();
    }

    // Adding of sizes of both arrays for merging
    int mergedSize = size1 + size2;
    mergedArray(size1, size2, mergedArr, arr1, arr2);  //Calls the mergedArray function 

    // Displays the merged arrays
    cout << "\n---------------------------------\n\n"; // divider for readability
    cout << "The merged array is: ";
    displayArray(mergedArr, mergedSize);

    sortArray(mergedSize, mergedArr); // Calls the sortedArray function

    // Displays the sorted array in descending order
    cout << "\n---------------------------------\n\n"; // divider for readability
    cout << "The descending order of the element(s) is: ";
    displayArray(mergedArr,mergedSize);

    //While loop for repeating or exiting the program 
    while(true){
        cout << "\n---------------------------------\n\n"; // divider for readability
        cout << "Merge and sort another array again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'Y' || choice == 'N'){
            break;
        } 
        cout << "Invalid input. Please choose only from 'Y' or 'N.";
        cin.clear(); // Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores wrong input dynamically
    } 
    } while (choice == 'Y'); // Repeats the whole program

    cout << "Program exited successfully. Thank you!"; //Exit message
    
    // new comment 
    return 0; 
}