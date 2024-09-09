// C++ program to read from a file 
#include <fstream> 
#include <iostream> 
#include <string> 
using namespace std; 

void printMattrix(double matrix[400][12], int row, int column){
    //int row, column;
    for (int i = 0; i < 40; i++) { 
        for (int j = 0; j < 11; j++) { 
            cout << matrix[i][j] << "     "; 
        } 
        cout << endl; 
    } 
    
}

double getPercentage(int row, int column){
    
    ifstream inputFile("z_chart copy.txt"); 

	// Check if the file is successfully opened 
	if (!inputFile.is_open()) { 
		cout << "Error opening the file!" << endl; 
		return 1; 
	} 

    double zValue;
    double matrix [400][12];
    int m = 0,  n = 0;
	while (inputFile >> zValue) { 
        matrix[n][m] = zValue;
        m++;
        if(m == 11){
            m = 0;
            n++;
        }
	} 

	inputFile.close(); 

    double percentageOfZ;

    percentageOfZ = matrix[row][column];
    return percentageOfZ * 100;
}

double findZ(double mean, double standardDeviation, double rawScore){
    double z;
    z = (rawScore - mean) / standardDeviation;
    return z;
}

int getRow(double z){
    int row;
    z = abs(z);
    row = z * 10 + 1;
    return row;
}

int getColumn(double z){
    int column, modifiedZ;
    z = abs(z);
    modifiedZ = z * 100;
    column = (modifiedZ % 10) + 1;
    return column;
}
bool checkParity(double z){
    bool ifNeg = 0;
    if (z < 0){
        ifNeg = true;
    }
    return ifNeg;
}

double getRange(){
    double mean, standardDeviation, lowerBound, upperBound, lowerZ, upperZ, lowerPercentage, upperPercentage;
    int lowerRow, lowerColumn, upperRow, upperColumn;
    double totalPercentage;
    cout << "Enter Mean:";
    cin >> mean;
    cout << endl << "Enter Standard Deveation:";
    cin >> standardDeviation;
    cout << endl << "Enter Lower Bound of Range:";
    cin >> lowerBound;
    cout << endl << "Enter Upper Bound of Range:";
    cin >> upperBound;

    lowerZ = findZ(mean, standardDeviation, lowerBound);
    cout << lowerZ;
    cout << lowerZ;

    upperZ = findZ(mean, standardDeviation, upperBound);
    cout << upperZ;
    cout << upperZ;

    lowerRow = getRow(lowerZ);
    upperRow = getRow(upperZ);

    lowerColumn = getColumn(lowerZ);
    upperColumn = getColumn(upperZ);

    lowerPercentage = getPercentage(lowerRow, lowerColumn);
    upperPercentage = getPercentage(upperRow, upperColumn);

    if(checkParity(lowerZ)){
        if(checkParity(upperZ)){
            totalPercentage = lowerPercentage - upperPercentage;
            return totalPercentage;
        }
    }

    if(!checkParity(lowerZ)){
        if(!checkParity(upperZ)){
            totalPercentage = upperPercentage - lowerPercentage;
            return totalPercentage;
        }
    }

    totalPercentage = upperPercentage + lowerPercentage;
    return totalPercentage;

}

int main() 
{ 

    double mean, standardDeviation, rawScore;
    int row, column, modifiedZ;
    double z, percentageOfZ;
/*
    cout << "Enter raw score: ";
    cin >> rawScore;
    cout << "Enter mean: ";
    cin >> mean;
    cout << "Enter standard deviation: ";
    cin >> standardDeviation;
    z = findZ(mean, standardDeviation, rawScore);
    row = getRow(z);
    column = getColumn(z);
    cout << endl << "z" << z << endl;
    percentageOfZ = getPercentage(row, column);
    cout << "perc" << percentageOfZ << endl;
    //cout << "TEST:    " << percentageOfZ << endl;
    if(checkParity(z)){
        percentageOfZ = 50 - percentageOfZ;
    }
    cout << "perc2" << percentageOfZ << endl;

    bool ifNeg;

    ifNeg = checkParity(z);

    
    
    cout << "z: " << z;
    cout << endl << "mod z: " << modifiedZ;
   
    cout << endl << "row: " << row;
    cout << endl << "column: " << column << endl;
    cout << "if Neg: " << ifNeg << endl;
	

*/
    int userChoice;
    char continueLoop = 'T';
    while(continueLoop == 'T'){
    cout << "press 1 for range, 2 for area greater than, 3 for area less than, 0 to exit";
    cin >> userChoice;
        switch (userChoice) {
        case 1:
            cout << "RANGE:" << endl;
            cout << getRange();
            break;
        case 2:
            cout << "greaterthan";
            break;
        case 3:
            cout << "less than";
            break;
        case 0:
            cout << "Exiting";
            continueLoop = 'F';
            break;
        default:
            cout << "ERROR";
            break;
        }
    }
}
