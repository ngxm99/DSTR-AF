#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Patient{
    string patientID;
    int age;
    string careType;
    int lengthOfStay;
    double baseCostPerHour;
    int daysVisitsPerYear;
};

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

    Patient patient;

    string age;
    string lengthOfStay;
    string baseCostPerHour;
    string daysVisitsPerYear;

    // Split at every comma
    getline(ss, patient.patientID, ',');
    getline(ss, age, ',');
    getline(ss, patient.careType, ',');
    getline(ss, lengthOfStay, ',');
    getline(ss, baseCostPerHour, ',');
    getline(ss, daysVisitsPerYear, ',');

    patient.age = stoi(age);
    patient.lengthOfStay = stoi(lengthOfStay);
    patient.baseCostPerHour = stod(baseCostPerHour);
    patient.daysVisitsPerYear = stoi(daysVisitsPerYear);

    cout << "Patient ID: " << patient.patientID << endl;
    cout << "Age: " << patient.age << endl;
    cout << "Care Type: " << patient.careType << endl;
    cout << "Length of Stay: " << patient.lengthOfStay << endl;
    cout << "Base Cost Per Hour: " << patient.baseCostPerHour << endl;
    cout << "Days Visits Per Year: " << patient.daysVisitsPerYear << endl;
    file.close();

    return 0;
}