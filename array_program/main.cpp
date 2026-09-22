#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    ifstream file("datasets/facility_a.csv");

    if (!file.is_open()){
        cout << "Failed to open dataset." << endl;
        return 1;
    }

    cout << "Dataset opened successfully!" << endl;

    string line;
     // Skip the first line because it is the column header
    getline(file, line);

    // Read the first patient
    getline(file, line);

    // Put the whole row into stringstream
    stringstream ss(line);

    string patientID;
    string age;
    string careType;
    string lengthOfStay;
    string baseCostPerHour;
    string daysVisitsPerYear;

    // Split at every comma
    getline(ss, patientID, ',');
    getline(ss, age, ',');
    getline(ss, careType, ',');
    getline(ss, lengthOfStay, ',');
    getline(ss, baseCostPerHour, ',');
    getline(ss, daysVisitsPerYear, ',');

    cout << "Patient ID: " << patientID << endl;
    cout << "Age: " << age << endl;
    cout << "Care Type: " << careType << endl;
    cout << "Length of Stay: " << lengthOfStay << endl;
    cout << "Base Cost Per Hour: " << baseCostPerHour << endl;
    cout << "Days Visits Per Year: " << daysVisitsPerYear << endl;

    file.close();

    return 0;
}