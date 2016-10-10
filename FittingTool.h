//
// Fit.h
// ==========
// Allows to implement all necessary informations and functions to perform likelihood fits.
//

#ifndef _FittingTool_
#define _FittingTool_

#include "TtHFitter/Common.h"

class RooFitResult;
class TString;
class RooAbsPdf;
class RooAbsData;

#include <string>
#include <map>
#include "RooStats/ModelConfig.h"

class FittingTool {

public:
    
    //
    // Standard C++ functions
    //
    FittingTool();
    ~FittingTool();
    FittingTool( const FittingTool & );
    
    //
    // Gettters and setters
    //
    inline void SetDebug ( const int debug ){ m_debug = debug>0; }
    
    inline void MinimType ( const TString &type ){ m_minimType = type; }
    inline TString GetMinimType(){ return m_minimType; }
    
    inline int GetMinuitStatus() { return m_minuitStatus; }
    inline int GetHessStatus() { return m_hessStatus; }
    inline double GetEDM() { return m_edm; }
    
    inline void ValPOI( const double value ) { m_valPOI = value; }
    inline double GetValPOI() { return m_valPOI; }
    
    //inline void UseMinos( const bool use ) { m_useMinos = use; }
    
    inline void ConstPOI( const bool constant ) { m_constPOI = constant; }
    inline double GetConstPOI() { return m_constPOI; }
    
    inline void SetRandomNP( const double rndNP, const bool rndize ) { m_randomNP = rndNP; m_randomize = rndize; }
    
    inline void FixNP( const TString &np, const double value ) { m_constNP = np; m_constNPvalue = value; }
    
    inline RooFitResult* GetFitResult() { return m_fitResult; }

    inline void RangePOI_up( const double value){m_RangePOI_up = value;}
    inline void RangePOI_down( const double value){m_RangePOI_down = value;}

    inline void UseMinos( const std::vector<std::string> minosvar){ m_useMinos = true; m_varMinos = minosvar; }
    inline void DisableMinos(){ m_useMinos = false; }
    
    //
    // Specific functions
    //
    void FitPDF( RooStats::ModelConfig* model, RooAbsPdf* fitpdf, RooAbsData* fitdata );
    void ExportFitResultInTextFile( const std::string &finaName );
    std::map < std::string, double > ExportFitResultInMap();
    
private:
    TString m_minimType;
    int m_minuitStatus, m_hessStatus;
    double m_edm,m_valPOI,m_randomNP;
    double m_RangePOI_up,m_RangePOI_down;
    bool m_useMinos,m_constPOI;
    std::vector<std::string> m_varMinos;
    RooFitResult* m_fitResult;
    bool m_debug,m_randomize;
    
    TString m_constNP;
    double m_constNPvalue;
};


#endif //FitTools
