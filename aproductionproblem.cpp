#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define float double

class Simplex
{

private:
    int rows, cols;
    // Stores coefficients of all the variables
    vector<vector<float>> A;
    // Stores constants of constraints
    vector<float> B;
    // Stores the coefficients of the objective function
    vector<float> C;

    float maximum;

    bool isUnbounded;

public:
    Simplex(vector<vector<float>> matrix, vector<float> b, vector<float> c)
    {
        maximum = 0;
        isUnbounded = false;
        rows = matrix.size();
        cols = matrix[0].size();
        A.resize(rows, vector<float>(cols, 0));
        B.resize(b.size());
        C.resize(c.size());

        for (int i = 0; i < rows; i++)
        { // Pass A[][] values to the matrix
            for (int j = 0; j < cols; j++)
            {
                A[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < c.size(); i++)
        { // Pass c[] values to the C vector
            C[i] = c[i];
        }
        for (int i = 0; i < b.size(); i++)
        { // Pass b[] values to the B vector
            B[i] = b[i];
        }
    }

    bool simplexAlgorithmCalculataion()
    {
        // Check whether the table is optimal, if optimal no need to process further
        if (checkOptimality() == true)
        {
            return true;
        }

        // Find the column which has the pivot. The least coefficient of the objective function(C array).
        int pivotColumn = findPivotColumn();

        // Find the row with the pivot value. The least value item's row in the B array
        int pivotRow = findPivotRow(pivotColumn);

        if (isUnbounded == true)
        {
            cout << "Error unbounded" << endl;
            return true;
        }

        // Form the next table according to the pivot value
        doPivotting(pivotRow, pivotColumn);

        return false;
    }

    bool checkOptimality()
    {
        double EPS = 1e-12;

        // Check if the coefficients of the objective function are negative
        for (int i = 0; i < C.size(); i++)
        {
            if(C[i] < -EPS) return false;
        }
        return true;
    }

    void doPivotting(int pivotRow, int pivotColumn)
    {

        float pivetValue = A[pivotRow][pivotColumn]; // Gets the pivot value

        float pivotRowVals[cols]; // The column with the pivot

        float pivotColVals[rows]; // The row with the pivot

        float rowNew[cols]; // The row after processing the pivot value

        maximum = maximum - (C[pivotColumn] * (B[pivotRow] / pivetValue)); // Set the maximum step by step
        // Get the row that has the pivot value
        for (int i = 0; i < cols; i++)
        {
            pivotRowVals[i] = A[pivotRow][i];
        }
        // Get the column that has the pivot value
        for (int j = 0; j < rows; j++)
        {
            pivotColVals[j] = A[j][pivotColumn];
        }

        // Set the row values that has the pivot value divided by the pivot value and put into new row
        for (int k = 0; k < cols; k++)
        {
            rowNew[k] = pivotRowVals[k] / pivetValue;
        }

        B[pivotRow] = B[pivotRow] / pivetValue;

        // Process the other coefficients in the A array by subtracting
        for (int m = 0; m < rows; m++)
        {
            // Ignore the pivot row as we already calculated that
            if (m != pivotRow)
            {
                for (int p = 0; p < cols; p++)
                {
                    float multiplyValue = pivotColVals[m];
                    A[m][p] = A[m][p] - (multiplyValue * rowNew[p]);
                    // C[p] = C[p] - (multiplyValue*C[pivotRow]);
                    // B[i] = B[i] - (multiplyValue*B[pivotRow]);
                }
            }
        }

        // Process the values of the B array
        for (int i = 0; i < B.size(); i++)
        {
            if (i != pivotRow)
            {

                float multiplyValue = pivotColVals[i];
                B[i] = B[i] - (multiplyValue * B[pivotRow]);
            }
        }
        // The least coefficient of the constraints of the objective function
        float multiplyValue = C[pivotColumn];
        // Process the C array
        for (int i = 0; i < C.size(); i++)
        {
            C[i] = C[i] - (multiplyValue * rowNew[i]);
        }

        // Replacing the pivot row in the new calculated A array
        for (int i = 0; i < cols; i++)
        {
            A[pivotRow][i] = rowNew[i];
        }
    }

    // Find the least coefficients of constraints in the objective function's position
    int findPivotColumn()
    {
        double EPS = 1e-12;
        int location = 0;
        float minm = C[0];

        for (int i = 1; i < C.size(); i++)
        {
            if(C[i] < -EPS) return i;
        }

        return location;
    }

    // Find the row with the pivot value.The least value item's row in the B array
    int findPivotRow(int pivotColumn)
    {
        double EPS = 1e-12;
        
        double best = 1e100;
        int row = -1;

        rep(i,0,rows){
            if(A[i][pivotColumn] > EPS){
                double r = B[i] / A[i][pivotColumn];
                if(r > -EPS){
                    if(r < best || (fabs(r - best) <= EPS && i < row)){
                        best = r;
                        row = i;
                    }
                }
            }
        }

        if(row == -1)isUnbounded = true;
        return row;
    }

    void CalculateSimplex()
    {
        bool end = false;

        while (!end)
        {

            bool result = simplexAlgorithmCalculataion();

            if (result == true)
            {

                end = true;
            }
        }

        for (int i = 0; i < A.size(); i++)
        { // every basic column has the values, get it form B array
            int count0 = 0;
            int index = 0;
            for (int j = 0; j < rows; j++)
            {
                if (A[j][i] == 0.0)
                {
                    count0 += 1;
                }
                else if (A[j][i] == 1)
                {
                    index = j;
                }
            }
        }

    }

    float returnMaximum(){
        return maximum;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,m;cin>>m>>n;
    int cols = n+m;
    vector<float> b(m), c(cols,0.0f);
    vector<vector<float>> A(m, vector<float>(cols,0.0f));

    rep(i,0,m)cin>>b[i];
    rep(j,0,n){
        rep(i,0,m){
            cin>>A[i][j];
            A[i][j]/=100;
        }
        cin>>c[j];
        c[j]*=-1;
    }
    rep(i,0,m){
        A[i][n+i]=1.0f;
    }

    Simplex sim(A,b,c);
    sim.CalculateSimplex();
    double ans = sim.returnMaximum();
    if(abs(ans) < 0.0005)ans = 0;
    cout << setprecision(2) << fixed << ans << "\n";
}