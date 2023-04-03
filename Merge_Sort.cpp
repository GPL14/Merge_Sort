#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include<sstream>
using namespace std;
class Node{
	public:
	    string invN, stcode, desT, quanT, invD,unitP, cusId, cntry;
};
//split function to split the date
int comp = 0;
int swaps = 0;
vector<int> split(string str)
{
    string temp;

    string s[3];
    int j;
    for(int i=0;i<str.length();i++){
        if(str[i] != '-' && str[i] != ' '){
            temp += str[i];
        }
        else if(str[i] != ' '){
          s[j] = temp;

          j++;
          temp = "";
        }
    }
    s[j] = temp;
    static vector<int> a(3);
    for(int i=0;i<3;i++){
//    	cout << s[i];
    	stringstream strm(s[i]);
		int num;
		strm >> num;
		a[i] = num;
	}
    return a;
}

// for compare the date
bool isSmaller(string d1, string d2){
	vector<int> s = split(d1);
	cout << '\n';
    int dd1 = s[0];
    int mm1 = s[1];
    int yy1 = s[2];

    vector<int> s2 = split(d2);

    int dd2 = s2[0];
    int mm2 = s2[1];
    int yy2 = s2[2];

    cout << '\n';
    if(yy1 < yy2){
		    return true;
	    }
    else if(yy1 == yy2){
		if(mm1 < mm2){
			return true;
		}
		else if(mm1 == mm2){
			if(dd1 <= dd2){
				return true;
			}
		}
	}
	return false;
}

// mergeSort for Date
//merge function for array
void mergeDates(vector<Node> &A, int left, int right, int mid){
	int l = mid - left + 1;
	int r = right - mid;

	Node a[l], b[r];

	//copy in both array
	for(int i=0;i<l;i++){
		a[i] = A[left+i];
	}
	for(int j=0;j<r;j++){
		b[j] = A[mid + 1 + j];
	}

	int i,j, k;
	i=0;
	j=0;
	k=left;


	while(i < l && j < r){
		comp++;
		if(isSmaller(a[i].invD, b[j].invD)){
			A[k] = a[i];
			i++;
			swaps++;
		}
		else{
			A[k] = b[j];
			j++;
			swaps++;
		}
		k++;
	}

	while(i < l){
		A[k] = a[i];
		i++;
		k++;
	}

	while(j < r){
		A[k] = b[j];
		j++;
		k++;
	}
}


void mergeSortD(vector<Node> &A,int left,int right){
	if(left < right){
		int mid = left + (right - left) / 2;
		//for left side
		mergeSortD(A, left, mid);

		//for right side
		mergeSortD(A, mid+1, right);

		// merge left and right
		mergeDates(A, left, right, mid);
	}
}


//merge function for array
void merge(vector<Node> &A, int left, int right, int mid, int x){
	int l = mid - left + 1;
	int r = right - mid;

	Node a[l], b[r];

	//copy in both array
	for(int i=0;i<l;i++){
		a[i] = A[left+i];
	}
	for(int j=0;j<r;j++){
		b[j] = A[mid + 1 + j];
	}

	int i,j, k;
	i=0;
	j=0;
	k=left;
	if(x == 1){
		while(i < l && j < r){
			comp++;
			if(a[i].invN <= b[j].invN){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
	}
	else if(x == 2){
		while(i < l && j < r){
			comp++;
			if(a[i].desT <= b[j].desT){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
	}
    else if(x == 3){
    	while(i < l && j < r){
    		comp++;
			if(a[i].quanT <= b[j].quanT){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
	}
	else if(x == 4){
		while(i < l && j < r){
			stringstream strm(a[i].unitP);
			float num1;
		    strm >> num1;

		    stringstream st(b[j].unitP);
			float num2;
		    st >> num2;
		    comp++;
			if(num1 <= num2){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
   }
   else if(x == 5){
   	  while(i < l && j < r){
   	  	    comp++;
			if(a[i].cusId <= b[j].cusId){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
   }
   else if(x == 6){
   	while(i < l && j < r){
   		    comp++;
			if(a[i].cntry <= b[j].cntry){
				A[k] = a[i];
				i++;
				swaps++;
			}
			else{
				A[k] = b[j];
				j++;
				swaps++;
			}
			k++;
		}

		while(i < l){
			A[k] = a[i];
			i++;
			k++;
		}

		while(j < r){
			A[k] = b[j];
			j++;
			k++;
		}
   }
}


void mergeSort(vector<Node> &A,int left,int right,int x){
	if(left < right){
		int mid = left + (right - left) / 2;
		//for left side
		mergeSort(A, left, mid, x);

		//for right side
		mergeSort(A, mid+1, right, x);

		// merge left and right
		merge(A, left, right, mid, x);
	}
}

int main() {
	//create a file to store the data
	fstream fout;

	//reading a file
	ifstream csv_file("A2.1_ecommerce - A2.1_ecommerce.csv");

	fout.open("A2.commerce.a.csv.", ios::out);

	fout << "Invoice Id " << ", " << "Stock Code " << ", " << "Description " << ", " << "Quantity " << ", " << "Invoice Date " << ", " << "Unit Price " << ", " << "Customer ID" << ", " << "Country " <<'\n';

	if (!csv_file) {
		cout << "File not created!";
	}
	else {
		vector<Node> data(151);

        string row_data, word;
        int col = 0,l = 0;
        int firstLine = 0;

        while(getline(csv_file, row_data))
        {
        if(firstLine != 0){
            stringstream s(row_data);
            int col = 0;
		    while(getline(s, word, ',')){
		    	if(col == 0){
		    		data[l].invN = word;
				}
				else if(col == 3){
					data[l].quanT = word;
				}
				else if(col == 1){
					data[l].stcode = word;
				}
				else if(col == 2){
					data[l].desT = word;
				}
				else if(col == 4){
					data[l].invD = word;
				}
				else if(col == 7){
					data[l].cntry = word;
				}
				else if(col == 5){
					data[l].unitP = word;
				}
				else if(col == 6){
					data[l].cusId = word;
				}
				col++;
			}
			l++;
        }
        firstLine++;
    }

         cout << "Choose an option..." << endl;
    	 cout << '\n';
    	 cout << " 1 : Sort By Invoice" << endl;
    	 cout << '\n';
	     cout << " 2 : Sort By Description" << endl;
	     cout << '\n';
	     cout << " 3 : Sort By Quantity" << endl;
	     cout << '\n';
	     cout << " 4 : Sort By UnitPrice" << endl;
	     cout << '\n';
	     cout << " 5 : Sort By CustomerID" << endl;
	     cout << '\n';
	     cout << " 6 : Sort By Country" << endl;
	     cout << '\n';
	     cout << " 7 : Sort By InvoiceDate" << endl;
	     cout << '\n';
	     cout << " 0 : exit" << endl;
	     cout << '\n';
        int x;
        cin >> x;
        if(x == 7){
			mergeSortD(data, 0, 150);
		}
		else{
			mergeSort(data, 0, 150, x);
		}
	    for (int i = 1; i < 151; i++){
	        fout << data[i].invN << ", " << data[i].stcode << ", " << data[i].desT << ", " << data[i].quanT << ", " << data[i].invD << ", " << data[i].unitP << ", " << data[i].cusId << ", " << data[i].cntry <<'\n';
        }
        cout << "Number of Comparisions : " << comp << '\n';

        cout << "Number of Swaps : " << swaps << '\n';

		cout << "File created successfully!";

		csv_file.close();

		return 0;
	}
}

