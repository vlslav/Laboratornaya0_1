#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>
struct complex{
	float re;
	float im;
};
void matritsaint(){
	int i, j, k, q, n,m,e;
	printf("Vvedite 1 dlya slozheniya, 2 dlya umnozheniya \n");
	scanf("%d", &q);
	if (q == 1){
		printf("Vvedite kol-vo strok matric:\n");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matric:\n ");
		scanf("%d", &m);
		int *a = (int *)malloc(n*m*sizeof(int));
		int *b = (int *)malloc(n*m*sizeof(int));
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				printf("a[%d][%d] = ", i, j);
				scanf("%d", (a + i*m + j)); //zapolnenie matric odinakovogo razmera v sluchae summy
				printf("b[%d][%d] = ", i, j);
				scanf("%d", (b + i*m + j));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++)
				printf("%d ", *(a + i*m + j) + *(b + i*m + j));
			    printf("\n");//vyvod znachenij matricy, poluchennoj posle slozheniya
		}
	}
	else if (q == 2){
		printf("Vvedite kol-vo strok matricy 1:\n ");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matricy 1 i kol-vo strok matricy 2: \n");
		scanf("%d", &m);
		printf("Vvedite kol-vo stolbcov matricy 2: \n");
		scanf("%d", &e);
		int *a = (int *)malloc(n*m*sizeof(int));
		int *b = (int *)malloc(m*e*sizeof(int));
		int *c = (int *)calloc(n*e, sizeof(int));
		for (i = 0; i < n; i++){
			for (k = 0; k < m; k++){
				printf("a[%d][%d] = ", i, k);//zapolnenie matricy A, razmerom n(strok) na m(stolbcov)
				scanf("%d", (a + i*m + k));
			}
		}
		for (k = 0; k < m; k++){
			for (j = 0; j < e; j++){
				printf("b[%d][%d] = ", k, j);//zapolnenie matricy V, razmerom m(strok) na e(stolbcov)
				scanf("%d", (b + k*e + j));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < e; j++){
				for (k = 0; k < m; k++){
					*(c + i*e + j) += *(a + i*m + k) * *(b + k*e + j);
				}
				printf("%d ", *(c + i*e + j));
			}
			printf("\n");
		}
   }
}
void matritsafloat(){
	int i, j, k, q, n, m, e;
	printf("Vvedite 1 dlya slozheniya, 2 dlya umnozheniya \n");
	scanf("%d", &q);
	if (q == 1){
		printf("Vvedite kol-vo strok matric:\n ");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matric:\n ");
		scanf("%d", &m);
		float *a = (float *)malloc(n*m*sizeof(float));
		float *b = (float *)malloc(n*m*sizeof(float));
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				printf("a[%d][%d] = ", i, j);
				scanf("%f", (a + i*m + j)); //zapolnenie matric odinakovogo razmera v sluchae summy
				printf("b[%d][%d] = ", i, j);
				scanf("%f", (b + i*m + j));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++)
				printf("%f ", *(a + i*m + j) + *(b + i*m + j));
			    printf("\n");//vyvod znachenij matricy, poluchennoj posle slozheniya
		}
	}
	else if (q == 2){
		printf("Vvedite kol-vo strok matricy 1:\n ");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matricy 1 i kol-vo strok matricy 2: \n");
		scanf("%d", &m);
		printf("Vvedite kol-vo stolbcov matricy 2: \n ");
		scanf("%d", &e);
		float *a = (float *)malloc(n*m*sizeof(float));
		float *b = (float *)malloc(e*m*sizeof(float));
		float *c = (float *)calloc(n*e, sizeof(float));
		for (i = 0; i < n; i++){
			for (k = 0; k < m; k++){
				printf("a[%d][%d] = ", i, k);//zapolnenie matricy A, razmerom n(strok) na m(stolbcov)
				scanf("%f", (a + i*m + k));
			}
		}
		for (k = 0; k < m; k++){
			for (j = 0; j < e; j++){
				printf("b[%d][%d] = ", k, j);//zapolnenie matricy V, razmerom m(strok) na e(stolbcov)
				scanf("%f", (b + k*e + j));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < e; j++){
				for (k = 0; k < m; k++){
					*(c + i*e + j) += *((a + i*m + k)) * (*(b + k*e + j));
				}
				printf("%f ", *(c + i*e + j));	
			}
			printf("\n");
		}
	}
}
void matritsacomplex(){
	int i, j, k, q, n, m, e;
	printf("Vvedite 1 dlya slozheniya, 2 dlya umnozheniya: \n");
	scanf("%d", &q);
	if (q == 1){
		printf("Vvedite kol-vo strok matric: \n");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matric: \n");
		scanf("%d", &m);
		struct complex *a = (struct complex *)calloc(n*m, sizeof(struct complex));
		struct complex *b = (struct complex *)calloc(n*m, sizeof(struct complex));
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				printf("a[%d][%d].re = ", i, j);
				scanf("%f", &((a + i*m + j)->re)); 
				printf("a[%d][%d].im = ", i, j);
				scanf("%f", &((a + i*m + j)->im));
				printf("b[%d][%d].re = ", i, j);
				scanf("%f", &((b + i*m + j)->re)); //zapolnenie matric odinakovogo razmera v sluchae summy
				printf("b[%d][%d].im = ", i, j);
				scanf("%f", &((b + i*m + j)->im));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++)
				printf(" (%f + i*%f ) ", ((a + i*m + j)->re + (b + i*m + j)->re), ((a + i*m + j)->im + (b + i*m + j)->im));
			    printf("\n");//vyvod znachenij matricy, poluchennoj posle slozheniya
		}
	}
	else if (q==2){
		printf("Vvedite kol-vo strok matricy 1:\n ");
		scanf("%d", &n);
		printf("Vvedite kol-vo stolbcov matricy 1 i kol-vo strok matricy 2: \n");
		scanf("%d", &m);
		printf("Vvedite kol-vo stolbcov matricy 2: \n ");
		scanf("%d", &e);
		struct complex *a = (struct complex *)calloc(n*m, sizeof(struct complex));
		struct complex *b = (struct complex *)calloc(m*e, sizeof(struct complex));
		struct complex *c = (struct complex *)calloc(n*e, sizeof(struct complex));
		for (i = 0; i < n; i++){
			for (k = 0; k < m; k++){
				printf("a[%d][%d].re = ", i, k);//zapolnenie matricy A, razmerom n(strok) na m(stolbcov)
				scanf("%f", &((a + i*m + k)->re));
				printf("a[%d][%d].im = ", i, k);
				scanf("%f", &((a + i*m + k)->im));
			}
		}
		for (k = 0; k < m; k++){
			for (j = 0; j < e; j++){
				printf("b[%d][%d].re = ", k, j);//zapolnenie matricy A, razmerom m(strok) na e(stolbcov)
				scanf("%f", &((b + k*e + j)->re));
				printf("b[%d][%d].im = ", k, j);
				scanf("%f", &((b + k*e + j)->im));
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < e; j++){
				for (k = 0; k < m; k++){
					(c + i*e + j)->re += ((a + i*m + k)->re)*((b + k*e + j)->re) - ((a + i*m + k)->im)*((b + k*e + j)->im);
					(c + i*e + j)->im += ((a + i*m + k)->re)*((b + k*e + j)->im) + ((a + i*m + k)->im)*((b + k*e + j)->re);
				}
				printf("(%f + i*%f) ", ((c + i*e + j)->re), ((c + i*e + j)->im));
			}
			printf("\n");
		}
	}
	}

int main(){
	int k;
	printf("Vvedite 1 dlya celyx, 2 dlya veshhestvennyx, 3 dlya kompleksnyx chisel: \n" );
	scanf("%d", &k);
	if (k == 1){
		matritsaint();
	}
	else if (k == 2){
		matritsafloat();
	}
	else if (k == 3){
		matritsacomplex();
	}
	system("PAUSE");
	}
