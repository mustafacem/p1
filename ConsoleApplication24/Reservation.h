
#include <iostream>
#include <vector>
#include <string>
#include "date.h"

class Sailor
{
	public:
		Sailor()
		{
			id = 0;
			name = "Jane Doe";
			age = 0;
			rank = 0;
		}
		double setrank(double);
		double setage(double); 
		int setid(int); 
		string setname(string);
	int Roll();  
	void Rollhep(); 
	void Roll2id();
	void Roll2name();
	void Roll2age();
	void Roll2rank();
	int Roll3(int);
	int getid();
	private:
		int id;
		string name;
		double age;
		double rank;
};

class Boat
{
	public:
		Boat()
		{
			id = 0;
			name = "Default";
			color = "Default";
		}
		int setid(int);
		int rsetid(int);

		string setcolor(string);
		string setname(string);
		void Roll2name();
		void Roll2color();
		void Roll2hep();
		int  rsetid();
	private:
		int id;
		string name;  
		string color;
};

class Reservation
{
	public:
		Reservation()
		{
			Sailor s;
			sailor = s;
			Boat b;
			boat = b;
			Date d(1,1,1900);
			resDate = d;

			
			zaman = 0;
		}
		Date setdate(int,int,int);
		Date setdate(Date);
		Sailor setsal(Sailor);
		Boat setboat(Boat);
		double getzaman( );
		int  getid( );
		Boat rsetboat();
		Sailor rsetsal();
		double rsetzaman();
		int setboatid(Boat);
		int rsetboatid();
		int setsailorid(Sailor);
		
		double setdatez(int,int,int);
		double setdateza(int,int,int);
		void Roll2();// Add here the Print function su sekil February 19 2014 -> Dustin(45,7.1) has reserved INTERLAKE(BLUE) Sailor,Boat
		void hermaster();
		void kral();
		void of();
		Reservation sort(Reservation,Reservation);
		
	private:
		double zaman;
		int boatid;
		Date resDate;
		Sailor sailor;
		Boat boat;
};

class Reservations
{
	public:
		// Fill this part with the member functions
		// 1. Add a Reservation
	vector<Reservation> AddaReservation(Reservation );
	vector<Reservation> getr( );
	vector<Reservation> SET( );
		void rol22();
		void rol31();

		// 2. Delete a Reservation
		vector<Reservation> deleteres(int );
		// 3.1. Find a Reservation (sailor and boat ids are 0)
		// 3.2. Find a Reservation (only sailor id is 0)
		// 3.3. Find a Reservation (only boat id is 0)

		void findareservation(Date , Date ,vector<Reservation>);                       // construct date with default value
		void findareservation(int , Date,vector<Reservation>);          // construct date from absolute #
  //  void findareservation(int , Date,vector<Reservation>);       // construct date with specified values
		
	
	private:
		int mal;
		vector<Reservation> reservations1;
		
};



