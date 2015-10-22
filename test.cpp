#include<iostream>
#include<map>
#include<vector>
using namespace std;
//Hello

struct data{
    int number;
};

bool compareByLength(const data &a, const data &b)
{
    return a.number > b.number;
}

int main(){
	

	struct data q;
	struct data w;
	q.number = 9;
	w.number = 90;

	vector<data> e;
	e.push_back(q);
	e.push_back(w);

	sort(e.begin(), e.end(), compareByLength);

	for(vector<data>::iterator it = e.begin(); it != e.end(); ++it)
		cout << it->number << endl;

}
