#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct sinhvien
{
    string maso;
    string hoten;
    int namsinh;
    float diemtb;
};
typedef struct sinhvien SINHVIEN;

struct danhsach
{
    SINHVIEN arr[100];
    int n;
};
typedef struct danhsach DANHSACH;

// hàm nhập thông tin 1 thằng sinh viên
void Nhap_Thong_Tin_1_Thang_Sinh_Vien(SINHVIEN &sv)
{
	// vòng lặp nhập họ tên sinh viên
	do{


        while (getchar() != '\n');
		cout << "\nNhap ho ten sinh vien: ";
		getline(cin, sv.hoten);
		if (sv.hoten.length() > 30){

			cout << "\nHo ten toi da 30 ki tu. Xin kiem tra lai";
		}

	} while (sv.hoten.length() > 30);

	// vòng lặp nhập mã số sinh viên
	do
	{

        while (getchar() != '\n');
		cout << "\nNhap ma so sinh vien: ";
		getline(cin, sv.maso);
		if (sv.maso.length() > 10){

			cout << "\nMa so sinh vien toi da 10 ki tu. Xin kiem tra lai";
		}
	} while (sv.maso.length() > 10);

	do{
		// nhập điểm cho sinh viên
		cout << "\nNhap diem trung binh sinh vien: ";
		cin >> sv.diemtb;
		if (sv.diemtb < 0 || sv.diemtb > 10)
		{

			cout << "\nDiem trung binh khong duoc < 0 hay > 10";
		}
	} while (sv.diemtb < 0 || sv.diemtb > 10);

}

// hàm xuất thông tin 1 thằng sinh viên
void Xuat_Thong_Tin_1_Thang_Sinh_Vien(SINHVIEN sv)
{
	// xuất họ tên sinh viên
	cout << "\nHo ten sinh vien: " << sv.hoten;

	// xuất mã số sinh viên
	cout << "\nMa so sinh vien: " << sv.maso;

	// xuất điểm sinh viên
	cout << "\nDiem trung binh sinh vien: " << sv.diemtb;
}

// hàm nhập danh sách sinh viên
void Nhap_Danh_Sach_Sinh_Vien(DANHSACH &ds)
{
	// vòng lặp cho chúng ta nhập nhiều thằng sinh viên
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t\t NHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
		// gọi lại hàm nhập thông tin 1 thằng sinh viên
		// nhập thông tin sinh viên thứ arr[i]
		Nhap_Thong_Tin_1_Thang_Sinh_Vien(ds.arr[i]);

	}
}

// hàm xuất danh sách sinh viên
void Xuat_Danh_Sach_Sinh_Vien(DANHSACH ds)
{
	// vòng lặp cho chúng ta xuất ra nhiều thằng sinh viên
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t\tTHONG TIN SINH VIEN THU " << i + 1 << endl;
		// gọi lại hàm xuất thông tin 1 thằng sinh viên
		// xuất thông tin sinh viên thứ arr[i]
		Xuat_Thong_Tin_1_Thang_Sinh_Vien(ds.arr[i]);

	}
}

// tìm ra điểm trung bình cao nhất
float Tim_Diem_Trung_Binh_Cao_Nhat(DANHSACH ds)
{

	float max = ds.arr[0].diemtb;
	for (int i = 1; i < ds.n; i++)
	{

		if (ds.arr[i].diemtb > max)
		{

			max = ds.arr[i].diemtb;

		}

	}
  return max;
}

// trả về sinh viên có điểm trung bình thấp nhất
void Tim_Sinh_Vien_Diem_Trung_Binh_Thap_Nhat(DANHSACH ds)
{
	// BƯỚC 1: duyệt danh sách sinh viên và tìm ra điểm trung bình thấp nhất
	float min = ds.arr[0].diemtb;
	for (int i = 1; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb < min)
		{
			min = ds.arr[i].diemtb;
		}
	}

	// BƯỚC 2: Duyệt danh sách sinh viên - nếu thằng nào có điểm trung bình bằng với min thì xuất
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb == min)
		{
			// xuất ra thông tin sinh viên thứ i
			Xuat_Thong_Tin_1_Thang_Sinh_Vien(ds.arr[i]);

		}
	}

}

// hàm tìm kiếm thông tin sinh viên dựa vào điểm
void Tim_kiem_sv_theo_diem(DANHSACH ds , float diem)
{
    int dem = 1;
    for (int i = 0; i < ds.n; i++)
    {
        if(ds.arr[i].diemtb == diem)
        {
            cout << "\nTHONG TIN SINH VIEN THU " << dem++;
            Xuat_Thong_Tin_1_Thang_Sinh_Vien(ds.arr[i]);
        }
    }
}

// hàm thêm sinh viên vào vị trí bất kì
void Them(DANHSACH ds, int vt, SINHVIEN x)
{
	for (int i = ds.n - 1; i >= vt; i--)
	{
		ds.arr[i + 1] = ds.arr[i];
	}
	ds.arr[vt] = x;
	ds.n++;
}

//Ham xoa
void Xoa(DANHSACH ds, int vt)
{
	for (int i = vt + 1; i < ds.n; i++)
	{
		ds.arr[i - 1] = ds.arr[i];
	}
	ds.n--;
}


//ham xoa sinh vien duoi 5 tuoi
void Xoa_Sinh_Vien_Duoi_5(DANHSACH ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb < 5)
		{
			Xoa(ds, i);
			i--;
		}
	}
}


// hàm hóa vị 2 sinh viên
void Hoan_Vi(SINHVIEN &x, SINHVIEN &y)
{
	SINHVIEN tam;
	tam = x;
	x = y;
	y = tam;
}


// hàm sắp xếp danh sách sinh viên tăng dần theo điểm tb
void Sap_Xep_Tang_Dan_Diem_TB(DANHSACH ds)
{
	for (int i = 0; i < ds.n - 1; i++)
	{
		for (int j = i + 1; j < ds.n; j++)
		{
			if (ds.arr[i].diemtb > ds.arr[j].diemtb)
			{
				Hoan_Vi(ds.arr[i], ds.arr[j]);
			}
		}
	}
}

//TAO 1 MENU
void menu(DANHSACH &ds)
{
    int luachon;
    while(true)
    {
        system("cls");
        cout << "\n\t\t=========== QUAN LI SINH VIEN ===========";
        cout << "\n\t1. Tim diem trung binh cao nhat ";
        cout << "\n\t2. Tim diem trung binh thap nhat ";
        cout << "\n\t3. Tim kiem sinh vien theo diem ";
        cout << "\n\t4. Them 1 sinh vien o vi tri bat ki ";
        cout << "\n\t5. Xoa 1 sinh vien o vi tri bat ki ";
        cout << "\n\t6. xuat danh sach sinh vien";
        cout << "\n\t0. Exit";
        cout << "\nNhap lua chon : ";
        cin >> luachon;
        if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            int MAX = Tim_Diem_Trung_Binh_Cao_Nhat(ds);
            cout << "\nDiem trung binh cao nhat la " << MAX;
            for(int i = 0 ; i < ds.n; i++)
            {
                if(ds.arr[i].diemtb == MAX)
                Xuat_Thong_Tin_1_Thang_Sinh_Vien(ds.arr[i]);
            }
            system("pause");
        }
        else if (luachon == 2)
        {
            Tim_Sinh_Vien_Diem_Trung_Binh_Thap_Nhat(ds);
            system("pause");
        }
        else if (luachon == 3)
        {
            int diem = 0;
            cout << "\nNHAP DIEM CUA SINH VIEN BAN MUON TIM : ";
            cin >> diem ;
            Tim_kiem_sv_theo_diem(ds ,diem);
            system("pause");
        }
        else if (luachon == 4)
        {
             int vt;
             SINHVIEN x;
	         cout << "\nNhap vi tri can them: ";
	         cin >> vt;
	         cout << "\n\n\t\tNHAP THONG TIN SINH VIEN CAN THEM\n";
             Nhap_Thong_Tin_1_Thang_Sinh_Vien(x);
	         Them(ds, vt, x);
	         cout << "\n\n\t\t\tXUAT DANH SACH SINH VIEN\n";
	         Xuat_Danh_Sach_Sinh_Vien(ds);
        }
        else if (luachon == 6)
        {
            Xuat_Danh_Sach_Sinh_Vien(ds);
            system("pause");
        }
        else if (luachon == 7)
        {
             Sap_Xep_Tang_Dan_Diem_TB(ds);
             Xuat_Danh_Sach_Sinh_Vien(ds);
        }
        cout << "\n\n\t\t===============END===============";
    }
}
int main()
{
    DANHSACH ds;
    cout << "\nNhap so luong sinh vien :";
    cin >> ds.n;
    Nhap_Danh_Sach_Sinh_Vien(ds);
    menu(ds);
    return 0;
}
