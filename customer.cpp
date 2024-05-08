#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime> // For getting current date

using namespace std;


class Customer {
public:
  // Data
  string name;
  string email;
  string address;
  string phone;
  char sex;
  string purchaseType; // Car or Bike
  string carModel;    // Valid car model (if purchaseType is Car)
  string bikeModel;   // Valid bike models (if purchase type is bike)

  
  bool validatePhone(const string& phoneNumber) {
    if (phoneNumber.length() != 10) {
      return false; 
    }
    for (char c : phoneNumber) {
      if (!isdigit(c)) {
        return false; 
      }
    }
    return true; 
  }
  bool validateName(const string& name){
    for (char c : name) {
        if (isdigit(c)) {
            return false; 
        }
    }
    return true; 
}

  void getDetails() {
    cout << "\nEnter Customer Details:\n";
    do{
        cout<<"Name : ";
        getline(cin,name);
        if (!validateName(name)) {
        cout << "Invalid name format. Please enter a valid name."<<endl;
      }
    }while(!validateName(name));
    cout << "Email: ";
    getline(cin, email);
    cout << "Address: ";
    getline(cin, address);
    do {
      cout << "Phone Number: ";
      getline(cin, phone);
      if (!validatePhone(phone)) {
        cout << "Invalid phone number format. Please enter a 10-digit phone number." << endl;
      }
    } while (!validatePhone(phone)); 
    do {
      cout << "Sex (M/F): ";
      cin >> sex;
      cin.ignore(); 
    } while (toupper(sex) != 'M' && toupper(sex) != 'F');
    do {
      cout << "Purchase Type (Car/Bike): ";
      getline(cin, purchaseType);
      for (char &c : purchaseType) {
        c = toupper(c); 
      }
    } while (purchaseType != "CAR" && purchaseType != "BIKE");

    if (purchaseType == "CAR") {
      selectCarModel();
    } else if (purchaseType == "BIKE") {
      selectBikeModel(); 
    }
  }

private:
  void selectCarModel() {
    const string validCarModels[] = {"tiago", "altroz", "tigor", "nexon", "safari", "harrier", "hexa", "punch"};
    int modelNumber;

    cout << "Available Car Models:\n";
    for (int i = 1; i <= 7; ++i) {
      cout << i << ". " << "TATA " << validCarModels[i - 1] << endl; 
    }
    cout << "Enter the number corresponding to your car model choice: ";

    do {
     cin>>modelNumber;
      try {
        if (modelNumber >= 1 && modelNumber <= 7) {
          carModel = validCarModels[modelNumber - 1]; 
          break;
        } else {
          cout << "Invalid car model selection. Please enter a number between 1 and "
               << 7 << ": ";
        }
      } catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a valid number." << endl;
      }
    } while (true);
  }

  void selectBikeModel() {
    cout << "Available Rivian Bike Models:\n";
    cout << "1. Rivian XPulse 200" << endl;
    cout << "2. Rivian Hunter 350" << endl;
    cout << "3. Rivian Pulsar NS160" << endl;
    cout << "4. Rivian RT400" << endl;
    cout << "Enter the number corresponding to your Rivian bike model choice: ";

    int modelNumber;
    do {
      cin >> modelNumber;
      if (cin.fail() || modelNumber < 1 || modelNumber > 4) {
        cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        cin.clear();
        cin.ignore(10000, '\n'); 
      } else {
        break;
      }
    } while (true);

    cin.ignore(); 

    switch (modelNumber) {
      case 1:
        selectXPulseSubOptions();
        break;
      case 2:
        selectHunterSubOptions();
        break;
      case 3:
        selectPulsarSubOptions();
        break;
      case 4:
        selectRT400SubOptions();
        break;
      default:
        cout << "Invalid bike model selection." << endl;
        break;
    }
  }

    void selectXPulseSubOptions() {
        cout << "Sub-options for Rivian XPulse 200:\n";
        cout << "1. Standard" << endl;
        cout << "2. Premium" << endl;
        cout << "Enter the number corresponding to your choice: ";

        int subOption;
        do {
            cin >> subOption;
            if (cin.fail() || (subOption != 1 && subOption != 2)) {
                cout << "Invalid input. Please enter either 1 or 2 : ";
                cin.clear();
                cin.ignore(10000, '\n'); 
            } else {
                break;
            }
        } while (true);

        cin.ignore(); 

        if (subOption == 1) {
            bikeModel = "Rivian XPulse 200 Standard";
        } else if (subOption == 2) {
            bikeModel = "Rivian XPulse 200 Premium";
        }
    }

    void selectHunterSubOptions() {
        cout << "Sub-options for Rivian Hunter 350:\n";
        cout << "1. Metro Dapper" << endl;
        cout << "2. Metro Rebel" << endl;
        cout << "3. Retro Factory" << endl;
        cout << "Enter the number corresponding to your choice: ";

        int subOption;
        do {
            cin >> subOption;
            if (cin.fail() || (subOption < 1 || subOption > 3)) {
                cout << "Invalid input. Please enter a number between 1 and 3 : ";
                cin.clear();
                cin.ignore(10000, '\n'); 
            } else {
                break;
            }
        } while (true);

        cin.ignore(); 
        if (subOption == 1) {
            bikeModel = "Rivian Hunter 350 Metro Dapper";
        } else if (subOption == 2) {
            bikeModel = "Rivian Hunter 350 Metro Rebel";
        } else if (subOption == 3) {
            bikeModel = "Rivian Hunter 350 Retro Factory";
        }
    }

    void selectPulsarSubOptions() {
        cout << "Sub-options for Rivian Pulsar NS160:\n";
        cout << "1. Single ABS" << endl;
        cout << "2. Dual ABS" << endl;
        cout << "3. Bluetooth" << endl;
        cout << "Enter the number corresponding to your choice: ";

        int subOption;
        do {
            cin >> subOption;
            if (cin.fail() || (subOption < 1 || subOption > 3)) {
                cout << "Invalid input. Please enter a number between 1 and 3 : ";
                cin.clear();
                cin.ignore(10000, '\n'); 
            } else {
                break;
            }
        } while (true);

        cin.ignore(); 

        if (subOption == 1) {
            bikeModel = "Rivian Pulsar NS160 Single ABS";
        } else if (subOption == 2) {
            bikeModel = "Rivian Pulsar NS160 Dual ABS";
        } else if (subOption == 3) {
            bikeModel = "Rivian Pulsar NS160 Bluetooth";
        }
    }

    void selectRT400SubOptions() {
        cout << "Sub-options for Rivian RT400:\n";
        cout << "1. BRZ" << endl;
        cout << "2. Premium" << endl;
        cout << "3. Stealth Black Edition" << endl;
        cout << "Enter the number corresponding to your choice: ";

        int subOption;
        do {
            cin >> subOption;
            if (cin.fail() || (subOption < 1 || subOption > 3)) {
                cout << "Invalid input. Please enter a number between 1 and 3." << endl;
                cin.clear();
                cin.ignore(10000, '\n'); 
            } else {
                break;
            }
        } while (true);

        cin.ignore(); 

        if (subOption == 1) {
            bikeModel = "Rivian RT400 BRZ";
        } else if (subOption == 2) {
            bikeModel = "Rivian RT400 Premium";
        } else if (subOption == 3) {
            bikeModel = "Rivian RT400 Stealth Black Edition";
        }
  }

};

int main() {
  ofstream customerDetailsFile("customer_details.txt", ios::app); 
  ofstream customerSummaryFile("customer_summary.txt", ios::app); 

  if (!customerDetailsFile.is_open()) {
    cerr << "Error opening customer_details.txt file!" << endl;
    return 1;
  }

  if (!customerSummaryFile.is_open()) {
    cerr << "Error opening customer_summary.txt file!" << endl;
    return 1;
  }
  char choice;
  do {
    Customer customer; 
    customer.getDetails(); 
    
    time_t now = time(0);   
    tm* localTime = localtime(&now); 
    customerDetailsFile << "################### THE CUSTOMER SUMMARY #################\n";
    customerDetailsFile << "NAME: " << customer.name << endl;
    customerDetailsFile << "PHONE NUMBER: " << customer.phone << endl;
    customerDetailsFile << "EMAIL: " << customer.email << endl;
    customerDetailsFile << "ADDRESS: " << customer.address << endl;
    customerDetailsFile << "SEX: " << customer.sex << endl;
    customerDetailsFile << "PURCHASE TYPE: " << customer.purchaseType << endl;
    if (customer.purchaseType == "CAR") {
      customerDetailsFile << "CAR MODEL: " << customer.carModel << endl;
    } else {
      customerDetailsFile << "BIKE MODEL: " << customer.bikeModel << endl;
    }
    // Write current date in format "DD-MM-YYYY"
    customerDetailsFile << "DATE: " << setfill('0') << setw(2) << localTime->tm_mday << "-"
                        << setfill('0') << setw(2) << (localTime->tm_mon + 1) << "-"
                        << localTime->tm_year + 1900 << endl; // Add 1900 for correct year
    customerDetailsFile << "###########################################\n\n";
    customerSummaryFile << left << setw(20) << "Name:" << customer.name << endl;
    customerSummaryFile << left << setw(20) << "Phone:" << customer.phone << endl;
    customerSummaryFile << left << setw(20) << "Email:" << customer.email << endl << endl;

    cout << "\nCustomer details added successfully.\n";
    cout << "Do you want to add another customer record (Y/N)? ";
    
    cin >> choice;
    cin.ignore(); 
  } while (toupper(choice) == 'Y');
  customerDetailsFile.close();
  customerSummaryFile.close();
  return 0;
}