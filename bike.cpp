#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
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

float inputFloat(string n)
{
  string n1 = n;
n1:
  cin.ignore(0, '\n');
  getline(cin, n1);
  int v = 0, x = 0, y = 0;
  for (char i : n1)
  {
    if ((i >= '0' && i <= '9') || i == '.')
    {
      v = 1;
    }
    else
    {
      cout << "Invalid input" << endl;
      break;
    }
  }

  while (v == 0)
  {
    goto n1;
  }
  float q = stof(n1);
  return q;
}

// File handling function
bool isFileEmpty(const string &filename)
{
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

// Function to write output to a file in tabular form
void writeOutputToFileBike(int *arr)
{
  ofstream outputFile("bike_details.txt", ios::app);
  string filename = "bike_details.txt";
  if (outputFile.is_open() && isFileEmpty(filename))
  {
    outputFile << "Rivian Xpulse 200 standard\tRivian Xpulse 200 premium\tMetro Dapper\tMetro Rebel\t\tRetro Factory\tSingle ABS\tDual ABS\tBluetooth\tBRZ\t\tPremium\t\tStealth Black Edition\n";
    outputFile << "\t\t" << arr[0] << "\t\t\t\t\t\t\t\t" << arr[1] << "\t\t\t\t\t" << arr[2] << "\t\t\t\t" << arr[3] << "\t\t\t\t" << arr[4] << "\t\t\t\t" << arr[5] << "\t\t\t" << arr[6] << "\t\t\t" << arr[7] << "\t\t" << arr[8] << "\t\t\t" << arr[9] << "\t\t\t" << arr[10] << endl;
    outputFile.close();
    cout << "Bike details written to bike_details.txt" << endl;
  }
  else if (outputFile.is_open() && !isFileEmpty(filename))
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

// Main Function
int main()
{
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