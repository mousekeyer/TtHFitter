// vim: ts=4:sw=4
/**********************************************************************************
 * Project: HistFitter - A ROOT-based package for statistical data analysis       *
 * Package: HistFitter                                                            *
 * Namespace: Util                                                                *
 *                                                                                *
 * Description:                                                                   *
 *      Util functions for processing of workspaces and hypotest results          *
 *                                                                                *
 * Authors:                                                                       *
 *      HistFitter group, CERN, Geneva                                            *
 *      Lorenzo Moneta, CERN, Geneva  <Lorenzo.Moneta@cern.h>                     *
 *      Wouter Verkerke, Nikhef, Amsterdam <verkerke@nikhef.nl>                   *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in the file          *
 * LICENSE.                                                                       *
 **********************************************************************************/

#ifndef Utils_hh
#define Utils_hh

#include <map>
#include <vector>
#include <string>
#include "TString.h"
#include "TH1.h"
#include "TH2.h"

#include <iostream>

#include "RooFitResult.h"
#include "RooArgSet.h"
#include "RooArgList.h"

class TMap;
class TTree;

class RooAbsReal;
class RooDataSet;
class RooWorkspace;
class RooRealVar;
class RooAbsPdf;
class RooAbsData;
class RooSimultaneous;
class RooCategory;
class RooPlot;
//class RooFitResult;
class RooMCStudy;
class FitConfig;
class RooProdPdf;
class RooHist;
class RooCurve;

namespace RooStats {
  class HypoTestResult;
  class ModelConfig;
}

namespace Util
{
 
  // Functions related to RooWorkspace
  
  RooStats::ModelConfig* GetModelConfig( const RooWorkspace* w, const TString& mcName ="ModelConfig" );

  void SetInterpolationCode(RooWorkspace* w, Int_t code);
  /**
     Reset errors of all (nuisance/normalization) parameters in RooWorkspace to 'natural' values
  */
  void resetAllErrors( RooWorkspace* wspace );
  /**
    Find the input parameter (systematic) with the given name and shift that parameter (systematic) by 1-sigma if given; otherwise set error to small number
  */
  void resetError( RooWorkspace* wspace, const RooArgList& parList, const RooArgList& vetoList = RooArgList() ) ;

  /**
     Set all parameter values to initial values
  */
  void resetAllValues( RooWorkspace* wspace );
  /**
     Set  parameter value to initial value
  */
  void resetValue( RooWorkspace* wspace, const RooArgList& parList, const RooArgList& vetoList = RooArgList() ) ;

  /**
     Set all parameter values to nominal values -- FIXME (same functionality as resetAllValues()?)
  */
  void resetAllNominalValues( RooWorkspace* wspace );
  /**
     Set parameters values to nominal values -- FIXME (same functionality as resetValue()?)
  */
  void resetNominalValue( RooWorkspace* wspace, const RooArgSet& globSet ) ;
  /**
     Set parameter to value at nominal value + Nsigma * parameter error
  */
  RooArgList getFloatParList( const RooAbsPdf& pdf, const RooArgSet& obsSet = RooArgSet() );



}

# endif
