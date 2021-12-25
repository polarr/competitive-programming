/**
 * Solution by 1egend
 * Date:
 * Contest: WOSS 
 * Problem:
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

int r, c;
vector<pair<pair<int, int>, pair<int, int>>> teleport;
int grid[200][200];
bool visited[200][200];

int N = 200;
bool areEqualArrays(int a[][N], int b[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] != b[i][j])
				return false;
		}
	}

	return true;
}

int minNeighborCostToGo(int C[][N], int r, int c, int &mr, int &mc)
{
	int minCost = C[r][c];

	if(r > 0)
	{
		if(C[r-1][c] < minCost)
		{
			mr = r-1;
			mc = c;
			minCost = C[r-1][c];	
		}
	}
	if(c > 0)
	{
		if(C[r][c-1] < minCost)
		{
			minCost = C[r][c-1];
			mr = r;
			mc = c-1;
		}
	}
	if(r < N-1)
	{
		if(C[r+1][c] < minCost)
		{
			minCost = C[r+1][c];
			mr = r+1;
			mc = c;
		}
	}
	if (c < N - 1)
	{
		if(C[r][c+1] < minCost)
		{
			minCost = C[r][c+1];
			mr = r;
			mc = c + 1 ;
		}
	}

	return minCost;
}

void dijkstra(int startc, int startr, int goalc, int goalr){
	int C[N][N];

	fill(&C[0][0], &C[N-1][N-1], 1);

	C[goalr][goalc] = 0;

	int obsr = 2;
	int obsc = 2;

	C[obsr][obsc] = 100;

	bool converged = false;

	int Ctemp[N][N];

	int mr, mc;

	while(!converged)
	{	

		// copy matrix from C to Ctemp
		copy(&C[0][0], &C[N-1][N-1]+1,&Ctemp[0][0]);

		// loop and update cost matrix
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(i == goalr && j == goalc)
				{				
					C[i][j] = 0;
				}
				if(i == obsr && j == obsc)
					C[i][j] = 10;
				else
					C[i][j] = 1 + minNeighborCostToGo(C, i, j, mr, mc);
			}
		}

		if(areEqualArrays(C,Ctemp))
			converged = true;

	}

	cout<<"Here is the cost matrix :"<<endl;
	printMatrix(C);

	int r = startr;
	int c = startc;

	while(!(r == goalr && c == goalc))
	{
		// get min neighbor cost
		int minCost = minNeighborCostToGo(C,r,c, mr, mc);

		r = mr;
		c = mc;

	}
}

void solve()
{   
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < ){

    }

	
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}