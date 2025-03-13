#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> // For high-resolution timing
#include <iomanip> // For std::fixed and std::setprecision
#include <fstream> // For file handling

using namespace std;
using namespace std::chrono;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    const int num_runs = 1000; // Number of runs
    const int array_size = 10; // Size of the array
    int arr[array_size];
    double total_time = 0.0; // Variable to store the total execution time

    // Open a file for writing
    ofstream outFile("execution_times.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }

    for (int k = 0; k < num_runs; k++) {
        // Generate random numbers between 1 and 1000
        for (int i = 0; i < array_size; i++) {
            arr[i] = rand() % 1000 + 1;
        }

        // Start measuring time
        auto start = high_resolution_clock::now();

        // Perform insertion sort
        insertionSort(arr, array_size);

        // Stop measuring time
        auto end = high_resolution_clock::now();

        // Calculate the duration in seconds
        duration<double> duration = end - start;
        double run_time = duration.count();

        // Add the current run's time to the total time
        total_time += run_time;

        // Print the execution time for this run in decimal notation
        cout << "Run " << k + 1 << ": " << fixed << setprecision(6) << run_time << " seconds" << endl;

        // Write the execution time to the file
        outFile << "Run " << k + 1 << ": " << fixed << setprecision(6) << run_time << " seconds" << endl;
    }

    // Write the total execution time to the file
    outFile << "Total execution time for " << num_runs << " runs: " << fixed << setprecision(6) << total_time << " seconds" << endl;

    // Close the file
    outFile.close();

    // Print the total execution time in decimal notation
    cout << "Total execution time for " << num_runs << " runs: " << fixed << setprecision(6) << total_time << " seconds" << endl;

    return 0;
}
