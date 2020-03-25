#include "driver.h"
#include "parser.tab.hh"

int analizer_driver::parse(const std::string& archivo)
{
  file = archivo;
  iniciarScanner();
  yy::analizer_parser parser(*this);
  parser.set_debug_level(false);
  parser.parse();
  return resultado;

}


