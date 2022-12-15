#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <span>

#include "doctest/doctest.h"
#include "spdlog/spdlog.h"
#include "clipp.h"

int main(int argc, char* argv[])
{
  bool rec = false; 
  bool utf16 = false;
  std::string infile;
  std::string fmt = "csv";
  bool file = false;

  auto cli = (
      clipp::required("-f", "--file").set(file),
      clipp::value("input file", infile),
      clipp::option("-r", "--recursive").set(rec).doc("convert files recursively"),
      clipp::option("-o") & clipp::value("output format", fmt),
      clipp::option("-utf16").set(utf16).doc("use UTF-16 encoding")
  );

  if(!parse(argc, argv, cli)) {
    std::cout << make_man_page(cli, argv[0]); // NOLINT
    return -1;
  };

  spdlog::info("hmm");
  std::cout << "print" << std::endl;

  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();
}