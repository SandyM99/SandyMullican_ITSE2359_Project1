#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Declare vectors for storing student data
    vector<string> names;
    vector<int> ages;
    vector<float> gpas;

    // Open the file for reading
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string name;
    int age;
    float gpa;

    // Read the data into the parallel vectors
    while (infile >> name >> age >> gpa) {
        names.push_back(name);
        ages.push_back(age);
        gpas.push_back(gpa);
    }

    infile.close();

    // Variables for calculations
    float totalGPA = 0;
    float highestGPA = numeric_limits<float>::min();
    int youngestAge = numeric_limits<int>::max();
    int oldestAge = numeric_limits<int>::min();
    vector<string> highestGPAStudents;
    vector<string> youngestStudents;
    vector<string> oldestStudents;

    // Calculate the average GPA and find the highest GPA and oldest/youngest students
    for (size_t i = 0; i < gpas.size(); ++i) {
        totalGPA += gpas[i];

        if (gpas[i] > highestGPA) {
            highestGPA = gpas[i];
            highestGPAStudents.clear();
            highestGPAStudents.push_back(names[i]);
        } else if (gpas[i] == highestGPA) {
            highestGPAStudents.push_back(names[i]);
        }

        if (ages[i] < youngestAge) {
            youngestAge = ages[i];
            youngestStudents.clear();
            youngestStudents.push_back(names[i]);
        } else if (ages[i] == youngestAge) {
            youngestStudents.push_back(names[i]);
        }

        if (ages[i] > oldestAge) {
            oldestAge = ages[i];
            oldestStudents.clear();
            oldestStudents.push_back(names[i]);
        } else if (ages[i] == oldestAge) {
            oldestStudents.push_back(names[i]);
        }
    }

    // Output the results
    cout << "Average GPA: " << totalGPA / gpas.size() << endl;

    cout << "Highest GPA (" << highestGPA << "): ";
    for (const auto& student : highestGPAStudents) {
        cout << student << " ";
    }
    cout << endl;

    cout << "Youngest Student(s) (Age " << youngestAge << "): ";
    for (const auto& student : youngestStudents) {
        cout << student << " ";
    }
    cout << endl;

    cout << "Oldest Student(s) (Age " << oldestAge << "): ";
    for (const auto& student : oldestStudents) {
        cout << student << " ";
    }
    cout << endl;

    return 0;
}
