// basic file operations
#include <iostream>
#include <fstream>
#include "src/test.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>

#define FNAME "data/tmp.cpn"

using namespace std;


void writeMultiArray(int fd, int num_elements) {
  ::capnp::MallocMessageBuilder message;
  MultiArray::Builder ndarray = message.initRoot<MultiArray>();
  ::capnp::List<Row>::Builder rows = ndarray.initRows(1);

  Row::Builder row = rows[0];

  ::capnp::List<int>::Builder values = row.initValues(num_elements);
  for (int idx = 0; idx < num_elements; ++idx)
  {
      values.set(idx, idx);
  }
  writePackedMessageToFd(fd, message);
}


void printMultiArray(int fd, int num_elements) {
  ::capnp::PackedFdMessageReader message(fd);
  MultiArray::Reader ndarray = message.getRoot<MultiArray>();
  for (Row::Reader row : ndarray.getRows()) {
    std::cout << ">> Number of elements (exp): " << num_elements << std::endl;
    std::cout << ">> Number of elements (act): " << row.getValues().size() << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2)
  {
      std::cout << "Requires a `num_elements` argument." << std::endl;
  }
  int num_elements = atoi(argv[1]);
  FILE* write_handle = ::fopen(FNAME, "w");
  writeMultiArray(fileno(write_handle), num_elements);
  ::fclose(write_handle);

  FILE* read_handle = ::fopen(FNAME, "r");
  printMultiArray(fileno(read_handle), num_elements);
  ::fclose(read_handle);

  return 0;
}
