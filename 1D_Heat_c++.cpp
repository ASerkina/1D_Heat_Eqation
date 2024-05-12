#include <iostream>
#include <fstream>
#include  <ctime>
using namespace std;

int main() {

	double h = 0.05;
	double t = 0.05*h*h;
	int l = 1;
	int n = l / h;
	int N = 1 / t;
	ofstream temp("tep1.txt");
	double* T1 = new double[n];
	double* T2 = new double[n];

	T1[n] = 1;
	T2[n] = 1;
	T2[0] = 0;
	int c = -1;

	for (int i = 0; i < n; i++)
		T1[i] = 0;


	for (int j = 0; j < N; j++) {
		for (int i = 1; i < n; i++) {
			T2[i] = (1 - 2 * t / h / h) * T1[i] + t / h / h * (T1[i - 1] + T1[i + 1]);

			/*(T1[i - 1] - 2 * T1[i] + T1[i + 1]) * t + T1[i];*/
		}
			
		for (int i = 0; i < n + 1; i++) {
			int k = i;
			temp << T2[i] << endl;
			
			/*if (k % 21 == 0)
				c += 1;
			temp << t * c << "  " << T2[i] << endl;
		}*/
		}
		double* T3;
		T3 = T1;
		T1 = T2;
		T2 = T3;
	}

	
	temp.close();
	/*for (int i = 0; i < n; i++)
		cout<< T2[i] << "\n";*/

}
