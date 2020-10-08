#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define PI 3.14159


using namespace std;

int main(void)
{
	//declaring variables
	double OD;
	double ID;
	double thickness;
	string customername;
	double density;
	double shipweight;
	double shipcost;
	int shiptype;
	int quantity;
	double areaID;
	double areaOD;
	double radius;
	double rimarea;
	double unitweight;
	
	//prompts the user for the dimensions

	cout << "Enter customer name: ";
	getline(cin, customername);
	cout << "Enter the inner diameter in centimeters: " ;
	cin >> ID;
	cout << "Enter the outer diameter in centimeters: ";
	cin >> OD;
	cout << "Enter the thickness in centimeters: ";
	cin >> thickness;
	cout << "Enter the material density in grams per cubic centimeter: " ;
	cin >> density;
	cout << "Enter the quantity ordered: ";
	cin >> quantity;
	cout << "Do you want expedited shipping (1 for yes, 0 for no): ";
	cin >> shiptype;
	cout << "\n";

	//calculate weight and other dimensions of washer
	double IDr=ID/2;
	double ODr=OD/2;
	areaID = PI * (IDr * IDr);
	areaOD = PI * (ODr * ODr);
	rimarea = areaOD - areaID;
	unitweight = rimarea * thickness * density;
	shipweight = unitweight * quantity;
	shipcost = shipweight * (1.15 / 20);

	//output cost depending on whether or not shipping is expedited

	cout << "Customer:" << customername << endl;
	cout << "The shipping weight is " << fixed << setprecision(2) << shipweight << " grams." << endl;
	if (shiptype == 1)
	{
		shipcost += 20;
		cout << "The shipping cost is $" << fixed << setprecision(2) << shipcost << "." << endl;
		cout << "Shipping speed: expedited." << endl;
		
	}
	else
	{
		cout << "The shipping cost is $" << fixed << setprecision(2) << shipcost << "." << endl;
	}

	ofstream outputFile;
	outputFile.open("shippingLabel.txt");
	outputFile << "SHIPPING LABEL" << endl;
	outputFile << "Customer:" << customername << endl;
	outputFile << "The shipping weight is " << fixed << setprecision(2) << shipweight << " grams." << endl;
	
	if (shiptype == 1)
	{
		shipcost += 20;
		outputFile<< "The shipping cost is $" << fixed << setprecision(2) << shipcost << "." << endl;
		outputFile << "Shipping speed: expedited." << endl;
	}
	else
	{
		outputFile << "The shipping cost is $" << fixed << setprecision(2) << shipcost << "." << endl;
	}

	outputFile.close();

	return 0;
}
