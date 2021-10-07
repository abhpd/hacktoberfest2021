#include <iostream.h>
#include <conio.h>

int segitiga (int als, int tggi) 
	{
	    int Luas;
	    Luas=0.5*als*tggi;
	    return Luas;
	}
	
	int persegi (int ssi)
	{
	    int LPersgi;
	    LPersgi=ssi*ssi;
	    return LPersgi;
	}

int main () 
{
    int angka;
    float lagi, LPersgi,Luas,ssi,als,tggi;
   
		cout<<"=============================================="<<endl;  
		cout<<"Program Hitung Luas Persegi Dan Luas Segitiga"<<endl;  
		cout<<"=============================================="<<endl;  
		cout<<endl; 
	    cout<<" 1. Hitung Luas Persegi"<<endl;
	    cout<<" 2. Hitung Luas Segitiga"<<endl;
		cout<<endl; 
		cout<<"=============================================="<<endl; 
	    cout<<"Masuk Pilihan (1 atau 2)	: ";cin>>angka;
	    cout<<endl; 

	switch (angka){
	    case 1: 
			cout<<"Masukan Sisi Persegi		: ";
		    cin>>ssi;
		    LPersgi=persegi(ssi);
		    cout<<"=============================================="<<endl; 
		    cout<<endl; 
		    cout<<"Hasil Luas Persegi		: "<<LPersgi<<endl;
			cout<<endl; 
		    cout<<"=============================================="<<endl;
		    cout<<endl; 
	    break;
	    case 2: 
			cout<<"Masukan Alas Persegi		: ";
		    cin>>als;
		    cout<<"Masukan Tinggi Persegi		: ";
		    cin>>tggi;
			cout<<"=============================================="<<endl;
			cout<<endl;  
		   	Luas=segitiga (als,tggi);
		   	cout<<"Hasil Luas Segitiga		: "<<Luas<<endl;
			   cout<<endl; 
		   	cout<<"=============================================="<<endl;
		   	cout<<endl; 
	   break;
	   
	}

getch ();
}