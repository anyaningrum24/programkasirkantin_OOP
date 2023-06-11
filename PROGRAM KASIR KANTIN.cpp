#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Menu
{
public:
    double hargaMenu;
    int nomor;

    Menu(double harga, int nomor)
    {
        hargaMenu=harga;
        this->nomor=nomor;
    }
};

class Makanan : public Menu
{
public:
    string namaMakanan;

    Makanan(double harga, int nomor, const string& nama) : Menu(harga, nomor)
    {
        namaMakanan=nama;
    }
};

class Minuman : public Menu
{
public:
    string namaMinuman;

    Minuman(double harga, int nomor, const string& nama) : Menu(harga, nomor)
    {
        namaMinuman=nama;
    }
};

class TipePesanan
{
public:
    int tipePesanan;
    TipePesanan(){};
    TipePesanan(int tipe)
    {
        tipePesanan = tipe;
    }

    string getNamaTipePesanan()
    {
        if (tipePesanan == 1)
        {
            return "Dine-in";
        }
        else if (tipePesanan == 2)
        {
            return "Take-away";
        }
        else
        {
            return "Unknown";
        }
    }
};



class Transaksi
{
public:
    char namaPemesan[50];
    int jumlahPesanan;
    int pesanan[30];	
    int porsi[30];
    double totalHarga;
    string namaPesanan;
    double uang;
    TipePesanan objTipePesanan;

    void Pemesanan() //fungsi
    {
        cout<<endl;
        cout<<"Nama Pemesan: ";
        cin>>namaPemesan;
        
		cout<<"Tipe Pesanan (1 = Dine-in, 2 = Take-away): ";
	    int tipe;
	    cin>>tipe;
	    objTipePesanan=TipePesanan(tipe); // Menggunakan konstruktor dengan argumen
	    
        cout<<"Banyak Pesanan: ";
        cin>>jumlahPesanan;  

        totalHarga=0;
        for (int i = 0; i < jumlahPesanan; ++i)
        {
            cout<<"\n== Pesanan Ke "<<(i + 1)<<" =="<<endl;
            cout<<"Masukkan Nomor Makanan/Minuman: ";
            cin>>pesanan[i];
            while (pesanan[i] < 1 || pesanan[i] > 20)
            {
                cout<<"Nomor Makanan/Minuman tidak valid. Silakan masukkan nomor yang valid: ";
                cin>>pesanan[i];
            }

            cout<<"Jumlah Pesan: ";
            cin>>porsi[i];
            while (porsi[i] <= 0)
            {
                cout<<"Jumlah pesanan tidak valid. Silakan masukkan jumlah pesanan yang valid: ";
                cin>>porsi[i];
            }
            totalHarga += porsi[i] * getMenuHarga(pesanan[i]);
            namaPesanan = getMenuNama(pesanan[i]);
            
            
        }
        
    }
    
    void Pembayaran() //fungsi
    {
		// Diskon 10% jika total harga >= 50000
        if (totalHarga >= 50000)
        {
            cout<<"\nTotal Pembayaran : Rp "<<totalHarga<<endl;
            double diskon = totalHarga * 0.1;
            totalHarga -= diskon;
            cout<<"\nDiskon 10% telah diberikan!"<< endl;
            cout<<"Total Pembayaran (setelah diskon): Rp "<<totalHarga<<endl;
        }

        cout<<"\n===== NOTA PEMBAYARAN ====="<<endl;
        cout<<"Nama Pemesan: "<<namaPemesan<<endl;
        cout<<"Tipe Pesanan: "<<objTipePesanan.getNamaTipePesanan()<<endl;
        cout << "Pesanan:" << endl;
		for (int i = 0; i < jumlahPesanan; ++i) {
		    cout << "  - " << namaPesanan<< " (" << porsi[i] << " porsi)" << endl;
		}
        cout<< "Total Bayar: Rp "<<totalHarga<<endl;
        cout << "Uang Bayar: Rp ";
        cin >> uang;

        double kembalian = uang - totalHarga;
        cout<<"Uang Kembali: Rp "<<kembalian<< endl;
    }

    double getMenuHarga(int nomor)
    {
        // Menentukan harga berdasarkan nomor menu
        if (nomor == 1)
        {
            return 16000;
        }
        else if (nomor == 2)
        {
            return 11000;
        }
        else if (nomor == 3)
        {
            return 18000;
        }
        else if (nomor == 4)
        {
            return 12000;
        }
        else if (nomor == 5)
        {
            return 10000;
        }
        else if (nomor == 6)
        {
            return 13000;
        }
        else if (nomor == 7)
        {
            return 12000;
        }
        else if (nomor == 8)
        {
            return 17000;
        }
        else if (nomor == 9)
        {
            return 13000;
        }
        else if (nomor == 10)
        {
            return 10000;
        }
        else if (nomor == 11)
        {
            return 5000;
        }
        else if (nomor == 12)
        {
            return 5000;
        }
        else if (nomor == 13)
        {
            return 10000;
        }
        else if (nomor == 14)
        {
            return 13000;
        }
        else if (nomor == 15)
        {
            return 4000;
        }
        else if (nomor == 16)
        {
            return 4000;
        }
        else if (nomor == 17)
        {
            return 15000;
        }
        else if (nomor == 18)
        {
            return 12000;
        }
        else if (nomor == 19)
        {
            return 10000;
        }
        else if (nomor == 20)
        {
            return 3000;
        }
        else
        {
            return 0;
        }
    }
    
     string getMenuNama(int nomor)
    {
        // Menentukan harga berdasarkan nomor menu
        if (nomor == 1)
        {
            return "Ayam Goreng";
        }
        else if (nomor == 2)
        {
            return "Nasi Goreng";
        }
        else if (nomor == 3)
        {
            return "Bebek Goreng";
        }
        else if (nomor == 4)
        {
            return "Sate Ayam";
        }
        else if (nomor == 5)
        {
            return "Ketoprak";
        }
        else if (nomor == 6)
        {
            return "Ayam Geprek";
        }
        else if (nomor == 7)
        {
            return "Soto Ayam";
        }
        else if (nomor == 8)
        {
            return "Rawon";
        }
        else if (nomor == 9)
        {
            return "Ayam Teriyaki";
        }
        else if (nomor == 10)
        {
            return "Seblak Bandung";
        }
        else if (nomor == 11)
        {
            return "Es Jeruk";
        }
        else if (nomor == 12)
        {
            return "Es Teh";
        }
        else if (nomor == 13)
        {
            return "Es Degan";
        }
        else if (nomor == 14)
        {
            return "Jus Alpukat";
        }
        else if (nomor == 15)
        {
            return "Jeruk Hangat";
        }
        else if (nomor == 16)
        {
            return "Teh Hangat";
        }
        else if (nomor == 17)
        {
            return "Es Campur";
        }
        else if (nomor == 18)
        {
            return "Es Dawet";
        }
        else if (nomor == 19)
        {
            return "Jus Tomat";
        }
        else if (nomor == 20)
        {
            return "Air Mineral";
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
	
    cout<<"=========== SELAMAT DATANG DI KANTIN MAMA ==========="<<endl<<endl;
    cout<<"============================================================"<<endl;
    cout<<"|KABAR GEMBIRA !                                           |"<<endl;
    cout<<"|KANTIN MAMA discount 10% untuk minimal pembelian RP 50.000|"<<endl;
    cout<<"|periode pembelian 1 Juni 2023 - 15 Juni 2023              |"<<endl;
    cout<<"============================================================"<<endl<<endl;
    system("pause");
	system("cls");   
	
	menutampilan:
        int pil;
            cout<<"                    Menu Tampilan\n";
	        cout<<" 1. Daftar Harga Menu Makanan dan Minuman  \n";
	        cout<<" 2. Pemesanan    \n";
	        cout<<" 3. Pembayaran       \n";
	        cout<<" 4. Keluar      \n";
	        cout<<"----------------------\n";
	        cout<<"Masukan Pilihan Anda = ";
	        cin>>pil;
	        system("cls");

                Makanan menuMakanan[] =
                {
                    Makanan(16000, 1, "Ayam Goreng"),
                    Makanan(11000, 2, "Nasi Goreng"),
                    Makanan(18000, 3, "Bebek Goreng"),
                    Makanan(12000, 4, "Sate Ayam"),
                    Makanan(10000, 5, "Ketoprak"),
                    Makanan(13000, 6, "Ayam Geprek"),
                    Makanan(12000, 7, "Soto Ayam"),
                    Makanan(17000, 8, "Rawon"),
                    Makanan(13000, 9, "Ayam Teriyaki"),
                    Makanan(10000, 10, "Seblak Bandung")
                    
                };

                Minuman menuMinuman[] =
                {
                    Minuman(5000, 11, "Es Jeruk"),
                    Minuman(5000, 12, "Es Teh"),
                    Minuman(10000, 13, "Es Degan"),
                    Minuman(13000, 14, "Jus Alpukat"),
                    Minuman(4000, 15, "Jeruk Hangat"),
                    Minuman(4000, 16, "Teh Hangat"),
                    Minuman(15000, 17, "Es Campur"),
                    Minuman(12000, 18, "Es Dawet"),
                    Minuman(10000, 19, "Jus Tomat"),
                    Minuman(3000, 20, "Air Mineral"),
                };
                
            if (pil==1)
            {
                cout << "                        MENU MAKANAN " << endl;
		        cout << "========================================================" << endl;
		        cout << "| NO |            Nama Makanan         |      Harga    | "<<endl;
		        cout << "========================================================"<<endl;
		        for (int i = 0; i < sizeof(menuMakanan) / sizeof(menuMakanan[0]); i++)
                {
                    cout <<"| " <<setiosflags(ios::left) << setw(3) << menuMakanan[i].nomor;
                    cout <<"| " <<setiosflags(ios::left) << setw(32) << menuMakanan[i].namaMakanan;
                    cout <<"| " <<setiosflags(ios::left) << setw(14) << menuMakanan[i].hargaMenu<<"|";
                    cout<<endl;
                }
		        cout << "========================================================" << endl<<endl;
		        
		        cout << "                        MENU MINUMAN " << endl;
		        cout << "========================================================" << endl;
		        cout << "| NO |            Nama Makanan         |      Harga    | "<<endl;
		        cout << "========================================================"<<endl;
		        for (int i = 0; i < sizeof(menuMinuman) / sizeof(menuMinuman[0]); i++)
                {
                    cout <<"| " <<setiosflags(ios::left) << setw(3) << menuMinuman[i].nomor;
                    cout <<"| " <<setiosflags(ios::left) << setw(32) << menuMinuman[i].namaMinuman;
                    cout <<"| " <<setiosflags(ios::left) << setw(14) << menuMinuman[i].hargaMenu<<"|";
                    cout<<endl;
                }
		        cout << "========================================================" << endl;
                cout << endl<<endl;
                system("pause");
				system("cls");
				goto menutampilan;
            }
            
            else if (pil==2)
            {
		        cout << "============= MENU MAKANAN =============" << endl;
		        cout << "========================================" << endl;
		        cout << "| NO |            Nama Makanan         |"<<endl;
		        cout << "========================================"<<endl;
		        for (int i = 0; i < sizeof(menuMakanan) / sizeof(menuMakanan[0]); i++)
                {
                    cout <<"| " <<setiosflags(ios::left) << setw(3) << menuMakanan[i].nomor;
                    cout <<"| " <<setiosflags(ios::left) << setw(32) << menuMakanan[i].namaMakanan<<"|";
                    cout<<endl;
                }
		        cout << "========================================" <<endl<<endl;
		        
		        cout << "============= MENU MINUMAN =============" << endl;
		        cout << "========================================" << endl;
		        cout << "| NO |            Nama Minuman         |"<<endl;
		        cout << "========================================"<<endl;
		        for (int i = 0; i < sizeof(menuMinuman) / sizeof(menuMinuman[0]); i++)
                {
                    cout<<"| "<<setiosflags(ios::left)<<setw(3)<<menuMinuman[i].nomor;
                    cout<<"| "<<setiosflags(ios::left)<<setw(32)<<menuMinuman[i].namaMinuman<<"|";
                    cout<<endl;
                }
		        cout<<"========================================"<<endl;
        
				Transaksi data;
                data.Pemesanan();
                cout << endl<<endl;
                system("pause");
				system("cls");
				goto menutampilan;
            }
            
            else if (pil==3)
	        {
	            Transaksi data;
	            data.Pembayaran();
	            cout<<endl;
	            system("pause");
				system("cls");
				goto menutampilan;
	        }
	        
            else if (pil==4)
            {
                cout<<"Terima kasih! Sampai jumpa kembali!"<<endl<<endl;
                system("pause");
				system("cls");
				exit(0);
            }
            
            else
            {
                cout<<"Pilihan tidak valid. Silakan masukkan pilihan yang valid!"<<endl;
                system("pause");
				system("cls");
				goto menutampilan;
            }

    return 0;
}

