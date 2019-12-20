#include <bits/stdc++.h>
using namespace std;

//to save the list of all possible solutions
vector<vector<int>> res;

//method to check if given position will be attacked by queen or not
bool isSafe(pair<int,int> temp, vector<pair<int,int>> p){
    for(auto a:p){
        //sum and difference of indices of diagonals is same (for checking diagonal attack)
        //if row is same (to check horizontal attack)
        if((a.first == temp.first || (a.first+a.second) == (temp.first+temp.second)) ||(( a.first - a.second) == (temp.first - temp.second)))
            return false;
    }
    return true;
}

void nqueens(vector<pair<int,int>> &queens, vector<int> &pos, int n, int col){
    for(int i=0;i<n;i++){
        pair<int,int> tmp;
        tmp.first = i;
        tmp.second = col;
        if(isSafe(tmp,queens)){
            //adding the safe position to the vector
            queens.push_back(make_pair(i,col));
            
            //keeping track of position by row number(starting from 1 in each column)
            pos.push_back(i+1);
            //base condition for recursive step
            if(col == n-1){
                //adding a sequence of positions to the result vector
                res.push_back(pos);
            }
            else{
                //recursive step
                nqueens(queens,pos,n,col+1);
            }
            
            //backtracking
            queens.pop_back();
            pos.pop_back();
        }
    }
}

int main() {
	int t,n,col;
	cin>>t;
	while(t--){
	    cin>>n;
	    res.clear();
	    col = 0;
      //if n = 1 (corner case)
	    if(n == 1){
	        cout<<"[1 ]"<<endl;
	    }
	    else{
      //iterating for all possible sequence
	    for(int i=0;i<n;i++){
	        vector<pair<int,int>> queens;
	        vector<int> pos;
	        pos.push_back(i+1);
	        queens.push_back(make_pair(i,col));
	        nqueens(queens,pos,n,col+1);
	        pos.pop_back();
	        queens.pop_back();
	    }
	    //if no solution found the printing -1
	    if(res.size() == 0) cout<<-1<<endl;
	    else{
      //output
	    for(auto a: res){
	        cout<<"[";
	        for(auto e: a){
	            cout<<e<<" ";
	        }
	        cout<<"] ";
	    }
	    cout<<endl;
	    }
	    }
	}
	return 0;
}
