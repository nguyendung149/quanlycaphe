#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#define SIZE 100
struct Menu {
	int maMon;
	char tenMon[SIZE];
	double giaTien;
	struct Menu *next;
};
struct Order {
	int maMonKhachGoi;
	int soPhan;
	double thanhTien;
	struct Order *next;
};
struct Bill {
	int maPhieu;
	double tongTien;
	struct Bill *next;
};
typedef struct Menu menu;
typedef struct Order order;
typedef struct Bill bill;
menu *head_menu;
order *head_order;
bill *head_bill;


void khoiTao(menu *&thucDon){
	printf("\n---------------------MON MOI---------------------------");
	fflush(stdin);
	printf("\nNhap ma mon: ");
	scanf("%d",&thucDon->maMon);
	fflush(stdin);
	printf("\nNhap ten mon: ");
	gets(thucDon->tenMon);
	fflush(stdin);
	printf("\nGia tien: ");
	scanf("%lf",&thucDon->giaTien);
	thucDon->next = NULL;
}
void themMon(menu *&thucDon,menu *monThemVao){
	menu *temp = thucDon;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = monThemVao;
}
void xemThucDon(menu *&thucDon){
	printf("-------------------QUAN CAFE-MENU------------------------");
	menu *temp = thucDon;
	while (temp!=NULL){
		printf("\nMa Mon: %d",temp->maMon);
		printf("\nTen Mon: %s",temp->tenMon);
		printf("\nGia Tien: %.2lf",temp->giaTien);
		printf("\n-----------------------\n");
		temp = temp->next;
	}
}
int timKiem (menu *&thucDon, int maM){
	menu *temp = thucDon;
	while(temp!=NULL){
		if(temp->maMon==maM){
			printf("\nMON CAN TIM\n");
			printf("\nMa Mon: %d",temp->maMon);
			printf("\nTen Mon: %s",temp->tenMon);
			printf("\nGia Tien: %lf",temp->giaTien);
			printf("\n-----------------------\n");	
			
			return 1;
		}
		temp = temp->next;
	}
	printf("\nKHONG CO TRONG THUC DON");
	return 0;
}
void xoaMon(menu *&thucDon, menu *monCanXoa){
	menu *temp = thucDon;
	int count = 0;
	while(temp->next!=NULL){
		if(temp->maMon!=monCanXoa->maMon){
			count++;
			temp = temp->next;
		}else {
			break;
		}
	}
	temp = thucDon;
	if(count==0){
		thucDon = thucDon->next;
	}else{
		for(int i = 1;i<count;i++){
			temp = temp->next;
		}
		if(temp->next->next==NULL){
			temp->next = NULL;
		} else{
			temp->next = temp->next->next;
		}
	}
}
void chinhSua(menu *&thucDon, menu *monCanChinhSua){
	menu *temp = thucDon;
	while(temp!=NULL){
		if(temp->maMon==monCanChinhSua->maMon){
			printf("\nCHINH SUA\n");
			printf("\nNhap Ten Mon: ");
			fflush(stdin);
			gets(temp->tenMon);
			fflush(stdin);
			printf("\nNhap Gia Tien: ");
			scanf("%lf",&temp->giaTien);
			break;
		}
		temp = temp->next;
	}
}
// Sort the linked list
void sapXep(menu *&head_ref) {
  menu *current = head_ref, *index = NULL;
  double temp;
  int temp2;
  char temp1[] = " ";
  if (head_ref == NULL) {
    return;
  } else {
    while (current != NULL) {
      // index points to the node next to current
      index = current->next;

  	while (index != NULL) {
        if (current->giaTien > index->giaTien) {
          temp = current->giaTien;
          current->giaTien = index->giaTien;
          index->giaTien = temp;
          
          temp2 = current->maMon;
          current->maMon = index->maMon;
          index->maMon = temp2;
          
          strcpy(temp1,current->tenMon);
          strcpy(current->tenMon,index->tenMon);
          strcpy(index->tenMon,temp1);
    	}
    	  index = index->next;
  	}
  	current = current->next;
    }
  }
}
void khoiTao_Order(order *head_order,menu *head_menu){
	printf("\nNhap ma mon khach goi: ");
	scanf("%d",&head_order->maMonKhachGoi);
	printf("\nSo luong phan: ");
	scanf("%d",&head_order->soPhan);
	menu *temp;
	temp = (menu*)malloc(sizeof(menu));
	temp = head_menu;
	while(temp!=NULL){
		if(temp->maMon==head_order->maMonKhachGoi){
			printf("\nMa Mon: %d",temp->maMon);
			printf("\nTen Mon: %s",temp->tenMon);
			printf("\nGia Tien: %.2lf",temp->giaTien);
			printf("\n-----------------------\n");
			break;
		}	
		temp = temp->next;
	}
	head_order->thanhTien = (head_order->soPhan)*(temp->giaTien);
	printf("So tien phai tra: %lf ",head_order->thanhTien);
	head_order->next = NULL;
}
void themVaoDau(order *goiMon){
	head_order = goiMon;
}
void themMonTuMenu(order *head_order,order *goiMon){
	order *temp = head_order;
	if(head_order==NULL){
		themVaoDau(goiMon);
	}
	else{
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = goiMon;
	}
}
void xemMonDaGoi(order *&head_order){
	printf("-------------------MON KHACH DAT------------------------");
	order *temp = head_order;
	while (temp!=NULL){
		printf("\nMa Mon: %d",temp->maMonKhachGoi);
		printf("\nSo phan: %d",temp->soPhan);
		printf("\nThanh tien: %.2lf",temp->thanhTien);
		printf("\n-----------------------\n");
		temp = temp->next;
	}
}
void xoaMonDaGoi(order *&head_order, int maMonCanXoa){
	order *temp = head_order;
	int count = 0;
	while(temp->next!=NULL){
		if(temp->maMonKhachGoi!=maMonCanXoa){
			count++;
			temp = temp->next;
		}else {
			break;
		}
	}
	temp = head_order;
	if(count==0){
		head_order = head_order->next;
	}else{
		for(int i = 1;i<count;i++){
			temp = temp->next;
		}
		if(temp->next->next==NULL){
			temp->next = NULL;
		} else{
			temp->next = temp->next->next;
		}
	}
}
void chinhSuaSoPhan(order *&head_order,int maMonCanChinhSua){
	order *temp = head_order;
	while(temp!=NULL){
		if(temp->maMonKhachGoi==maMonCanChinhSua){
			printf("\nCHINH SUA\n");
			double thanhTien;
			thanhTien = (double)(temp->thanhTien)/(temp->soPhan);
			printf("\nNhap so luong: ");
			fflush(stdin);
			scanf("%d",&temp->soPhan);
			fflush(stdin);
			temp->thanhTien = thanhTien*(temp->soPhan);
			printf("\nThanh tien: %.2lf",temp->thanhTien);
			break;
		}
		temp = temp->next;
	}
}
void khoiTao_Bill(bill *head_bill,order *head_order){
	double TongTien = 0;
	order *temp = head_order;
	while(temp!=NULL){
		TongTien = TongTien + temp->thanhTien;
		temp = temp->next;
	}
	printf("\nNhap ma phieu thanh toan ");
	scanf("%d",&head_bill->maPhieu);
	head_bill->tongTien = TongTien;
	head_bill->next = NULL;
}
void themVaoDauBill(bill *bill_canThem){
	head_bill = bill_canThem;
}
void themBill(bill *head_bill,bill *bill_canThem){
	bill *temp1 = head_bill;
	if(head_bill==NULL){
		themVaoDauBill(bill_canThem);
	}else{
		while(temp1->next!=NULL){
			temp1 = temp1->next;
		}
		temp1->next = bill_canThem;
	}
}
void xemDanhSachBill (bill *head_bill){
	printf("-------------------DANH SACH BILL------------------------");
	bill *temp = head_bill;
	while (temp!=NULL){
		printf("\nMa phieu thanh toan: %d",temp->maPhieu);
		printf("\nTong so tien can tra: %.2lf",temp->tongTien);
		printf("\n-----------------------\n");
		temp = temp->next;
	}
}
int timKiemBill (bill *&head_bill, int maPhieu){
	bill *temp = head_bill;
	while(temp!=NULL){
		if(temp->maPhieu==maPhieu){
			printf("\nPHIEU CAN TIM\n");
			printf("\nMa phieu: %d",temp->maPhieu);
			printf("\nTong so tien phai tra: %.2lf",temp->tongTien);
			printf("\n-----------------------\n");	
			
			return 1;
		}
		temp = temp->next;
	}
	printf("\nKHONG CO PHIEU NAY");
	return 0;
}
// Sort the linked list
void sapXepBill(bill *head_bill) {
  bill *current = head_bill, *index = NULL;
  double temp;
  int temp2;
  char temp1[] = " ";
  if (head_bill == NULL) {
    return;
  } else {
    while (current != NULL) {
      // index points to the node next to current
      index = current->next;

  	while (index != NULL) {
        if (current->tongTien > index->tongTien) {
          temp = current->tongTien;
          current->tongTien = index->tongTien;
          index->tongTien = temp;
          
          temp2 = current->maPhieu;
          current->maPhieu = index->maPhieu;
          index->maPhieu = temp2;
    	}
    	  index = index->next;
  	}
  	current = current->next;
    }
  }
}
int main(){
	head_menu = (menu*)malloc(sizeof(menu));
	head_order = (order*)malloc(sizeof(order));
	head_bill = (bill*)malloc(sizeof(bill));
	int luaChon = 0;
	do {
		printf("\n-----------------------------MENU LUA CHON--------------------------\n");
		printf("\n1. Khoi tao thuc don");
		printf("\n2. Them mon");
		printf("\n3. Xem thuc don");
		printf("\n4. Xoa mon");
		printf("\n5. Tim kiem theo ma mon");
		printf("\n6. Chinh sua thong tin");
		printf("\n7. Sap xep theo gia");
		printf("\n8. Khoi tao dat mon (chon dau tien)");
		printf("\n9. Them mon can Dat mon");
		printf("\n10. Xem danh sach dat mon");
		printf("\n11. Xoa mon da goi");
		printf("\n12. Chinh sua so phan");
		printf("\n13. Khoi tao Bill ban dau");
		printf("\n14. Them Bill khac");
		printf("\n15. Xem danh sach Bill");
		printf("\n16. Tim kiem theo ma Phieu");
		printf("\n17. Sap xep theo tong tien");
		printf("\n0. Nhan 0 de thoat ra");
		printf("\nNhap lua chon: ");
		scanf("%d",&luaChon);
		switch(luaChon){
			case 1: {
				khoiTao(head_menu);
				break;
			}
			case 2: {
				menu *monThemVao;
				monThemVao = (menu*)malloc(sizeof(menu));	
				khoiTao(monThemVao);
				themMon(head_menu,monThemVao);
				break;
				
			}
			case 3: {
				xemThucDon(head_menu);
				break;
			}
			case 4: {
				menu *monCanXoa;
				monCanXoa = (menu*)malloc(sizeof(menu));	
				khoiTao(monCanXoa);
				xoaMon(head_menu, monCanXoa);
				break;
			}
			case 5: {
				int maM;
				printf("\nNhap ma mon: ");
				scanf("%d",&maM);
				timKiem (head_menu,maM);
				break;
			}
			case 6: {
				menu *monCanChinhSua;
				monCanChinhSua = (menu*)malloc(sizeof(menu));
				khoiTao(monCanChinhSua);
				chinhSua(head_menu,monCanChinhSua);
				break;
			}
			case 7: {
				sapXep(head_menu);
				break;
			}
			case 8: {
				khoiTao_Order(head_order,head_menu);
				break;
			}
			case 9: {
				order *monThemVao;
				monThemVao = (order*)malloc(sizeof(order));	
				khoiTao_Order(monThemVao,head_menu);
				themMonTuMenu(head_order,monThemVao);
				break;
			}	
			case 10: {
				xemMonDaGoi(head_order);
				break;
			}
			case 11: {
				int maMon;
				printf("\nNhap ma mon can xoa: ");
				scanf("%d",&maMon);
				xoaMonDaGoi(head_order,maMon);
				break;	
			}
			case 12: {
				int ma;
				printf("\nNhap ma mon can chinh sua: ");
				scanf("%d",&ma);
				fflush(stdin);
				chinhSuaSoPhan(head_order,ma);
				break;
			}
			case 13: {
				khoiTao_Bill(head_bill,head_order);
				break;
			}
			case 14: {
				bill *bill_canThem;
				bill_canThem = (bill*)malloc(sizeof(bill));
				khoiTao_Bill(bill_canThem,head_order);
				themBill(head_bill,bill_canThem);
				break;
			}
			case 15: {
				xemDanhSachBill(head_bill);
				break;	
			}
			case 16: {
				int maPhieu;
				printf("Nhap ma phieu can tim");
				scanf("%d",&maPhieu);
				timKiemBill(head_bill,maPhieu);
				break;
			}
			case 17: {
				sapXepBill(head_bill);
				break;
			}	
		}		
	}while(luaChon>0);
	free(head_menu);
	return 0;
	
}


	
