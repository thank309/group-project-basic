#include <stdio.h>
#include <string.h>

void hienThiTenCot();

struct HoTen {
	char ho[20];
	char dem[20];
	char ten[20];
};
struct NgayThangNam {
	int ngay;
	int thang;
	int nam;
};
struct DiemMH {
	float toan;
	float van;
	float anh;
	float tbc;
};

struct SinhVien {
	char ma[100];
	struct HoTen hoVaTen;
	struct NgayThangNam ngaysinh;
	struct DiemMH diem;
};

void nhapDiem(struct DiemMH* diem) {
	printf("Toan: ");
	scanf("%f", &diem->toan);
	printf("Van: ");
	scanf("%f", &diem->van);
	printf("Anh: ");
	scanf("%f", &diem->anh);
	diem->tbc = (diem->toan + diem->van + diem->anh) / 3;

}

void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}
void nhapNgayThangNam(struct NgayThangNam* ngaysinh){
        printf("Day: ");
        scanf("%d", &ngaysinh->ngay);
        printf("Month: ");
        scanf("%d", &ngaysinh->thang);
        printf("Year: ");
        scanf("%d", &ngaysinh->nam);
}
struct SinhVien nhapSV() {
	struct SinhVien sv;
	printf("Nhap ma: ");
	fflush(stdin);
	gets(sv.ma);
	nhapHoTen(&sv.hoVaTen);
	nhapNgayThangNam(&sv.ngaysinh);
	nhapDiem(&sv.diem);
	return sv;
}

void hienThiTTSV(struct SinhVien sv) {
	printf("%-10s %s %s %-10s %-10d %-10d %-10d %-10.2f %-10.2f %-10.2f %-10.2f\n",
	sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, 
	sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam, 
	sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
}

void diemGPAmax(struct SinhVien* sv, int n)
{
    int index=1;
    float max=(sv[1].diem.toan+sv[1].diem.van+sv[1].diem.anh)/3;
    int i;
    for(i=1;i<=n;i++)
    {
        if(((sv[i].diem.toan+sv[i].diem.van+sv[i].diem.anh)/3)>max)
        {
        max=(sv[i].diem.toan+sv[i].diem.van+sv[i].diem.anh)/3;
        index=i;
        }
    }
    return ;
}

void ghiFile(struct SinhVien* ds, int slsv) {
	FILE* fout = fopen("SV.txt", "a");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fout, "%-10s %s %s %-10s %-10d %-10d %-10d %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, 
		sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam,
		sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
	}
	fclose(fout);
}

void hienThiTenCot() {
	printf("%-10s %s %s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
		"Ma SV", "Ho", "Dem", "Ten", 
		"Day", "Month", "Year",  
		"Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
}

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	
	do {
		printf("=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep theo diem giam dan.");
		printf("\n4. Ghi thong tin sinh vien ra file.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		int i;
		switch(luaChon) {
			case 0:
				break;
				
			case 1:
				{
                    int n;
                    printf("\nNhap so luong Sinh vien : ");
                    scanf("%d",&n);
                    for(int i = 1; i <= n ;i++)
                    {
                        printf("\nNhap Don vi Sinh vien thu: %d \n",i);
				sv = nhapSV();
				dssv[slsv++] = sv;
			}
				break;
			}
			case 2:
				hienThiTenCot();
				for(i = 0; i < slsv; i++) {
					hienThiTTSV(dssv[i]);
				}
				break;
				
			case 3:
				diemGPAmax();
				printf("GPA cao nhat la: ");
				break;
				
			case 4:
				ghiFile(dssv, slsv);
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}
