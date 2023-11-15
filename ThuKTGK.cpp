#include <iostream>
using namespace std;
struct SACH{
    int IDSach;
    string TenSach;
    string TypeSach;
    string TenTG;
    int NamXB;
    string NhaSX;
    bool TinhTrang;
    SACH* next;
};

SACH* THEMSACH(SACH *&head,int IDSach, string TenSach, string TypeSach,string TenTG, int NamXB, string NhaSX,bool TinhTrang){
    SACH *s = new SACH;
    s->IDSach = IDSach;
    s->TenSach = TenSach;
    s->TypeSach = TypeSach;
    s->TenTG = TenTG;
    s->NamXB = NamXB;
    s->NhaSX = NhaSX;
    s->TinhTrang = TinhTrang;
    s->next = NULL;
    if (head  == NULL){
        head = s;
    }
    else{
        SACH *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = s;
    }
    return head;
}

void InDS(SACH *head){
    SACH *current = head;
    while (current != NULL){
        cout << "Ma sach: " << current->IDSach << endl;
        cout << "Ten sach: " << current->TenSach << endl;
        cout << "The loai sach: " << current->TypeSach << endl;
        cout << "Ten tav gia: " << current->TenTG << endl;
        cout << "Nam xuat ban: " << current->NamXB << endl;
        cout << "Nha xuat ban: " << current->NhaSX << endl;
        cout << "Tinh trang: " << (current->TinhTrang ? "Con" : "Het") << endl;
        cout << endl;
        current = current->next;
    }
} 

int DemSach(SACH *head){
    int count = 0;
    SACH *current  = head;
    while(current!= NULL){
        count++;
        current = current->next;
    }
    return count;
}

void TimSach(SACH *head, int code){
    SACH *current  = head;
    while(current != NULL){
        if(current->IDSach == code){
            cout << "Ma sach: " << current->IDSach << endl;
            cout << "Ten sach: " << current->TenSach << endl;
            cout << "The loai sach: " << current->TypeSach << endl;
            cout << "Ten tav gia: " << current->TenTG << endl;
            cout << "Nam xuat ban: " << current->NamXB << endl;
            cout << "Nha xuat ban: " << current->NhaSX << endl;
            cout << "Tinh trang: " << (current->TinhTrang ? "Con" : "Het") << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }
    cout<<"Khong tim thay!";
}

void SachCon(SACH *head){
    SACH *current = head;
    while(current != NULL){
        if(current->TinhTrang){
            cout << "Ma sach: " << current->IDSach << endl;
            cout << "Ten sach: " << current->TenSach << endl;
            cout << "The loai sach: " << current->TypeSach << endl;
            cout << "Ten tac gia: " << current->TenTG << endl;
            cout << "Nam xuat ban: " << current->NamXB << endl;
            cout << "Nha xuat ban: " << current->NhaSX << endl;
            cout << "Tinh trang: " << (current->TinhTrang ? "Con" : "Het") << endl;
            cout << endl;
        }
        current = current->next;
    }
}


void XoaSachKhongTT(SACH *&head) {
    SACH *current = head;
    SACH *prev = NULL;

    while (current != NULL) {
        if (!current->TinhTrang) {
            if (prev == NULL) {
                // Xóa phần tử đầu danh sách
                head = current->next;
                delete current;
                current = head;
            } else {
                // Xóa phần tử không phải ở đầu danh sách
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            // Di chuyển đến phần tử tiếp theo
            prev = current;
            current = current->next;
        }
    }
}





int main(){
    SACH *head = NULL;
    char luachon;
    while(true){
        cout<<"a. Nhap danh sach thong tin sach ban phim."<<endl;
        cout<<"b. Xuat danh sach thong tin sach ra man hinh."<<endl;
        cout<<"c. Dem so luong sach trong thu vien."<<endl;
        cout<<"d. Tim kiem mot quyen sach theo ma va tra ve thong tin day du."<<endl;
        cout<<"e. Xuat thong tin ra man hinh cac quyen sach o trang thai con."<<endl;
        cout<<"f. Xoa tat ca cac thong tin quyen sach o trang thai het."<<endl;
        cout<<"g. Sap xep danh sach tang dan theo ten sach."<<endl;
        cout<<"h. Ghi danh sach thong tin sach ra file nhi phan."<<endl;
        cout<<"i. Doc danh sach thong tin sach tu file nhi phan."<<endl;
        cout<<"j. Thoat."<<endl;
        cout<<"Nhap lua chon cua ban: ";
        cin>>luachon;
        switch(luachon){
            case 'a':
                int soLuongSach;
                cout << "Nhap so luong sach can them: ";
                cin >> soLuongSach;
                for (int i = 0; i < soLuongSach; i++) {
                    int IDSach;
                    string TenSach;
                    string TypeSach;
                    string TenTG;
                    int NamXB;
                    string NhaSX;
                    bool TinhTrang;
                    string TinhTrangstr;
                    cout << "Nhap ma sach: ";
                    cin >> IDSach;
                    cout << "Nhap ten sach: ";
                    cin.ignore();
                    getline(cin, TenSach);
                    cout << "Nhap the loai sach: ";
                    getline(cin, TypeSach);
                    cout << "Nhap ten tac gia: ";
                    getline(cin, TenTG);
                    cout << "Nhap nam xuat ban: ";
                    cin >> NamXB;
                    cout << "Nhap nha xuat ban: ";
                    cin.ignore();
                    getline(cin, NhaSX);
                    cout << "Nhap tinh trang sach (1: Con, 0: Het): ";
                    cin >> TinhTrangstr;
                    if (TinhTrangstr == "1") TinhTrang = true;
                    else TinhTrang = false;
                    THEMSACH(head, IDSach, TenSach, TypeSach, TenTG, NamXB, NhaSX, TinhTrang);
                }
                break;
            case 'b':
                InDS(head);
                break;
            case 'c':
                cout << "So luong sach trong thu vien la: " << DemSach(head) << endl;
                break;
            case 'd':
                int code;
                cout << "Nhap ma sach can tim: ";
                cin >> code;
                TimSach(head, code);
                break;
            case 'e':
                SachCon(head);
                break;
            case 'f':
                XoaSachKhongTT(head);
                break;
            case 'g':
                // Gọi hàm sắp xếp sách ở đây
                break;
            case 'h':
                // Gọi hàm ghi sách ra file ở đây
                break;
            case 'i':
                // Gọi hàm đọc sách từ file ở đây
                break;
            case 'j':
                exit(0);
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
    return 0;
}