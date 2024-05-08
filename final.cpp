#include <bits/stdc++.h>
using namespace std;
#define MAX 20

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

    // int m = stoi(n);
    int q = stoi(n1);


    return q;
    
}

float inputFloat(string n) {
    string n1=n;
    n1:
    cout<<"Enter : ";
    cin.ignore(0,'\n');
    getline(cin,n1);
    int v = 0 ;
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
    // int m = stoi(n);
    float q = stof(n1);
    return q;
}

// Employee db

class Automobile {
protected:
    string Vehicletype;

public:
    Automobile(string type) : Vehicletype(type) {}
    friend class Employee;
    
};

class Employee {
private:
    string name;
    int id, age;
    int c, b, hv;
    string username;
    string password;
    vector<Automobile> cars;
    vector<Automobile> bikes;
    vector<Automobile> heavyvehicles;
    double salary; // Added member
public:
    Employee(string empName, int empId, string uname, string pwd, int age) : name(empName), id(empId), username(uname), password(pwd), age(age), c(0), hv(0), b(0), salary(0) {} // Initialized salary
    void addCar(Automobile car) {
        cars.push_back(car);
        c++;
        updateSalary();
    }
    void addBike(Automobile bike) {
        bikes.push_back(bike);
        b++;
        updateSalary();
    }
    void addHeavyVehicle(Automobile heavyVehicle) {
        heavyvehicles.push_back(heavyVehicle);
        hv++;
        updateSalary();
    }
    void updateEmployeeDetails(Employee &emp);
    void writeEmployeeDataToFile() {
        ofstream file("employee_data.txt", ios::out);
        if (!(age >= 65 || age <= 20)) {
            file << "Name: " << name << endl;
            file << "ID: " << id << endl;
            file << "Age: " << age << endl;
            file << "Salary: " << salary << endl; // Added salary to file output
            file << "Automobiles:" << endl;
            file << "Cars: " << c << endl;
            file << "Bikes: " << b << endl;
            file << "Heavy Vehicle: " << hv << endl;
            file.close();
        }
    }
    void displayInfo() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Employee Age: " << age << endl;
        cout << "Employee Salary: " << salary << endl; // Display salary
        for (int i = 0; i < cars.size(); i++) {
            cout << "Car " << i + 1 << " - Type: " << cars[i].Vehicletype << endl;
        }
        for (int j = 0; j < bikes.size(); j++) {
            cout << "Bike " << j + 1 << " - Type: " << bikes[j].Vehicletype << endl;
        }
        for (int k = 0; k < heavyvehicles.size(); k++) {
            cout << "Heavy Vehicle " << k + 1 << " - Type: " << heavyvehicles[k].Vehicletype << endl;
        }
    }
    friend void handleEmployeeInteraction(Employee &emp);
    friend bool login(Employee &emp, string pwd);
    friend void changePassword(Employee &emp, string newPwd);
private:
    void updateSalary() {
        salary = c * 700 + b * 400 + hv * 600; // Calculate and update salary
    }
};

void Employee::updateEmployeeDetails(Employee &emp) {
    cout << "Do you want to update existing details? (Y/N): ";
    string updateChoice;
    cin >> updateChoice;

    if (updateChoice == "Y" || updateChoice == "y") {
        string updateField, empName, uname, pwd, existingPwd;

        cout << "Enter the field you want to update (name/age/username/password): ";
        cin >> updateField;

        if (updateField == "name") {
            cout << "Enter new Employee Name: ";
            cin >> empName;
            emp.name = empName;
        } else if (updateField == "age") {
            int empag;
            cout << "Enter new Employee Age: ";
            cin >> empag;
            emp.age = empag;
        } else if (updateField == "username") {
            cout << "Enter new Username: ";
            cin >> uname;
            emp.username = uname;
        } else if (updateField == "password") {
            cout << "Enter old Password to confirm: ";
            cin >> existingPwd;

            if (emp.password == existingPwd) {
                string newPwd;
                cout << "Enter new Password: ";
                cin >> newPwd;
                emp.password = newPwd;
            } else {
                cout << "Incorrect existing password. Cannot update password." << endl;
            }
        }
    }
}

bool login(Employee &emp, string pwd) {
    if (emp.password == pwd) {
        cout << "Login successful." << endl;
        return true;
    } else {
        cout << "Login failed. Incorrect password." << endl;
        return false;
    }
}

void changePassword(Employee &emp, string newPwd) {
    emp.password = newPwd;
    cout << "Password changed successfully." << endl;
}

void handleEmployeeInteraction(Employee &emp) {
    int choice = 0;
    string newPwd;
    string vehicleType;
    cout << "Enter password: ";
    string password;
    cin >> password;
    if (login(emp, password))
    if(!(emp.age>=65 || emp.age<=20))
    while (choice != 6) {
        cout << "Menu Options:" << endl;
        cout << "1. Add a new car" << endl;
        cout << "2. Add a new bike" << endl;
        cout << "3. Add a new heavy vehicle" << endl;
        cout << "4. Update employee details" << endl;
        cout << "5. Show data of employee" << endl;
        cout<<"6. Exit"<<endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car type: ";
                cin >> vehicleType;
                emp.addCar(Automobile(vehicleType));
                break;
            case 2:
                cout << "Enter bike type: ";
                cin >> vehicleType;
                emp.addBike(Automobile(vehicleType));
                break;
            case 3:
                cout << "Enter heavy vehicle type: ";
                cin >> vehicleType;
                emp.addHeavyVehicle(Automobile(vehicleType));
                break;
            case 4:
                emp.updateEmployeeDetails(emp);
                break;
            case 5:
                emp.displayInfo();
                break;
            case 6:
                cout<<"Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}









// employee main
int employeeMain(){
  int numEmployees;
    cout << "Enter the number of employees you want to store data for: ";
    cin >> numEmployees;
    vector<Employee> employees;
    for (int i = 0; i < numEmployees; i++) {
        string empName, uname, pwd;
        int empId, emage;
        cout << "Enter Employee Name for Employee " << i + 1 << ": ";
        cin>>empName;
        cout << "Enter Employee ID for Employee " << i + 1 << ": ";
        string n1;
        empId=inputInt(n1);
        cout << "Enter Username for Employee " << i + 1 << ": ";
        cin >> uname;
        cout << "Enter age for Employee " << i + 1 << ": ";
        string n;
        emage=inputInt(n);
        cout << "Enter Password for Employee " << i + 1 << ": ";
        cin >> pwd;
        Employee emp(empName, empId, uname, pwd,emage);
        employees.push_back(emp);
        cout << "Details of Employee " << i + 1 << ":" << endl;
        employees[i].displayInfo();
        handleEmployeeInteraction(employees[i]);
        employees[i].writeEmployeeDataToFile();
    }
    return 0;
}



//////


class Finance {
public:
    double calculateCost() ;
};

/// CAR DB 



bool isFileEmpty(const string &filename) {
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

void writeOutputToFile(string Car_type, string Model, float engine,float mileage,float power,int Seating,int Warranty,float fuel_tank,string Fuel_type,string Transmission) {
  ofstream outputFile("car_database.txt", ios::app);
  string filename = "car_database.txt";
  if (outputFile.is_open() && isFileEmpty(filename)) {
    cout<<"Car Inventory Details: "<<endl;
    outputFile << "Car Type\tModel Name \tEngine Capacity\tMileage\tPower\tSeating Capacity\tWarranty\tFuel Tank\tFuel Type\tTransmission\n";
    outputFile << Car_type << "\t\t\t\t\t\t\t" << Model << "\t\t\t\t\t" << engine<< "\t\t\t\t\t\t" << mileage << "\t\t\t\t\t\t"<<power<< "\t\t\t\t\t\t"<<Seating<< "\t\t\t\t\t\t"<<Warranty<< "\t\t\t\t\t\t"<<fuel_tank<< "\t\t\t\t\t\t"<<Fuel_type<<Transmission<< endl;
    outputFile.close();
    cout << "Servicing details written to Servicing_Details.txt" << endl;
  } 
  else if (outputFile.is_open() && !isFileEmpty(filename)) {
    outputFile << Car_type << "\t\t\t\t\t\t\t" << Model << "\t\t\t\t\t" << engine<< "\t\t\t\t\t\t" << mileage << "\t\t\t\t\t\t"<<power<< "\t\t\t\t\t\t"<<Seating<< "\t\t\t\t\t\t"<<Warranty<< "\t\t\t\t\t\t"<<fuel_tank<< "\t\t\t\t\t\t"<<Fuel_type<<Transmission<< endl;
    outputFile.close();
  } 
  else {
    cout << "Unable to open file for writing."<<endl;
}
}

// float inputFloat(string n) {
//   string n1 = n;
// n1:
//   cin.ignore(0, '\n');
//   getline(cin, n1);
//   int v = 0; //x = 0, y = 0;
//   for (char i : n1) {
//     if ((i >= '0' && i <= '9') || i == '.') {
//       v = 1;
//     } else {
//       cout << "Invalid input!!" << endl;
//       // v=0;
//       break;
//     }
//   }

//   while (v == 0) {
//     goto n1;
//   }

//   // int m = stoi(n);
//   float q = stof(n1);

//   return q;
// }

void inputStr(string &s) {
  bool flag = false;
  while (flag == false) {

    cin.ignore(0, '\n');
    getline(cin, s);
    for (char c : s) {
      if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||
          (c >= 48 && c <= 57)) {
        flag = true;
      } else {
        flag = false;
      }
    }
  }
}

class Car {
protected:
  string modelName;
  float engine;
  float engine_low;
  float engine_high;
  float mileage;
  float mileage_high;
  float mileage_low;
  float power;
  float power_high;
  float power_low;
  int seating_capacity;
  int warranty;
  int boot_space;
  string fuel_type;
  float fuel_tank;
  string car_type;
  static int count;
string transmission;

public:
  friend void disp_count();
  friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  void input();
  void display();
};

void Car::input() {
  string n;
  cout << "Enter Car Type: ";
  inputStr(car_type);
  cout << "Enter Model Name: ";
  inputStr(modelName);
  cout << "Enter Engine Capacity (in cc): ";
  // Input Engine Capacity
  engine = inputFloat(n);
  // Input Milage
  cout << "Enter Milage (in km/l): ";
  mileage = inputFloat(n);
  // Input Power
  cout << "Enter Power (in bhp): ";
  power = inputFloat(n);
  cout << "Enter Seating Capacity: ";
  seating_capacity = inputFloat(n);
  cout << "Enter Warranty (in years): ";
  warranty = inputFloat(n);
  cout << "Enter Boot Space (in litres): ";
  boot_space = inputFloat(n);
a:
  cout << "Enter Fuel Type: ";
  cout << "1. Petrol" << endl
       << "2. Diesel" << endl
       << "3. CNG" << endl
       << "4. EV" << endl;
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "Petrol";
    break;
  case 2:
    fuel_type = "Diesel";
    break;
  case 3:
    fuel_type = "CNG";
    break;
  case 4:
    fuel_type = "EV";
    break;
  default:
    cout << "Invalid Input!!" << endl;
    goto a;
  }
  cout << "Enter Fuel Tank Capacity (in litres): ";
  fuel_tank = inputFloat(n);

  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    int ch2 = inputFloat(n);
    switch (ch2) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
  
}


class Altroz : public Car {

  static int count_Altroz;

public:
  Altroz();
  void input();
  friend void disp_count();

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
};

Altroz::Altroz() {
  modelName = "Rivian Altroz";
  engine_low = 1199;
  engine_high = 1497;
  power_high = 108.48;
  power_low = 72.41;
  mileage_high = 19.60;
  mileage_low = 18.05;
  warranty = 3;
  fuel_tank = 40;
  boot_space = 350;
  seating_capacity = 5;
  car_type = "Hatchbacks";
  count_Altroz++;
}

int Altroz::count_Altroz =0;

void Altroz::input() {
z:
  string n;
  cout << "Enter Engine Capacity(in cc): ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Altroz should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Altroz should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Altroz should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }
a:
  cout << "Enter Fuel Type (CNG/Petrol/EV): \n"
       << "Enter '1' for CNG\nEnter '2' for Petrol\nEnter '3' for EV\n";
  int ch1 = inputFloat(n);
  switch (ch1) {
  case 1:
    fuel_type = "CNG";
    break;
  case 2:
    fuel_type = "Petrol";
    break;
  case 3:
    fuel_type = "EV";
    break;
  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  }
b:
  cout << "Enter Transmission (Manual/Automatic): \n"
       << "Enter '1' for Manual\nEnter '2' for Automatic\n";
  int ch2 = inputFloat(n);
  switch (ch2) {
  case 1:
    transmission = "Manual";
    break;
  case 2:
    transmission = "Automatic";
    break;

  default:
    cout << "Invalid choice entered!! Enter again...";
    goto b;
  }
  writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

class Ariel: public Car {
  static int count_Ariel;

public:

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  Ariel() {
    modelName = "Rivian Ariel";
    engine_high = 1199;
    engine_low = 1210;
    warranty = 3;
    fuel_tank = 34;
    boot_space = 335;
    mileage_low = 19.00;
    mileage_high = 20.09;
    seating_capacity = 5;
    power_high = 84.48;
    power_low = 72.41;
    car_type = "Hatchbacks";
    count_Ariel++;
  }
  void input();
  friend void disp_count();
};
void Ariel::input() {
z:
  string n;
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Ariel should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }
  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Ariel should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }
  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Ariel should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }
// Input Power
a:
  cout << "Enter Fuel Type (CNG/Petrol/EV): \n"
       << "Enter '1' for CNG\nEnter '2' for Petrol\nEnter '3' for EV\n";
  // Input Fuel Type
  int ch = inputFloat(n);

  switch (ch) {
  case 1:
    fuel_type = "CNG";
    break;
  case 2:
    fuel_type = "Petrol";
    break;
  case 3:
    fuel_type = "EV";
    break;
  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type
    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Ariel::count_Ariel = 0;

class Rivian_Haste : public Car {
  static int count_Haste;

public:
  Rivian_Haste();
  void input();
  friend void disp_count();

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
};

Rivian_Haste::Rivian_Haste() {
  modelName = "Rivian Haste";
  engine_low = 1199;
  engine_high = 1210;
  power_high = 84.48;
  power_low = 72.41;
  mileage_high = 19.60;
  mileage_low = 19.28;
  warranty = 3;
  fuel_tank = 40;
  boot_space = 350;
  seating_capacity = 5;
  car_type = "Hatchbacks";
  count_Haste++;
}

void Rivian_Haste::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of haste should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }
y:
  // Input Engine Capacity
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of haste should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of haste should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (CNG/Petrol/EV): \n"
       << "Enter '1' for CNG\nEnter '2' for Petrol\nEnter '3' for EV\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "CNG";
    break;
  case 2:
    fuel_type = "Petrol";
    break;
  case 3:
    fuel_type = "EV";
    break;
  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Rivian_Haste::count_Haste = 0;

class Rivian_Allure : public Car {
  static int count_Rivian_Allure;

public:

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  Rivian_Allure() {
    modelName = "Rivian Allure";
    engine_high = 1497;
    engine_low = 1199;
    warranty = 5;
    fuel_tank = 35;
    boot_space = 320;
    seating_capacity = 5;
    mileage_low = 17.01;
    mileage_high = 24.08;
    power_high = 113.31;
    power_low = 118.27;
    car_type = "SUV";
    count_Rivian_Allure++;
  }
  void input();
  friend void disp_count();
};
void Rivian_Allure::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Allure should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }
  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Allure should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Allure should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (Diesel/Petrol/EV): \n"
       << "Enter '1' for Diesel\nEnter '2' for Petrol\nEnter '3' for EV\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "Diesel";
    break;
  case 2:
    fuel_type = "Petrol";
    break;
  case 3:
    fuel_type = "EV";
    break;
  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Rivian_Allure::count_Rivian_Allure = 0;

class Rivian_Harrier : public Car {
  static int count_Rivian_Harrier;

public:

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  Rivian_Harrier() {
    modelName = "Rivian Harrier";
    engine_high = 1956;
    engine_low = 1950;
    warranty = 4;
    fuel_tank = 45;
    boot_space = 345;
    seating_capacity = 5;
    mileage_low = 16.80;
    mileage_high = 17.01;
    power_high = 167.62;
    power_low = 165.08;
    car_type = "SUV";
    count_Rivian_Harrier++;
  }
  void input();
  friend void disp_count();
};

void Rivian_Harrier::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Harrier should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }

  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Harrier should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Harrier should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (Diesel/Petrol): \n"
       << "Enter '1' for Diesel\nEnter '2' for Petrol\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "Diesel";
    break;
  case 2:
    fuel_type = "Petrol";
    break;
  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Rivian_Harrier::count_Rivian_Harrier =0;

class Rivian_Safari : public Car {
  static int count_Rivian_Safari;

public:

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  Rivian_Safari() {
    modelName = "Rivian Safari";
    engine_high = 1960;
    engine_low = 1956;
    warranty = 5;
    fuel_tank = 60;
    boot_space = 400;
    seating_capacity = 7;
    mileage_low = 15.30;
    mileage_high = 16.30;
    power_high = 167.62;
    power_low = 165.52;
    car_type = "SUV";
    count_Rivian_Safari++;
  }
  void input();
  friend void disp_count();
};
void Rivian_Safari::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Safari should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }

  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Safari should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Safari should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (Diesel/Petrol): \n"
       << "Enter '1' for Diesel\nEnter '2' for Petrol\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "Diesel";
    break;
  case 2:
    fuel_type = "Petrol";
    break;

  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Rivian_Safari::count_Rivian_Safari =0;

class Hexa : public Car {
  static int count_Hexa;

public:
  Hexa();
  void input();
  friend void disp_count();

friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
};

Hexa::Hexa() {
  modelName = "Rivian Hexa";
  engine_low = 2123;
  engine_high = 2179;
  power_high = 153.80;
  power_low = 138.80;
  mileage_high = 14.40;
  mileage_low = 12.40;
  warranty = 5;
  fuel_tank = 60;
  boot_space = 420;
  seating_capacity = 7;
  car_type = "SUV";
  count_Hexa++;
}

void Hexa::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Hexa should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }

  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Hexa should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Hexa should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (Diesel/Petrol): \n"
       << "Enter '1' for Diesel\nEnter '2' for Petrol\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "Diesel";
    break;
  case 2:
    fuel_type = "Petrol";
    break;

  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Hexa::count_Hexa = 0;

class Punch : public Car {

  static int count_Punch;

public:
friend void writeOutputTofile(string car_type, string modelName, float engine, float mileage, float power, int seating_capacity, int warranty, float fuel_tank, string fuel_type, string transmission);
  Punch() {
    modelName = "Rivian Punch";
    engine_high = 1199;
    engine_low = 1215;
    warranty = 4;
    fuel_tank = 37;
    boot_space = 366;
    seating_capacity = 5;
    mileage_low = 18.80;
    mileage_high = 20.09;
    power_high = 86.63;
    power_low = 72.41;
    car_type = "CrossOvers";
    count_Punch++;
  }
  void input();
  friend void disp_count();
};
void Punch::input() {
  string n;
z:
  cout << "\nEnter Engine Capacity: ";
  engine = inputFloat(n);
  if (engine < engine_low || engine > engine_high) {
    cout << "\nInvalid Engine Capacity\nEngine Capacity of Punch should be "
            "between "
         << engine_low << " and " << engine_high << endl
         << "Enter again\n";
    goto z;
  }

  // Input Engine Capacity
y:
  cout << "Enter Mileage(in kmpl): ";
  mileage = inputFloat(n);
  if (mileage < mileage_low || mileage > mileage_high) {
    cout << "\nInvalid Mileage\nMileage of Punch should be between "
         << mileage_low << " and " << mileage_high << endl
         << "Enter again\n";
    goto y;
  }

  // Input Mileage
x:
  cout << "Enter Power(in bHp): ";
  power = inputFloat(n);
  if (power < power_low || power > power_high) {
    cout << "\nInvalid Power\nPower of Punch should be between " << power_low
         << " and " << power_high << endl
         << "Enter again\n";
    goto x;
  }

// Input Power
a:
  cout << "Enter Fuel Type (CNG/Petrol): \n"
       << "Enter '1' for CNG\nEnter '2' for Petrol\n";
  // Input Fuel Type
  int ch = inputFloat(n);
  switch (ch) {
  case 1:
    fuel_type = "CNG";
    break;
  case 2:
    fuel_type = "Petrol";
    break;

  default:
    cout << "Invalid choice entered!! Enter again...";
    goto a;
  b:
    cout << "Enter Transmission (Manual/Automatic): \n"
         << "Enter '1' for Manual\nEnter '2' for Automatic\n";
    // Input Fuel Type

    switch (ch) {
    case 1:
      transmission = "Manual";
      break;
    case 2:
      transmission = "Automatic";
      break;

    default:
      cout << "Invalid choice entered!! Enter again...";
      goto b;
    }
  }
   writeOutputToFile(car_type,modelName,engine,mileage, power,seating_capacity, warranty,fuel_tank, fuel_type,transmission);
}

int Punch::count_Punch = 0;

int inputInteger(string n) {
  int input;
  cout << n;
  cin >> input;
  return input;
}

void disp_count() {
  cout << "Rivian Altroz: " << Altroz::count_Altroz << endl;
  cout << "Rivian Ariel:" << Ariel::count_Ariel <<endl;
  cout << "Rivian Haste: " << Rivian_Haste::count_Haste << endl;
  cout << "Rivian Harrier: " << Rivian_Harrier::count_Rivian_Harrier <<endl;
  cout << "Rivian Safari: " << Rivian_Safari::count_Rivian_Safari <<endl;
  cout << "Rivian Hexa: " << Hexa::count_Hexa <<endl;
  cout << "Rivian Punch:R" << Punch::count_Punch <<endl; 
  cout<<"Total no. of Cars: "<<Altroz::count_Altroz+Ariel::count_Ariel+Rivian_Haste::count_Haste+Rivian_Harrier::count_Rivian_Harrier+Rivian_Safari::count_Rivian_Safari+Hexa::count_Hexa+Punch::count_Punch<<endl;
}

//car main

int carMain(){
  string n;
  b:
  cout << "1. Enter a new Car Model" << endl;
  cout << "2. Enter a new Car Variety of an Existing Model" << endl;
  cout << "3. Display Inventory" << endl;
  cout << "4. Display no. of Cars" << endl;
  cout << "5. Exit" << endl;
  int ch = inputInteger(n);
  switch (ch) {
  case 1: {
    Car obj;
    obj.input();
    cout << "Car entered into the Inventory successfully!!";
    break;
  }
  case 2: {
  a:
    cout << "Models in our Inventory: " << endl;
    cout << "1. Rivian Ariel" << endl;
    cout << "2. Rivian Altroz" << endl;
    cout << "3. Rivian Haste" << endl;
    cout << "4. Rivian Allure" << endl;
    cout << "5. Rivian Harrier" << endl;
    cout << "6. Rivian Safari" << endl;
    cout << "7. Rivian Punch" << endl;
    cout << "Select the model to add new variant: ";
    int ch2 = inputInteger(n);
    switch (ch2) {
    case 1: {
      Ariel ariel;
      ariel.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 2: {
      Altroz altroz;
      altroz.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 3: {
      Rivian_Haste haste;
      haste.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 4: {
      Rivian_Allure allure;
      allure.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 5: {
      Rivian_Harrier harrier;
      harrier.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 6: {
      Rivian_Safari safari;
      safari.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    case 7: {
      Punch punch;
      punch.input();
      cout << "Variety entered into the Inventory successfully!!";
      break;
    }
    default:
      cout << "Invalid choice! Try again...";
      goto a;
    }
    break;
  }
    break;
  case 3:
    {
      cout<<"Check out the car_database.txt file to see the inventory"<<endl;
    }
    break;

  case 4:
    {
      cout<<"Count of Cars in the Inventory: "<<endl;
      disp_count();
    // Exit program
    break;
    }
    case 5:
    cout<<"Thank you for using our Inventory Management System!!";
    exit(0);
    break;

  default:
    cout << "Invalid choice! Try again...";
    goto b;
  }
  cout<<"Want to continue? (y/n): ";
  char con;
  cin>>con;
  if(con=='y')
    goto b;
  else
  {
    cout<<"Thank you for using our Inventory Management System!!";
     exit(0);
  }
   
  return 0;
}










/// BIKE DB 

// Declared an array as a global variable
static int arr[11] = {25, 31, 45, 43, 27, 29, 37, 41, 33, 39, 31};

// Main class Bike
class bike
{
protected:
  float mileage;
  long price;
  string model;
  float power;
  int gear;
  string brake;
  string body_type;

public:
  bike() {}
  bike(float m, long p, string M, float P, int g, string b, string bty)
  {
    mileage = m;
    price = p;
    model = M;
    power = P;
    gear = g;
    brake = b;
    body_type = bty;
  }
};

// Conversion function from upper case to lower case
string Ascii(string name)
{
  for (int j = 0; j < name.length(); j++)
  {
    if (name[j] >= 'A' && name[j] <= 'Z')
    {
      name[j] += 32;
    }
  }
  return name;
};

// String input function
void input(string &s)
{
  bool flag = false;
  while (flag == false)
  {
    cin.ignore(0, '\n');
    getline(cin, s);
    for (char c : s)
    {
      if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||
          (c >= 48 && c <= 57))
      {
        flag = true;
      }
      else
      {
        flag = false;
      }
    }
  }
}

// float inputFloat(string n)
// {
//   string n1 = n;
// n1:
//   cin.ignore(0, '\n');
//   getline(cin, n1);
//   int v = 0, x = 0, y = 0;
//   for (char i : n1)
//   {
//     if ((i >= '0' && i <= '9') || i == '.')
//     {
//       v = 1;
//     }
//     else
//     {
//       cout << "Invalid input" << endl;
//       break;
//     }
//   }

//   while (v == 0)
//   {
//     goto n1;
//   }
//   float q = stof(n1);
//   return q;
// }

// File handling function
bool isFileEmptyBike(const string &filename)
{
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

// Function to write output to a file in tabular form
void writeOutputToFileBike(int *arr)
{
  ofstream outputFile("bike_details.txt", ios::app);
  string filename = "bike_details.txt";
  if (outputFile.is_open() && isFileEmptyBike(filename))
  {
    outputFile << "Rivian Xpulse 200 standard\tRivian Xpulse 200 premium\tMetro Dapper\tMetro Rebel\t\tRetro Factory\tSingle ABS\tDual ABS\tBluetooth\tBRZ\t\tPremium\t\tStealth Black Edition\n";
    outputFile << "\t\t" << arr[0] << "\t\t\t\t\t\t\t\t" << arr[1] << "\t\t\t\t\t" << arr[2] << "\t\t\t\t" << arr[3] << "\t\t\t\t" << arr[4] << "\t\t\t\t" << arr[5] << "\t\t\t" << arr[6] << "\t\t\t" << arr[7] << "\t\t" << arr[8] << "\t\t\t" << arr[9] << "\t\t\t" << arr[10] << endl;
    outputFile.close();
    cout << "Bike details written to bike_details.txt" << endl;
  }
  else if (outputFile.is_open() && !isFileEmptyBike(filename))
  {
    outputFile << "\t\t" << arr[0] << "\t\t\t\t\t\t\t\t" << arr[1] << "\t\t\t\t\t" << arr[2] << "\t\t\t\t" << arr[3] << "\t\t\t\t" << arr[4] << "\t\t\t\t" << arr[5] << "\t\t\t" << arr[6] << "\t\t\t" << arr[7] << "\t\t" << arr[8] << "\t\t\t" << arr[9] << "\t\t\t" << arr[10] << endl;
    outputFile.close();
    cout << "Bikes details written to expenditure_details.txt" << endl;
  }
  else
  {
    cout << "Unable to open file for writing." << endl;
  }
}

// Function to add more bikes
void stock_add()
{
  string str;
  int val;
ag:
  cout << "Enter the model name : ";
  input(str);
  cout << "Enter the number of bikes want to add : ";
  cin >> val;
  if (Ascii(str) == "rivian xpulse 200 standard")
  {
    arr[0] = arr[0] + val;
    cout << "Total bikes after changes : " << arr[0] << endl;
  }
  else if (Ascii(str) == "rivian xpulse 200 premium")
  {
    arr[1] = arr[1] + val;
    cout << "Total bikes after the changes : " << arr[1] << endl;
  }
  else if (Ascii(str) == "metro dapper")
  {
    arr[2] = arr[2] + val;
    cout << "Total bikes after the changes : " << arr[2] << endl;
  }
  else if (Ascii(str) == "metro rebel")
  {
    arr[3] = arr[3] + val;
    cout << "Total bikes after the changes : " << arr[3] << endl;
  }
  else if (Ascii(str) == "retro factory")
  {
    arr[4] = arr[4] + val;
    cout << "Total bikes after the changes : " << arr[4] << endl;
  }
  else if (Ascii(str) == "single abs")
  {
    arr[5] = arr[5] + val;
    cout << "Total bikes after the changes : " << arr[5] << endl;
  }
  else if (Ascii(str) == "dual abs")
  {
    arr[6] = arr[6] + val;
    cout << "Total bikes after the changes : " << arr[6] << endl;
  }
  else if (Ascii(str) == "bluetooth")
  {
    arr[7] = arr[7] + val;
    cout << "Total bikes after the changes : " << arr[7] << endl;
  }
  else if (Ascii(str) == "brz")
  {
    arr[8] = arr[8] + val;
    cout << "Total bikes after the changes : " << arr[8] << endl;
  }
  else if (Ascii(str) == "premium")
  {
    arr[9] = arr[9] + val;
    cout << "Total bikes after the changes : " << arr[9] << endl;
  }
  else if (Ascii(str) == "stealth black edition")
  {
    arr[10] = arr[10] + val;
    cout << "Total bikes after increament : " << arr[10] << endl;
  }
  else
  {
    cout << "Invalid Input !!";
    cout << "Enter a valid one." << endl;
    goto ag;
  }
  writeOutputToFileBike(arr);
}

// Function to delete bikes
void stock_del()
{
  string str;
  int val;
ag:
  cout << "Enter the model name : " << endl;
  input(str);
del:
  cout << "Enter the number of bikes want to decrease : " << endl;
  cin >> val;
  if (Ascii(str) == "rivian xpulse 200 standard")
  {
    if (arr[0] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[0] = arr[0] - val;
      cout << "Total bikes after change : " << arr[0] << endl;
    }
  }
  else if (Ascii(str) == "rivian xpulse 200 premium")
  {
    if (arr[1] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[1] = arr[1] - val;
      cout << "Total bikes after change : " << arr[1] << endl;
    }
  }
  else if (Ascii(str) == "metro dapper")
  {
    if (arr[2] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[2] = arr[2] - val;
      cout << "Total bikes after change : " << arr[2] << endl;
    }
  }
  else if (Ascii(str) == "metro rebel")
  {
    if (arr[3] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[3] = arr[3] - val;
      cout << "Total bikes after change : " << arr[3] << endl;
    }
  }
  else if (Ascii(str) == "retro factory")
  {
    if (arr[4] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[4] = arr[4] - val;
      cout << "Total bikes after change : " << arr[4] << endl;
    }
  }
  else if (Ascii(str) == "single abs")
  {
    if (arr[5] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[5] = arr[5] - val;
      cout << "Total bikes after change : " << arr[5] << endl;
    }
  }
  else if (Ascii(str) == "dual abs")
  {
    if (arr[6] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[6] = arr[6] - val;
      cout << "Total bikes after change : " << arr[6] << endl;
    }
  }
  else if (Ascii(str) == "bluetooth")
  {
    if (arr[7] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[7] = arr[7] - val;
      cout << "Total bikes after change : " << arr[7] << endl;
    }
  }
  else if (Ascii(str) == "brz")
  {
    if (arr[8] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[8] = arr[8] - val;
      cout << "Total bikes after change : " << arr[8] << endl;
    }
  }
  else if (Ascii(str) == "premium")
  {
    if (arr[9] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[9] = arr[9] - val;
      cout << "Total bikes after change : " << arr[9] << endl;
    }
  }
  else if (Ascii(str) == "stealth black edition")
  {
    if (arr[10] < val)
    {
      cout << "Invalid Input !!" << endl;
      goto del;
    }
    else
    {
      arr[10] = arr[10] - val;
      cout << "Total bikes after change : " << arr[10] << endl;
    }
  }
  else
  {
    cout << "Invalid Input !!" << endl;
    cout << "Enter a valid one." << endl;
    goto ag;
  }
  writeOutputToFileBike(arr);
}

// Display of stock available
void display(int arr[11])
{
  cout << "Rivian Xpulse 200 Standard : " << arr[0] << endl;
  cout << "Rivian Xpulse 200 Premium  : " << arr[1] << endl;
  cout << "Metro Dapper                : " << arr[2] << endl;
  cout << "Metro Rebel                 : " << arr[3] << endl;
  cout << "Retro Factory               : " << arr[4] << endl;
  cout << "Single Abs                  : " << arr[5] << endl;
  cout << "Dual Abs                    : " << arr[6] << endl;
  cout << "Bluetooth                   : " << arr[7] << endl;
  cout << "BRZ                         : " << arr[8] << endl;
  cout << "Premium                     : " << arr[9] << endl;
  cout << "Stealth Black Edition       : " << arr[10] << endl;
}

// Petrol sub-class of main class bike
class petrolbike : protected bike
{
protected:
  float engine_capacity;
  float tank_capacity;

public:
  petrolbike() {}
  petrolbike(float m, long p, string M, float P, int g, string b, float ec,
             float tc, string bty)
      : bike(m, p, M, P, g, b, bty)
  {
    engine_capacity = ec;
    tank_capacity = tc;
  }
};

// ELectric sub-class of main class bike
class evBike : protected bike
{
protected:
  float battery_capacity;
  float charging_time;
  string battery_type;
  string battery_range;
  double battery_warranty;

public:
  evBike() {}
  evBike(float m, long p, string M, float P, int g, string b, float bc,
         string bt, float ct, string br, string bty, double bw)
      : bike(m, p, M, P, g, b, bty)
  {
    battery_capacity = bc;
    charging_time = ct;
    battery_type = bt;
    battery_range = br;
    battery_warranty = bw;
  }
};

// Bike 1 sub-class of petrolbike
class Rivian_XPulse_200 : public petrolbike
{

protected:
  int seat_height;
  string handlebar_riser;

public:
  void set_data1()
  {
    mileage = 32.9;
    engine_capacity = 199.6;
    power = 18.9;
    gear = 5;
    brake = "f-disc-dia(276mm)/r-disc-dia(220mm)";
    body_type = "off-road";
    tank_capacity = 13;
  }

  void put_data1(int sh, string hbr, long p, string M)
  {
    seat_height = sh;
    handlebar_riser = hbr;
    price = p;
    model = M;
  }

  void get_data1()
  {
    cout << "\nModel           : " << model << endl;
    cout << "Price           : " << price << "/-" << endl;
    cout << "Mileage         : " << mileage << "km/L" << endl;
    cout << "Engine Capacity : " << engine_capacity << "cc" << endl;
    cout << "Power           : " << power << "bhp" << endl;
    cout << "Gear            : " << gear << endl;
    cout << "Brake           : " << brake << endl;
    cout << "Body Type       : " << body_type << endl;
    cout << "Tank Capacity   : " << tank_capacity << "L" << endl;
    cout << "Seat Height     : " << seat_height << "mm" << endl;
    cout << "Handlebar Riser : " << handlebar_riser << endl;
  }
};

// Bike 2 sub-class of petrolbike
class Rivian_Hunter_350 : public petrolbike
{
  string taillight;
  string grab_rail;

public:
  void set_data2()
  {
    engine_capacity = 349.0;
    mileage = 36.2;
    tank_capacity = 13.0;
    power = 20.20;
    gear = 5;
    body_type = "Cruiser";
  }

  void put_data2(long p, string b, string t, string gr, string m)
  {
    price = p;
    brake = b;
    taillight = t;
    grab_rail = gr;
    model = m;
  }

  void get_data2()
  {
    cout << "\nModel           : " << model << endl;
    cout << "Price           : Rs." << price << endl;
    cout << "Engine Capacity : " << engine_capacity << "cc" << endl;
    cout << "Mileage         : " << mileage << "Km/L" << endl;
    cout << "Tank Capacity   : " << tank_capacity << "L" << endl;
    cout << "Power           : " << power << "bhp" << endl;
    cout << "Gear            : " << gear << endl;
    cout << "Body Type       : " << body_type << endl;
    cout << "Brake           : " << brake << endl;
    cout << "Taillight       : " << taillight << endl;
    cout << "Grab Rail       : " << grab_rail << endl;
  }
};

// Bike 3 sub-class of petrolbike
class Rivian_Pulsar_NS160 : public petrolbike
{
public:
  void set_data3()
  {
    engine_capacity = 160.3;
    mileage = 52.2;
    tank_capacity = 12.0;
    power = 17.03;
    gear = 5;
    brake = "f-disc-dia(260mm)/r-disc-dia(230mm)";
    body_type = "commuter";
  }

  void put_data3(long p, string m)
  {
    price = p;
    model = m;
  }

  void get_data3()
  {
    cout << "\nModel           : " << model << endl;
    cout << "Price           : Rs." << price << endl;
    cout << "Engine Capacity : " << engine_capacity << "cc" << endl;
    cout << "Mileage         : " << mileage << "Km/L" << endl;
    cout << "Tank Capacity   : " << tank_capacity << "L" << endl;
    cout << "Power           : " << power << "bhp" << endl;
    cout << "Gear            : " << gear << endl;
    cout << "Brake           : " << brake << endl;
    cout << "Body Type       : " << body_type << endl;
  }
};

// Bike 4 sub-class of evbike
class Rivian_RT400 : public evBike
{
  int top_speed;

public:
  void set_data4()
  {
    battery_capacity = 3.24;
    charging_time = 4.5;
    battery_type = "Li-Ion";
    battery_range = "80-150";
    body_type = "Commuter";
    mileage = 150.00;
    brake = "Disc";
    top_speed = 85;
  }

  void put_data4(long p, double w, string m)
  {
    price = p;
    battery_warranty = w;
    model = m;
  }

  void get_data4()
  {
    cout << "\nModel            : " << model << endl;
    cout << "Price            : Rs." << price << endl;
    cout << "Battery Capacity : " << battery_capacity << "kWh" << endl;
    cout << "Charging Time    : " << charging_time << "hrs" << endl;
    cout << "Battery Type     : " << battery_type << endl;
    cout << "Battery Range    : " << battery_range << endl;
    cout << "Body Type        : " << body_type << endl;
    cout << "Mileage          : " << mileage << "Km/full charge" << endl;
    cout << "Brake            : " << brake << endl;
    cout << "Battery Warranty : " << battery_warranty << "years" << endl;
    cout << "Top Speed        : " << top_speed << "km/h" << endl;
  }
};


int bikeMain(){
    Rivian_XPulse_200 std, pr;
  Rivian_Hunter_350 md, mr, rf;
  Rivian_Pulsar_NS160 sabs, dabs, blu;
  Rivian_RT400 br, pre, sb;
  int choice, add, del, y;
  char c1, c2, c3, c4;
  string x, s;
  cout << "\n\t\t~RIVIAN BIKES~ " << endl;
reset:
  cout << " Please Enter your choice " << endl;
main:
  cout << "\t Enter 1 for Rivian Xpulse 200 " << endl;
  cout << "\t Enter 2 for Rivian Hunter 350 " << endl;
  cout << "\t Enter 3 for Rivian Pulsar NS 160 " << endl;
  cout << "\t Enter 4 for Rivian RT400 " << endl;
  cout << "\t Enter 5 to Add and Delete bikes" << endl;
  cout << "\t Enter 6 to Exit" << endl;
  cin >> choice;

  // using switch case to choose a bike
  switch (choice)
  {
    // Case 1:choosing Rivian Xpulse 200
  case 1:
    cout << "\nThis is Rivian Xpulse 200 !!" << endl;
    cout << "It has 2 Variants." << endl;
  a1:
    cout << "\tEnter a for Standard Variant" << endl;
    cout << "\tEnter b for Premium Variant" << endl;
    cin >> c1;
    switch (c1)
    {
      // choosing variants of Xpulse 200
    case 'a':
      std.set_data1();
      std.put_data1(825, "yes", 146276, "Rivian Xpulse 200 standard");
      std.get_data1();
      break;
    case 'b':
      pr.set_data1();
      pr.put_data1(891, "no", 153651, "Rivian Xpulse 200 premium");
      pr.get_data1();
      break;

    default:
      cout << " \nThe entered input is invalid!! Please enter a valid input"
           << endl;
      goto a1;
      break;
    }
    break;
    // Case 2:choosing Rivian Hunter 350
  case 2:
    cout << "\nThis is Rivian Hunter 350 !!" << endl;
    cout << "It has 3 Variants." << endl;
  a2:
    cout << "\tEnter a for Metro Dapper Variant." << endl;
    cout << "\tEnter b for Metro Rebel Variant." << endl;
    cout << "\tEnter c for Retro factory Variant." << endl;
    cin >> c2;
    switch (c2)
    {
      // choosing variants of Hunter 350
    case 'a':
      md.set_data2();
      md.put_data2(163900, "Disc brakes with standard channel ABS", "LED",
                   "Split aluminium grab rails", "Metro Dapper");
      md.get_data2();
      break;

    case 'b':
      mr.set_data2();
      mr.put_data2(168900, "Dual channel ABS", "LED", "Aluminium grab rails",
                   "Metro Rebel");
      mr.get_data2();
      break;

    case 'c':
      rf.set_data2();
      rf.put_data2(149900, "Dual channel ABS", "Halogen",
                   "A steel tube-type passenger grab rail", "Retro Factory");
      rf.get_data2();
      break;

    default:
      cout << "\n The entered input is invalid!! Please enter a valid input"
           << endl;
      goto a2;
      break;
    }
    break;
    // Case 3:choosing Rivian Pulsar NS 160
  case 3:
    cout << "\nThis is Rivian Pulsar NS 160 !!" << endl;
    cout << "It has 3 Variants." << endl;
  a3:
    cout << "\tEnter a for single abs Variant" << endl;
    cout << "\tEnter b for dual abs Variant" << endl;
    cout << "\tEnter c for bluetooth Variant" << endl;
    cin >> c3;
    switch (c3)
    {
      // choosing variants of Pulsar NS 160
    case 'a':
      sabs.set_data3();
      sabs.put_data3(124612, "Rivian Pulsar NS 160 single abs");
      sabs.get_data3();
      break;
    case 'b':
      dabs.set_data3();
      dabs.put_data3(137633, "Rivian Pulsar NS 160 dual abs");
      dabs.get_data3();
      break;
    case 'c':
      blu.set_data3();
      blu.put_data3(146427, "Rivian Pulsar NS 160 bluetooth");
      blu.get_data3();
      break;

    default:
      cout << "\n The entered input is invalid!! Please enter a valid input"
           << endl;
      goto a3;
      break;
    }
    break;
    // Case 4:choosing Rivian RT400
  case 4:
    cout << "\nThis is Rivian RT400 !!" << endl;
    cout << "It has 3 Variants." << endl;
  a4:
    cout << "\tEnter a for BRZ Variant" << endl;
    cout << "\tEnter b for Premium Variant" << endl;
    cout << "\tEnter c for Stealth Black Edition Variant" << endl;
    cin >> c4;
    switch (c4)
    {
      // choosing variants of RT400
    case 'a':
      br.set_data4();
      br.put_data4(132000, 4, "BRZ");
      br.get_data4();
      break;
    case 'b':
      pre.set_data4();
      pre.put_data4(139000, 4.5, "Premium");
      pre.get_data4();
      break;
    case 'c':
      sb.set_data4();
      sb.put_data4(144000, 5, "Stealth Black Edition");
      sb.get_data4();
      break;

    // default case
    default:
      cout << "\n The entered input is invalid!! Please enter a valid input"
           << endl;
      goto a4;
      break;
    }
    break;
    // Case 5:Adding and Deleting bikes
  case 5:
    cout << "\nThe available stock is :\n " << endl;
    display(arr);
    cout << "Do you want to add or delete bikes ?(1/0)" << endl;
  value:
    y = inputFloat(s);
    if (y == 1)
    {
      stock_add();
    }
    else if (y == 0)
    {
      stock_del();
    }
    else
    {
      cout << "Enter a valid Input !!" << endl;
      goto value;
    }
    break;
    // Case 6:Exiting the program
  case 6:
    cout << "\n\tThank You !!" << endl;
    break;
  default:
    cout << " \nThe entered input is invalid!! Please enter a valid input"
         << endl;
    goto main;
    break;
  }
  char a;
abc:
  cout << "\t\n Want to continue?? Enter y to continue and n to leave " << endl;
  cin >> a;
  if (a == 'y')
  {
    goto reset;
  }
  else if (a == 'n')
  {
    cout << " \tThank you for visiting !! " << endl;
  }
  else
  {
    goto abc;
  }
    return 0;
}



//service db

class Servicing {
protected:
  string vehicle;
  string serving[MAX];
  int index;
  float price[MAX];
  int warrantee[MAX];
  float bill;

public:
  void serv() {
  label:
    string x;
    cout << "Select the vehicle you want to service: " << endl;
    cout << "1. Car" << endl
         << "2. Bike" << endl
         << "3. Heavy vehicles" << endl
         << "4. Exit" << endl;
    int n = inputInt(x);
    switch (n) {
    case 1:
      cout << "You have selected Car" << endl;
      vehicle = "Car";
      break;
    case 2:
      cout << "You have selected Bike" << endl;
      vehicle = "Bike";
      break;
    case 3:
      cout << "You have selected Heavy vehicles" << endl;
      vehicle = "Heavy vehicles";
      break;
    case 4:
      cout << "You have selected Exit" << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      goto label;
    }
  }
  string return_vehicle() { return vehicle; }
};

class CarServing : public Servicing {
protected:
  string ServiceType;

public:
  void carServing() {
  labels:
    string x;
    cout << "Select the type of services you want to use: " << endl;
    cout << "1. Manual Servicing" << endl
         << "2. Digital Servicing" << endl
         << "3. Exit" << endl;
    int y = inputInt(x);
    switch (y) {
    case 1:
      cout << "You have selected Manual Servicing" << endl;
      ServiceType = "Manual Servicing";
      break;
    case 2:
      cout << "You have selected Digital Servicing" << endl;
      ServiceType = "Digital Servicing";
      break;
    case 3:
      cout << "You have selected Exit" << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      goto labels;
    }
  }
  string return_serviceType() { return ServiceType; }
};

class ManualServicing : public CarServing {
protected:

public:
  friend void display(ManualServicing &obj);
  ManualServicing() {
    bill = 0;
    index = 0;
  }
  float return_bill() { return bill; }
  void manualServicing() {
  label:
    string x;
    cout << "Following are the Manual Servicing available: " << endl;
    cout << "1. Oil Change" << endl
         << "2. Brake Repair" << endl
         << "3. Engine Repair" << endl
         << "4. Suspension Repair" << endl
         << "5. Clutch Repair" << endl
         << "6. Transmission Repair" << endl
         << "7. Battery Repair" << endl
         << "8. Brake Pad Repair" << endl
         << "9. Exit" << endl;
    int y = inputInt(x);
    switch (y) {
    case 1:
      cout << "You have selected Oil Change" << endl << "Price: 100" << endl;
      serving[index] = "Oil Change";
      price[index] = 100;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 2:
      cout << "You have selected Brake Repair" << endl << "Price: 200" << endl;
      serving[index] = "Brake Repair";
      price[index] = 200;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 3:
      cout << "You have selected Engine Repair" << endl << "Price: 300" << endl;
      serving[index] = "Engine Repair";
      price[index] = 300;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 4:
      cout << "You have selected Suspension Repair" << endl
           << "Price: 400" << endl;
      serving[index] = "Suspension Repair";
      price[index] = 400;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 5:
      cout << "You have selected Clutch Repair" << endl << "Price: 500" << endl;
      serving[index] = "Clutch Repair";
      price[index] = 500;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 6:
      cout << "You have selected Transmission Repair" << endl
           << "Price: 600" << endl;
      serving[index] = "Transmission Repair";
      price[index] = 600;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 7:
      cout << "You have selected Battery Repair" << endl
           << "Price: 700" << endl;
      serving[index] = "Battery Repair";
      price[index] = 700;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 8:
      cout << "You have selected Brake Pad Repair" << endl<< "Price: 800" << endl;
      serving[index] = "Brake Pad Repair";
      price[index] = 800;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 9:
      cout << "You have selected Exit" << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      goto label;
    }
  }
};

void display(ManualServicing &obj) {
  cout << "Manual Servicing: " << endl;
  for (int i = 0; i < obj.index; i++) {
    cout << "Item no." << i + 1 << ": " << endl;
    cout << obj.serving[i] << endl;
    cout << obj.price[i] << endl;
    cout << "Lifespan: " << obj.warrantee[i] << " years" << endl;
  }
  cout << "Your Final bill of manual is: " << obj.bill << endl;
}

class DigitalServicing : public CarServing {
protected:
  float total;

public:
  float return_bill() { return bill; }
  friend void display(DigitalServicing &obj);
  DigitalServicing() {
    bill = 0;
    index = 0;
    total = 0;
  }
  void digitalServicing() {
  label:
    string x,y;
    int b;
    cout << "Following are the Digital Servicing available: " << endl;
    cout << "1. Wheel Allignment" << endl
         << "2. Tire Rotation" << endl
         << "3. Stearing Allignment" << endl
         << "4. Electrical Check" << endl
         << "5. Exit" << endl;
    int a = inputInt(x);
    switch (a) {
    case 1:
      cout << "You have selected Wheel Allignment" << endl
           << "price : 100" << endl;
      serving[index] = "Wheel Allignment";
      price[index] = 100;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 2:
      cout << "You have selected Tire Rotation" << endl
           << "price : 200" << endl;
      serving[index] = "Tire Rotation";
      price[index] = 200;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 3:
      cout << "You have selected Stearing Allignment" << endl
           << "price : 300" << endl;
      serving[index] = "Stearing Allignment";
      price[index] = 300;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 4:
      cout << "You have selected Electrical Check" << endl
           << "price : 400" << endl;
      serving[index] = "Electrical Check";
      price[index] = 400;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 5:
      cout << "You have selected Exit" << endl;
      label3:
      cout << "Do you want manual servicing? (1 for yes, 0 for no)" << endl;
      b = inputInt(y);
      if (b == 1) {
        ManualServicing manualservicing;
        manualservicing.manualServicing();
        total = bill + manualservicing.return_bill();
        display(manualservicing);
      } else if (b == 0) {
        cout << "Thank you for using our service" << endl;
      } else {
        cout << "Invalid input" << endl;
        goto label3;
      }
      break;
    default:
      cout << "Invalid input" << endl;
      goto label;
    }
  }
  float return_total() { return total; }
};

void display(DigitalServicing &obj) {
  cout << "Digital Servicing: " << endl;
  for (int i = 0; i < obj.index; i++) {
    cout << "Item no." << i + 1 << ": " << endl;
    cout << obj.serving[i] << endl;
    cout << obj.price[i] << endl;
    cout << "Lifespan: " << obj.warrantee[i] << " years" << endl;
  }
  cout << "Your Final bill for digital is: " << obj.bill << endl;
}

class BikeServing : public Servicing {
protected:

public:
  friend void display(BikeServing &bike);
  BikeServing() {
    index = 0;
    bill = 0;
  }
  float return_bill() { return bill; }
  void bikeServing() {
  label:
    string x;
    cout << "Following are the Bike Servicing available: " << endl;
    cout << "1. Brake Repair" << endl
         << "2. Spark Plug" << endl
         << "3. Clutch" << endl
         << "4. Battery Servicing"<<endl
         << "5. Chain Repair" << endl
         << "6. Teflon Coating" << endl
         << "7. Engine service" << endl
         << "8. Washing" << endl
         << "9. Exit" << endl;
    int y = inputInt(x);
    switch (y) {
    case 1:
      cout << "You have selected Brake Repair" << endl << "Price: 100" << endl;
      serving[index] = "Brake Repair";
      price[index] = 100;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 2:
      cout << "You have selected Spark Plug" << endl << "Price: 200" << endl;
      serving[index] = "Spark Plug";
      price[index] = 200;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 3:
      cout << "You have selected Clutch" << endl << "Price: 300" << endl;
      serving[index] = "Clutch";
      price[index] = 300;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 4:
      cout << "You have selected Battery Servicing" << endl
           << "Price: 400" << endl;
      serving[index] = "Battery Servicing";
      price[index] = 400;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 5:
      cout << "You have selected Chain Repair" << endl << "Price: 500" << endl;
      serving[index] = "Chain Repair";
      price[index] = 500;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 6:
      cout << "You have selected Teflon Coating" << endl
           << "Price: 600" << endl;
      serving[index] = "Teflon Coating";
      price[index] = 600;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 7:
      cout << "You have selected Engine service" << endl
           << "Price: 700" << endl;
      serving[index] = "Engine service";
      price[index] = 700;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 8:
      cout << "You have selected Washing" << endl << "Price: 800" << endl;
      serving[index] = "Washing";
      price[index] = 800;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 9:
      cout << "You have selected Exit" << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      goto label;
    }
  }
};

void display(BikeServing &bike) {
  for (int i = 0; i < bike.index; i++) {
    cout << "Item no." << i + 1 << ": " << endl;
    cout << bike.serving[i] << endl;
    cout << bike.price[i] << endl;
    cout << "Lifespan: " << bike.warrantee[i] << " years" << endl;
  }
  cout << "Your Final bill is: " << bike.bill << endl;
}

class HeavyVehicleServing : public Servicing {
protected:

public:
  friend void display(HeavyVehicleServing &heavyvehicle);
  HeavyVehicleServing() {
    index = 0;
    bill = 0;
  }
  float return_bill() { return bill; }
  void heavyVehicleServing() {
  label:
    string x;
    cout << "Following are the Heavy Vehicle Servicing available: " << endl;
    cout << "1. Suspension" << endl
         << "2. Battery Change" << endl
         << "3. Fuel System" << endl
         << "4. Tale Light" << endl
         << "5. Radiate Maintainance" << endl
         << "6. Engine service" << endl
         << "7. Exit" << endl;
    int y = inputInt(x);
    switch (y) {
    case 1:
      cout << "You have selected Suspension" << endl << "Price: 100" << endl;
      serving[index] = "Suspension";
      price[index] = 100;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 2:
      cout << "You have selected Battery Change" << endl
           << "Price: 200" << endl;
      serving[index] = "Battery Change";
      price[index] = 200;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 3:
      cout << "You have selected Fuel System" << endl << "Price: 300" << endl;
      serving[index] = "Fuel System";
      price[index] = 300;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 4:
      cout << "You have selected Tale Light" << endl << "Price: 400" << endl;
      serving[index] = "Tale Light";
      price[index] = 400;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 5:
      cout << "You have selected Radiate Maintainance" << endl
           << "Price: 500" << endl;
      serving[index] = "Radiate Maintainance";
      price[index] = 500;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 6:
      cout << "You have selected Engine service" << endl
           << "Price: 700" << endl;
      serving[index] = "Engine service";
      price[index] = 700;
      warrantee[index] = 1;
      bill += price[index];
      index++;
      goto label;
      break;
    case 7:
      cout << "You have selected Exit" << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      goto label;
    }
  }
};

void display(HeavyVehicleServing &heavy) {
  for (int i = 0; i < heavy.index; i++) {
    cout << "Item no." << i + 1 << ": " << endl;
    cout << heavy.serving[i] << endl;
    cout << heavy.price[i] << endl;
    cout << "Lifespan: " << heavy.warrantee[i] << " years" << endl;
  }
  cout << "Your Final bill is: " << heavy.bill << endl;
}

class SpareParts {
protected:
  static string Total_SpareParts[MAX];
  string sparePart[MAX];
  float price[MAX];
  float price1[MAX];
  int index1;
  int index2;
  float bill;

public:
  SpareParts() {
    index2 = 0;
    index1 = 0;
    bill = 0;
    addPart("Brake Pad", 520);
    addPart("Wheels", 400);
    addPart("Gear Box", 620);
    addPart("Radiator", 320);
    addPart("Fuel lines", 450);
    addPart("Cooling System", 760);
    addPart("Speaker", 420);
    addPart("Bumper", 1200);
  }
  int return_index2(){
   return index2;
  }
  string return_sparePart(int i){
    return sparePart[i];
  }
  float return_price(int i){
    return price[i];
  }
  float return_bill(){
    return bill;
  }
  float return_price1(int i){
    return price1[i];
  }
  void addPart(string s, float p) {
    Total_SpareParts[index1] = s;
    price[index1] = p;
    index1++;
  }
  void addPart() {
    string s;
    string p;
    cout << "Enter the name of the spare part you want to add: ";
    cin >> s;
    cout << "Enter the price of the spare part: ";
    float p1 = inputFloat(p);
    addPart(s, p1);
  }
  void choose() {
  label:
    string x;
    cout << "Choose any spare part from the list below: " << endl;
    for (int i = 0; i < index1; i++) {
      cout << i + 1 << ". " << Total_SpareParts[i] << "\tPrice - " << price[i]<< endl;
    }
    cout << index1+1 << ". Exit" << endl;
    int y = inputInt(x);
    if (y == index1+1) {
      cout << "Your Final Amount is:" << bill << endl;
      return;
    }
    for (int i = 0; i < index1; i++) {
      if (i == y - 1) {
        sparePart[index2] = Total_SpareParts[i];
        price1[index2] = price[i];
        index2++;
        bill += price[i];
      }
    }
    goto label;
  }
  void spare() {
    cout << "What do you want to do: " << endl;
    cout << "1. Add a new spare part" << endl;
    cout << "2. Choose a spare part" << endl;
    cout << "3. Delete a spare part" << endl;
    cout << "4. Exit" << endl;
    string x;
    int y = inputInt(x);
    switch (y) {
    case 1:
      addPart();
      spare();
      break;
    case 2:
      choose();
      spare();
      break;
    case 3:
      delete_part();
      spare();
      break;
    case 4:
      return;
    default:
      cout << "Invalid input" << endl;
      spare();
      break;
  }
}
  void delete_part(){
    string s;
    int x =1;
    cout<<"Enter the name of the spare part you want to delete: ";
    cin>>s;
    for(int i=0;i<index1;i++){
      if(s==Total_SpareParts[i]){
        x = 0;
        for(int j=i;j<index1;j++){
          Total_SpareParts[j]=Total_SpareParts[j+1];
          price[j]=price[j+1];
        }
        index1--;
      }
    }
    if(x==1){
      cout<<"Part not found"<<endl;
    }
  }
};

string SpareParts::Total_SpareParts[MAX];

class Vehicle {
protected:
  string vehicle;
public:
  string return_vehicle() {
    return vehicle;
  }
  int category() {
  incorrect:
    int x = 0;
    cout << "Enter the Category of your Vehicle: " << endl;
    cout << "1. Car " << endl
         << "2. Bike " << endl
         << "3. Exit Portal " << endl;
    cin >> x;
    switch (x) {
    case 1:
      cout << "Car is selected" << endl;
      vehicle = "Car";
      return 1;

    case 2:
      cout << "Bike is selected" << endl;
      vehicle = "Bike";
      return 2;

    case 3:
      cout << "You want to Exit Portal." << endl;
      return 3;

    default:
      cout << "Invalid Input." << endl;
      goto incorrect;
    }
  }
};

class CarModel : public Vehicle {
protected:
  string model;

public:
  void modelSelection() {
  label:
    int x = 0;
    cout << "Enter the Model of your Car: " << endl;
    cout << "1. Sedan " << endl
         << "2. SUV " << endl
         << "3. HatchBack " << endl
         << "4. CrossOvers " << endl
         << "5. Exit Portal " << endl;
    cin >> x;
    switch (x) {
    case 1:
      cout << "Sedan is selected" << endl;
      model = "Sedan";
      cout << model << endl;
      break;
    case 2:
      cout << "SUV is selected" << endl;
      model = "SUV";
      break;
    case 3:
      cout << "HatchBack is selected" << endl;
      model = "HatchBack";
      break;
    case 4:
      cout << "CrossOvers is selected" << endl;
      model = "CrossOvers";
      break;
    case 5:
      cout << "You want to Exit Portal." << endl;
      break;
    default:
      cout << "Invalid Input." << endl;
      goto label;
    }
  }
  string return_model(){
   return model;
  }
};

class Car_Accessories : public CarModel {
protected:
  string accessories[MAX];
  int index;
  float price[MAX];
  float bill;

public:
  friend void billing(Car_Accessories &obj);
  Car_Accessories() {
    bill = 0;
    index = 0;
  }
  float return_bill() { return bill; }

  void display(CarModel &obj) {
  invalid:
    int x = 0;
    cout << "Enter the accessories you want to apply: " << endl;
    goto options;
  repeat:
    cout << "Do you want to add any other accessories: " << endl;
  options:
    cout << "1. Ambient Mood Lighting " << endl
         << "2. Puddle Lamps " << endl
         << "3. Air Freshners " << endl
         << "4. Speakers " << endl
         << "5. Number Plates Designing" << endl
         << "6. Vehicle Tracking Device " << endl
         << "7. Exit Portal " << endl;
    cin >> x;

    switch (x) {
    case 1:
      cout << "Ambient Mood Lighting is Selected." << endl;
      accessories[index] = "Ambient Mood Lighting";
      cout<<obj.return_model()<<endl;
      if (obj.return_model() == "Sedan") {
        price[index] = 5400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 6000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 5000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 5600;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 1;

    case 2:
      cout << "Puddle Lamps is selected" << endl;
      accessories[index] = "Puddle Lamps";
      cout << accessories[index] << endl;
      cout << obj.return_model() << endl;
      if (obj.return_model() == "Sedan") {
        price[index] = 1200;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 1500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 1000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 1350;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 2;

    case 3:
      cout << "Air Freshners is selected" << endl;
      accessories[index] = "Air Freshners";
      if (obj.return_model() == "Sedan") {
        price[index] = 250;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 150;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 350;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 3;

    case 4:
      cout << "Speakers is selected" << endl;
      accessories[index] = "Speakers";
      if (obj.return_model() == "Sedan") {
        price[index] = 2500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 4000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 2000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 3000;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 4;

    case 5:
      cout << "Number Plates Designing is selected" << endl;
      accessories[index] = "Number Plates Designing";
      if (obj.return_model() == "Sedan") {
        price[index] = 400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 350;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 450;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 5;

    case 6:
      cout << "Vehicle Tracking Device is selected" << endl;
      accessories[index] = "Vehicle Tracking Device";
      if (obj.return_model() == "Sedan") {
        price[index] = 6500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "SUV") {
        price[index] = 7500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "HatchBack") {
        price[index] = 6000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "CrossOvers") {
        price[index] = 7000;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 6;

    case 7:
      cout << "Thank You for using our portal" << endl;
      break;
      // return 7;

    default:
      cout << "Invalid Input" << endl;
      goto invalid;
    }
  }
};

void billing(Car_Accessories &obj) {
  cout << "Accessories: " << endl;
  for (int i = 0; i < obj.index; i++) {
    cout << "Accessory no." << i + 1 << ": " << endl;
    cout << obj.accessories[i] << endl;
    cout << obj.price[i] << endl;
  }
  cout << "Final bill Amount: " << obj.bill << endl;
}

class BikeModel : public Vehicle {
protected:
  string model;

public:
  void modelSelection() {
  label:
    int x = 0;
    cout << "Enter the Model of your Bike: " << endl;
    cout << "1. Rivian XPulse " << endl
         << "2. Rivian Hunter 350 " << endl
         << "3. Rivian Pulsar NS160 " << endl
         << "4. Rivian RT400 " << endl
         << "5. Exit Portal " << endl;
    cin >> x;
    switch (x) {
    case 1:
      cout << "Rivian XPulse is selected" << endl;
      model = "Rivian XPulse";
      cout << model << endl;
      break;
    case 2:
      cout << "Rivian Hunter 350 is selected" << endl;
      model = "Rivian Hunter 350";
      break;
    case 3:
      cout << "Rivian Pulsar NS160 is selected" << endl;
      model = "Rivian Pulsar NS160";
      break;
    case 4:
      cout << "Rivian RT400 is selected" << endl;
      model = "Rivian RT400";
      break;
    case 5:
      cout << "You want to Exit Portal." << endl;
      break;
    default:
      cout << "Invalid Input." << endl;
      goto label;
    }
  }
  string return_model(){
   return model;
  }
};

class Bike_Accessories : public CarModel {
protected:
  string accessories[MAX];
  int index;
  float price[MAX];
  float bill;

public:
  friend void billing(Bike_Accessories &obj);
  Bike_Accessories() {
    bill = 0;
    index = 0;
  }
  float return_bill() { return bill; }

  void display(BikeModel &obj) {
  invalid:
    int x = 0;
    cout << "Enter the accessories you want to apply: " << endl;
    goto options;
  repeat:
    cout << "Do you want to add any other accessories: " << endl;
  options:
    cout << "1. Mobile Holder " << endl
         << "2. Anti Scratch Mask " << endl
         << "3. Bike Cover " << endl
         << "4. Liquid Polish " << endl
         << "5. Fog Light" << endl
         << "6. Bike Gloves " << endl
         << "7. Exit Portal " << endl;
    cin >> x;

    switch (x) {
    case 1:
      cout << "Mobile Holder is Selected." << endl;
      accessories[index] = "Mobile Holder";
      cout<<obj.return_model()<<endl;
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 5400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 6000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 5000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400") {
        price[index] = 5600;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 1;

    case 2:
      cout << "Mobile Holder is selected" << endl;
      accessories[index] = "Mobile Holder";
      cout << accessories[index] << endl;
      cout << obj.return_model() << endl;
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 1200;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 1500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 1000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400") {
        price[index] = 1350;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 2;

    case 3:
      cout << "Bike Cover is selected" << endl;
      accessories[index] = "Bike Cover";
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 250;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 150;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400") {
        price[index] = 350;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 3;

    case 4:
      cout << "Liquid Polish is selected" << endl;
      accessories[index] = "Liquid Polish";
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 2500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 4000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 2000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400") {
        price[index] = 3000;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 4;

    case 5:
      cout << "Fog Light is selected" << endl;
      accessories[index] = "Fog Light";
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 400;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 350;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400") {
        price[index] = 450;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 5;

    case 6:
      cout << "Bike Gloves is selected" << endl;
      accessories[index] = "Bike Gloves";
      if (obj.return_model() == "Rivian XPulse") {
        price[index] = 6500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Hunter 350") {
        price[index] = 7500;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian Pulsar NS160") {
        price[index] = 6000;
        bill += price[index];
        index++;
      } else if (obj.return_model() == "Rivian RT400 ") {
        price[index] = 7000;
        bill += price[index];
        index++;
      }
      goto repeat;
      break;
      // return 6;

    case 7:
      cout << "Thank You for using our portal" << endl;
      break;
      // return 7;

    default:
      cout << "Invalid Input" << endl;
      goto invalid;
    }
  }
};

void billing(Bike_Accessories &obj) {
  cout << "Accessories: " << endl;
  for (int i = 0; i < obj.index; i++) {
    cout << "Accessory no." << i + 1 << ": " << endl;
    cout << obj.accessories[i] << endl;
    cout << obj.price[i] << endl;
  }
  cout << "Final bill Amount: " << obj.bill << endl;
}

bool isFileEmptyService(const string &filename) {
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

void writeOutputToFile2Service(string model,float bill) {
  ofstream outputFile("Accessories.txt", ios::app);
  string filename = "Accessories.txt";
  if (outputFile.is_open() && isFileEmptyService(filename)) {
    outputFile << "Model\t\tTotal Bill" << endl;
    outputFile <<  model << "\t\t\t\t"<< bill << endl;
    outputFile.close();
    cout << "Accessories details written to Accessories.txt" << endl;
  }
  else if (outputFile.is_open() && !isFileEmptyService(filename)){
    outputFile <<  model << "\t\t\t\t"<< bill << endl;
    outputFile.close();
    cout << "Accessories details written to Accessories.txt" << endl;
  }
  else {
    cout << "Unable to open file for writing." << endl;
  }
}
  
  // Function to write output to a file in tabular form
void writeOutputToFileService(string vehicle_type, float ManualBill, float DigitalBill,float TotalBill) {
    ofstream outputFile("Servicing_Details.txt", ios::app);
    string filename = "Servicing_Details.txt";
    if (outputFile.is_open() && isFileEmptyService(filename)) {
      outputFile << "Vehicle_Type\tManual_Bill\tDigital_Bill\tTotal_Bill\n";
      outputFile << vehicle_type << "\t\t\t\t\t\t\t" << ManualBill << "\t\t\t\t\t" << DigitalBill<< "\t\t\t\t\t\t" << TotalBill << endl;
      outputFile.close();
      cout << "Servicing details written to Servicing_Details.txt" << endl;
    } 
    else if (outputFile.is_open() && !isFileEmptyService(filename)) {
      outputFile << vehicle_type << "\t\t\t\t\t\t\t" << ManualBill << "\t\t\t\t\t" << DigitalBill<< "\t\t\t\t\t\t" << TotalBill << endl;
      outputFile.close();
      cout << "Servicing details written to Servicing_Details.txt" << endl;
    } 
    else {
      cout << "Unable to open file for writing." << endl;
    }
}

// Function to display the sparepart details in tabular form
void writeOutputToFile1Service(string spare_part, float Price) {
  ofstream outputFile("SparePart_Details.txt", ios::app);
  string filename = "SparePart_Details.txt";
  if (outputFile.is_open() && isFileEmptyService(filename)) {
    outputFile << "Spare Parts\tPrice\n";
    outputFile << spare_part << "\t\t" << Price << endl;
    outputFile.close();
    cout << "SparePart details written to SparePart_Details.txt" << endl;
  } else if (outputFile.is_open() && !isFileEmptyService(filename)) {
    outputFile << spare_part << "\t\t" << Price << endl;
    outputFile.close();
    cout << "Servicing details written to Servicing_Details.txt" << endl;
  } else {
    cout << "Unable to open file for writing." << endl;
  }
}


//SERVICE MAIN

int serviceMain(){
   label:
  string x;
  cout << "Choose what you want to do: " << endl;
  cout << "1. Servicing" << endl;
  cout << "2. Spare Parts" << endl;
  cout << "3. Accessories" << endl;
  cout << "4. Exit" << endl;
  int y = inputInt(x);
  if(y == 1){
    cout << "Welcome to the Servicing Management System" << endl;
    Servicing serve;
    serve.serv();
    if (serve.return_vehicle() == "Car") {
      CarServing car;
      car.carServing();
      if (car.return_serviceType() == "Manual Servicing") {
        ManualServicing manual;
        manual.manualServicing();
        display(manual);
        writeOutputToFileService("Car", manual.return_bill(), 0, manual.return_bill());
      } 
      else {
        DigitalServicing digital;
        digital.digitalServicing();
        display(digital);
        if (digital.return_total() != 0) {
          cout << "Your Final bill is: " << digital.return_total() << endl;
          writeOutputToFileService("Car", digital.return_total() - digital.return_bill(), digital.return_bill(),digital.return_total());
        } 
        else {
          writeOutputToFileService("Car", 0, digital.return_bill(),digital.return_bill());
        }
      }
    } 
    else if (serve.return_vehicle() == "Bike") {
      BikeServing bike;
      bike.bikeServing();
      display(bike);
      writeOutputToFileService("Bike", 0, 0, bike.return_bill());
    } 
    else {
      HeavyVehicleServing heavy;
      heavy.heavyVehicleServing();
      display(heavy);
      writeOutputToFileService("Hea_Veh", 0, 0, heavy.return_bill());
    }
  }
  else if(y == 2){
    SpareParts spare;
    spare.spare();
    for(int i =0; i<spare.return_index2(); i++){
      writeOutputToFile1Service(spare.return_sparePart(i), spare.return_price1(i));
    }
    writeOutputToFile1Service("Total - ",spare.return_bill());
  }
  else if(y == 3){
    Vehicle vehicleObj;
    int x = vehicleObj.category();
    if (x == 1) {
      CarModel modelObj;
      modelObj.modelSelection();
      Car_Accessories accesObj;
      accesObj.display(modelObj);
      billing(accesObj);
      writeOutputToFile2Service(modelObj.return_model(), accesObj.return_bill());
    }
    else if(x ==2){
      BikeModel modelObj;
      modelObj.modelSelection();
      Bike_Accessories accesObj;
      accesObj.display(modelObj);
      billing(accesObj);
      writeOutputToFile2Service(modelObj.return_model(), accesObj.return_bill());
    }
    else{
      cout<<"Thank You for using our portal"<<endl;
    }
  }
  else if(y == 4){
    return 0;
  }
  else{
    cout << "Invalid input" << endl;
    goto label;
  }
  return 0;
}










// FINANCE DB
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


bool isFileEmptyFinance(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

// Function to write output to a file in tabular form
void writeOutputToFile(double totalCost, double Marketingcost, double Overheads, double Taxes, double  Maintenance, double Logistics) {
    ofstream outputFile("expenditure_details.txt", ios::app);
    string filename = "expenditure_details.txt";
    if (outputFile.is_open() && isFileEmptyFinance(filename)) {
        outputFile << "Marketing\tOverheads\tTaxes\tMaintenance\tLogistics\tTotal\n";
        outputFile << Marketingcost<<"\t\t"<<Overheads<<"\t\t"<< Taxes<<"\t\t\t"<< Maintenance<<"\t\t\t"<<Logistics<<"\t\t"<<totalCost << endl;
        outputFile.close();
        cout << "Expenditure details written to expenditure_details.txt" << endl;
    }
    else if (outputFile.is_open() && !isFileEmptyFinance(filename)) {
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
    if (outputFile.is_open() && isFileEmptyFinance(filename)) {
        outputFile << "Bikes \t Cars \t Heavy Vehicles \t Servicing \t Accessories \t Spare Parts \t Total Sales\n";
        outputFile << BikeSales<<"\t\t"<<CarSales<<"\t\t"<< Heavyvehicles<<"\t\t\t"<< Servicing<<"\t\t\t"<<Accessories<<"\t\t"<<spareparts<<"\t\t"<<totalsales<< endl;
        outputFile.close();
        cout << "Sales details written to sales.txt" << endl;
    }
    else if (outputFile.is_open() && !isFileEmptyFinance(filename)) {
        outputFile << BikeSales<<"\t\t"<<CarSales<<"\t\t"<< Heavyvehicles<<"\t\t\t"<< Servicing<<"\t\t\t"<<Accessories<<"\t\t"<<spareparts<<"\t\t"<<totalsales << endl;
        outputFile.close();
        cout << "Expenditure details written to expenditure_details.txt" << endl;
    } 
    else {
        cout << "Unable to open file for writing." << endl;
    }
}


int financeMain(){
     cout << "Welcome Finance Database of RIVIAN MOTOR " << endl;
    
    while (true) {
        cout << "Please enter your choice:" << endl;
        cout << "1. Enter Expenditure" << endl;
        cout << "2. Enter Total Sales" << endl;
        cout << "3. Exit" << endl;

        string choice;
        //cin >> choice;
        int res1 =inputInt(choice);
        int res =res1;

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
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    
    return 0;
}

// customer db

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
      cout << i << ". " << " RIVIAN " << validCarModels[i - 1] << endl; 
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

//customer Main

int customerMain(){
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






int main() {

    cout<<"\n***WELCOME TO RIVIAN MOTORS***"<<endl;

    bool final = true ;
    while(final){
        cout << " Please enter your choice "<<endl;
        cout << "1. EMPLOYEE DATABASE " << endl;
        cout << "2. CAR DATABASE" << endl;
        cout << "3. BIKE DATABASE" << endl;
        cout << "4. HEAVY VEHICLE DATABASE" << endl;
        cout << "5. SERVICE DATABASE" << endl;
        cout << "6. FINANCE DATABASE" << endl;
        cout << "7. CUSTOMER DATABASE" << endl;

        string misc ;
        int final = inputInt(misc);

        switch (final){
            case 1 :{
                employeeMain();
                break;
            }
            case 2 :{
                carMain();
                break;
            }
            case 3 :{
                bikeMain();
                break;
            }

            case 4:{
              //heavy vehicle
            }
            case 5 :{
                serviceMain();
                break;
            }
            case 6 :{
             financeMain();
             break;
            }

            case 7 :{
              customerMain();
              break;
            }

            default :{
                cout<<"invalid"<<endl;
            }
        }

    }

    return 0;
}