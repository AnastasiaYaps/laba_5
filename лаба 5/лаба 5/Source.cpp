#include <iostream>
using namespace std;
class cfigure {
protected:
	int angle1;
	int angle2;
	int angle3;
	int angle4;
	int square1;
public:
	cfigure() : angle1(0), angle2(0), angle3(0), angle4(0) {}
	cfigure(int angle11, int angle22, int angle33, int angle44) :
		angle1(angle11),
		angle2(angle22),
		angle3(angle33),
		angle4(angle44) {}
	virtual ~cfigure() {}
	virtual void output() = 0;
	virtual int square() = 0;
};
class cparalellogram : public cfigure {
protected:
	int size;
	int height;
public:
	cparalellogram(int angle11, int angle22, int angle33, int angle44,int size,int height) :
		cfigure(angle11, angle22, angle33, angle44),size(size),height(height){}
	~cparalellogram() {}
	int square() override{
		square1 = size * height;
		return square1;

	}
	void output() override{
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "size: " << size << endl << "height" << height << endl;
		
	}
}; class crectangle : public cparalellogram {
protected:
	int size1;
	int size2;
public:
	crectangle(int angle11, int angle22, int angle33, int angle44, int size,int height,int size1,int size2) :
		cparalellogram(angle11, angle22, angle33, angle44, size,height),
		size1(size1),size2(size2){}
	int square() override{
		square1 = size1 * size2;
		return square1;

	}
	void output() override {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "size1: " << size1 << endl << "size2: " << size2 << endl;
	
	}
	~crectangle() {}
};
class cquadrangle : public cfigure {
protected:
	int perimeter;
	int square1;
public:

	cquadrangle(int angle11, int angle22, int angle33, int angle44, int perimeter1,int square1) :cfigure(angle11, angle22, angle33, angle44), perimeter(perimeter1),
	square1(square1){}
	int square() override {
		return square1;
	}
	void output() override {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "perimeter:  " << perimeter << endl;
		
	}
	~cquadrangle() {}

};
int main()
{
	int size, height,size1,size2,perimeter,square1;
	cfigure* figure[3];
	int angle11,angle22, angle33,angle44;
	int a = 360;
	bool fail = true;
	do {
		cout << "input angles: "<<endl;
		cin >> angle11 >> angle22 >> angle33 >> angle44;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (angle11 != 90 || angle22 != 90 || angle33 != 90 || angle44 != 90 || fail);
	fail = true;
	do {
		cout << "input size and  height for parallelogram: "<<endl;
		cin >> size;
		cin >> height;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (size<=0|| height<=0|| fail);
	fail = true;
	do {
		cout << "input size1 and  size2 for rectangle: " << endl;
		cin >> size1 >> size2;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (size1 <= 0 || size2 <= 0 || fail);
	fail = true;
	do {
		cout << "input perimeter and square  for quadrangle: " << endl;
		cin >> perimeter>>square1;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (perimeter<=0|| square1<=0|| fail);
	

	figure[0] = new cparalellogram(angle11, angle22, angle33, angle44, size,height);
	figure[1] = new crectangle(angle11,angle22,angle33,angle44,size,height,size1,size2);
	figure[2] = new cquadrangle(angle11, angle22, angle33, angle44,perimeter,square1);
	for (int i = 0; i < 3; i++) {
		int a;
		a = figure[i]->square();
		cout << i << endl << "square: " << a << endl;
		figure[i]->output();
	}
	for (int i = 0; i < 3; i++) {
		delete figure[i];
	}


	return 0;
}
//1+ 2 a+ b+ c+ d+ 3+ 4+ 5+ 6+ 7�����
