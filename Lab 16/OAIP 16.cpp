#include<iostream> 
#include <math.h> 
#include <fstream>
#include <conio.h> 
#include <cstdlib> 
#include <stdlib.h> 
using namespace std;

int countEdges(int** mat, int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (mat[i][j] == 0)
				count++;
	return count;
}

int* edgeMat(int** mat, int nodes, int edges) {
	int count = 0;
	int* value = new int[edges];
	for(int i=0;i<nodes;i++)
		for (int j=0;j<nodes;j++)
			if (mat[i][j] != 0) {
				value[count] = mat[i][j];
				count++;
			}
	return value;
}

void incMatrix(int** mat, int size) {
	int e = countEdges(mat, size);
	int* value = edgeMat(mat, size, e);
	int** incMat = new int* [size];
	for (int i = 0; i < size; i++)
		incMat[i] = new int[e];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < e; j++)
			incMat[i][j] = 0;
	for (int i=0;i<size;i++)
		for (int j = 0; j < size; j++)
		{
			if (mat[i][j] != 0) {
				for(int k=0;k<e;k++)
					if (value[k] == mat[i][j]) {
						incMat[i][k] = mat[i][j];
						incMat[j][k] = mat[i][j];
					}
			}
		}
	cout << "The incidency matrix: \n" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < e; j++)
			cout << incMat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < size; i++)
		delete[] incMat[i];
	delete[] incMat;

}

int main() {
	int s1,s,e,node,value;
	int n = NULL;
	ifstream reading("Graph.txt");
	cout << "Choose a way to input the matrix: " << endl;
	cout << "\t 1. From keyboard; \n";
	cout << "\t 2. From file;\n";
	cin >> s1;
	switch (s1) {
	case 1:
		cout << "Input the number of nodes: ";
		cin >> n;
		break;
	case 2:
		if (reading) {
			reading >> n;
			if (n == NULL) {
				cout << "Error! The file is empty." << endl;
				reading.close();
				exit(1);
			}
		}
		else {
			cout << "Error! The file couldn't be accessed correctly." << endl;
			reading.close();
			exit(1);
		}
		break;
	}
	int** adjMat = new int* [n];
	for (int i = 0; i < n; i++)
		adjMat[i] = new int[n];
	ofstream record("Graph.txt", ios::trunc);
	switch (s1) {
	case 1:	
		cout << "Input the adjacency matrix: " << endl;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					cin >> adjMat[i][j];
			break;
	case 2:
		if (reading) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					reading >> adjMat[i][j];
		}
		else {
			cout << "Error! The file couldn't be accessed correctly." << endl;
			reading.close();
			record.close();
			for (int i = 0; i < n; i++)
				delete[] adjMat[i];
			delete[] adjMat;
			exit(1);
		}
		break;
	}
	reading.close();
	for (;;) {
		cout << "Choose an action: " << endl;
		cout << "\t1. Print adjacency matrix;\n";
		cout << "\t2. Print incidence matrix;\n";
		cout << "\t3. Print all the nodes connected to the chosen node;\n";
		cout << "\t0. Exit.\n";
		cin >> s;
		switch (s) {
		case 1:
			cout << "The adjency matrix: \n" << endl;
			for(int i=0;i<n;i++){
				for (int j = 0; j < n; j++)
					cout << adjMat[i][j] << " ";
				cout << "\n";
			}
			cout << endl;
			cout << "Do you wish to record the matrix?" << endl;
			cout << "\t1. Yes;\n";
			cout << "\t2. No.\n";
			cin >> s1;
			switch (s1) {
			case 1: 
				if (record) {
					record << n<<endl;
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							record << adjMat[i][j] << endl;
				}
				else {
					cout << "Error! The file couldn't be accessed correctly." << endl;
					record.close();
					for (int i = 0; i < n; i++)
						delete[] adjMat[i];
					delete[] adjMat;
					exit(1);
				}
				break;
			case 2:break;
			}
			system("pause");
			system("cls");
			break;
		case 2:
			incMatrix(adjMat, n);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Input the number of the node you want to see edges of: ";
			cin >> node;
			node--;
			cout << endl;
			for (int i = 0; i < n; i++)
				if (adjMat[node][i] != 0)
					cout << node + 1 << " --- " << adjMat[node][i] << " --- " << i + 1 << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			record.close();
			for (int i = 0; i < n; i++)
				delete[] adjMat[i];
			delete[] adjMat;
			exit(1);
		}
	}

}
