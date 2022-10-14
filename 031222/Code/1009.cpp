#include <iostream>
using namespace std;

/*
string factorial(int num) {

	int a[2010]= {},b[2010]= {};
	float *c = new float[4080];
	string ain,bin,res;
	res="";
	ain=last;
	bin=to_string(num);
	for (int i=0; i<ain.length(); i++) a[i]=ain[ain.length()-1-i]-'0';
	for (int i=0; i<bin.length(); i++) b[i]=bin[bin.length()-1-i]-'0';
	//取反
	int max_l=ain.length()+bin.length();
	for (int i=0; i<=ain.length(); i++) {
		for (int j=0; j<=bin.length(); j++) {
			c[i+j]+=a[i]*b[j];
		}
	}
	for (int i=0; i<=max_l; i++) {
		if (c[i]>9) {
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}


	bool flag=false;	//是否输出
	for (int i=max_l-1; i>=0; i--) {
		if (c[i]!=0) flag=true;
		if (i==0) flag=true;
		if (flag) res+=c[i];

	}
	last=res;

	return c;
}
*/
int main() {
	int a[100]= {},b[100]= {};
	//初始化
	int ask;
	cin>>ask;
	a[0]=1;
	int maxl=100;
    // a[0] a[1] a[2] a[3]
    //  21    0   3    4
    // 21 x 10^0 + 0 x 10^1 + 3 x 10^2 + 4 x 10^3 = 4321
	for (int m=1; m<=ask; m++) {
		for (int i=0; i<100; i++) {
			a[i]*=m;
		}
		for (int i=0; i<maxl; i++) {
			if (a[i]>9) {
				a[i+1]+=a[i]/10;
				a[i]%=10;
			}
				//bin=factorial(m);
				//for (int i=0; i<ain.length(); i++) a[i]=ain[ain.length()-1-i]-'0';
				//for (int i=0; i<bin.length(); i++) b[i]=bin[bin.length()-1-i]-'0';
				//取反

				/*
				for (int i=0;i<max_l;i++){
				if (c[i]>9){
					c[i+1]++;
					c[i]-=10;

				}*/

				/*
						if (c[max_l]!=0) max_l++;
						for (int i=max_l-1; i>=0; i--) {
							res+=c[i];
						}
						ans=res;*/
			
		}
		for (int k=0; k<maxl; k++) {
			b[k]+=a[k];
			if (b[k]>9) {
				b[k+1]+=b[k]/10;
				b[k]%=10;

			}
		}
	}
    bool flag = false;
	for (int i=99; i>=0; i--) {
        if (b[i]) flag = true;
        if (flag) cout<<b[i];
	}
	cout<<endl;
	return 0;
}