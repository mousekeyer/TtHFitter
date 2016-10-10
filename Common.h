// c++ stuff
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

// ROOT stuff
#include "TArrow.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TFrame.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TList.h"
#include "TMath.h"
#include "TNamed.h"
#include "TObject.h"
#include "TPad.h"
#include "TRandom3.h"
#include "TROOT.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"
#include "TF1.h"

// RooStats stuff
#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/MakeModelAndMeasurementsFast.h"

// ATLAS stuff
#include "AtlasStyle.h"
#include "AtlasLabels.h"
#include "AtlasUtils.h"

using namespace std;

#ifndef __Common__
#define __Common__

namespace TtHFitter{
    extern int DEBUGLEVEL;
    void SetDebugLevel(int level=0);
    extern bool SHOWYIELDS; // flag to show or not yields in plots
    extern bool SHOWSTACKSIG;  // flag to show signal or not
    extern bool SHOWNORMSIG;  // flag to show normalized signal or not
    extern bool SHOWOVERLAYSIG;  // flag to show overlayed signal or not
    extern bool LEGENDLEFT;  // flag to show sample names on left aligned in the legend
    extern bool SYSTCONTROLPLOTS;
    extern bool SYSTDATAPLOT;
    extern bool SYSTERRORBARS;
    extern bool SPLITHISTOFILES;
    extern bool HISTOCHECKCRASH;
    extern float CORRELATIONTHRESHOLD;
    extern std::map< string,string > SYSTMAP;
    extern std::map< string,string > NPMAP;
    extern std::vector< string > IMAGEFORMAT;
    extern int NCPU;
    //
    extern std::map< string, float > OPTION;
};

const int MAXregions = 100;
const int MAXsamples = 100;
const int MAXsyst = 500;
const int MAXnorm = 10;

TH1F* HistFromNtuple(string ntuple, string variable, int nbin, float xmin, float xmax, string selection, string weight);
TH1F* HistFromNtupleBinArr(string ntuple, string variable, int nbin, double *bins, string selection, string weight);
TH1* HistFromFile(string fullName);
TH1* HistFromFile(string fileName,string histoName);
void WriteHistToFile(TH1* h,string fileName,string option="UPDATE");
void MergeUnderOverFlow(TH1* h);
std::vector<string> CreatePathsList( std::vector<string> paths, std::vector<string> pathSufs,
                                    std::vector<string> files, std::vector<string> fileSufs,
                                    std::vector<string> names, std::vector<string> nameSufs);
std::vector<string> CombinePathSufs( std::vector<string> pathSufs, std::vector<string> newPathSufs );
std::vector<string> ToVec(string s);
// string RemovePrefix(string s,string prefix);
string ReplaceString(string subject, const string& search,
                     const string& replace);

int FindInStringVector(std::vector<string> v, string s);
double GetSeparation( TH1F* S1, TH1F* B1 );

TH1F* BlindDataHisto( TH1* h_data, TH1* h_bkg, TH1* h_sig, float threshold=0.02 );
double convertStoD(string toConvert);

// TH1F* SmoothHistogram( TH1* h );
bool SmoothHistogram( TH1* h, int forceFlat=-1 ); // forceFlat: 0 force no flat, 1 force flat, -1 keep it free

#endif
