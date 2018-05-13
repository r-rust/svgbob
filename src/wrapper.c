#define R_NO_REMAP
#define STRICT_R_HEADERS
#include <Rinternals.h>

// Import C headers for rust API
#include "myrustlib/api.h"

SEXP R_ascii2svg(SEXP ascii, SEXP svgfile){
  if(!Rf_isString(ascii) || !Rf_isString(svgfile))
    Rf_error("Both ascii and svgfile must be strings");
  run_ascii2svg(CHAR(STRING_ELT(ascii, 0)), CHAR(STRING_ELT(svgfile, 0)));
  return svgfile;
}

// Standard R package stuff
static const R_CallMethodDef CallEntries[] = {
  {"R_ascii2svg", (DL_FUNC) &R_ascii2svg, 2},
  {NULL, NULL, 0}
};

void R_init_svgbob(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
