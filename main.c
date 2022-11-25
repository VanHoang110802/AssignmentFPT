#pragma warning (disable:4996)

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef int in;
typedef double db;
typedef long long ll;

#define forxuoi(x,batdau,ketthuc) for (int i=(batdau);i<=(ketthuc);i+=x)
#define colorchar(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)x)
#define giam_gia_trong_khoang_14_den_17 0.9
#define giam_tu_gio_thu_4 0.7

const db PI = 3.14159265358979;
const db laithang = 0.05;
const in kyhan = 12;
const in gia_tien_cua_1_gio = 150000;
const in so_gio_ban_dau = 3;

ll lc;

in gio_bat_dau, gio_ket_thuc, so_gio_da_su_dung, thanh_tien;

void gotoxy(in x, in y) 
{
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor_an_Pos);
}

in MIN(in a, in b)
{
	if (a > b) return b;
	else return a;
}

void Menu(in color_all, in color)
{
	in color_row[11];
	forxuoi(1, 0, 11-1) color_row[i] = 15;
	color_row[color-1] = 12;

	system("cls");
	colorchar(10);
	printf("\t   __    __     ______     __   __     __  __");
	printf("\n\t  /\\ *-./  \\   /\\  ___\\   /\\ *-.\\ \\   /\\ \\/\\ \\");
	printf("\n\t  \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\");
	printf("\n\t   \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\*\\_\\  \\ \\_____\\");
	printf("\n\t    \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/");

	printf("\n");

	colorchar(color_all); printf("\n\t++------------------------------------------------++");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[0]); printf("Chuc nang 1: Kiem tra so nguyen"); colorchar(color_all); printf("                  |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[1]); printf("Chuc nang 2: Tim uoc chung va boi chung cua 2 so"); colorchar(15); printf(" |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[2]); printf("Chuc nang 3: Tinh tien cho quan karaoke"); colorchar(15); printf("          |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[3]); printf("Chuc nang 4: Tinh tien dien"); colorchar(color_all); printf("                      |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[4]); printf("Chuc nang 5: Chuc nang doi tien"); colorchar(color_all); printf("                  |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[5]); printf("Chuc nang 6: Tinh lai suat vay ngan hang tra gop"); colorchar(color_all); printf(" |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[6]); printf("Chuc nang 7: Chuong trinh vay tien mua xe"); colorchar(color_all); printf("        |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[7]); printf("Chuc nang 8: Sap xep thong tin sinh vien"); colorchar(color_all); printf("         |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[8]); printf("Chuc nang 9: Tro choi FPT-LOTT"); colorchar(15); printf("                   |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[9]); printf("Chuc nang 10: Tinh toan phan so"); colorchar(color_all); printf("                  |");
	colorchar(color_all); printf("\n\t| "); colorchar(color_row[10]); printf("Chuc nang 11: Thoat chuong trinh"); colorchar(color_all); printf("                 |");
	colorchar(color_all); printf("\n\t++------------------------------------------------++");
	
}

//======================================================================================================

void Chuc_Nang_1()
{
	db x;
	printf("Nhap x = "); scanf("%lf", &x);
	if (x == (in)x) printf("\nx la so nguyen");
	else
	{
		printf("\nx khong la so nguyen");
		return;
	}
	in n = (in)x;
	if (n < 2) printf("\nx khong la so nguyen to");
	else if (n != 2 && n % 2 == 0) printf("\nx khong la so nguyen to");
	else
	{
		in check = 1;
		forxuoi(2, 3, sqrt(n))
		{
			if (n % i == 0)
			{
				check = 0;
				break;
			}
		}
		if (check) printf("\nx la so nguyen to");
		else printf("\nx khong la so nguyen to");
	}
	if (x < 1) printf("\nx khong la so chinh phuong");
	else
	{
		if ((in)sqrt(x) == sqrt(x)) printf("\nx la so chinh phuong");
		else printf("\nx khong la so chinh phuong");
	}
}

//======================================================================================================

void Chuc_Nang_2()
{
	ll a, b;
	do
	{
		printf("Nhap a = "); scanf("%lld", &a);
		if (a < 1) printf("a phai luon lon hon 0, xin hay kiem tra lai!\n");
	} while (a < 1);

	do
	{
		printf("Nhap b = "); scanf("%lld", &b);
		if (b < 1) printf("b phai luon lon hon 0, xin hay kiem tra lai!\n");
	} while (b < 1);

	ll Min = a < b ? a : b;
	ll Max = a > b ? a : b;
	ll ucln = 0;

	if (Max % Min == 0)
	{	// mình chỉ xét min thôi, còn max chắc chắn không chia được rồi.
		ucln = Min;
	}
	else
	{
		for (ll i = Min / 2; i >= 1; --i)
		{
			if (Max % i == 0 && Min % i == 0)
			{
				ucln = i;
				break;
			}
		}
	}
	printf("UCLN (%lld, %lld) = %lld", a, b, ucln);
	printf("\nBCNN (%lld, %lld) = %lld", a, b, (a * b) / ucln);
}

void Resize_Num(in n)
{
	in dem = 0;
	in temp = n;
	while (temp > 0) 
	{
		temp /= 10;
		dem++;
	}
	temp = n;
	in sodauphay = (dem - 1) / 3;
	in luythua = pow(10.0, (3 * sodauphay));
	in a = temp / luythua;
	printf(" %d", a);
	temp %= luythua;
	while (--sodauphay >= 0) 
	{
		luythua = pow(10.0, (3 * sodauphay));
		a = temp / luythua;
		printf(".%03d", a);
		temp %= luythua;
	}
}

//======================================================================================================

void Chuc_nang_3()
{
	do
	{
		printf("Nhap so gio bat dau: "); scanf("%d", &gio_bat_dau);
		if (gio_bat_dau < 12 || gio_bat_dau > 24) printf("\nSo gio bat dau ban nhap khong hop le! (gio bat dau >= 12 & gio bat dau < 24)\n");
	} while (gio_bat_dau < 12 || gio_bat_dau > 24);
	do
	{
		printf("\nNhap so gio ket thuc: "); scanf("%d", &gio_ket_thuc);
		if (gio_ket_thuc < gio_bat_dau || gio_ket_thuc > 24) printf("\nSo gio ket thuc ban nhap khong hop le! (gio ket thuc >= gio bat dau & gio ket thuc < 24)\n");
	} while (gio_ket_thuc < gio_bat_dau || gio_ket_thuc > 24);

	so_gio_da_su_dung = gio_ket_thuc - gio_bat_dau;
	printf("\nSo gio da hat la: %d", so_gio_da_su_dung);

	if (so_gio_da_su_dung <= so_gio_ban_dau)
	{
		if (gio_bat_dau >= 14 && gio_bat_dau <= 17)
		{
			thanh_tien = (so_gio_da_su_dung * gia_tien_cua_1_gio) * giam_gia_trong_khoang_14_den_17;
		}
		else
		{
			thanh_tien = so_gio_da_su_dung * gia_tien_cua_1_gio;
		}
	}
	else
	{
		if (gio_bat_dau >= 14 && gio_bat_dau <= 17)
		{
			thanh_tien = ((so_gio_ban_dau * gia_tien_cua_1_gio) + ((so_gio_da_su_dung - so_gio_ban_dau) * gia_tien_cua_1_gio * giam_tu_gio_thu_4)) * giam_gia_trong_khoang_14_den_17;
		}
		else
		{
			thanh_tien = (so_gio_ban_dau * gia_tien_cua_1_gio) + (((so_gio_da_su_dung - so_gio_ban_dau) * gia_tien_cua_1_gio) * giam_tu_gio_thu_4);
		}
	}
	
	printf("\nSo tien khach phai thanh toan:");  Resize_Num(thanh_tien); printf(" VND");
}

//======================================================================================================

void Chuc_Nang_4()
{
	in soDien, tien;
	printf("\nNhap so dien tieu thu : "); scanf("%d", &soDien);
	if (soDien <= 50) tien = soDien * 1678;

	else if (soDien <= 100) tien = (50 * 1678) + ((soDien - 50) * 1734);

	else if (soDien <= 200) tien = (50 * 1678) + (50 * 1734) + ((soDien - 100) * 2014);

	else if (soDien <= 300) tien = (50 * 1678) + (50 * 1734) + (100 * 2014) + ((soDien - 200) * 2536);

	else if (soDien <= 400) tien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + ((soDien - 300) * 2834);

	else tien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + (100 * 2834) + ((soDien - 400) * 2927);

	printf("\nSo tien dien can phai tra la:"); Resize_Num(tien); printf(" VND");
}

//======================================================================================================

void Chuc_Nang_5()
{
	in sotiencandoi, tien;
	do
	{
		printf("Nhap so tien can doi: "); scanf("%d", &sotiencandoi);
		if (sotiencandoi < 1000) printf("\nSo tien nhap khong hop le!\n");
	} while (sotiencandoi < 1000);

	tien = sotiencandoi;
	Resize_Num(sotiencandoi);
	printf(" se duoc doi thanh cac so to menh gia duoi day:\n");

	in X = 500000, dem;		// mệnh giá mặc định cho là mệnh giá lớn nhất.

	while (tien != 0) 
	{
		// nếu số tiền là 25, thì quy đổi thành 10,20,50 cho đúng mệnh giá. 
		if (X == 250000) X -= 50000;
		else if (X == 25000) X -= 5000;
		else if (X == 2500) X -= 500;
		else if (X == 500)
		{
			dem = 0;
			tien = tien - 500;
			dem++;
			printf(" So to menh gia"); Resize_Num(X); printf(" co %d to!\n", dem);
		}
		if (tien > X) 
		{
			dem = tien / X;
			tien %= X;
			printf(" So to menh gia"); Resize_Num(X); printf(" co %d to!\n", dem);
		}
		if(X > 500) X /= 2;
	}
}

//======================================================================================================

void Chuc_Nang_6()
{
	in tien_vay;
	printf("Nhap so tien muon vay: "); scanf("%d", &tien_vay);
	in goc_phai_tra = tien_vay / kyhan;
	printf("\nKy han Lai phai tra\tGoc phai tra\tSo tien phai tra\tSo tien con lai");
	forxuoi(1, 1, kyhan)
	{	
		in lai_phai_tra = tien_vay * laithang;
		in tien_phai_tra = goc_phai_tra + lai_phai_tra;
		tien_vay -= goc_phai_tra;

		printf("\n%02d", i);
		printf("     "); Resize_Num(lai_phai_tra);
		printf("\t\t"); Resize_Num(goc_phai_tra);
		printf("\t"); Resize_Num(tien_phai_tra);
		printf("\t\t"); Resize_Num(tien_vay);
	}
}

//======================================================================================================

void tinh_vay_tra_gop(double phantramvay)
{
	double phantramtratruoc = 1.0 - phantramvay;
	double sotien = 500000000;
	double laihangthang = 0.072 / 288;
	int thoihan = 288;

	double sotientratruoc = sotien * phantramtratruoc;
	sotien = sotien - sotientratruoc;

	double trahangthang = sotien / thoihan;

	printf("So tien tra truoc: %.lf\n", sotientratruoc);
	printf("\nSo tien tra hang thang: ");
	//printf("\nKyhan\t   Lai phai tra\t   Goc phai tra\t  So tien phai tra\tSo tien con lai\n");
	gotoxy(1, 6); printf("Ky han"); gotoxy(10, 6); printf("Lai phai tra");
	gotoxy(26, 6); printf("Goc phai tra"); gotoxy(41, 6); printf("So tien phai tra");
	gotoxy(60, 6); printf("So tien con lai\n");
	for (int i = 1; i <= thoihan; ++i)
	{
		double tralai = sotien * laihangthang;
		double tongphaitra = tralai + trahangthang ;
		sotien = sotien - trahangthang;
		if (sotien < 1) sotien = 0;
		gotoxy(1, i+6); printf("%d", i); gotoxy(10, i+6); printf("%.lf", tralai);
		gotoxy(26, i+6); printf("%.lf",trahangthang); gotoxy(41, i+6); printf("%.lf",tongphaitra);
		gotoxy(60, i+6); printf("%.lf",sotien);
	}
}

void Chuc_Nang_7()
{
	double phantramvay;
	do
	{
		printf("Nhap phan tram vay(tu 0.1 -> 1.0): ");
		scanf("%lf", &phantramvay);
		if (phantramvay < 0.1 || phantramvay > 1.0)
		{
			printf("\nSo phan tram nhap khong hop le!!\n");
			getch();
			system("cls");
		}
	} while (phantramvay < 0.1 || phantramvay > 1.0);
	tinh_vay_tra_gop(phantramvay);
}

//======================================================================================================
void Menu_sinh_vien()
{
	system("cls");
	printf("\n\t\t++----------------------++");
	printf("\n\t\t| [1]: Nhap sinh vien    |");
	printf("\n\t\t| [2]: Xuat sinh vien    |");
	printf("\n\t\t| [3]: Sap xep sinh vien |");
	printf("\n\t\t| [4]: Thoat             |");
	printf("\n\t\t++----------------------++");
	printf("\n\nXin moi chon chuc nang (1,2,3,4): ");
}
struct SinhVien
{
	char masv[10], ten[50], nganh[25], xeploai[15];
	db dtb;
};
typedef struct SinhVien SINHVIEN;

void SWAP(SINHVIEN* a, SINHVIEN* b)
{
	SINHVIEN temp = *a;
	*a = *b;
	*b = temp;
}

void nhap_sinh_vien(SINHVIEN* sv, in n)
{
	printf("Nhap thong tin cho %d sinh vien\n", n);
	getchar(); // xoa bo nho dem
	for (int i = 0; i < n; ++i)
	{
		printf("\n------------------------------------\n");
		printf("Nhap thong tin diem thi cho sv thu %d:\n", i + 1);

		printf("Nhap ma so sinh vien: "); fgets(sv[i].masv, 10, stdin);
		strtok(sv[i].masv, "\n");

		printf("Nhap ho ten sinh vien: "); fgets(sv[i].ten, 50, stdin);
		strtok(sv[i].ten, "\n");

		printf("Nhap nganh cua sinh vien: "); fgets(sv[i].nganh, 25, stdin);
		strtok(sv[i].nganh, "\n");

		do
		{
			printf("Nhap diem trung binh cho sinh vien nay: "); scanf("%lf", &sv[i].dtb);
			if (sv[i].dtb < 0 || sv[i].dtb > 10) printf("\nDiem trung binh nhap khong hop le!\n");
		} while (sv[i].dtb < 0 || sv[i].dtb>10);

		if (sv[i].dtb >= 9.0) strcpy(sv[i].xeploai, "Xuat xac");

		else if (sv[i].dtb >= 8.0) strcpy(sv[i].xeploai, "Gioi");

		else if (sv[i].dtb >= 6.5) strcpy(sv[i].xeploai, "Kha");

		else if (sv[i].dtb >= 5.0) strcpy(sv[i].xeploai, "Trung binh");

		else strcpy(sv[i].xeploai, "Yeu");

		getchar(); // xoa bo nho dem
	}
	printf("\n\nDa nhap thanh cong data!!");
	getch();
}

void sap_xep_sinh_vien(SINHVIEN* sv, in n, char luachon)
{
	for (in i = 0; i < n - 1; ++i)
	{
		for (in j = i + 1; j < n; ++j)
		{
			if (luachon == 't' || luachon == 'T')
			{
				if (sv[i].dtb < sv[j].dtb)
				{
					SWAP(&sv[i], &sv[j]);
				}
			}
			else if (luachon == 'g' || luachon == 'G')
			{
				if (sv[i].dtb > sv[j].dtb)
				{
					SWAP(&sv[i], &sv[j]);
				}
			}
		}
	}
}

void xuat_sinh_vien(SINHVIEN sv[], in n)
{
	printf("\n------------------------------------\n");
	printf("\nThong tin cua %d sinh vien:\n", n);
	gotoxy(1, 6); printf("Ma so");
	gotoxy(11, 6); printf("Ho va ten");
	gotoxy(38, 6); printf("Chuyen nganh");
	gotoxy(60, 6); printf("Diem");
	gotoxy(70, 6); printf("Xep loai");

	for (in i = 0; i < n; ++i)
	{
		gotoxy(1, i + 7); printf("%s", sv[i].masv);
		gotoxy(11, i + 7); printf("%s", sv[i].ten);
		gotoxy(38, i + 7); printf("%s", sv[i].nganh);
		gotoxy(60, i + 7); printf("%.2lf", sv[i].dtb);
		gotoxy(70, i + 7); printf("%s", sv[i].xeploai);
	}
}

void Chuc_Nang_8()
{
	in so_luong_sv = 0;
	SINHVIEN ar[100];
	in lc, check = 1;
	while (check)
	{
		Menu_sinh_vien();
		scanf("%d", &lc);
		switch (lc)
		{
		case 1:
			do
			{
				printf("Nhap so luong sinh vien: "); scanf("%d", &so_luong_sv);
				if (so_luong_sv < 0 || so_luong_sv > 100) printf("\nSo luong sinh vien nhap khong hop le!\n");
			} while (so_luong_sv < 0 || so_luong_sv > 100);

			nhap_sinh_vien(ar, so_luong_sv);
			system("cls");
			break;

		case 2:
			system("cls");
			xuat_sinh_vien(ar, so_luong_sv);
			getch();
			system("cls");
			break;

		case 3:
			if (so_luong_sv != 0)
			{
				system("cls");
				printf("\n\nBan muon sap xep sinh vien theo kieu:");
				printf("\n[t] Tang dan");
				printf("\n[g] Giam dan\n");
				getchar();
				char lc_sx; scanf("%c", &lc_sx);
				sap_xep_sinh_vien(ar, so_luong_sv, lc_sx);
				system("cls");
				printf("\n\nDa sap xep!!\nVui long quay lai nhan phim 2 de xem!");
				getch(); system("cls");
			}
			else
			{
				system("cls");
				printf("\n\nXin hay nhap sinh vien de sap xep!");
				getch(); system("cls");
			}
			break;

		case 4:
			check = 0;
			break;


		default:
			printf("\nLua chon khong hop le");
			getch();
			system("cls");
			break;
		}
	}
}

//======================================================================================================

void Chuc_Nang_9()
{
	srand(time(0));
	in a, b, c = 1+rand()%15, d = 1+rand()%15, cnt = 0;
	do
	{
		printf("\nVui long nhap a, b: "); scanf("%d%d", &a, &b);
		if (a < 1 || b < 1 || a > 15 || b > 15) printf("\na hoac b nhap khong chinh xac (1 <= a, b <= 15)\n");
	} while (a < 1 || b < 1 || a > 15 || b > 15);
	if (a == c || a == d) cnt++;
	else if (b == c || b == d) cnt++;
	printf("\nXin cho."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
	printf("\n2 so trung thuong cua chuong trinh la: %d, %d", c, d);
	if (cnt == 2) printf("\nXin chuc mung ban duoc giai nhat!");
	else if (cnt == 1) printf("\nXin chuc mung ban duoc giai nhi!");
	else if (cnt == 0) printf("\nChuc ban may man lan sau");
}

//======================================================================================================

struct PhanSo
{
	in tuso, mauso;
};
typedef struct PhanSo PHANSO;

int TimUCLN(in a, in b)
{
	// chi xet khi a != b, a = b return luon
	// xet truong hop con truoc: hoac a= 0 hoac b = 0:

	if (a == 0 && b != 0) return b;

	if (b == 0 && a != 0) return a;

	if (a < 0) a *= -1;

	if (b < 0) b *= -1;

	while (a != b)
	{
		if (a > b) a -= b;

		else b -= a;

	}
	return a; // or b cung ok
}

void nhap_phan_so(PHANSO* ps)
{
	printf("\nNhap vao tu so: "); scanf("%d", &(*ps).tuso);
	printf("\nNhap vao mau so: "); scanf("%d", &(*ps).mauso);
}

void xuat_phan_so(PHANSO ps)
{
	printf("%d/%d", ps.tuso, ps.mauso);
}

PHANSO tong_phan_so(PHANSO ps1, PHANSO ps2)
{
	PHANSO temp;
	temp.tuso = (ps1.tuso * ps2.mauso) + (ps2.tuso * ps1.mauso);
	temp.mauso = ps1.mauso * ps2.mauso;
	in rutgon = TimUCLN(temp.tuso, temp.mauso);
	if (temp.tuso % rutgon == 0) temp.tuso = temp.tuso / rutgon;
	if (temp.mauso % rutgon == 0) temp.mauso = temp.mauso / rutgon;
	if (temp.mauso < 0)
	{
		temp.tuso *= -1;
		temp.mauso *= -1;
	}

	return temp;
}

PHANSO hieu_phan_so(PHANSO ps1, PHANSO ps2)
{
	//	a/b - c/d = (a*d - b*c)/(b*d)

	PHANSO temp;
	temp.tuso = (ps1.tuso * ps2.mauso) - (ps2.tuso * ps1.mauso);
	temp.mauso = ps1.mauso * ps2.mauso;
	in rutgon = TimUCLN(temp.tuso, temp.mauso);
	if (temp.tuso % rutgon == 0) temp.tuso = temp.tuso / rutgon;
	if (temp.mauso % rutgon == 0) temp.mauso = temp.mauso / rutgon;
	if (temp.mauso < 0)
	{
		temp.tuso *= -1;
		temp.mauso *= -1;
	}
	return temp;
}

PHANSO nhan_phan_so(PHANSO ps1, PHANSO ps2)
{
	//	a/b * c/d = a*b/c*d

	PHANSO temp;
	temp.tuso = ps1.tuso * ps2.tuso;
	temp.mauso = ps1.mauso * ps2.mauso;
	in rutgon = TimUCLN(temp.tuso, temp.mauso);
	if (temp.tuso % rutgon == 0) temp.tuso = temp.tuso / rutgon;
	if (temp.mauso % rutgon == 0) temp.mauso = temp.mauso / rutgon;

	if (temp.mauso < 0)
	{
		temp.tuso *= -1;
		temp.mauso *= -1;
	}
	return temp;
}

PHANSO chia_phan_so(PHANSO ps1, PHANSO ps2)
{
	//	a/b - c/d = a*d/b*c

	PHANSO temp, ans;	// ps dao
	// dao lai ps2
	temp.tuso = ps2.mauso;
	temp.mauso = ps2.tuso;
	ans = nhan_phan_so(ps1, temp);
	in rutgon = TimUCLN(temp.tuso, temp.mauso);
	if (ans.tuso % rutgon == 0) ans.tuso = ans.tuso / rutgon;
	if (ans.mauso % rutgon == 0) ans.mauso = ans.mauso / rutgon;
	if (ans.mauso < 0)
	{
		ans.tuso *= -1;
		ans.mauso *= -1;
	}
	return ans;
}

void Chuc_Nang_10()
{
	PHANSO ps1, ps2, tong, hieu, nhan, thuong;
	nhap_phan_so(&ps1);
	nhap_phan_so(&ps2);
	printf("\nPhan so thu nhat la: "); xuat_phan_so(ps1);
	printf("\nPhan so thu hai la: "); xuat_phan_so(ps2);
	tong = tong_phan_so(ps1, ps2);
	printf("\n\nTong hai phan so la: "); xuat_phan_so(tong);
	hieu = hieu_phan_so(ps1, ps2);
	printf("\nHieu hai phan so la: "); xuat_phan_so(hieu);
	nhan = nhan_phan_so(ps1, ps2);
	printf("\nTich hai phan so la: "); xuat_phan_so(nhan);
	thuong = chia_phan_so(ps1, ps2);
	printf("\nThuong hai phan so la: "); xuat_phan_so(thuong);
}

//======================================================================================================

void NhayNhayCacthu()
{
	forxuoi(1, 1, 14)
	{
		gotoxy(10, 22);
		colorchar(i); printf("Lua chon nhap khong hop le!");
		Sleep(70);
	}
}

in main()
{
	while (1)
	{
		Menu(15,15);
		colorchar(15); printf("\nXin moi chon chuc nang: "); scanf("%lld", &lc);

		switch (lc)
		{
		case 1:
			Menu(15, 1);
			printf("\n");
			Chuc_Nang_1();
			getch();
			system("cls");
			break;

		case 2:
			Menu(15, 2);
			printf("\n");
			Chuc_Nang_2();
			getch();
			system("cls");
			break;

		case 3:
			Menu(15, 3);
			printf("\n");
			Chuc_nang_3();
			getch();
			system("cls");
			break;

		case 4:
			Menu(15, 4);
			printf("\n");
			Chuc_Nang_4();
			getch();
			system("cls");
			break;

		case 5:
			Menu(15, 5);
			printf("\n");
			Chuc_Nang_5();
			getch();
			system("cls");
			break;

		case 6:
			Menu(15, 6);
			printf("\n");
			Chuc_Nang_6();
			getch();
			system("cls");
			break;

		case 7:
			Menu(15, 7);
			printf("\n");
			Chuc_Nang_7();
			getch();
			system("cls");
			break;

		case 8:
			Menu(15, 8);
			printf("\n");
			Chuc_Nang_8();
			getch();
			system("cls");
			break;

		case 9:
			Menu(15, 9);
			printf("\n");
			Chuc_Nang_9();
			getch();
			system("cls");
			break;

		case 10:
			Menu(15, 10);
			printf("\n");
			Chuc_Nang_10();
			getch();
			system("cls");
			break;

		case 11:
			Menu(15, 11);
			Sleep(250);
			system("cls");
			return 0;
			break;

		default:
			NhayNhayCacthu();
			gotoxy(10, 22); printf("                              "); gotoxy(25, 20);
			system("cls");
			break;
		}
	}
	return 0;
}
