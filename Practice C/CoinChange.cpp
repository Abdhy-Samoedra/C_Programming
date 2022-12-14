#include<stdio.h>

//mungkin atau tidak??
int cc1(int nominal){
	if(nominal<0) return 0; //ga sukses
	if(nominal==0) return 1; //sukses
	return cc1(nominal-1) || cc1(nominal-5) || cc1(nominal-3);
}

int min(int a, int b){
	return a<b?a:b; //apakah a lebih kecil? kalau iya balikin a kalau engga balikin b
}
//cari jumlah minimum untuk membuat n itu (biasanya berbentuk kombinasi)
int cc2(int nominal){
	if(nominal<0){
		return 100000; //didefine sebagai angka terbesar
	}
	if(nominal==0){
		return 0;
	}
	return min(cc2(nominal-7), min (cc2(nominal-5), cc2(nominal-3)))+1;
}

//biasanya n!
int cc3(int nominal){
	//sukses kalau berhasil mengembalikan 0
	if(nominal==0){
		return 1;
	}
	if(nominal<0){
		return 0;
	}
//	kalau banyak
//	int count=0;
//	for(){
//		count+=cc3();
//	}
//	return count;
	return cc3(nominal-7)+cc3(nominal-5)+cc3(nominal-3);
}
int main(){
	//misal : 3, 5, 7
	printf("%d\n", cc1(4));
	printf("%d\n", cc2(4));
	printf("%d\n", cc3(4));
	printf("%d\n", cc1(100));
	printf("%d\n", cc2(50));
	printf("%d\n", cc3(50));
	return 0;
}
