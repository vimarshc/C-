
#include<iostream>
#include<vector>
using namespace std;


string lleft = "left";
string rright =  "right";
string uup =  "up";
string ddown =  "down";
int* rotate(int* arr, int dim){

	int* ar;
	ar = (int*)malloc(dim*dim*sizeof(int));
	for(int i = 0; i < dim; i++)
		for(int j = 0; j<dim; j++){

			*((ar+dim*j)+(dim-i-1)) = *((arr+i*dim) + j);
		}

	return ar;	
}

int* clash(int* arr, int dim){

	vector<int> exist;
	for(int i = 0; i < dim; i++){
		if(arr[i] > 0) exist.push_back(i);
	}

	int* row = (int*)malloc(dim*sizeof(int));
	for(int i = 0; i < dim; i++)
		row[i] = 0;
	int i = 0;
	for(vector<int>::iterator it = exist.begin(); it != exist.end(); ++it, i++)
		row[i] = arr[*it];

	return row;
}

int* add(int* arr, int dim){
    
    int* row = (int*)malloc(dim*sizeof(int));
    for(int i = 0; i < dim; i++)
        row[i] = 0;
    int i = 0;
    while(i < dim){
        
        if(arr[i] == arr[i+1]){
            row[i] = arr[i] + arr[i+1];
            i++;
        }
        else{
            row[i] = arr[i];
        }
        i++;
    }
    row = clash(row, dim);
    
    return row;
}

int* boom(int* arr, int dim){

	for(int i = 0; i < dim; i++){
		int* row = (int*)malloc(dim*sizeof(int));
		for(int j = 0; j<dim;j++){
			row[j] = *((arr+i*dim) + j);
		}
		row = clash(row, dim);
		row = add(row, dim);

		for(int j = 0; j < dim; j++){
			*((arr+dim*i) + j) = row[j];
		}
	}

	return arr;
}

int* up(int* arr, int dim){

	int* rot = rotate(arr, dim);
	rot = rotate(rot, dim);
	rot = rotate(rot, dim);
	rot = boom(rot, dim);
	rot = rotate(rot, dim);
	return rot;
}




int* right(int* arr, int dim){

	int* rot = rotate(arr, dim);
	rot = rotate(rot, dim);

	rot = boom(rot, dim);

	rot = rotate(rot, dim);
	rot = rotate(rot, dim);
	return rot;
}


int* down(int* arr, int dim){

	int* rot = rotate(arr, dim);
	rot = boom(rot, dim);

	rot = rotate(rot, dim);
	rot = rotate(rot, dim);
	rot = rotate(rot, dim);
return rot;
}

int main(){


	int test;
	cin >> test;
	for(int var = 0; var < test; var++){

		int dim;
		string dir;
		cin >> dim >> dir;

		int* arr;
		arr = (int*)malloc(dim*dim*sizeof(int));
		for(int i = 0; i < dim; i++)
			for(int j =0; j < dim; j++)
				cin >> *((arr+i*dim) + j);


		int* result;
		if(dir == rright)
			result = right(arr, dim);	
		else if(dir == uup)
			result = up(arr, dim);
		else if(dir == ddown)
			result = down(arr, dim);
		else if(dir == lleft)
			result = boom(arr, dim);
		cout << "Case #" << var + 1 << ":";
		for(int i = 0; i < dim; i++){
			cout << "\n";
			for(int j =0; j < dim; j++){
				if(j == dim - 1)
					cout << *((result+i*dim) + j);
				else 

				cout << *((result+i*dim) + j) << " ";
			}
		}
		cout << "\n";

	}
	return 0;
}
