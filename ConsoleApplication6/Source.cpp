#include <iostream>
#include <string>
using namespace std;



bool inputCheck(double kl,double l1 ,int l2, double phu1,int phu2, double plu1,int plu2,double  wl1 ,int wl2,double wl3)
{

	if (kl < 30)
	{
		cout<<"Weight out of range!"; 
		return false;
	}
	
	if (wl3 < 0 | wl3 >35 )
	{
		cout<<"Lifted weight out of range!";
		return false;
	}



	if (l2 < 0 |l2 > 50)
	{
		cout<<"Reps out of range!";
		return false;
	}
	if (phu2 < 0 |phu2 > 50)
	{
		cout<<"Reps out of range!";
		return false;
	}
	if (plu2 < 0 | plu2 > 50)
	{
		cout<<"Reps out of range!";
		return false;
	}
	if (wl2 < 0 | wl2 > 50)
	{
		cout<<"Reps out of range!";
		return false;
	}




	if (l1< 0 | l1 >2000)
	{
		cout<<"Minute out of range!";
		return false;
	}

	
	if (phu1< 0 | phu1 >2000)
	{
		cout<<"Minute out of range!";
		return false;
	}


	if (plu1< 0 | plu1 >2000)
	{
		cout<<"Minute out of range!";
		return false;
	}

	
	return true;


}

void calculateMET(string trpe , int p2 , double & met)
{
	//ex
	if(trpe == "Lunges")
	{
		if(p2 < 15)
		{
		met = met + 3;
		}else if(p2>=15 & p2 <30 )
		{
		met = met + 6.5;
		}
		else if(p2>=30  )
		{
		met = met + 10.5;
		}
	}
	if(trpe == "Push Ups")
	{
		if(p2 < 15)
		{
		met = met + 4;
		}else if(p2>=15  )
		{
		met = met + 7.5;
		}
	
	}
	if(trpe == "Pull Ups"){
		if(p2 < 25)
		{
		met = met + 5;
		}else if(p2>=25  )
		{
		met = met + 9;
		}
	}
	



}


void calculateWeightLiftMET (int wl2,double wl3,double & metwl)
{

    if(wl2<20 & wl3 <5 )
	{
	metwl = metwl + 3;

	}else if(wl2>=20 & wl2<40 & wl3 <5 )
	{
	metwl = metwl + 5.5;
	}else if( wl2>40 & wl3 <5 )
	{
	metwl = metwl + 10;

	}
	
	else if(wl2<20 & wl3 >=5 & wl3 <15)
	{
	metwl = metwl + 4;
	
	}else if(wl2>=20 & wl2<40 & wl3 >=5 & wl3 <15)
	{
	metwl = metwl + 7.5;
	}else if( wl2>40 & wl3 >=5 & wl3 <15)
	{
	metwl = metwl + 12;
	}


	else if(wl2<20 & wl3 >=15 )
	{
	metwl = metwl + 5;
	
	}else if(wl2>=20 & wl2<40 & wl3 >=15)
	{
	metwl = metwl + 9;
	}else if( wl2>40 & wl3 >=15)
	{
	metwl = metwl + 13.5;
	}



}



void computeResults (double kl,double l1 ,int l2, double phu1,int phu2, double plu1,int plu2,double  wl1 ,int wl2,double metl,double metphu,double metpl,double metwl,double & calol,double & calophu,double & calopl, double & calowl)


{
	
	 calculateMET("Lunges", l2,  metl);
	  calculateMET("Push Ups", phu2, metphu);
	  calculateMET("Pull Ups", plu2,  metpl);

	  calol = l1*(metl*3.5*kl)/200;
	 calophu =phu1*(metphu*3.5*kl)/200;
	calopl = plu1*(metpl*3.5*kl)/200;
	calowl = wl1*(metwl*3.5*kl)/200;
 cout<<metl<<"  "<<metphu<<"  "<<metpl<<"  "<<metwl<<endl<<endl<<endl;

}


void displayResults (double cal,double calol,double calophu,double calopl,double calowl,double wl3 ,int l1 ,int phu1,int plu1,int wl1,double kl,double metl,double metphu,double metpl,double metwl )
{
	if(cal== (calol+calophu + calopl+ calowl))
	{

	cout <<"From lunges, you burned "<<calol<< " calories."<<endl;
	cout <<"From push ups, you burned "<<calophu<< " calories."<<endl;
	cout <<"From pull ups, you burned "<<calopl<< " calories."<<endl;
	cout <<"From weight lifting, you burned"<< calowl<< " calories."<<endl;
	cout <<"You burned" <<(calol+calophu + calopl+ calowl)<< " calories."<<endl;
	cout<<"Congratulations! You have reached your goal!";
	}
	else if(cal < (calol+calophu + calopl+ calowl))
	{

	cout <<"From lunges, you burned "<<calol<< " calories."<<endl;
	cout <<"From push ups, you burned "<<calophu<< " calories."<<endl;
	cout <<"From pull ups, you burned "<<calopl<< " calories."<<endl;
	cout <<"From weight lifting, you burned "<< calowl<< " calories."<<endl;
	cout <<"You burned " <<(calol+calophu + calopl+ calowl)<< " calories."<<endl;
	cout << "You have surpassed your goal! You can eat something worth " <<(calol+calophu + calopl+ calowl)-cal <<" calories :)";
	}
	else if(cal > (calol+calophu + calopl+ calowl))
	{

	cout <<"From lunges, you burned "<<calol<< " calories."<<endl;
	cout <<"From push ups, you burned "<<calophu<< " calories."<<endl;
	cout <<"From pull ups, you burned "<<calopl<< " calories."<<endl;
	cout <<"From weight lifting, you burned "<< calowl<< " calories."<<endl;
	cout <<"You burned " <<(calol+calophu + calopl+ calowl)<< " calories."<<endl<<endl; 

	cout << "You did not reach your goal by "<<(cal - (calol+calophu + calopl+ calowl))<<" calories.";
	cout<<"You need to do lunges "<< (cal - (calol+calophu + calopl+ calowl))/ ((metl*3.5*kl)/200) <<" minutes more to reach your goal or,"<<endl;
	cout<<"You need to do push ups "<< (cal - (calol+calophu + calopl+ calowl))/ ((metphu*3.5*kl)/200) <<" minutes more to reach your goal or,"<<endl;
	cout<<"You need to do pull ups "<< (cal - (calol+calophu + calopl+ calowl))/ ((metpl*3.5*kl)/200) <<" minutes more to reach your goal or,"<<endl;
	cout<<"You need to do weight lifting "<< (cal - (calol+calophu + calopl+ calowl))/ ((metwl*3.5*kl)/200) <<" minutes more to reach your goal."<<endl;
	cout <<((metl*3.5*kl)/200) << ((metphu*3.5*kl)/200)<< ((metpl*3.5*kl)/200) << ((metwl*3.5*kl)/200) ;
	cout<<metl<<metphu<<metpl<<metwl;
	 cout<<metl<<"  "<<metphu<<"  "<<metpl<<"  "<<metwl<<endl<<endl<<endl;
	}
}

void getInput(string isim , string trpe ,double & p1 ,int & p2, double & p3 )
{
	if(trpe == "Lunges"){
	cout<<isim<<", please enter minutes and repetitions in a week for the activities below."<<endl;
	cout<<"Lunges: " ;
	cin>>p1>>p2;
	fflush(stdin);
	cin.clear();
	
	}
	if(trpe == "Push Ups"){
	cout<<"Push Ups: " ;
	cin>>p1>>p2;
	fflush(stdin);
	cin.clear();
	}if(trpe == "Pull Ups"){
	cout<<"Pull Ups: " ;
	cin>>p1>>p2;
	fflush(stdin);
	cin.clear();
	}if(trpe == "Weight Lifting"){
		cout<<isim<<", please enter minutes, repetitions and lifted weight in a week for the activities below."<<endl;
	cout<<"Weight Lifting: ";
	cin>>p1>>p2>>p3;
	fflush(stdin);
	cin.clear();
	
	}
}




int main ()
{
string isim,trpe;
double kl,wl1,wl3,uganda,metl,metphu,metpl,metwl,l1,ger,phu1,plu1,calol,calophu,calopl,calowl;
int l2,phu2,plu2,wl2;

l1 = 30;
l2 = 30;
phu1 = 30;
phu2 = 30;
plu1= 30;
plu2 = 30;
wl1 = 1;
wl2 = 1;
wl3 = 1;
metl =0;
metphu =0;
metpl =0;
metwl =0;
ger =1 ;

 cout<<"Please enter your name: "; 
 cin >> isim;
 fflush(stdin);
 cin.clear();
 cout<<isim<<", please enter your weight(kg): ";



 cin >> kl;
 fflush(stdin);
 cin.clear();
 
 

 getInput(isim,"Lunges",l1,l2,ger);
 getInput(isim,"Push Ups",phu1,phu2,ger);
 getInput(isim,"Pull Ups",plu1,plu2,ger);
 getInput(isim,"Weight Lifting",wl1,wl2,wl3);

 cout<<isim<<", please enter your weekly calorie burn goal: ";
 cin >> uganda;
 fflush(stdin);
 cin.clear();


 if(inputCheck(kl,l1,l2,phu1,phu2,plu1,plu2,wl1,wl2,wl3) == false)
 {
 return 0;
 }
 

 calculateWeightLiftMET (wl2,wl3,metwl);
 computeResults ( kl, l1 , l2,  phu1, phu2, plu1, plu2,  wl1 , wl2, metl, metphu, metpl, metwl, calol, calophu, calopl, calowl);

 	 calculateMET("Lunges", l2,  metl);
	  calculateMET("Push Ups", phu2, metphu);
	  calculateMET("Pull Ups", plu2,  metpl);


  displayResults (uganda, calol, calophu, calopl, calowl, wl3 , l1 ,phu1, plu1,wl1,kl,metl, metphu, metpl,metwl);
  return 0;
}