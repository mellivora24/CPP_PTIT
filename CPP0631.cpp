#include<bits/stdc++.h>

using namespace std;

int idKH=0;
int idMH=0;
int idHD=0;

class KhachHang;
class MatHang;
class HoaDon;

map<string,KhachHang> mpKH;
map<string,MatHang> mpMH;

void chuanhoa (string &ma, int id){
	if (id < 10) ma += "00" + to_string(id);
	else if (id < 100) ma += "0" + to_string(id);
	else ma += to_string(id);
}

class KhachHang {
private:
	string maKH = "KH";
	string tenKH, gioitinh, ngaysinh, diachi;

public:
	friend istream & operator >> (istream & in, KhachHang & kh);
	friend ostream & operator << (ostream & out, const HoaDon & hd);
	friend class HoaDon;
};

istream & operator >> (istream & in, KhachHang & kh) {
	scanf("\n");
	++idKH;
	chuanhoa(kh.maKH, idKH);
	getline(in, kh.tenKH);
	in >> kh.gioitinh;

	in >> kh.ngaysinh;
	if (kh.ngaysinh[1]=='/') kh.ngaysinh.insert(0,"0");
	else if(kh.ngaysinh[4]=='/') kh.ngaysinh.insert(3,"0");

	scanf("\n");
	getline(in, kh.diachi);
	mpKH[kh.maKH] = kh;
	return in;
}

class MatHang {
private:
	string maMH, tenMH, donvi;
	int giamua, giaban;

public:
	friend istream & operator >> (istream & in, MatHang & mh);
	friend ostream & operator << (ostream & out, const HoaDon & hd);
	friend class HoaDon;
};

istream & operator >> (istream & in, MatHang & mh) {
	scanf("\n");
	++idMH;
	chuanhoa(mh.maMH, idMH);
	getline(in, mh.tenMH);
	getline(in, mh.donvi);
	in >> mh.giamua >> mh.giaban;
	mpMH[mh.maMH] = mh;
	return in;
}

class HoaDon {
private:
	string maMH="MH", maKH, maMD;
	int soluong;

public:
	friend istream & operator >> (istream & in, HoaDon & hd);
	friend ostream & operator << (ostream & out, const HoaDon & hd);
};

istream & operator >> (istream &in, HoaDon & hd) {
	scanf("\n");
	++idHD;
	chuanhoa(hd.maMH, idHD);
	in >> hd.maKH >> hd.maMH >> hd.soluong;
	return in;
}

ostream & operator << (ostream & out, const HoaDon & hd) {
	out << hd.maMD << " ";
	KhachHang kh = mpKH[hd.maKH];
	out << kh.tenKH << " " << kh.diachi <<" ";
	MatHang mh = mpMH[hd.maMH];
	out << mh.tenMH << " " << mh.donvi << " " << mh.giamua << " " << mh.giaban << " " << hd.soluong << " ";
}

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
