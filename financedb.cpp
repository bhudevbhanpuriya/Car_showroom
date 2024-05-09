#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Base class for finance details
class Finance {
public:
    double calculateCost() ;
};

// Class for marketing costs
class Marketing : public Finance {
protected:
    double advertisingCost;
    double salesPromotionCost;

public:
    Marketing(double adCost, double promoCost) : advertisingCost(adCost), salesPromotionCost(promoCost) {}

    double calculateCost()  {
        return advertisingCost + salesPromotionCost;
    }
};

// Class for overheads
class Overheads : public Finance {
protected:
    double rent;
    double utilities;

public:
    Overheads(double rentCost, double utilitiesCost) : rent(rentCost), utilities(utilitiesCost) {}

    double calculateCost() const  {
        return rent + utilities;
    }
};

// Class for taxes
class Taxes : public Finance {
protected:
    double incomeTax;
    double salesTax;

public:
    Taxes(double incomeTaxAmount, double salesTaxAmount) : incomeTax(incomeTaxAmount), salesTax(salesTaxAmount) {}

    double calculateCost() {
        return incomeTax + salesTax;
    }
};

// Class for maintenance costs
class Maintenance : public Finance {
protected:
    double laborCost;
    double partsCost;

public:
    Maintenance(double labor, double parts) : laborCost(labor), partsCost(parts) {}

    double calculateCost()  {
        return laborCost + partsCost;
    }
};

// Class for logistic costs
class Logistics : public Finance {
protected:
    double transportationCost;
    double storageCost;

public:
    Logistics(double transport, double storage) : transportationCost(transport), storageCost(storage) {}

    double calculateCost()  {
        return transportationCost + storageCost;
    }
};

// Function to get user input for double value
double getDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            // Input is a valid double
            break;
        } else {
            // Clear input buffer to remove invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return value;
}

// Function to get user input for marketing costs
Marketing getMarketingInput() {
    double adCost = getDoubleInput("Enter advertising cost: Rs.");
    double promoCost = getDoubleInput("Enter sales promotion cost: Rs.");
    return Marketing(adCost, promoCost);
}

// Function to get user input for overheads
Overheads getOverheadsInput() {
    double rentCost = getDoubleInput("Enter rent cost: Rs");
    double utilitiesCost = getDoubleInput("Enter utilities cost: Rs");
    return Overheads(rentCost, utilitiesCost);
}

// Function to get user input for taxes
Taxes getTaxesInput() {
    double incomeTax = getDoubleInput("Enter income tax amount: Rs.");
    double salesTax = getDoubleInput("Enter sales tax amount: Rs.");
    return Taxes(incomeTax, salesTax);
}

// Function to get user input for maintenance costs
Maintenance getMaintenanceInput() {
    double labor = getDoubleInput("Enter labor cost: Rs.");
    double parts = getDoubleInput("Enter parts cost: Rs.");
    return Maintenance(labor, parts);
}

// Function to get user input for logistic costs
Logistics getLogisticsInput() {
    double transport = getDoubleInput("Enter transportation cost: Rs.");
    double storage = getDoubleInput("Enter storage cost: Rs.");
    return Logistics(transport, storage);
}

double getSalesData(double BikeSales, double CarSales, double Servicing, double Accessories, double spareparts, double Heavyvehicles){
    return BikeSales+CarSales+Servicing+Accessories+spareparts+Heavyvehicles;
}


bool isFileEmpty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

// Function to write output to a file in tabular form
void writeOutputToFile(double totalCost, double Marketingcost, double Overheads, double Taxes, double  Maintenance, double Logistics) {
    ofstream outputFile("expenditure_details.txt", ios::app);
    string filename = "expenditure_details.txt";
    if (outputFile.is_open() && isFileEmpty(filename)) {
        outputFile << "Marketing\tOverheads\tTaxes\tMaintenance\tLogistics\tTotal\n";
        outputFile << Marketingcost<<"\t\t"<<Overheads<<"\t\t"<< Taxes<<"\t\t\t"<< Maintenance<<"\t\t\t"<<Logistics<<"\t\t"<<totalCost << endl;
        outputFile.close();
        cout << "Expenditure details written to expenditure_details.txt" << endl;
    }
    else if (outputFile.is_open() && !isFileEmpty(filename)) {
        outputFile << Marketingcost<<"\t\t"<<Overheads<<"\t\t"<< Taxes<<"\t\t\t"<< Maintenance<<"\t\t\t"<<Logistics<<"\t\t"<<totalCost << endl;
        outputFile.close();
        cout << "Expenditure details written to expenditure_details.txt" << endl;
    } 
    else {
        cout << "Unable to open file for writing." << endl;
    }
}

void writeOutputToFile2(double totalsales,double  BikeSales, double CarSales, double Servicing, double Accessories, double spareparts, double Heavyvehicles) {
    ofstream outputFile("sales.txt", ios::app);
    string filename = "sales.txt";
    if (outputFile.is_open() && isFileEmpty(filename)) {
        outputFile << "Bikes \t Cars \t Heavy Vehicles \t Servicing \t Accessories \t Spare Parts \t Total Sales\n";
        outputFile << BikeSales<<"\t\t"<<CarSales<<"\t\t"<< Heavyvehicles<<"\t\t\t"<< Servicing<<"\t\t\t"<<Accessories<<"\t\t"<<spareparts<<"\t\t"<<totalsales<< endl;
        outputFile.close();
        cout << "Sales details written to sales.txt" << endl;
    }
    else if (outputFile.is_open() && !isFileEmpty(filename)) {
        outputFile << BikeSales<<"\t\t"<<CarSales<<"\t\t"<< Heavyvehicles<<"\t\t\t"<< Servicing<<"\t\t\t"<<Accessories<<"\t\t"<<spareparts<<"\t\t"<<totalsales << endl;
        outputFile.close();
        cout << "Expenditure details written to expenditure_details.txt" << endl;
    } 
    else {
        cout << "Unable to open file for writing." << endl;
    }
}

int inputInt(string n) {
    string n1=n;
    n1:
    cin.ignore(0,'\n');
    getline(cin,n1);
    int v = 0 , x=0 ,y=0;
    for(char i : n1) {
        if ((i >= '0' && i <= '9') || i=='.'){
            v = 1;
        } else {
            cout<<"Invalid input"<<endl;
            //v=0;
            break;
        }
    }

    while(v == 0) {
       goto n1;
    }

    
    int q = stoi(n1);


    return q;
    
}


int main() {
    cout << "Welcome Finance Database" << endl;
    
    while (true) {
        cout << "Please enter your choice:" << endl;
        cout << "1. Enter Expenditure" << endl;
        cout << "2. Enter Total Sales" << endl;
        cout << "3. Exit" << endl;
        
        string choice;
        int res =inputInt(choice);

        switch (res) {
            case 1: {
                Marketing marketing = getMarketingInput();
                Overheads overheads = getOverheadsInput();
                Taxes taxes = getTaxesInput();
                Maintenance maintenance = getMaintenanceInput();
                Logistics logistics = getLogisticsInput();

                double totalCost = marketing.calculateCost() + overheads.calculateCost() + taxes.calculateCost() + maintenance.calculateCost() + logistics.calculateCost();
                double Marketingcost = marketing.calculateCost();
                double OverheadsCost = overheads.calculateCost();
                double TaxesCost = taxes.calculateCost();
                double MaintenanceCost = maintenance.calculateCost();
                double LogisticsCost = logistics.calculateCost();

                writeOutputToFile(totalCost, Marketingcost, OverheadsCost, TaxesCost, MaintenanceCost, LogisticsCost);
                break;
            }
            case 2: {
                double BikeSales = getDoubleInput("Enter Bikes Sales : Rs.");
                double CarSales = getDoubleInput("Enter Car Sales : Rs.");
                double Servicing = getDoubleInput("Enter Servicing Sales: Rs.");
                double Accessories = getDoubleInput("Enter Accessories Sales: Rs.");
                double SpareParts = getDoubleInput("Enter Spare Parts Sales: Rs.");
                double HeavyVehicles = getDoubleInput("Enter Heavy Vehicles Sales : Rs.");
                double TotalSales = getSalesData(BikeSales, CarSales, Servicing, Accessories, SpareParts, HeavyVehicles);
                
                writeOutputToFile2(TotalSales, BikeSales, CarSales, Servicing, Accessories, SpareParts, HeavyVehicles);
                break;
            }
            case 3:
                cout << "Thank you for using the Finance Database" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
