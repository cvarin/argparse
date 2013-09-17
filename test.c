#include "argparse.hpp"

int main(int argc, const char** argv) 
{

  // make a new ArgumentParser
  ArgumentParser parser;

  // add some arguments to search for
  parser.addArgument("-a");
  parser.addArgument("-b");
  parser.addArgument("-c", "--cactus", 1);
  parser.addArgument("-o", "--optional");
  parser.addArgument("-r", "--required", 1, true);
  parser.addArgument("--five", 5);
  parser.addArgument("--atleast", '+');
  parser.addArgument("--any", '*');
  parser.addFinalArgument("output");

  // parse the command-line arguments - throws if invalid format
  parser.parse(argc, argv);

  // if we get here, the configuration is valid
  int cactus = parser.retrieve<int>("cactus");
  return cactus;
}
