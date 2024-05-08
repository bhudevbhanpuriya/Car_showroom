#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 20

int inputInt(string n) {
    string n1=n;
    n1:
    cout<<"Enter : ";
    cin.ignore(0,'\n');
    getline(cin,n1);
    int v = 0 ;
    for(char i : n1) {
        if ((i >= '0' && i <= '9')){
            v = 1;
        } 
        else {
          cout<<"Invalid input"<<endl;
          //v=0;
          break;
        }
    }
    while(v == 0) {
       goto n1;
    }
    int m = stoi(n1);
    //float q = stof(n1);
    return m;
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

bool isFileEmpty(const string &filename) {
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

void writeOutputToFile2(string model,float bill) {
  ofstream outputFile("Accessories.txt", ios::app);
  string filename = "Accessories.txt";
  if (outputFile.is_open() && isFileEmpty(filename)) {
    outputFile << "Model\t\tTotal Bill" << endl;
    outputFile <<  model << "\t\t\t\t"<< bill << endl;
    outputFile.close();
    cout << "Accessories details written to Accessories.txt" << endl;
  }
  else if (outputFile.is_open() && !isFileEmpty(filename)){
    outputFile <<  model << "\t\t\t\t"<< bill << endl;
    outputFile.close();
    cout << "Accessories details written to Accessories.txt" << endl;
  }
  else {
    cout << "Unable to open file for writing." << endl;
  }
}
  
  // Function to write output to a file in tabular form
void writeOutputToFile(string vehicle_type, float ManualBill, float DigitalBill,float TotalBill) {
    ofstream outputFile("Servicing_Details.txt", ios::app);
    string filename = "Servicing_Details.txt";
    if (outputFile.is_open() && isFileEmpty(filename)) {
      outputFile << "Vehicle_Type\tManual_Bill\tDigital_Bill\tTotal_Bill\n";
      outputFile << vehicle_type << "\t\t\t\t\t\t\t" << ManualBill << "\t\t\t\t\t" << DigitalBill<< "\t\t\t\t\t\t" << TotalBill << endl;
      outputFile.close();
      cout << "Servicing details written to Servicing_Details.txt" << endl;
    } 
    else if (outputFile.is_open() && !isFileEmpty(filename)) {
      outputFile << vehicle_type << "\t\t\t\t\t\t\t" << ManualBill << "\t\t\t\t\t" << DigitalBill<< "\t\t\t\t\t\t" << TotalBill << endl;
      outputFile.close();
      cout << "Servicing details written to Servicing_Details.txt" << endl;
    } 
    else {
      cout << "Unable to open file for writing." << endl;
    }
}

// Function to display the sparepart details in tabular form
void writeOutputToFile1(string spare_part, float Price) {
  ofstream outputFile("SparePart_Details.txt", ios::app);
  string filename = "SparePart_Details.txt";
  if (outputFile.is_open() && isFileEmpty(filename)) {
    outputFile << "Spare Parts\tPrice\n";
    outputFile << spare_part << "\t\t" << Price << endl;
    outputFile.close();
    cout << "SparePart details written to SparePart_Details.txt" << endl;
  } else if (outputFile.is_open() && !isFileEmpty(filename)) {
    outputFile << spare_part << "\t\t" << Price << endl;
    outputFile.close();
    cout << "Servicing details written to Servicing_Details.txt" << endl;
  } else {
    cout << "Unable to open file for writing." << endl;
  }
}

int main() {
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
        writeOutputToFile("Car", manual.return_bill(), 0, manual.return_bill());
      } 
      else {
        DigitalServicing digital;
        digital.digitalServicing();
        display(digital);
        if (digital.return_total() != 0) {
          cout << "Your Final bill is: " << digital.return_total() << endl;
          writeOutputToFile("Car", digital.return_total() - digital.return_bill(), digital.return_bill(),digital.return_total());
        } 
        else {
          writeOutputToFile("Car", 0, digital.return_bill(),digital.return_bill());
        }
      }
    } 
    else if (serve.return_vehicle() == "Bike") {
      BikeServing bike;
      bike.bikeServing();
      display(bike);
      writeOutputToFile("Bike", 0, 0, bike.return_bill());
    } 
    else {
      HeavyVehicleServing heavy;
      heavy.heavyVehicleServing();
      display(heavy);
      writeOutputToFile("Hea_Veh", 0, 0, heavy.return_bill());
    }
  }
  else if(y == 2){
    SpareParts spare;
    spare.spare();
    for(int i =0; i<spare.return_index2(); i++){
      writeOutputToFile1(spare.return_sparePart(i), spare.return_price1(i));
    }
    writeOutputToFile1("Total - ",spare.return_bill());
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
      writeOutputToFile2(modelObj.return_model(), accesObj.return_bill());
    }
    else if(x ==2){
      BikeModel modelObj;
      modelObj.modelSelection();
      Bike_Accessories accesObj;
      accesObj.display(modelObj);
      billing(accesObj);
      writeOutputToFile2(modelObj.return_model(), accesObj.return_bill());
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
}