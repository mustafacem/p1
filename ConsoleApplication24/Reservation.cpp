#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "Reservation.h"
/*
Sailor::Sailor ()
// postcondition: all private fields initialized     
{
	//id = 27;
}*/

struct kedi{
int sboatid ,ssaiolrid;
double zaman;
Date des;

};
int Sailor::setid(int n)
{
	id = n;
	return id ;
}
double Sailor::setage(double n)
{
	age = n;
	return age ;
}
double Sailor::setrank(double n)
{
	rank = n;
	return rank ;
}
string Sailor::setname(string n)
{
	name = n;
	return name ;
}
int Sailor::Roll()
{
	//cout<<id;
	return id ;
}

void Sailor::Roll2id()
{
	cout<<id;
	
}
void Sailor::Roll2name()
{
	cout<<name;
	
}void Sailor::Roll2age()
{
	cout<<age;
	
}void Sailor::Roll2rank()
{
	cout<<rank;
	
}
int Sailor :: getid()
{
	return id;
}
void Sailor::Rollhep()
{
	cout<<id<<" q   q "<<name<<" a   a "<<age <<" a    a "<<rank<<endl ;
	
}
int Sailor::Roll3(int n)
{
	id = n;
	return id ;
}



int Boat::setid(int n)
{
	id = n;
	return id ;
}
string Boat::setname(string n)
{
	name = n;
	return name ;
}
string Boat::setcolor(string n)
{
	color = n;
	return color ;
}

void Boat::Roll2name()
{
	cout<<name;
	
}
void Boat::Roll2color()
{
	cout<<color;
	
}
void Boat::Roll2hep()
{
	cout<<id<< "x   x"<<name<<" s   s " <<color<<endl;
	
}

int Boat::rsetid()
{
	
	return id ;
}
Date Reservation::setdate(int n,int m, int k )
{
	resDate = Date(n,m,k);
	 
	return resDate ;
}
Date Reservation::setdate(Date n )
{
	resDate = n;
	 
	return resDate ;
}
Sailor Reservation::setsal( Sailor LAKS)
{
	sailor =  LAKS;
	return sailor;
}
Boat Reservation::setboat( Boat LAKS)
{
	boat =  LAKS;
	return boat;
}
Boat Reservation::rsetboat( )
{

	return boat;
}
Sailor Reservation::rsetsal( )
{

	return sailor;
}
double Reservation::rsetzaman( )
{

	return zaman;
}

double Reservation::setdatez(int n,int m, int k )
{
	 zaman = n*30+m+k*365;
	 zaman = Date(n,m,k).Absolute();
	 
	return zaman ;
}
double Reservation::setdateza(int n,int m, int k )
{
	// zaman = 0;
	 
	return zaman ;
}
void Reservation::Roll2()
{
	//cout<<zaman<<"  <zaman1 tarih  >"<<resDate<<endl; Sailor mal,Boat esek
	
}
void Reservation::hermaster()
{
	cout<< resDate <<"  "<<endl;
		sailor.Roll2name();
}
void Reservation::kral()
{
	
	cout<<resDate<<" -> ";
		sailor.Roll2name();
		cout<<"(";
		sailor.Roll2age();
		cout<<",";
		sailor.Roll2rank();
		cout<<") has reserved ";
		boat.Roll2name();
		cout<<"(";
		boat.Roll2color();
		cout<<")"<<endl;
}

vector<Reservation> Reservations:: AddaReservation( Reservation al)
{
	Reservation bok;
	reservations1.push_back(al);
	//deservations1.push_back(bok);
	return reservations1;
}

void Reservations:: rol31()
{
	cout<<reservations1.size()<<endl;
}
int  Reservation:: setboatid(Boat k)
{
	boatid = k.rsetid();
	return boatid ; 
}

int  Reservation:: rsetboatid()
{
	
	return boatid ; 
}
void Reservations:: rol22()
{

	for (int i = 0; i < reservations1.size(); i++)
		{
			//cout << reservations1.size()<<reservations1[i].zaman<< endl;
	}


 
}
double Reservation:: getzaman()
{
	return resDate.Absolute();
 
}
void Reservation:: of()
{
	cout<<resDate.Absolute();
 
}
 int  Reservation:: getid()
{
	return boatid;
 
}


vector<Reservation> Reservations:: deleteres( int a)
{
	    reservations1.erase(reservations1.begin()+a);
		//cout<<"sildim"<<reservations1[0].boat.rsetid<<endl;
  return reservations1;
}

vector<Reservation> Reservations:: getr( )
{
	    //reservations1.erase(reservations1.begin()+a);
		//cout<<"sildim"<<reservations1[0].boat.rsetid<<endl;
  return reservations1;
}

Reservation Reservation::sort(Reservation mal,Reservation esek)
{
	if(mal.zaman >esek.zaman )
	{
		cout<<"sounda";
		
	}


	return mal ;

}
//void findareservation(Date a , Date b );      
void Reservations:: findareservation( Date a , Date b,vector<Reservation> c )
{
	
	bool dolu = false;
		 vector<Reservation> al ;
		 int bok= 0;
		
		 
	if (a.Absolute() < b.Absolute())
	{
		Date OK  = a;
		a = b;
		b = OK;
	}
	for (int i = 0; i < reservations1.size(); i++)
	{
		//cout<<"OFFF"<<i<<endl;
 		 int mal = c[i].getzaman();
		// cout<< mal<<"  66666666666";
		// int mal1 = c[i].getid();
		// bool dolu = false;
		 // vector<Reservation> al ;
		// vector<Reservation> al ;
		 //cout<<reservations1.size()<<endl;
		 //out<<mal<< " 2   2 "<< a.Absolute()<<" 1  1 "<<b.Absolute()<<endl; 
		 //cout<<mal<<"   as@@@da"<<a.Absolute()<<endl;
		 //cout<<a.Absolute() << " 55 " <<b.Absolute()<<"gg "<<mal<<endl;
		 if (a.Absolute()>= mal && mal>=b.Absolute())
		 { 
			// cout<<"GIRDIM!!! "<<endl;
			// cout<<"test "<< Date(mal)<<"  test1 " <<mal<<endl;
			 dolu = true;
			// al.push_back(c[i]);
			 al.push_back(c[i]);
			
			
		} 
		 bok +=1;
		 //cout<<bok<<" bok "<<al.size()<<endl;
		 if (dolu == true && bok ==  reservations1.size() )
		 {  
			 cout<<"Find Results:"<<endl;
			 for (int i = 0; i < al.size(); i++)
			 { 
				 //cout<<al.size()<<endl;
				 al[i].kral();
			 }
			 cout<<endl;
	       }
		 
     }
	
	


}
vector<Reservation> Reservations:: SET(  )
{

	return  reservations1;
}
void Reservations:: findareservation( int a , Date b , vector<Reservation> AL)
{
	bool dolu = false;
	 vector<Reservation> al ;
	int bok = 0;
	
	for (int i = 0; i < reservations1.size(); i++)
	{
		
			//AL[i].of();
		////	cout<<endl;
			int sa = AL[i].getid();
		int xa = AL[i].getzaman();
		//cout<<xa<<"  "<<sa  <<endl;

		//cout<<xa <<"SSSSSSSS" <<sa<<endl;
		if(sa == a){
			if(xa == b.Absolute())
		{
		 dolu = true;
			// al.push_back(c[i]);
			 al.push_back(AL[i]);
		
		}

			bok +=1;
		 cout<<bok<<" bok "<<al.size()<<endl;
		 if (dolu == true && bok ==  reservations1.size() )
		 {  
			 cout<<"Find Results:"<<endl;
			 for (int i = 0; i < al.size(); i++)
			 { 
				 //cout<<al.size()<<endl;
				 al[i].kral();
			 }
			 cout<<endl;
	       }
		
	       
		 
     }
}
}
// postcondition: number of rolls updated
// 

/*random 'die' roll returned     
{
    RandGen gen;    // random number generator
    
    myRollCount= myRollCount + 1;         // update # of times die rolled
    return gen.RandInt(1,mySides);        // in range [1..mySides]
}*/