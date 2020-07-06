
#include <iostream> 
using namespace std;

const int N = 4;
const int c[N][N] = {
  {0, 3, 7, 4},
  {3, 0, 1, 2},
  {7, 1, 0, 5},
  {4, 2, 5, 0}
};

int cmin = 100000, x[N], x_star[N], f_star = 100000, f = 0, z_duoi = 0;
bool visited[N];

void TRY(int k) 
{
  for (int v = 0; v < N; v++)
    if (visited[v] == false)
    {
      x[k] = v;
      visited[v] = true;
      f += c[x[k-1]][x[k]];
      if (k == N-1)
      {
        if (f + c[x[N-1]][x[0]] < f_star)
        {
           f_star = f + c[x[N-1]][x[0]];
           for (int i = 0; i < N; i++) 
		   	x_star[i] = x[i]; 
        }         
      } else { // k < N
        z_duoi = f + (N-k+1) * cmin;
        if (z_duoi < f_star) // branch-and-bound
          TRY(k+1); 
      }
      visited[v] = false;
      f -= c[x[k-1]][x[k]];
    }
}

int main(){ 
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if ( (c[i][j] < cmin) && (c[i][j] > 0) ) 
	  cmin = c[i][j];
  
  for (int i = 0; i < N; i++) 
  {
    x[i] = -1;
    visited[i] = false;
  }

  x[0] = 3;
  visited[x[0]] = true;
  TRY(1);

  cout << "Khoang cach ngan nhat tim duoc: " << f_star << endl;
  cout << "Hanh trinh can di: ";
  for (int i = 0; i < N; i++) 
  	cout << (x_star[i]+1) << " -> ";
  cout << (x_star[0]) << endl;
 return 0;  
}
