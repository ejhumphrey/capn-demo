# test.capnp
@0xb94eb3e83e53ade1;

struct Row {
  values @0 :List(Int32);
}

struct MultiArray {
  rows @0 :List(Row);
}
