#pragma once

#include<iostream>

using namespace std;


//ImportData è la funzione che permette di leggere il file
//inputeFilePath: percorso del file da leggere
//S: investimento iniziale totale
//n: numero di assets su cui si vuole investire
//w: vettore che comprende le frazioni di S da investire in n assets diversi
//r: vettore che comprende i tassi di interesse per ogni specifico investimento
//La funzione permette di definire i dati descritti sopra e restituisce vero se il file viene letto correttamente, falso altrimenti
bool ImportData(const string& inputFilePath, 
					double& S,
                   size_t& n,
                   double*& w,
                   double*& r);



// PortfolioValue calcola il valore totale del Portfolio
// S; investimento totale iniziale
// n: dimensione del vettore
// w: vettore degli investimenti
// r: vettore dei tassi di rendimento
// Restituisce il valore totale del portafoglio in una variabile double V
double PortfolioValue(const double& S,
						const size_t& n,
						const double*const& w,
						const double*const& r);



// ExportResult esporta i risultati ottenuti
// outputFilePath: percorso del file in cui esportare
// S: investimento totale iniziale
// n: dimensione del vettore
// w: vettore degli investimenti
// r: vettore dei tassi di rendimento
// tot_r: tasso di rendimento totale
// V: valore totale del portfolio
// restituisce il risultato dell'esportazione, true se va a buon fine, false viceversa. 
// Nel caso in cui vada a buon fine stampa tutto nel file richiesto
bool ExportResult(const string& outputFilePath,
					const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& tot_r,
				  const double& V);


// ArrayToString stampa un vettore come stringa
// n: dimensione del vettore
// v: vettore
// Restituisce la stringa
string ArrayToString(const size_t& n,
                     const double* const& v);
