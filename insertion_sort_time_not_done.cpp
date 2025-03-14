#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

void insertion_sort(int arr[], int length);

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(nullptr));
    const int length = 100;
    int arr[length];
    int iterations = 1000;
    int counter = 1;
    double time[1000][100];
    int column_counter = 0;

    // Abre un archivo para escribir los tiempos
    ofstream outFile("execution_times.csv");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }

    for (int j = 10; j < length; j+=10){
        for (int i = 0; i < iterations; i++) {
            // Genera un arreglo de numeros aleatoreos del 1 al 1000 de longitud lenght
            cout << "Valor de j: " << j << endl;
            for (int k = 0; k < j; k++) {
                arr[k] = 1 + rand() % 1000;
                cout << arr[k] << endl;
            }
            cout << endl;


            // Inicia el timer
            auto start = high_resolution_clock::now();

            insertion_sort(arr, j);

            // Termina el timer
            auto end = high_resolution_clock::now();


            duration<double> duration = end - start;

            time[i][column_counter] = duration.count() * 1000;


            cout << "Tiempo run " << counter << ": " << fixed << setprecision(6) << time[i][column_counter] << " segundos" << endl;

            //outFile << "Tiempo run " << counter << ": " << fixed << setprecision(6) << time[i][column_counter] << " segundos" << endl;

            counter++;
        }
        column_counter++;
        counter = 0;
    }

    for (int i = 0; i < length; i++){
        for (int j = 0; j < 100; j++){
            outFile << fixed << setprecision(6) <<  time[i][j] << ",";
        }
        cout << endl;
    }



    outFile.close();

    return 0;
}

void insertion_sort(int arr[], int length) {
    /*
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    */

    for (int i = 1; i < length; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
           arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    /*
    cout << endl;

    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
    */
}
