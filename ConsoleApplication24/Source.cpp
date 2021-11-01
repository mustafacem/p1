#include <iostream>
#include <string>
#include "strutils.h"
#include "Reservation.h"
#include "date.h"
#include <fstream>     
#include <vector>

using namespace std;
//mustafa cem buyukalpelli
struct kedi{
int sboatid ,ssaiolrid;
double zaman;
Date des;

};
struct kedi2{
int sboatid ,ssaiolrid;
double zaman;
Date des,des2;

};

void count(string & filename,bool & dg)
{
		ifstream input,input1;
	  input.open(filename.c_str());  
	if (input.fail())  
		{
		//cout << "Error: Cannot open file " << filename << endl;
		dg = false;
		}
	
		else {



			dg= true;


			}
    

   input.close();
}

void parcalatrh2(string str,double &zmn,Date & ks)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  int SID =0 ,BID= 0,BUK = 0;

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 45 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				
				SID = atoi(kelime);
			}
     
			if (ina == 1)
			{
				BID = atoi(kelime);
			}
     
			if (ina == 2)
			{
				BUK = atoi(kelime);
			}
			if(ina ==2){
			//cout<<SID<<"*    * "<<BID<<"*    *"<<BUK<<endl;

			zmn = BID*30+BUK+SID*365;
			ks = Date(BID,BUK,SID);
			//zmn = Date(BID,BUK,SID).Absolute();
         	   }
 			ina +=1;
            kelime= "";
        }
        
    }

}
void parcalatrh(string str, Reservation & RDATE,double &zmn,Date & ks)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  int SID =0 ,BID= 0,BUK = 0;

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 45 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				
				SID = atoi(kelime);
			}
     
			if (ina == 1)
			{
				BID = atoi(kelime);
			}
     
			if (ina == 2)
			{
				BUK = atoi(kelime);
			}
			if(ina ==2){
			//cout<<SID<<"*    * "<<BID<<"*    *"<<BUK<<endl;
			RDATE.setdate(BID,BUK,SID);
			RDATE.setdatez(BID,BUK,SID);
			zmn = BID*30+BUK+SID*365;
			ks = Date(BID,BUK,SID);
			//zmn = Date(BID,BUK,SID).Absolute();
			
         	   }
 			ina +=1;
            kelime= "";
        }
        
    }

}
void parcalayar(string str, int & te,int & te2,int & te3,bool& dg ,int & yrk)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				if (kelime == "A")
				{
					te+= 1;
					yrk = 2;
				} else if (kelime == "D")
				{
					te2+= 1;
					yrk = 0;
					dg = false;
				}else if(kelime == "F")
				{
					te3+= 1;
					yrk = 1;
					dg = false;
				}
			}
        
			ina +=1;
            kelime= "";
        }
        
    }

}
void parcalamak(string str,Sailor & SID,Boat & BID ,Reservation & RDATE, int &boatd,int &sailord,double & zmn,Date & ks)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				
			}
     
			if (ina == 1)
			{


				SID.Roll3(atoi(kelime));
				boatd =(atoi(kelime));
			}
     
			if (ina == 2)
			{
				BID.setid(atoi(kelime));
				sailord = (atoi(kelime));
			}
			if (ina == 3)
			{
				parcalatrh(kelime,RDATE,zmn, ks);
			}
     
			ina +=1;
            kelime= "";
        }
        
    }

}

void parcala1(string str,int  SID,Boat & gemi2)
{
	int length,ina;
	  string kelime,sid,sal,sal1;
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				sid = kelime;
			}
     
			if (ina == 1)
			{
				sal = kelime;
			}
     
			if (ina == 2)
			{
				sal1 =kelime;
			}
			//cout<<kelime<<endl;
			ina +=1;
            kelime= "";



				   if (itoa(SID) == sid)
				 {
				//cout<<SID<<" Q   Q  "<<sid<<endl; 
			/*	gemi = "";
			    gemi +=sal;
			    gemi +="(";
			   gemi += sal1;
			  gemi += ")";*/
					 gemi2.setid(atoi(sid));
					 gemi2.setcolor(sal1);
					 gemi2.setname(sal);

			}
        }

        
    }

}
void esek(string str,int  SID, Sailor & gemi2)
{
	int length,ina;
	  string kelime,sal,sal1,sal2,sal3, gemi;
	  gemi ="";
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{

			if (ina == 0)
			{
				sal = kelime;
			}
     
			if (ina == 1)
			{
				sal1 = kelime;
			}
     
			if (ina == 2)
			{
				sal2 =kelime;

					if (sal2[sal2.length()-1] == '0')
						sal2 = sal2.substr(0, sal2.length()-2);
			}
			if (ina == 3)
			{
				sal3 =kelime;
				if (sal3[sal3.length()-1] == '0')
						sal3 = sal3.substr(0, sal3.length()-2);
			}
     
     
			ina +=1;
            kelime= "";
			 if (itoa(SID) == sal)
				 {
					 gemi2.setid(atoi(sal));
					 gemi2.setname(sal1);
					 gemi2.setage(atof(sal3));
					 gemi2.setrank(atof(sal2));
					 /*
				gemi = "";
			    gemi +=sal1;
			    gemi +="(";
				gemi +=sal3;
				gemi += ",";
			   gemi += sal2;
			  gemi += ")";
			  */
			   } 
        }
        
    }

}
void parcalamak2(string str, int &boatd,int &sailord,double & zmn,Date & ks)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				
			}
     
			if (ina == 1)
			{


				
				boatd =(atoi(kelime));
			}
     
			if (ina == 2)
			{
				
				sailord = (atoi(kelime));
			}
			if (ina == 3)
			{
				parcalatrh2(kelime,zmn, ks);
			}
     
			ina +=1;
            kelime= "";
        }
        
    }

}

void parcalamak3(string str, int &boatd,int &sailord,double & zmn,Date & ks,Date & ks1)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  

        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 32 && int(str.at(i)) != 9 )
        {
         kelime+=str.at(i);   
            
            
        }else{


			if (ina == 0)
			{
				
			}
     
			if (ina == 1)
			{


				
				boatd =(atoi(kelime));
			}
     
			if (ina == 2)
			{
				
				sailord = (atoi(kelime));
			}
			if (ina == 3)
			{
				parcalatrh2(kelime,zmn, ks);
			}
			if (ina == 4)
			{
				parcalatrh2(kelime,zmn, ks1);
			}
     
     
			ina +=1;
            kelime= "";
        }
        
    }

}

int main ()
{
	/*
	Reservation makars;
	vector<Reservation> ugandt(12);

	
	Sailor tesrak;
    tesrak.Roll2();
	vector<Sailor> ugandt(12);
	ugandt[2].Roll2();
	ugandt[3].Roll3();
	ugandt[3].Roll2();
	*/
	
	
	ifstream input,input1,input2,input3;
	string filename,filename1,filename99,makarna,fl0,fl1;
	string SID,BID,RDATE;
	bool dg;
	int te,bos,SAY,merak,sar,yrk,te2,te3;
	te = 0;
	te2 = 0;
	te3 = 0;
	bos =0;
	SAY= 0;
	merak = 0;
	sar = 0;
	yrk = 0;
	cout<<"Enter filename for reservation database: ";
		cin>>filename;
		//filename ="Reservations1.txt";
		count(filename, dg);
		if(dg == true)
		
   {

		input.open(filename.c_str());  
				while(getline(input,makarna))
				{
					if (makarna[makarna.length()-1] == '\r')
					{
						makarna = makarna.substr(0, makarna.length()-1);
					}
					parcalayar(makarna, te,te2,te3 ,dg,yrk);
					sar +=1;
				}
				input.close();
				vector<kedi> ofk(te);
				vector<kedi> ofd(te2);
				
				vector<kedi2> off(te3);
				vector<Sailor> ugandta(te);
				vector<Boat> ugandtb(te);
				vector<Reservation> ugandtc(te);
				vector<Reservations> ugandtd(te);
						
		int temp,temp1;
		double temp3;
		Date yalaka;
					for(int i = 0; i < te; i++)
						{
							for(int a = 0; a < te; a++)
							{
								if(ofk[i].zaman < ofk[a].zaman  )
								  {
									  yalaka = ofk[i].des;
									  temp3 = ofk[i].zaman ;
									  temp = ofk[i].ssaiolrid ;
									  temp1 = ofk[i].sboatid ;
									
									  ofk[i].zaman = ofk[a].zaman;
									  ofk[i].ssaiolrid = ofk[a].ssaiolrid;
									  ofk[i]. sboatid = ofk[a].sboatid;
									 ofk[i].des= ofk[a].des;;
									  ofk[a].zaman =  temp3;
									  ofk[a].ssaiolrid =  temp;
									  ofk[a].sboatid =  temp1;
									  ofk[a].des= yalaka;
									  
									  
              
              
								  }
							}
						}

	
		input.open(filename.c_str());  
		while(getline(input,makarna) && merak < te )
				{
					if (makarna[makarna.length()-1] == '\r')
					{
						makarna = makarna.substr(0, makarna.length()-1);
					}
					//cout<<"/    /"<<makarna<<endl<<"/    /"<<merak<<"   "<<te<<endl;
					parcalamak(makarna,ugandta[merak], ugandtb[merak],ugandtc[merak],ofk[merak].ssaiolrid,ofk[merak].sboatid,ofk[merak].zaman,ofk[merak].des);
					merak +=1;
					
				}
		input.close();
		/*
		for (int i  = 0; i  < te ; i ++)
		{
			cout<<ofk[i].ssaiolrid<<"  "<<ofk[i].sboatid<<"   "<<ofk[i].zaman<<endl<<endl; 
		}*/
	//int x	= ugandta[2].getid();
	//cout<<"  wsdd"<< x <<"sds"<<endl;
	
	   	for(int i = 0; i < te; i++)
						{
							for(int a = 0; a < te; a++)
							{
								if(ofk[i].zaman < ofk[a].zaman  )
								  {
									  yalaka = ofk[i].des;
									  temp3 = ofk[i].zaman ;
									  temp = ofk[i].ssaiolrid ;
									  temp1 = ofk[i].sboatid ;
									
									  ofk[i].zaman = ofk[a].zaman;
									  ofk[i].ssaiolrid = ofk[a].ssaiolrid;
									  ofk[i]. sboatid = ofk[a].sboatid;
									 ofk[i].des= ofk[a].des;;
									  ofk[a].zaman =  temp3;
									  ofk[a].ssaiolrid =  temp;
									  ofk[a].sboatid =  temp1;
									  ofk[a].des= yalaka;
									  
									  
              
              
								  
								
								  }
							}
						}

/*
		for (int i = 0; i < ofk.size(); i++)
				{
					cout<<ofk[i].des<<"  "<<ofk[i].zaman<<endl;
				}*/
				
				
		  
	   SAY =0;
		  fl0 = "Sailors.txt";
				input1.open(fl0.c_str());  
				while(getline(input1,makarna))
				{
					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (SAY >= 1)
					{
						for (int i = 0; i < te; i++)
						{
							esek(makarna,ofk[i].ssaiolrid,ugandta[i]);
						}
					}
						
						SAY +=1;
					
				}
				input1.close();
				fl1 = "Boats.txt";
						SAY= 0;
						input2.open(fl1.c_str());  
				while(getline(input2,makarna))
				{
					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (SAY >= 1)
					{
						for (int i = 0; i < te; i++)
						{
							parcala1(makarna,ofk[i].sboatid,ugandtb[i]);
						}
					}
						
						SAY +=1;
					
				}
				input2.close();

				/*
						for (int i  = 0; i  < te ; i ++)
		{
			ugandta[i].Rollhep();
			cout<<endl;
			ugandtb[i].Roll2hep();
			cout<<endl;
		}*/
				
			for (int i  = 0; i  < te ; i ++)
		{
			//gandta[i].Rollhep();
			ugandtc[i].setdate(ofk[i].des);
			ugandtc[i].setboat(ugandtb[i]);
			ugandtc[i].setsal(ugandta[i]);
			//ugandtc[i].kral();
			ugandtd[0].AddaReservation(ugandtc[i]);
			//ugandtd[0].rol31();
		}
		//	ugandtd[0].rol31();

	
		//	cout<<"booookk nnaahha"<<&Reservation::rsetboatid<<endl;
						
			/*		for (int i  = 0; i  < te ; i ++)
		{
			cout<<ofk[i].ssaiolrid<<"  "<<ofk[i].sboatid<<"   "<<ofk[i].zaman<<endl; 
		}*/
		  
     dg = false;
 
		int son = ofk.size()+off.size()+ofd.size();	
		int son2 =son-off.size();
	 filename99 = filename;
	  		input3.open(filename99.c_str());  
				while(getline(input3,makarna))
				{
					//cout<<"test iyi1"<<endl;
					if (makarna[makarna.length()-1] == '\r')
					{
						makarna = makarna.substr(0, makarna.length()-1);
					}
					parcalayar(makarna, te,te2,te3,dg,yrk);
					

					if (yrk == 0)
					{
						//cout<<"test iyi2"<<endl;
						//cout<<makarna<<endl;
						//cout<< te2<<endl<<te3<<endl;
					}
					//cout<<makarna<<endl<<yrk<<endl;

				}
				input3.close();
				//ugandtd[0].rol31();
				//cout<<"cxzcxzcz"<<ofd.size()<<"  asads ";
				int salak = 0;
				
				input3.open(filename.c_str()); 
				while(getline(input3,makarna)  )
				{
					if (makarna[makarna.length()-1] == '\r')
					{
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (salak >= merak &&  salak < ofd.size()+merak)
					{
						
					//cout<<"/    /"<<makarna<<" adda "<<"/    /"<<merak<<"   "<<te<<endl;
					parcalamak2(makarna,ofd[salak-merak].ssaiolrid,ofd[salak-merak].sboatid,ofd[salak-merak].zaman,ofd[salak-merak].des);
					//cout<<"yen"<<ofd[salak-merak].ssaiolrid<<"asas"<<ofd[salak-merak].sboatid<<endl;
					//cout<<makarna<<endl;
					//cout<<ofd[salak-merak].ssaiolrid<<" @////@ "<< ofd[salak-merak].zaman <<endl;
					if (ofd[salak-merak].ssaiolrid == 0 && ofd[salak-merak].zaman == 0)
					{ 
						
						//cout<<"balk"<<ofd[salak-merak].ssaiolrid<<endl;
						bool  buldumu;
					buldumu =false;
					vector<int> kutu;
					int kutu2 =0 ;
						for (int i = 0; i < ofk.size(); i++)
						{
							if (ofd[salak-merak].sboatid == ofk[i].sboatid)
							{
								
									buldumu= true;
							kutu.push_back(i);
							kutu2 +=1;
							}
						}

						if (buldumu == false)
						{
							cout<<"Error: Could not delete reservation for boat "<<ofd[salak-merak].sboatid <<endl<<endl;
						}else
						{
							for (int i = 0; i < kutu2; i++)
							{
								ofk.erase(ofk.begin() + kutu[i]);
								 ugandtd[0].deleteres(kutu[i]);
							}
						}
						
	
					}
					
					 else if (ofd[salak-merak].sboatid == 0 && ofd[salak-merak].zaman == 0)
					{ 
						
						//cout<<"balk1"<<ofd[salak-merak].ssaiolrid<<endl;
						bool  buldumu;
					buldumu =false;
					vector<int> kutu;
					int kutu2 =0;
						for (int i = 0; i < ofk.size(); i++)
						{
							if (ofd[salak-merak].ssaiolrid == ofk[i].ssaiolrid)
							{
								
								buldumu= true;
							kutu.push_back(i);
							kutu2 +=1;
							ofk.erase(ofk.begin() + i);
								 ugandtd[0].deleteres(i);
							}
						}

						if (buldumu == false)
						{
							cout<<"Error: Could not delete reservation for sailor id "<<ofd[salak-merak].ssaiolrid <<endl<<endl;
						}
						{
							for (int i = 0; i < kutu2; i++)
							{
								ofk.erase(ofk.begin() + kutu[i]);
								 ugandtd[0].deleteres(kutu[i]);
							}
						}
						
					}else
					{
						
				      
						bool  buldumu;
					    buldumu =false;
						vector<int> kutu;
						int kutu2=0;
						for (int i = 0; i < ofk.size(); i++)
						{
							if (ofd[salak-merak].sboatid == ofk[i].sboatid && ofd[salak-merak].ssaiolrid == ofk[i].ssaiolrid && ofd[salak-merak].zaman == ofk[i].zaman )
							{
							buldumu= true;
							kutu.push_back(i);
							kutu2 +=1;
							 //ofk.erase(ofk.begin() + i);
								// ugandtd[0].deleteres(i);

							}

						}
						if (buldumu == false)
						{
							cout<<"Error: Could not delete reservation "<<'"'<<ofd[salak-merak].ssaiolrid<<" "<<ofd[salak-merak].sboatid<<" "<<ofd[salak-merak].des.Year()<<"-"<<ofd[salak-merak].des.Month()<<"-"<<ofd[salak-merak].des.Day()<<'"'<<endl<<endl;
						} else
						{
							for (int i = 0; i < kutu2; i++)
							{
								ofk.erase(ofk.begin() + kutu[i]);
								 ugandtd[0].deleteres(kutu[i]);
							}
						}
					}
					
					
					//cout<<ofd[salak-merak].ssaiolrid<<"  "<<ofd[salak-merak].sboatid<<"   "<<ofd[salak-merak].zaman<<endl<<endl; 
					}
					if (salak >= son2 &&  salak < son)
					{
						
						//cout<<"asa";
						//cout<<off.size()<<salak-son2;
						int buyucu = 0;
						parcalamak3(makarna,off[buyucu].ssaiolrid,off[buyucu].sboatid,off[buyucu].zaman,off[buyucu].des,off[buyucu].des2);
						///cout<<off[buyucu].ssaiolrid<<"yarrak"<<off[buyucu].sboatid<<endl;
						//cout<<"yen"<<off[buyucu].ssaiolrid<<"asas"<<off[buyucu].sboatid<<"sad"<<off[buyucu].des<<off[buyucu].des2<<off[buyucu].zaman<<endl;
						//cout<<off[buyucu].ssaiolrid<<"  "<<off[buyucu].sboatid<<endl;
						if (off[buyucu].ssaiolrid == 0 && off[buyucu].sboatid == 0)
						{
							
						vector<Reservation> mok = ugandtd[0].getr(); 
						//cout<<"sdsd"<<mok.size()<<" mal";
						
						ugandtd[0].findareservation( off[buyucu].des, off[buyucu].des2 , mok);
						//	
							
						}
						 else if (off[buyucu].ssaiolrid == 0)
						{
							vector<Reservation> mok = ugandtd[0].getr(); 
							
							
							ugandtd[0].findareservation( off[buyucu].sboatid, off[buyucu].des , mok);
						}
						 else if (off[buyucu].sboatid== 0)
						{
							vector<Reservation> mok = ugandtd[0].getr(); 
							
							
							ugandtd[0].findareservation( off[buyucu].ssaiolrid, off[buyucu].des , mok);
						}
						buyucu +=1;
					}
					
					//cout<<"/    /"<<makarna<<" adda "<<"/    /"<<merak<<"   "<<te<<endl;
					//parcalamak2(makarna,ofd[salak-merak].ssaiolrid,ofd[salak-merak].sboatid,ofd[salak-merak].zaman,ofd[salak-merak].des);
					//cout<<son<<"  asdsa"<<son2<<endl;

					//cout<<salak<<"   "<<merak<<endl;
					salak +=1;
				}
				
				input3.close();

				/*
				for (int i = 0; i < ofk.size(); i++)
				{
					cout<<ofk[i].des<<"  "<<ofk[i].zaman<<endl;
				}*/
				
				

		
	
		}else
		{ 
			cout<<"Cannot open the files. Exiting...";
		}
		
	
		return 0;
 }
