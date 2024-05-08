#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

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

float inputFloat(string n) {
  string n1 = n;
n1:
  cin.ignore(0, '\n');
  getline(cin, n1);
  int v = 0; //x = 0, y = 0;
  for (char i : n1) {
    if ((i >= '0' && i <= '9') || i == '.') {
      v = 1;
    } else {
      cout << "Invalid input!!" << endl;
      // v=0;
      break;
    }
  }

  while (v == 0) {
    goto n1;
  }

  // int m = stoi(n);
  float q = stof(n1);

  return q;
}

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

int main() {
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