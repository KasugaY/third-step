#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 20 //クラスの人数
#define SUBJECT 2 //科目

enum subject{
	sci, //理科
	eng  //英語
};

//統計量(総和，二乗和，平均，平方和，分散，標準偏差)
struct Statistics{
	double sum, sumv, ave, squ, v, s;
};

// -- 比較用の関数 --
int cmp( const void *p, const void *q ) {
    if( *(double*)p < *(double*)q ) return 1;
    if( *(double*)p > *(double*)q ) return -1;
    return 0;
}

int main(){

	int i, j;
	struct Statistics sub[SUBJECT];
	double t; //偏差値
	//テストの点数
	double Score[SUBJECT][N] = 
	{
		{65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70},
		{44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84}
	};

	for(j = 0; j < SUBJECT; j++){
		
		//初期化
		sub[j].sum = 0.0;
		sub[j].sumv = 0.0;

		//総和と二乗和を計算
		for(i = 0; i < N; i++){
			sub[j].sum += Score[j][i];
			sub[j].sumv += Score[j][i] * Score[j][i];
		}
		
		sub[j].ave = sub[j].sum / N; //平均
		sub[j].squ = sub[j].sumv - (sub[j].sum * sub[j].sum / N); //平方和
		sub[j].v = sub[j].squ / (N - 1.0); //分散
		sub[j].s = sqrt(sub[j].v); //標準偏差

	}

	//統計量表示
	printf("	 |	 理科	　	英語\n");
	printf("----------------------------------------\n");
	printf("N	 |	   %d		 %d\n", N, N);
	printf("平均点　 |	 %.1f		%.1f\n", sub[sci].ave, sub[eng].ave);
	printf("標準偏差 |	 %.1f		%.1f\n", sub[sci].s, sub[eng].s);
	printf("合計点　 |	 %.1f		%.1f\n", sub[sci].sum, sub[eng].sum);

	//偏差値を計算・表示
	printf("----------------------------------------\n");
	printf("偏差値   |\n");
	for(j = 0; j < N; j++){
		printf("         |");
		for(i = 0; i < SUBJECT; i++){
			t = 10.0 * ( Score[i][j] - sub[i].ave ) / sub[i].s + 50; //偏差値の計算
			printf("	 %.1f	", t);
		}
		printf("\n");
	}

	//テストの点でソート(降順)
	for(i = 0; i < SUBJECT; i++){
		qsort( Score[i], N, sizeof(double), cmp );
	}

	//ソート後の並びを表示
	printf("----------------------------------------\n");
	printf("ソート　 |\n");
	for(j = 0; j < N; j++){
		printf("         |");
		for(i = 0; i < SUBJECT; i++){
			printf("	 %.1f	", Score[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}