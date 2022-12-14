#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>

#include "doctest/doctest.h"
#include "spdlog/spdlog.h"

int main(int argc, char** argv)
{
  spdlog::info("hmm");
  std::cout << "print" << std::endl;

  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();

  return 0;
}