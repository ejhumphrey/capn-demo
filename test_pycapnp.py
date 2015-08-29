import capnp
import test_capnp
import numpy as np

FNAME = "temp.data"
DTYPE = np.int32
NUM_ELEMENTS = 2**8


def test_reading():
    x = test_capnp.AddressBook.read_packed(open(FNAME, 'r'))
    assert x, "Failed reading {}".format(FNAME)
    a = x.people[0]
    assert a
    np.testing.assert_equal(
        np.asarray(a.array, dtype=DTYPE),
        np.arange(NUM_ELEMENTS))
