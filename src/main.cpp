#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <span>

#include "clipp.h"
#include "doctest/doctest.h"
// #include "spdlog/sinks/android_sink.h"
#include "spdlog/spdlog.h"

int main(int argc, char* argv[])
{
  bool rec = false;
  bool utf16 = false;
  std::string infile;
  std::string fmt = "csv";
  bool file = false;

  auto cli =
      (clipp::required("-f", "--file").set(file),
       clipp::value("input file", infile),
       clipp::option("-r", "--recursive").set(rec).doc("convert files recursively"),
       clipp::option("-o") & clipp::value("output format", fmt),
       clipp::option("-utf16").set(utf16).doc("use UTF-16 encoding"));

  if (!parse(argc, argv, cli))
  {
    std::cout << make_man_page(cli, argv[0]);  // NOLINT
    return -1;
  };

  // std::string tag = "spdlog-android";
  // auto android_logger = spdlog::android_logger_mt("android", tag);
  // android_logger->critical("Use \"adb shell logcat\" to view this message.");

  std::cout << "print" << std::endl;

  doctest::Context context;
  context.applyCommandLine(argc, argv);
  return context.run();
}