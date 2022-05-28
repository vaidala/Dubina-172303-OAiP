#include <iostream> 
#include <fstream> 
#include <iomanip>

using namespace std; 
struct Node {
	int data;
	Node* next;
};

Node** hashTable;
int SIZE;

int myhash(int data) {
	return (data % SIZE);
}
Node* insertNode(int data) {
	Node* p, * p0;
	int bucket;
	bucket = myhash(data);
	if ((p = new Node) == 0) {
		cout << "The memory couldn't be allocated.\n";
		exit(1);
	}
	p0 = hashTable[bucket]; 
	hashTable[bucket] = p;
	p->next = p0;
	p->data = data;

	return p;
}
void printTable(int size) {
	Node* p;
	for (int i = 0; i < size; i++){
		cout << i << ": ";
		p = hashTable[i];
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}
static void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void quickSort(int *a, int start, int finish) {
	int left, right;
	left = start;
	right = finish;
	int pivot = a[(start + finish) / 2];
	do {
		while (a[left] < pivot)
			left++;
		while (a[right] > pivot)
			right--;
		if (left <= right) {
			swap(&a[left], &a[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (start < right) quickSort(a, start, right);
	if (left < finish) quickSort(a, left, finish);
}
void sortTable(int size, int el) {
	int count = 0;
	int* tmp = new int[el];
	Node* p;
	for (int i = 0; i < size; i++){
		p = hashTable[i];
		for (int j = count; j < el; j++){
			if (p == NULL)
				break;
			tmp[j] = p->data;
			count++;
			p = p->next;
		}
	}
	quickSort(tmp, 0, el - 1);
	cout << "Sorted elements are: \n";
	for (int i = 0; i < el; i++)
		cout << tmp[i] << " ";
	cout << endl;
}
void deleteNode(int data) {
	Node* p0, * p;
	int bucket; p0 = 0;
	bucket = myhash(data); p = hashTable[bucket];
	while (p && p->data!= data) {
		p0 = p;
		p = p->next;
	}
	if (!p) return; if (p0)
		p0->next = p->next; else
		hashTable[bucket] = p->next; free(p);
}
int main() {
	int i, * a, maxnum,s;
	cout << "Enter number of elements: "; 
	cin >> maxnum;
	cout << "Enter HashTable Size : "; 
	cin >> SIZE;
	a = new int[maxnum];
	hashTable = new Node * [SIZE]; for (i = 0; i < SIZE; i++)
		hashTable[i] = NULL;
	for (i = 0; i < maxnum; i++) 
		a[i] = rand();
	for (i = 0; i < maxnum; i++)
		insertNode(a[i]);
	for (;;){
		cout << "Choose an action : " << endl;
		cout << "\t 1.Print table;\n";
		cout << "\t 2.Individual task;\n";
		cout << "\t 0.Exit\n";
		cin >> s;
		switch (s) {
		case 1: 
			printTable(SIZE);
			system("pause");
			system("cls");
			break;
		case 2: sortTable(SIZE,maxnum);
			system("pause");
			system("cls");
			break;
		case 0: exit(1);
		}
	}
	for (i = maxnum - 1; i >= 0; i--) {
		deleteNode(a[i]);
	}
	return 0;
}

