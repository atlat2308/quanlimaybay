#include"Mylib.h"
#include"Maybay.h"
#include<iostream>
using namespace std;
int main() {
    LISTMB LMB;
    LMB.n = 0;

    DocFileDSMB(FileDSMB, LMB);

    NODECB LCB;
    Init(LCB);
    DocFileDSCB(FileDSCB, LCB);

    BSTKH LKH;
    InitBST(LKH);
    DocFileDSKH(FileDSKH, LKH);
    int soluongmenu = 8;// so luong menu

    char a[8][70] = { "1. QUAN LI MAY BAY",
                          "2. QUAN LI CHUYEN BAY",
                          "3. DAT VE",
                          "4. HUY VE",
                          "5. IN DANH SACH HANH KHACH TREN MOT CHUYEN BAY",
                          "6. IN DANH SACH CAC CHUYEN BAY KHOI HANH TRONG NGAY",
                          "7. IN DANH SACH CAC VE CON TRONG CUA MOT CHUYEN BAY",
                          "8. THONG KE SO LUOT THUC HIEN CHUYEN BAY CUA TUNG MAY BAY"
    };
    // goi ham menu trong menu.h
    int m;
    do
    {
        ShowCur(false);
        TextColor(0x0004);
        system("cls");
        TextColor(Green);
        vekhung(68, 35, 1, 30);
        PutCharXY(70, 36, "ESC: THOAT | ENTER: XAC NHAN", Green);
        m = menu(55, 10, a, soluongmenu);
        switch (m)
        {
        case  0:
        {
            UpdateMB(LMB, LCB);
            break;
        }
        case 1:
        {
            UpdateCB(LCB, LMB);
            break;
        }
        case 2:
        {
            DatVe(LCB, LMB, LKH);
            break;
        }
        case 3:
        {    
            HuyVe(LCB);
            break;

        }
        case 4:
        {
            InDSHK(LCB, LKH);
            break;
        }
        case 5:
        {

            DSCBKHTN(LCB, LMB);
            break;
        }
        case 6:
        {
            DSVT(LCB, LMB);
            break;
        }


        }
    } while (m != -1);
    delete[] LMB.nodes;
    deleteAll(LCB);
    PutCharXY(55, 21, "CAM ON BAN DA SU DUNG PHAN MEM!!", Cyan);
    Sleep(3000);
    return 0;
}