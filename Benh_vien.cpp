#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Nguoi{
	private:
	string ho_ten;
	int nam_sinh; 
	
	public:
		
	void Nhap(){
		while(getchar() != '\n');
			cout << "Nhap ten benh nhan : ";
			getline(cin, ho_ten);
			cout << "Nhap nam sinh : ";
			cin >> nam_sinh;
		}
	    
		void Xuat(){
			cout << "Ten benh nhan la : " << ho_ten << endl;
			cout << "Nam sinh la : " << nam_sinh << endl;
		}
	    
	    int getNam_Sinh(){
	    	return nam_sinh;
		}
		
		string getTen(){
			return ho_ten;
		}
	
};

class Benh_nhan_ngoai_tru : public Nguoi{
	private:
		string benh;
		string ten_benh;
		float tien_dt;
		public:
			
			float getTien_dt(){
				return tien_dt;
			}
			
			void Nhap_bn_ngoai(){
			Nguoi::Nhap();
			while(getchar() != '\n');
			cout << "Nhap benh : ";
			getline(cin, benh);
			cout << "Nhap ten benh : ";
			getline(cin, ten_benh);
			cout << "Nhap tien thuoc : ";
			cin >> tien_dt;
		}
		
		void Xuat_bn_ngoai(){
			cout << "\n---------------------------------------" << endl;
			Nguoi::Xuat();
			cout << "Ten benh nhan la : " << benh << endl;
			cout << "Ten benh : " << ten_benh << endl;
			cout << "Tien thuoc la : " << tien_dt << endl;
			cout << "---------------------------------------" << endl;
		}
		
		double Tinh_tien(){
			int NAM_Sinh;
			float tong = 0;
			NAM_Sinh =  this->getNam_Sinh();
			if(NAM_Sinh > 1960){
			 tong += 0.92 * tien_dt;
			}
			else{
				tong +=  tien_dt;
			}
			return tong;
		}
};

class Benh_nhan_noi_tru : public Nguoi{
	private:
		string benh_ban_dau;
		float tien_dieu_tri;
		float tien_o;
		
		public:	
			void Nhap_bn_noi(){
			Nguoi::Nhap();
			cin.ignore();
			cout << "Nhap benh ban dau : ";
			getline(cin, benh_ban_dau);
			cout << "Nhap tien dieu tri : ";
			cin >> tien_dieu_tri;
			cout << "Nhap tien o : ";
			cin >> tien_o;
		}
		
		void Xuat_bn_noi(){
			cout << "\n---------------------------------------" << endl;
			Nguoi::Xuat();
			cout << "Ten benh ban dau : " << benh_ban_dau << endl;
			cout << "Tien dieu tri : " << tien_dieu_tri << endl;
			cout << "Tien o : " << tien_o << endl;
			cout << "---------------------------------------" << endl;
		}
		
		
		double tinhtien(){
			int NAM_Sinh;
			float tong;
			NAM_Sinh =  this->getNam_Sinh();
			if(NAM_Sinh > 1960){
			tong += 0.92 * tien_dieu_tri + 0.88 * tien_o;
			}
			else{
				tong += tien_dieu_tri + tien_o;
			}
			return tong;
		}
};

void Xuat_tat_ca_thong_tin_bn(Benh_nhan_ngoai_tru BN_NG[], int n, Benh_nhan_noi_tru BN_N[], int m){
	int dem = 1;
	cout << "\n\n DANH SACH BENH NHAN NGOAI TRU\n";
	for(int i = 0; i < n; i++){
		cout << "\nTHONG TIN BENH NHAN NGOAI TRU " << dem++ << endl;
		BN_NG[i].Xuat_bn_ngoai();
	}
	
	cout << "\n\n DANH SACH BENH NHAN NOI TRU\n";
	int dem_1 = 1;
	for(int i = 0; i < m; i++){
		cout << "\nTHONG TIN BENH NHAN NOI TRU " << dem_1++ << endl;
		BN_N[i].Xuat_bn_noi();
	}
}

int Tinh_tien_bn_ngoai_noi(Benh_nhan_ngoai_tru BN_NG[], int n, Benh_nhan_noi_tru BN_N[], int m){
	int dem = 1;
	float tong = 0;
	cout << "\n\n DANH SACH BIEN LAI BENH NHAN NGOAI TRU\n";
	for(int i = 0; i < n; i++){
		cout << "\nBENH NHAN NGOAI TRU " << dem++ ;
		cout << " sinh nam " << 
		BN_NG[i].getNam_Sinh();
		cout << " ten la " <<
		BN_NG[i].getTen();
		cout << " tong tien phai tra la : ";
		cout << BN_NG[i].Tinh_tien();
	}
	
	int dem_1 = 1;
	float tong_1 = 0;
	cout << "\n\n DANH SACH BIEN LAI BENH NHAN NOI TRU\n";
	for(int i = 0; i < m; i++){
		cout << "\nBENH NHAN NOI TRU " << dem_1++ ;
		cout << " sinh nam " << 
		BN_N[i].getNam_Sinh();
		cout << " ten la " <<
		BN_N[i].getTen();
		cout << " tong tien phai tra la : ";
		cout << BN_N[i].tinhtien();
		
	}
}

class Phong_kham{
	private:
		
		public:
			
			void Nhap(Benh_nhan_ngoai_tru BN_NG[], int n, Benh_nhan_noi_tru BN_N[], int m){
				int choice;
				while(true){
        		system("cls");
				cout << "======CHON YEU CAU======" << endl;
				cout << "\n 1.Nhap danh sach benh nhan" << endl;
				cout << "\n 2.Xuat danh sach benh nhan" << endl;
				cout << "\n 3.Tinh tien benh nhan ngoai va noi" << endl;
				cout << "\n 4.Thoat khoi vong lap" << endl;
				cout << "\n ======END======" << endl;
				
				cout << "Chon : ";
				cin >> choice;
				cin.ignore();
				
				if(choice == 1){
				int chon;
				
				while(true){
                system("cls");
                cout << "\n1. BENH NHAN NGOAI TRU";
            	cout << "\n2. BENH NHAN NOI TRU";
            	cout << "\n3. KET THUC" << endl;
            	
            	cout << "\nNHAP BENH NHAN MUON KHAI BAO : ";
            	cin >> chon;
            	
            	if(chon == 1 ){
            		Benh_nhan_ngoai_tru NGOAI;
            		cout << "\nNHAP THONG TIN BENH NHAN NGOAI TRU" << endl;
            		NGOAI.Nhap_bn_ngoai();
            		BN_NG[n] = NGOAI;
            		n++;
					}
				else if(chon == 2){
					Benh_nhan_noi_tru NOI;
					cout << "\nNHAP THONG TIN BENH NHAN NOI TRU" << endl;
					NOI.Nhap_bn_noi();
					BN_N[m] = NOI;
					m++;
				}
				else{
					break;
					}
				}		
			}
			else if(choice == 2){
				Xuat_tat_ca_thong_tin_bn(BN_NG, n, BN_N, m);
				system("pause");
			}
			
			else if(choice == 3){
				Tinh_tien_bn_ngoai_noi(BN_NG, n, BN_N, m);
				system("pause");
			}			
		}
	}
};

int main(){
	Benh_nhan_ngoai_tru BN_NG[100];
	int n = 0;
	Benh_nhan_noi_tru BN_N[100];
	int m = 0;
	Phong_kham dis;
	dis.Nhap(BN_NG, n, BN_N, m);
//	dis.Xuat();
//	dis.tong_thanhtoan();
}
