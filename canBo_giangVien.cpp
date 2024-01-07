#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Date {
    int ngay;
    int thang;
    int nam;
};

Date getDate(std::string date) {
    std::stringstream ss(date);
    std::string tmp;
    std::vector<int> v;
    while(getline(ss, tmp, '/')) {
        v.push_back(stoi(tmp));
    }
    Date time;
    time.ngay = v[0];
    time.thang = v[1];
    time.nam = v[2];
    return time;
}

bool check(std::vector<std::string> v, std::string donVi) {
    for(int i = 0; i < v.size(); i ++) {
        if(donVi == v[i]) {
            return 1;
        }
    }
    return 0;
}

class CanBo {
    public:
        CanBo() {
            this->maCanBo = "Unknown";
            this->hoTen = "Unknown";
            this->ngayVaoCoQuan.ngay = 0;
            this->ngayVaoCoQuan.ngay = 0;
            this->ngayVaoCoQuan.nam = 0;
        }
        CanBo(std::string maCanBo, std::string hoTen, std::string ngayVaoCoQuan) {
            this->maCanBo = maCanBo;
            this->hoTen = hoTen;
            this->ngayVaoCoQuan = getDate(ngayVaoCoQuan);
        }
        void setMaCanBo(std::string maCanBo) {
            this->maCanBo = maCanBo;
        }
        std::string getMaCanBo() {
            return this->maCanBo;
        }
        void setHoTen(std::string hoTen) {
            this->hoTen = hoTen;
        }
        std::string getHoTen() {
            return this->hoTen;
        }
        void setNgayVaoCoQuan(std::string ngayVaoCoQuan) {
            this->ngayVaoCoQuan = getDate(ngayVaoCoQuan);
        }
        Date getNgayVaoCoQuan() {
            return this->ngayVaoCoQuan;
        }
        void nhapDuLieu() {
            std::cout << "\tNhap vao ma can bo: ";
            std::cin >> this->maCanBo;
            std::cin.ignore();
            std::cout << "\tNhap vao ho ten: ";
            getline(std::cin, this->hoTen);
            std::string ngayVaoCoQuan;
            std::cout << "\tNhap vao ngay vao co quan (ngay/thang/nam): ";
            std::cin >> ngayVaoCoQuan;
            this->ngayVaoCoQuan = getDate(ngayVaoCoQuan);
            std::cin.ignore();
        }
        void hienThi() {
            std::cout << "\tMa can bo: " << this->maCanBo << "\n";
            std::cout << "\tHo ten: " << this->hoTen << "\n";
            std::cout << "\tNgay vao co quan: " << this->ngayVaoCoQuan.ngay << '/' << this->ngayVaoCoQuan.thang << '/' << this->ngayVaoCoQuan.nam << "\n";
        }
        bool operator>(CanBo &other) {
            if(this->ngayVaoCoQuan.nam > other.ngayVaoCoQuan.nam) {
                return 1;
            }
            else if(this->ngayVaoCoQuan.nam == this->ngayVaoCoQuan.nam) {
                if(this->ngayVaoCoQuan.thang > other.ngayVaoCoQuan.thang) {
                    return 1;
                }
                else if(this->ngayVaoCoQuan.thang == other.ngayVaoCoQuan.thang) {
                    if(this->ngayVaoCoQuan.ngay > this->ngayVaoCoQuan.ngay) {
                        return 1;
                    }
                    return 0;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
    private:
        std::string maCanBo;
        std::string hoTen;
        Date ngayVaoCoQuan;
};

class GiangVien : public CanBo {
    public:
        GiangVien() {
            this->donVi = "Unknown";
            this->heSoLuong = 0;
            this->phuCapChuVu = 0;
        }
        GiangVien(std::string maCanBo, std::string hoTen, std::string ngayVaoCoQuan, std::string donVi, int heSoLuong, int phuCapChucVu) : CanBo(maCanBo, hoTen, ngayVaoCoQuan) {
            this->donVi = donVi;
            this->heSoLuong = heSoLuong;
            this->phuCapChuVu = phuCapChucVu;
        }
        void setDonVi(std::string donVi) {
            this->donVi = donVi;
        }
        std::string getDonVi() {
            return this->donVi;
        }
        void setHeSoLuong(float heSoLuong) {
            this->heSoLuong = heSoLuong;
        }
        float getHeSoLuong() {
            return this->heSoLuong;
        }
        void setPhuCapChucVu(float phuCapChucVu) {
            this->phuCapChuVu = phuCapChucVu;
        }
        float getPhuCapChucVu() {
            return this->phuCapChuVu;
        }
        float getTienLuong() {
            return this->heSoLuong * 1490000 + this->phuCapChuVu;
        }
        void nhapDuLieu() {
            CanBo::nhapDuLieu();
            std::cout << "\tNhap vao don vi: ";
            getline(std::cin, this->donVi);
            std::cout << "\tNhap vao he so luong: ";
            std::cin >> this->heSoLuong;
            std::cout << "\tNhap vao phu cap chuc vu: ";
            std::cin >> this->phuCapChuVu;
        }
        void hienThi() {
            CanBo::hienThi();
            std::cout << "\tDon vi: " << this->donVi << "\n";
            std::cout << "\tHe so luong: " << this->heSoLuong << "\n";
            std::cout << "\tPhu cap chu vu: " << this->phuCapChuVu << "\n";
            std::cout << "\tTien luong: " << this->getTienLuong() << "\n";
        }
    private:
        std::string donVi;
        float heSoLuong;
        float phuCapChuVu;
};

int main() {
    int n;
    std::cout << "Nhap vao so luong giang vien: ";
    std::cin >> n;
    GiangVien gv[n];
    for(int i = 0; i < n; i ++) {
        std::cout << "Nhap vao giang vien thu " << i + 1 << ":\n";
        gv[i].nhapDuLieu();
    }
    for(int i = 0; i < n - 1; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(gv[i] > gv[j]) {
                std::swap(gv[i], gv[j]);
            }
        }
    }
    std::cout << "Danh sach giang vien:\n";
    for(int i = 0; i < n; i ++) {
        std::cout << "Giang vien:\n";
        gv[i].hienThi();
    }
    float tongLuong = 0;
    for(int i = 0; i < n; i ++) {
        tongLuong += gv[i].getTienLuong();
    }
    std::cout << "Luong trung binh cua cac giang vien: " << tongLuong / n << "\n";
    std::vector<std::string> donVi;
    for(int i = 0; i < n; i ++) {
        if(check(donVi, gv[i].getDonVi()) == 0) {
            donVi.push_back(gv[i].getDonVi());
        }
    }
    std::cout << "Bang luong cua cac giao vien theo tung don vi:\n";
    for(int i = 0; i < donVi.size(); i ++) {
        std::cout << "Don vi " << donVi[i] << ":\n";
        for(int j = 0; j < n; j ++) {
            if(donVi[i] == gv[j].getDonVi()) {
                std::cout << "Giang vien:\n";
                gv[j].hienThi();
            }
        }
    }
    return 0;
}