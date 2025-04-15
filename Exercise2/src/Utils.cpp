#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportData(const string& inputFilePath,
					double& S,
                   size_t& n,
				   double*& w,
                   double*& r)
{
	// Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	
	stringstream ss;
	string line;
	string Ignore;

	getline(file, line);
	ss.str(line);
	getline(ss, Ignore, ';');

	ss >> S;
	ss.clear();
	
	getline(file, line);
	ss.str(line);
	getline(ss, Ignore, ';');
	
	ss >> n;
	ss.clear();
	
	getline(file,line);
	
	w= new double[n];
	stringstream ssw;
	string sw;
	
	r = new double[n];
	stringstream ssr;
	
	unsigned int i=0;
	 while (!file.eof())
	{
		getline(file,line);
		ssr.str(line);
		getline(ssr, sw, ';');
		
		ssw.str(sw);
		ssw >> w[i];
		ssw.clear();
		
		ssr >> r[i];
		ssr.clear();
		
		i++;
	}
	return true;
}	

double PortfolioValue(const double& S,
						const size_t& n,
						const double*const& w,
						const double*const& r)
{
	double V=0;
	for (unsigned int i=0; i < n; i++)
		V+=(1+r[i])*w[i]*S;
	
	return V;
}


bool ExportResult(const string& outputFilePath,
					const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& tot_r,
				  const double& V)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    file << "w = [";
    for (unsigned int i = 0; i < n; i++)
        file << " " << w[i];
    file << " ]" <<  endl;

	
    file << "r = [";
    for (unsigned int i = 0; i < n; i++)
        file << " " << r[i];
    file << " ]" <<  endl;

    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << tot_r << endl;
    file << "V: "<< fixed << setprecision(2) << V << endl;

    // Close File
    file.close();

    return true;
}						

string ArrayToString(const size_t& n,
					const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
	


					   