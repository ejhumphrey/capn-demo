// basic file operations
#include <iostream>
#include <fstream>
#include "math.h"
#include "src/test.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>

#define FNAME "data/tmp.cpn"
#define POWOF2 12

const int kNumElements = (int)pow(2, POWOF2);
using namespace std;


void writeMultiArray(int fd) {
  ::capnp::MallocMessageBuilder message;
  MultiArray::Builder ndarray = message.initRoot<MultiArray>();
  ::capnp::List<Row>::Builder rows = ndarray.initRows(1);

  Row::Builder row = rows[0];

  ::capnp::List<int>::Builder values = row.initValues(kNumElements);
  for (int idx = 0; idx < kNumElements; ++idx)
  {
      values.set(idx, idx);
  }
  writePackedMessageToFd(fd, message);
}


void printMultiArray(int fd) {
  ::capnp::PackedFdMessageReader message(fd);
  MultiArray::Reader ndarray = message.getRoot<MultiArray>();
  for (Row::Reader row : ndarray.getRows()) {
    std::cout << ">> Number of elements (exp): " << kNumElements << std::endl;
    std::cout << ">> Number of elements (act): " << row.getValues().size() << std::endl;
  }
}

int main() {
  FILE* write_handle = ::fopen(FNAME, "w");
  writeMultiArray(fileno(write_handle));
  ::fclose(write_handle);

  FILE* read_handle = ::fopen(FNAME, "r");
  printMultiArray(fileno(read_handle));
  ::fclose(read_handle);

  return 0;
}
