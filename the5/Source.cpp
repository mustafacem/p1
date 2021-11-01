#include <iostream>
#include <string>
#include "strutils.h"
#include <fstream>     
#include <vector>
using namespace std;
//mustafa cem buyukalpelli
struct kedi{
int sra;
double zaman;
string gemici, gemi,trh,SID,BID,RDATE;

};
/*
void new_order(vector<int> & a){
// pre: a contains a.size() elements
// post: elements of a are sorted in non-decreasing order
    int j, k, temp, minIndex, numElts = a.size();
    for(k=0; k < numElts - 1; k++){
        minIndex = k;             // minimal element index
        for(j=k+1; j < numElts; j++)
            if (a[j] < a[minIndex])
               minIndex = j;     // new min, store index
        temp = a[k];         // swap min and k-th elements
        a[k] = a[minIndex];
        a[minIndex] = temp;
    }
}*/

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
void parcalaczg(string str,double & bok)
{
	int length,ina;
	  string kelime;
	  str += " ";
      length = str.length();
	  bok = 0;
        ina = 0;
    for (int i = 0; i < length; i++) 
    {
       if(int(str.at(i)) != 45 && int(str.at(i)) != 32)
        {
         kelime+=str.at(i);   
            
            
        }else{
			//cout<<ina<<" a   a "<<kelime<<endl;
			if (ina == 0)
			{
				//cout<<atoi(kelime)<<endl;
				bok	 +=  (atoi(kelime)*365);
				//cout<<bok<<endl;
			}
     
			if (ina == 1)
			{
				//cout<<atoi(kelime)<<endl;
				bok	 +=  (atoi(kelime)*30);
				//cout<<bok<<endl;
				//cout<<kelime<<endl;
			}
     
			if (ina == 2)
			{
				
				//cout<<atoi(kelime)<<endl<<endl;
				bok	 +=  (atoi(kelime)*1);
				//cout<<bok<<endl;
				//bok = bok/10000;		
				//cout<<atoi(kelime)<<endl;
			}
     
			ina +=1;
            kelime= "";
        }
        
    }

}


void parcala1(string str,string & SID,string & gemi)
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



				   if (SID == sid)
				 {
				//cout<<SID<<" Q   Q  "<<sid<<endl; 
				gemi = "";
			    gemi +=sal;
			    gemi +="(";
			   gemi += sal1;
			  gemi += ")";

			}
        }

        
    }

}

void esek(string str,string & SID,string & gemi)
{
	int length,ina;
	  string kelime,sal,sal1,sal2,sal3;
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
			 if (SID == sal)
				 {
	
				gemi = "";
			    gemi +=sal1;
			    gemi +="(";
				gemi +=sal3;
				gemi += ",";
			   gemi += sal2;
			  gemi += ")";

			   } 
        }
        
    }

}
void parcala(string str,string & SID,string & BID ,string & RDATE)
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
				SID = kelime;
			}
     
			if (ina == 1)
			{
				BID = kelime;
			}
     
			if (ina == 2)
			{
				RDATE =kelime;
			}
     
			ina +=1;
            kelime= "";
        }
        
    }

}



int main ()
{
	ifstream input,input1,input2,input3;
	string filename,filename1,makarna,fl0,fl1;
	string SID,BID,RDATE;
	bool dg;
	int te,bos,SAY;
	te = -1;
	bos =0;
	SAY= 0;
		cout<<"Enter filename for reservation database: ";
		cin>>filename;
		count(filename, dg);
		if(dg == true){
		input.open(filename.c_str());  
				while(getline(input,makarna))
				{
					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					te +=1;
				}
				input.close();

				vector<kedi> ugandt(te);

				input.open(filename.c_str());  
				while(getline(input,makarna))
				{
					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (SAY >= 1)
					{
					parcala(makarna,ugandt[SAY-1].SID,ugandt[SAY-1].BID,ugandt[SAY-1].RDATE);
					parcalaczg(ugandt[SAY-1].RDATE, ugandt[SAY-1].zaman);
					

					}
					
						SAY +=1;
					
				}
				input.close();
				//cout<<ugandt.size()<<endl;
				        double zamana;
						string SIDA,BIDA,RDATEA;
						for(,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,)
						{
							for(int a = 0; a < te; a++)
							{
								if(ugandt[i].zaman < ugandt[a].zaman  )
								  {
									  zamana= ugandt[i].zaman ;
									  SIDA = ugandt[i].SID ;
									  BIDA = ugandt[i].BID ;
									  RDATEA = ugandt[i].RDATE;
									  ugandt[i].zaman = ugandt[a].zaman;
									  ugandt[i].BID = ugandt[a].BID;
									  ugandt[i].SID = ugandt[a].SID;
									  ugandt[i].RDATE = ugandt[a].RDATE;
									  ugandt[a].zaman = zamana;
									  ugandt[a].SID = SIDA;
									  ugandt[a].BID = BIDA;
									  ugandt[a].RDATE = RDATEA;
              
              
								  }
							}
						}
						fl0 = "Sailors.txt";
						fl1 = "Boats.txt";
						SAY= 0;
						input1.open(fl1.c_str());  
				while(getline(input1,makarna))
				{
					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (SAY >= 1)
					{
						for (int i = 0; i < te; i++)
						{
						parcala1(makarna,ugandt[i].BID,ugandt[i].);
						}
					}
						
						SAY +=1;
					
				}
				input1.close();
				SAY= 0;
				input2.open(fl0.c_str());  

				while(getline(input2,makarna))
				{

					if (makarna[makarna.length()-1] == '\r'){
						makarna = makarna.substr(0, makarna.length()-1);
					}
					if (SAY >= 1)
					{

						for (int i = 0; i < te; i++)
						{
							esek(makarna,ugandt[i].SID,ugandt[i].gemici);
						}

						
					}
						
						SAY +=1;
					
				}
				input2.close();


				for(int i = 0; i < te; i++)
							{
	
								cout<<ugandt[i].RDATE<<" -> "<<ugandt[i].gemici<<" has reserved "<<ugandt[i].gemi<<endl;
							}



		}else
		{
			cout<<"Cannot open the files. Exiting..."<<endl;
		}


	return 0;
}