#include <iostream>
#include <fstream>
using namespace std;


void swap(int& a, int& b);
void bubbleSort(int* arr, int s);
void datainsert(int** arr, int r, int c);
void readdata(char file[], int** arr01, int r, int c);
int** createarr(int r, int c);
void matrixmultiplication(int** array1, int** array2, int r1, int c1, int c2, int** final);
void rowwisesort(int** arr, int r, int c);
void deleteArray2dA(int** arr, int r);
void getRowsColumns(int& r1, int& c1, int& r2, int& c2);
void findRowsColumn(char file[], int& r, int& c);
bool fileexists(char file[]);
float matrixsum(int** arr, int r, int c);
float matrixproduct(int** arr, int r, int c);
void rowwiseavg(int** arr, int r, int c);
void columnwiseavg(int** arr, int r, int c);
int** twomatrixaddition(int** array1, int** array2, int r, int c);
int** twomatrixsubstraction(int** array1, int** array2, int r, int c);
int** matrixtranspose(int** arr, int r, int c);
void displayMenu();
void displaymatrixentryways();
void displaymatrix(int** arr, int r, int c);

int main() {
	int row1, col1, row2, col2, operation, matrixentry;
	displayMenu();
	cin >> operation;
	if (operation == 1) {

	}
	if (operation == 6) {
		displaymatrixentryways();
		cin >> matrixentry;
		if (matrixentry == 1) {
			char filename[50];
			cout << "Enter the filename " << endl;
			cin.ignore();
			cin.getline(filename, 50);
			bool fileexistence = fileexists(filename);
			if (fileexistence) {
				findRowsColumn(filename, row1, col1);
				int** matrix = createarr(row1, col1);
				readdata(filename, matrix, row1, col1);
				rowwisesort(matrix, row1, col1);
				displaymatrix(matrix, row1, col1);

			}
		}
	}
			else if (operation == 10) {
				displaymatrixentryways();
				cin >> matrixentry;
				if (matrixentry == 1) {
					char filename[50];
					cout << "Enter the filename " << endl;
					cin.ignore();
					cin.getline(filename, 50);
					bool fileexistence = fileexists(filename);
					if (fileexistence) {
						findRowsColumn(filename, row1, col1);
						int** matrix = createarr(row1, col1);
						readdata(filename, matrix, row1, col1);
						int** aftermatrix = matrixtranspose(matrix, row1, col1);
						displaymatrix(aftermatrix, col1, row1);

					}
					else {
						cout << "File not found" << endl;
					}

				}
			}

		


	



	system("pause");
	return 0;
}
void displayMenu() {
	cout << " What do you want to do?" << endl;
	cout << "1: Sum of matrix(sum of all values)" << endl;
	cout << "2: Product of matrix(product of all values)" << endl;
	cout << "3: Row wise average" << endl;
	cout << "4: Column wise average" << endl;
	cout << "5: Average of whole matrix" << endl;
	cout << "6: Row wise Sorting of matrix" << endl;
	cout << "7: Column wise sorting of matrix" << endl;
	cout << "8: Addition of two matrices" << endl;
	cout << "9: Substration of two matrices" << endl;
	cout << "10: Transpose of a matrix" << endl;
}
void displaymatrixentryways() {
	cout << "How do you want to enter the matrix" << endl;
	cout << "1: Through File" << endl;
	cout << "2: THrough console" << endl;
}
void datainsert(int** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Enter the value for: " << i << "," << j << " coordinates" << endl;
			cin >> arr[i][j];
		}
	}
}
int** createarr(int r, int c) {
	int** temp = new int* [r];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[c];
	}
	return temp;
}
void matrixmultiplication(int** array1, int** array2, int r1, int c1, int c2, int** final) {
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			final[i][j] = 0;
			for (int x = 0; x < c1; x++) {
				final[i][j] += array1[i][x] * array2[x][j];
			}
		}
	}
}
void deleteArray2dA(int** arr, int r) {
	for (int i = 0; i < r; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
void getRowsColumns(int& r1, int& c1, int& r2, int& c2) {
	cout << "Enter the rows of array1" << endl;
	cin >> r1;
	cout << "Enter the columns of array1" << endl;
	cin >> c1;
	cout << "Enter the rows of array2" << endl;
	cin >> r2;
	cout << "Enter the columns of array2" << endl;
	cin >> c2;
}
void readdata(char file[], int** arr01, int r, int c) {
	ifstream infile(file);
	if (infile.is_open()) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				infile >> arr01[i][j];
			}
		}
	}
}
void findRowsColumn(char file[], int& r, int& c) {
	int maincolumnLength = 0;
	ifstream infile(file);
	char line[1000];
	r = 0; c = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			c = 0;
			infile.getline(line, 500);
			r++;
			for (int i = 0; i < 500; i++) {
				if (line[i] == '\0') {
					break;
				}
				else {
					maincolumnLength++;
				}
			}
			for (int i = 0; i < maincolumnLength; i++) {
				if (line[i] == ' ' && line[i - 1] != ' ') {
					c++;
				}
			}
		}
	}
	else {
		cout << "File not found" << endl;
	}
	c++;
	infile.close();
}
bool fileexists(char file[]) {
	ifstream infile(file);
	bool exist = false;
	if (infile.is_open()) {
		exist = true;
	}
	infile.close();
	return exist;
}
float matrixsum(int** arr, int r, int c) {
	float sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
float matrixproduct(int** arr, int r, int c) {
	float product = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			product *= arr[i][j];
		}
	}
	return product;
}
void rowwiseavg(int **arr, int r, int c) {
	float sum, avg;
	
	for (int i = 0; i < r; i++) {
		sum = 0;
		avg = 0;
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
		avg = sum / c;
		cout << "The averge of row " << i + 1 << " is: " << avg << endl;

	}
}

void columnwiseavg(int** arr, int r, int c) {
	float sum, avg;
	int index = 0;
	for (int i = 0; i < c; i++) {
		sum = 0;
		avg = 0;
		for (int j = 0; j < r; j++) {
			sum += arr[j][i];
		}
		avg = sum / r;
		cout << "The averge of row " << i + 1 << " is: " << avg << endl;
		index++;
	}
}
float matrixAverage(int** arr, int r, int c) {
	float sum = 0, avg = 0;

	for (int i = 0; i < r; i++) {
		
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
		
	}
	avg = sum / (c*r);
	cout << "The averge of whole matrix is: " << avg << endl;
	return avg;
}
void rowwisesort(int** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		bubbleSort(arr[i], c);
		/*
		for (int j = 0; j < c; j++) {
			for (int x = j; x < c-j-1; x++) {
				if (arr[i][x + 1] < arr[i][x]) {
					swap(arr[i][x + 1], arr[i][x]);
				}
			}
		}
		*/

	}
}
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void columnwisesort(int** arr, int r, int c) {
	for (int i = 0; i < c; i++) {

		for (int j = 0; j < r; j++) {
			for (int x = j; x < r-j; x++) {
				if (arr[x+1][i] < arr[x][i]) {
					swap(arr[x+1][i], arr[x][i]);
				}
			}
		}

	}
}
int**  twomatrixaddition(int** array1, int** array2, int r, int c) {
	int** temp = createarr(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
				temp[i][j] = array1[i][j] + array2[i][j];
		}
	}
	return temp;
}
int** twomatrixsubstraction(int** array1, int** array2, int r, int c) {
	int** temp = createarr(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
				temp[i][j] = array1[i][j] - array2[i][j];
		}
	}
	return temp;
}
int** matrixtranspose(int **arr, int r, int c) {
	int** temp = createarr(c, r);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			temp[i][j] = arr[j][i];
		}
	}
	return temp;
}
void displaymatrix(int **arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void bubbleSort(int *arr, int s){
	
	for (int y = 0; y < s - 1; y++)

		
		for (int z = 0; z < s - y - 1; z++)
			if (arr[z] > arr[z + 1]) {
				swap(arr[z], arr[z + 1]);
			}
				
}