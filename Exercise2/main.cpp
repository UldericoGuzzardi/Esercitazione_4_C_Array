#include <iostream>
#include <fstream>
#include <sstream>
#include<iomanip>
#include "src/Utils.hpp"

using namespace std; 


int main()
{
	string inputFileName = "data.txt";
    size_t n = 0;
	double S;
	double* w= nullptr;
	double* r= nullptr;
	double V;
	double tot_r;
	
	if (!ImportData(inputFileName, S, n, w, r))
		{
			cerr<< "Something goes wrong with import"<< endl;
			return -1;
		}
		
	V = PortfolioValue(S, n, w, r);
	tot_r = V/S - 1;
	cout<< "S = " << fixed << setprecision(2) << S << ", n = "<< n << endl;
	cout << "w = "<< ArrayToString(n, w)<< endl; 
	cout << "r = "<< ArrayToString(n, r)<< endl;
	cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << tot_r << endl;
	cout << "V: " << fixed << setprecision(2) << V << endl;
		
	string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, tot_r, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    

    delete[] w;
    delete[] r;
		
	
	
	
	
    return 0;
}

