#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int t = 0;
class a
{
  char bus_number[20], bus_arrival[20], bus_depart[20], b_from[20], b_to[20], bus_seat[8][4][10];
  char bus_driver[20];
//  string bus_driver[20];

public:
  void add_new_number_of_bus();
  void reservation();
  void empty();
  void view();
  void avail();
  void position(int i);
}
bus[5];
void bus_line(char ch)
{
  for (int x = 80; x > 0; x--)
    cout << ch;
}

//case1
void a::add_new_number_of_bus()
{
  cout << "\t\t\t\t\t\t\t\tEnter Bus Number: ";
  cin >> bus[t].bus_number;

  cout << "\n\t\t\t\t\t\t\t\tEnter Driver's Name: ";
  cin >> bus[t].bus_driver;

  cout << "\n\t\t\t\t\t\t\t\tArrival Time: ";
  cin >> bus[t].bus_arrival;

  cout << "\n\t\t\t\t\t\t\t\tDeparture Time: ";
  cin >> bus[t].bus_depart;

  cout << "\n\t\t\t\t\t\t\t\tFrom: ";
  cin >> bus[t].b_from;

  cout << "\n\t\t\t\t\t\t\t\tTo:";
  cin >> bus[t].b_to;

  bus[t].empty();
  cout << "\n\n\t\t\t\t\t#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$"
       << "\n\t\t\t\t\t\t\t\tNew Bus Added Successfully \t\t\t"
       << "\n\t\t\t\t\t#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$\n\n";
  t++;
}

//case2
void a::reservation()
{
  int bus_seat;
  char no[20];
top:
  cout << "Bus Number: ";
  cin >> no;

  int y;
  for (y = 0; y <= t; y++)
  {
    if (strcmp(bus[y].bus_number, no) == 0)
      break;
  }
  while (y <= t)
  {
    cout << "\nSeat Number: ";
    cin >> bus_seat;
    if (bus_seat > 32)
    {
      cout << "\nThere are only 32 Seats Available in this Bus.";
    }
    else
    {
      if (strcmp(bus[y].bus_seat[bus_seat / 4][(bus_seat % 4) - 1], "Empty") == 0)
      {
        cout << "Enter Passenger's Name: ";
        cin >> bus[y].bus_seat[bus_seat / 4][(bus_seat % 4) - 1];
        break;
      }
      else
        cout << "The Seat Number. is Already Reserved.\n";
    }
  }
  if (y > t)
  {
    cout << "Enter Correct Bus Number.\n";
    goto top;
  }
}

void a::empty()
{
  for (int x = 0; x < 8; x++)
  {
    for (int z = 0; z < 4; z++)
    {
    strcpy(bus[t].bus_seat[x][z], "Empty");
    }
  }
}

//case3
void a::view()
{
  int m;
  char number[20];

  cout << "Enter Bus Number: ";
  cin >> number;

  for (m = 0; m <= t; m++)
  {
    if (strcmp(bus[m].bus_number, number) == 0)
      break;
  }
  while (m <= t)
  {
    bus_line('*'); 
    cout << "\n\tBus Number:\t" << bus[m].bus_number
         << "\n\tDriver:\t" << bus[m].bus_driver 
         << "\n\tArrival Time:\t"<< bus[m].bus_arrival 
         << "\n\tDeparture Time:\t" << bus[m].bus_depart
         << "\n\tFrom:\t" << bus[m].b_from 
         << "\n\tTo:" << bus[m].b_to << "\n";

    bus_line('*');
    bus[0].position(m);

    int d = 1;
    for (int x = 0; x < 8; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        d++;
        if (strcmp(bus[m].bus_seat[x][y], "Empty") != 0)
          cout << "\nThe Seat no " << (d - 1) << " is Reserved for " << bus[m].bus_seat[x][y] << ".";
      }
    }
    break;
  }
  if (m > t)
    cout << "Enter Correct Bus Number: ";
}

void a::position(int l)
{
  int r = 0;
  t = 0;

  for (int x = 0; x < 8; x++)
  {
    cout << "\n";
    for (int z = 0; z < 4; z++)
    {
      r++;
      if (strcmp(bus[l].bus_seat[x][z], "Empty") == 0)
      {
        cout.width(10);
        cout.fill(' ');
        cout << r << ".";
        cout.width(10);
        cout.fill(' ');
        cout << bus[l].bus_seat[x][z];
        t++;
      }
      else
      {
        cout.width(10);
        cout.fill(' ');
        cout << r << ".";
        cout.width(10);
        cout.fill(' ');
        cout << bus[l].bus_seat[x][z];
      }
    }
  }
  cout << "\n\nThere are " << t << " Seats Empty in Bus Number: " << bus[l].bus_number;
}

//case4
void a::avail()
{
  for (int y = 0; y < t; y++)
  {
    bus_line('*');
    cout << endl << "Bus Number:  " << bus[y].bus_number 
	     << "\nDriver: " << bus[y].bus_driver
         << "\nArrival Time: " << bus[y].bus_arrival 
		 << "\nDeparture Time: "<< bus[y].bus_depart 
		 << "\nFrom: " << bus[y].b_from 
		 << "\nTo: "<< bus[y].b_to 
		 << "\n";

    bus_line('*');
    //bus_line('_');
  }
}

int main()
{
  system("cls");
  int w;
  while (1)
  {
    // system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t    SIMPLE BUS RESERVATION SYSTEM";
    cout << "\n\t\t\t\t\t###################################################################################################################";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t1.Add New Bus Number\n"
         << "\t\t\t\t\t\t\t\t2.Reservation\n"
         << "\t\t\t\t\t\t\t\t3.Show Reservation\n"
         << "\t\t\t\t\t\t\t\t4.Buses Available \n"
         << "\t\t\t\t\t\t\t\t5.Exit"
         << "\n\n\t\t\t\t\t###################################################################################################################";
    
    cout << "\n\n\t\t\tEnter your Choice:- ";
    cin >> w;

    switch (w)
    {
    case 1:
      bus[t].add_new_number_of_bus();
      break;

    case 2:
      bus[t].reservation();
      break;

    case 3:
      bus[0].view();
      break;

    case 4:
      bus[0].avail();
      break;

    case 5:
      exit(0);
    }
  }
  return 0;
}