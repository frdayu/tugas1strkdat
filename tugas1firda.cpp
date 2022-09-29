    //Tugas1StrukturData//
    //Firda Ayu Dwi Aryanti//
    //A11.2021.13586//
    //43.UG.1//

    #include<iostream>
	#include<conio.h>
	#include<windows.h>
	#define MAX 8  //mempunyai fungsi untuk definisi banyaknya max


	void gotoxy(int x, int y)
	{
	    COORD coord;
	    coord.X=x;
	    coord.Y=y;
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	}


	using namespace std;
	struct paket
	{
	    int top = 1;
	    char jenis_brg[30];
	    int berat;
	    char kota[30];
	}Tumpukan;


	struct paket kirim[MAX];


	//-------------------------------------------
	bool isEmpty()
	{
	    if(Tumpukan.top == 1){
	        return 1;
	    } else{
	        return 0;
	    }


	}


	bool isFull()
	{
	    if(Tumpukan.top > MAX){
	        return 1;
	    } else{
	        return 0;
	    }
	}

	//-------------------------------------------
	void push()
	{
	    if(isFull()){
	        gotoxy(40,14); cout << "Maaf Stack Penuh !";
	        gotoxy(40,15);cout<<"Press Any Key...";
	        getch();
	    } else{
	        gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
	        cin>>kirim[Tumpukan.top].jenis_brg;
	        gotoxy(20,16);cout<<"Inputkan Berat           :";
	        cin>>kirim[Tumpukan.top].berat;
	        gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
	        cin>>kirim[Tumpukan.top].kota;
	        Tumpukan.top++;
	    }
	}


	//-------------------------------------------
	void pop()
	{
	    if(isEmpty()){
	        gotoxy(40,14); cout << "Maaf Data Kosong";
	        gotoxy(40,15);cout<<"Press Any Key...";
	        getch();
	    } else{
	        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
	        gotoxy(40,13);cout<<kirim[Tumpukan.top-1].jenis_brg<<" ";
	        cout<<kirim[Tumpukan.top-1].berat<<" Kg ";
	        cout<<kirim[Tumpukan.top-1].kota<<endl<<endl;


	        gotoxy(40,15);cout<<"Press Any Key...";
	        getch();
	        Tumpukan.top--;
	    }
	}


	//-------------------------------------------
	void tampildata()
	{
	    if(!isEmpty()){
	        gotoxy(40,9);cout<<"Daftar Kiriman Paket"<<endl;
	        for(int a=1; a < Tumpukan.top; a++)
	        {
	            gotoxy(40,19-a);
	            cout<<a<<" ";
	            cout<<kirim[a].jenis_brg<<" ";
	            cout<<kirim[a].berat<<" ";
	            cout<<kirim[a].kota;
	        }
	        gotoxy(40,20);
	        cout<<"Press Any Key...";
	        getch();
	        //harus Ijin --> #include<conio.h>
	    }else {
	        gotoxy(40,10); cout << "Tumpukan Kosong";
	        gotoxy(40,15);cout<<"Press Any Key...";
	        getch();
	    }


	    if(isFull()){
	        gotoxy(40,10); cout << "Tumpukan Penuh";
	        getch();
	    }
	}

	//*******************************************
	void bersihlayar()
	{
	    for(int a=0;a<80;a++)
	    {
	        for(int b=0;b<=24;b++)
	        {
	            gotoxy(a,b);cout<<" ";
	        }
	    }
	}


	int main()
	{
	    int pilih;
	    int datake=1;
	    do
	    {
	        bersihlayar();
	        gotoxy(1,1);cout<<"MENU UTAMA";
	        gotoxy(1,2);cout<<"1. Tambah Data";
	        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
	        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
	        gotoxy(1,5);cout<<"9. Keluar"<<endl;


	        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
	        cin>>pilih;
	        if(pilih==1)
	            { /*Menambahkan Data Baru Diletakan di DATAKE*/
	                push();
	            }
	        if(pilih==2)
	            { /*Menghapuskan Data Terakhir (DATAKE-1*/
	                pop();
	            }
	        if(pilih==3)
                { /*Menampilkan Data Meliputi Data ke-1 hingga DATAKE*/
                    tampildata();


	    }
	    while(pilih!=9);
	    return 0;
	}

