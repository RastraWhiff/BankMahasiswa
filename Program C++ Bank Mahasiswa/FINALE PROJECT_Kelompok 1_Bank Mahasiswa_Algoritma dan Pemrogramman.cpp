#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
    	
struct nasabah
{
	string nama,alamat,tdk,password;
	long int norek,saldo;
	int tahun;
};
int ch;
int i,pil,x,pos;
int no;
long int setor,tarik;
string pas;
bool ada = false;
int n=0;
nasabah nas[50];

void cetak()
{
		system("cls");
		system ("color 3F");
        cout<<"\n";
        cout<<"\t +=======================================================+\n";
        cout<<"\t |          BANK MAHASISWA AMIKOM YOGYAKARTA             |\n";
        cout<<"\t +=======================================================+\n";
	    cout<<"\n\n";
	    cout<<" ========================================================================"<<endl;
	    cout<<"                             MENU TRANSAKSI                         "<<endl;
	    cout<<" ========================================================================"<<endl;
	    cout<<"\n";
	    cout<<"        +========================================================+"<<endl;
	    cout<<"        |                                                        |"<<endl;
	    cout<<"        |    1. Pendaftaran Nasabah                              |"<<endl;
		cout<<"        |    2. Setoran Tunai                                    |"<<endl;
		cout<<"        |    3. Penarikan Tunai                                  |"<<endl;
		cout<<"        |    4. Cetak Daftar Nasabah                             |"<<endl;
		cout<<"        |    5. Cari Nasabah                                     |"<<endl;
		cout<<"        |    6. Matrix Nasabah                                   |"<<endl;
		cout<<"        |    7. Hapus Nasabah                                    |"<<endl;
		cout<<"        |    8. Akumulasi Total Nasabah                          |"<<endl;
		cout<<"        |    9. Info Aplikasi/Program                            |"<<endl;
		cout<<"        |   10. Keluar                                           |"<<endl;
		cout<<"        |                                                        |"<<endl;
		cout<<"        +========================================================+"<<endl;
	    cout<<"\n\n";
	    cout<<" Masukkan Pilihan Anda = ";cin>>pil;
	    system("cls");
}
void setoran()
{
	nas[pos].saldo=nas[pos].saldo+setor;
}
void penarikan()
{
	nas[pos].saldo=nas[pos].saldo-tarik;
}
void cek_total()
{
	int i;
	int jumlah=0;
	
	for(i=0;i<n;i++)
	{
		jumlah = jumlah + nas[i].saldo;
	}
	cout<<" Jumlah Nasabah Bank Mahasiswa   = "<<i<<" Orang"<<endl;
	cout<<"\n";
	cout<<" Jumlah Total saldo Seluruh Nasabah Bank Mahasiswa = Rp."<<jumlah<<endl;
}
void daftar_nasabah()
{
	system ("color 8E");
				cout<<"\n";
				cout<<"\t\t\t    ========================================================="<<endl;
	    		cout<<"\t\t\t                 DAFTAR NASABAH MAHASISWA AMIKOM             "<<endl;
	    		cout<<"\t\t\t    ========================================================="<<endl;
				cout<<"\n";
				cout<<" ========================================================================================================================"<<endl;
				cout<<" || No ||     No Rekening    ||              Nama            ||       Alamat      ||      Total Saldo    ||    Tahun   ||"<<endl;
				cout<<" ||====||====================||==============================||===================||=====================||============||"<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" ||"<<setw(3)<<i+1<<" ||";
					cout<<setw(14)<<nas[i].norek<<"      ||";
					cout<<setw(25)<<nas[i].nama<<"     ||";
					cout<<setw(14)<<nas[i].alamat<<"     ||";
					cout<<"   Rp."<<setw(8)<<nas[i].saldo<<"       ||";
					cout<<setw(8)<<nas[i].tahun<<"    ||"<<endl;
				}
			   cout<<" ======================================================================================================================== "<<endl;
}

main()
{
	int j,k,baris,kolom;
    int m[baris][kolom];
    int bil[15][15];
	menu:
		//
	    cetak();
	
	    switch(pil)
	    {
	    	case 1 :
	    		system ("color 8E");
	    		lagi:
	    		cout<<"\n";
	    		cout<<"   ========================================================="<<endl;
	    		cout<<"                  FORMULIR PENDAFTARAN NASABAH              "<<endl;
	    		cout<<"   ========================================================="<<endl;
	    		cout<<"\n";
	    		cout<<" [ Minimal Masukkan 8 Nomor dalam pembuatan nomor Rekening ]"<<endl;
	    		cout<<"\n";
	    		
	    		cout<<" | Masukkan Nomor Rekening = ";cin>>no;
                cout<<" | Masukkan Password       = ";cin>>pas;
                cout<<" ";getline(cin,nas[n].tdk);
	    		for(i=0;i<n;i++)
	    		     {
	    		     	if(no == nas[i].norek && pas == nas[i].password)
	    		     	ada = true;
	    		     	else
	    		     	ada = false;
					 }
			    if(ada)
			         {
			         	cout<<"\n";
			         	cout<<" Nomor Rekening Tersebut Sudah Ada, Ulangi Lagi"<<endl;
			         	goto lagi;
					 }
				else
				     {
				     	cout<<"\n";
				     	cout<<"\n";
				     	cout<<"Masukkan Nama Anda        = ";getline(cin,nas[n].nama);
				     	cout<<"Masukkan Alamat           = ";getline(cin,nas[n].alamat);
				     	cout<<"Masukkan Tahun            = ";cin>>nas[n].tahun;
				     	cout<<"Masukkan Saldo Awal Anda  = Rp.";cin>>nas[n].saldo;
				     }
					 n = n+1;
					 nas[i].norek = no;
					 nas[i].password = pas;
					 cout<<"\n";
					 cout<<"          Nomor Rekening Anda Berhasil Ditambahkan     "<<endl;
					 cout<<" ======================================================"<<endl;
					 cout<<"\n";
					 cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
					 goto menu;
			case 2 :
				system ("color 8E");
				cout<<"\n";
				cout<<"   ========================================================="<<endl;
	    		cout<<"                     FORMULIR SETORAN TUNAI                 "<<endl;
	    		cout<<"   ========================================================="<<endl;
				cout<<"\n";
				cout<<" | Masukkan Nomor Rekening = ";cin>>no;
				
				for(i=0;i<n;i++)
				{
					if(no == (nas[i].norek))
					{
						pos = i;
						ada = true;
						break;
					}
					else
					    ada = false;
				}
				if(ada)
				    {
				    	cout<<" | Masukkan Password       = ";
				    	pas = "";
					    ch = _getch();
                         while(ch != 13)
                            {
                	            pas.push_back(ch);
                	            cout<<'*';
                	            ch = _getch();
				            }
				    	for(i=0;i<n;i++)
				        {
					        if(no == nas[i].norek && pas == nas[i].password)
					        {
						        pos = i;
						        ada = true;
						        pas = "";
						        break;
					        }
					        else
					            ada = false;
				        }
				        
				        system("cls");
				        if(ada)
				            {
				               cout<<"\n";
				               cout<<"   ========================================================="<<endl;
	    		               cout<<"                     FORMULIR SETORAN TUNAI                 "<<endl;
	    		               cout<<"   ========================================================="<<endl;
				               cout<<"\n";
				    	       cout<<" Nama Nasabah               = "<<nas[pos].nama<<endl;
				    	       cout<<" Alamat                     = "<<nas[pos].alamat<<endl;
				        	   cout<<" Saldo                      = Rp."<<nas[pos].saldo<<endl;
				        	   cout<<"\n";
				    	       cout<<" Masukkan Nominal Setoran = Rp.";cin>>setor;
				    	       //
				    	       setoran();
				    	       system("cls");
				    	       cout<<"\n";
				               cout<<"   ========================================================="<<endl;
	    		               cout<<"                     FORMULIR SETORAN TUNAI                 "<<endl;
	    		               cout<<"   ========================================================="<<endl;
				    	       cout<<"\n";
						       cout<<"          Setoran Anda Telah Berhasil Ditambahkan        "<<endl;
						       cout<<"\n";
						       cout<<" Nominal Setoran            = +Rp."<<setor<<endl;
						       cout<<" Jumlah Saldo Anda Sekarang =  Rp."<<nas[pos].saldo<<endl;
						       cout<<" Nama Nasabah               =  "<<nas[pos].nama<<endl;	
						       cout<<" Nomor Rekening             =  "<<nas[pos].norek<<endl;
				    	       cout<<" Alamat                     =  "<<nas[pos].alamat<<endl;
						   }
						else
						   {
						    cout<<"\n";
				    	    cout<<"\n Mohon Maaf Password Anda salah"<<endl;
				            cout<<" ===================================================="<<endl;
					        cout<<"\n";
				            cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				            goto menu;
				           }
				            
					}
				else
				   cout<<"\n Mohon Maaf Nomor Rekening Tidak Ditemukan"<<endl;
				   cout<<" ===================================================="<<endl;
				   cout<<"\n";
				   cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				   goto menu;
			case 3 :
				system ("color 1F");
				cout<<"\n";
				cout<<" ========================================================="<<endl;
	    		cout<<"               FORMULIR PENARIKAN UANG TUNAI              "<<endl;
	    		cout<<" ========================================================="<<endl;
				cout<<"\n";
				cout<<" | Masukkan Nomor Rekening = ";cin>>no;
				for(i=0;i<n;i++)
				{
					if(no == (nas[i].norek))
					{
						pos = i;
						ada = true;
						break;
					}
					else
					    ada = false;
				}
				if(ada)
				    {
				    	cout<<" | Masukkan Password       = ";
				    	pas = "";
				    	ch = _getch();
                         while(ch != 13)
                            {
                	            pas.push_back(ch);
                	            cout<<'*';
                	            ch = _getch();
				            }
				    	for(i=0;i<n;i++)
				        {
					        if(no == nas[i].norek && pas == nas[i].password)
					        {
						        pos = i;
						        ada = true;
						        pas = "";
						        break;
					        }
					        else
					            ada = false;
				        }
				        system("cls");
				        if(ada)
				            {
				            	cout<<"\n";
				                cout<<" ========================================================="<<endl;
	    		                cout<<"               FORMULIR PENARIKAN UANG TUNAI              "<<endl;
	    		                cout<<" ========================================================="<<endl;
				            	cout<<"\n";
				    	        cout<<" Nama Nasabah               = "<<nas[pos].nama<<endl;
				    	        cout<<" Alamat                     = "<<nas[pos].alamat<<endl;
				    	        cout<<" Saldo                      = Rp."<<nas[pos].saldo<<endl;
				    	        cout<<"\n";
				    	        cout<<" Masukkan Jumlah Penarikan = Rp.";cin>>tarik;
				    	        if(tarik<=(nas[pos].saldo))
				    	            {
				    	    	        //
				    	    	        penarikan();
				    	    	        system("cls");
				    	    	        cout<<"\n";
				                        cout<<" ========================================================="<<endl;
	    		                        cout<<"               FORMULIR PENARIKAN UANG TUNAI              "<<endl;
	    		                        cout<<" ========================================================="<<endl;
				    	    	        cout<<"\n";
				    	    	        cout<<"          Penarikan Telah Berhasil Dilakukan       "<<endl;
				    	    	        cout<<"\n";
						                cout<<" Nominal Penarikan          = -Rp."<<tarik<<endl;
						                cout<<" Jumlah Saldo Anda Sekarang =  Rp."<<nas[pos].saldo<<endl;
						                cout<<" Nama Nasabah               =  "<<nas[pos].nama<<endl;
						                cout<<" Nomor Rekening             =  "<<nas[pos].norek<<endl;
				    	                cout<<" Alamat                     =  "<<nas[pos].alamat<<endl;
						                cout<<"\n";
							        }
						        else
						        {
						
						        cout<<"\n Maaf Saldo Anda Tidak Mencukupi | Saldo Yang Anda Miliki Sekarang Adalah = Rp."<<nas[pos].saldo<<endl;
						        cout<<"\n";
						        cout<<" Jumlah Saldo Anda          = Rp."<<nas[pos].saldo<<endl;
						        cout<<" Nama Nasabah               = "<<nas[pos].nama<<endl;
						        cout<<" Nomor Rekening             = "<<nas[pos].norek<<endl;
					            }
						    }
						else
						   {
						    cout<<"\n";
				    	    cout<<"\n Mohon Maaf Password Anda salah"<<endl;
				            cout<<" ===================================================="<<endl;
					        cout<<"\n";
				            cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				            goto menu;
				           }
						    
					}
				else
				   cout<<"\n Mohon Maaf Nomor Rekening Tidak Ditemukan"<<endl;
				   cout<<" ===================================================="<<endl;
				   cout<<"\n";
				   cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				   goto menu;
			case 4 :
			   //
			   daftar_nasabah();
			   cout<<"\n";
			   cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
			   goto menu;
			case 5 :
				system ("color 8E");
				cout<<"\n";
				cout<<" ========================================================="<<endl;
	    		cout<<"          PENCARIAN DAFTAR NASABAH MAHASISWA AMIKOM       "<<endl;
	    		cout<<" ========================================================="<<endl;
				cout<<"\n";
				cout<<" | Masukkan Nomor Rekening Yang Akan Dicari = ";cin>>no;
				cout<<endl;
				for(i=0;i<n;i++)
				{
					if(no == (nas[i].norek))
					{
						pos = i;
						ada = true;
						break;
					}
					else
					ada = false;
				}
				if(ada)
				    {
				    	cout<<" Nomor Rekening             = "<<nas[pos].norek<<endl;
				    	cout<<" Nama Nasabah               = "<<nas[pos].nama<<endl;
				    	cout<<" Alamat                     = "<<nas[pos].alamat<<endl;
				    	cout<<" Saldo                      = Rp."<<nas[pos].saldo<<endl;
				    	cout<<"\n";
					}
				else
				   cout<<"\n Mohon Maaf Nomor Rekening Tidak Ditemukan"<<endl;
				   cout<<" ===================================================="<<endl;
				   cout<<"\n";
				   cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				   goto menu;
			case 6 :
				{
					//
			        daftar_nasabah();
			        cout<<"\n";
			        do{
		                cout<<"\n"; 
    	                cout<<"\t\t\t +======================================================+\n"; 
    	                cout<<"\t\t\t |               PROGRAM MATRIX NASABAH                 |\n"; 
    	                cout<<"\t\t\t +======================================================+\n"; 
 		                cout<<"\n====================================================================\n";
                        cout << "Masukkan banyak baris = ";
                        cin >> baris;
                        cout << "Masukkan banyak kolom = ";
                        cin >> kolom;
                        cout<<"\n"; 

                    } while (baris>16 ||kolom>16);

                    for (int j=0;j<baris;j++){
                       for (int k=0;k<kolom;k++){
                            cout << "Nomor Rekening [" <<j<<","<<k<< "] = ";
                            cin >> bil[j][k];
                        }
                    }
                    cout<<"\n";
                    cout<<"\t\t\t +======================================================+\n"; 
                    cout<<"\t\t\t |                 HASIL OUTPUT PROGRAM                 |\n"; 
                    cout<<"\t\t\t +======================================================+\n"; 
 	                cout<<"\n====================================================================\n";
                    cout << "Matriks Nomor Rekening ("<<baris<<"x"<<kolom<<")\n\n";
                    for (int j=0;j<baris;j++){
                        for(int k=0;k<kolom;k++){
        	                cout <<"|| "<<"Nomor Rekening = " <<bil[j][k]<< " || ";
                        }cout << endl;
                    }
				}
				cout<<"\n";
				cout<<" Masukkan Sembarang Angka Jika Ingin Kembali Ke Menu Utama = ";cin>>x;
				goto menu;
			case 7 :
				//
			    daftar_nasabah();
			    cout<<"\n";
			    cout<<"\t\t\t ========================================================="<<endl;
	    		cout<<"\t\t\t                HAPUS DATA NASABAH MAHASISWA              "<<endl;
	    		cout<<"\t\t\t ========================================================="<<endl;
				cout<<"\n";
				cout<<" Nomor Rekening yang akan di hapus = ";cin>>no;
				for(int i=0;i<n;i++)
				{
					if(no == nas[i].norek)
					{
						for(int pos=i;pos<10;pos++)
						{
							nas[pos].norek=nas[pos+1].norek;
							nas[pos].nama=nas[pos+1].nama;
							nas[pos].alamat=nas[pos+1].alamat;
							nas[pos].saldo=nas[pos+1].saldo;
							nas[pos].tahun=nas[pos+1].tahun;
							nas[pos].password=nas[pos+1].password;
						}
						n-=1;
						break;
					}
				}
				for(int h=0;h<n;h++)
				{
					cout<<" "<<nas[n].norek;
				}
				cout<<"\n";
				cout<<" Daftar Data Baru Nasabah = "<<endl;
				//
			    daftar_nasabah();
			    cout<<"\n";
				cout<<" Masukkan Sembarang Angka Jika Ingin Kembali Ke Menu Utama = ";cin>>x;
				goto menu;
			case 8 :
				{
					//
			        daftar_nasabah();
			        cout<<"\n";
					//
					cek_total();
	                cout<<"\n";
				    cout<<" Masukkan Sembarang Angka Jika Ingin Kembali Ke Menu Utama = ";cin>>x;
				    goto menu;
				}
			case 9 :
				{
				system ("color 8E");
				cout<<"\n";
				cout<<"\t\t    ===================================================="<<endl;
				cout<<"\t\t                    INFO APLIKASI/PROGRAM               "<<endl;
				cout<<"\t\t    ===================================================="<<endl;
				cout<<"\n";
				cout<<"   +=====================================================================================+"<<endl;
	            cout<<"   |     Aplikasi/Program Bank AMIKOM Yogyakarta ini kami buat untuk memudahkan          |"<<endl;
		        cout<<"   | Seorang Nasabah agar lebih mudah mengakses perbankan melalui Aplikasi/program ini   |"<<endl;
	        	cout<<"   |   Manfaat yang dapat didapatkan yaitu yang pertama ialah Nasabah bisa dengan mudah  |"<<endl;
		        cout<<"   |  mendaftarkan data diri, bisa menyetor dan manarik saldo dari masing-masing Nasabah |"<<endl;
		        cout<<"   | dan bahkan memudahkan operator untuk mencetak data Nasabah, mencari Nasabah, dan    |"<<endl;
		        cout<<"   |   program data Matrix. Program ini juga dilengkapi dengan keamanan Password         |"<<endl;
		        cout<<"   +=====================================================================================+"<<endl;
		        cout<<"\n";
				cout<<" = UNIVERSITAS AMIKOM YOGYAKARTA"<<endl;
				cout<<" = FALKUTAS       : ILMU KOMPUTER"<<endl;
				cout<<" = JURUSAN        : INFORMATIKA"<<endl;
				cout<<" = KELAS          : 21 IF 04"<<endl;
				cout<<" = MATA KULIAH    : ALGORITMA DAN PEMROGRAMAN"<<endl;
				cout<<" = DOSEN PENGAMPU : Yuli Astuti, M.Kom"<<endl;
				cout<<"\n";
				cout<<" = ANGGOTA KELOMPOK FINALE PROJECT [ BANK MAHASISWA AMIKOM YOGYAKARTA ]"<<endl;
				cout<<"\n";
				cout<<" 1.) Rastra Ardiansyah Pora    [ NIM = 21.11.4077 ]"<<endl;
				cout<<" 2.) Achmad Fadillah Pernata   [ NIM = 21.11.4093 ]"<<endl;
				cout<<" 3.) Muhammad Maulid Sam Endra [ NIM = 21.11.4062 ]"<<endl;
				cout<<" 4.) Faadhil Asyraf Rafii Amir [ NIM = 21.11.4045 ]"<<endl;
				cout<<" 5.) Kholan Sururi             [ NIM = 21.11.4059 ]"<<endl;
				cout<<"\n";
				cout<<" Masukkan Sembarang Angka Jika Ingin Kembali Ke Menu Utama = ";cin>>x;
				goto menu;
			    }
			case 10 :
				{
				system ("color 8E");
				cout<<"\n";
				cout<<" ===================================================="<<endl;
				cout<<"         Terima Kasih Telah Melakukan Transaksi      "<<endl;
				cout<<" ===================================================="<<endl;
				cout<<"\n";
				cout<<" Masukkan Sembarang Angka Jika Ingin Kembali Ke Menu Utama = ";cin>>x;
				goto menu;
			    }
			default :
				{
				system ("color 8E");
				cout<<"\n";
				cout<<" ===================================================="<<endl;
				cout<<"       Maaf Pilihan yang Anda Masukkan Tidak Ada     "<<endl;
				cout<<" ===================================================="<<endl;
				cout<<"\n";
				cout<<" Masukkan Sembarang Angka Untuk Kembali Ke Menu Utama = ";cin>>x;
				goto menu;
			    }
		}
		return 0;
}
