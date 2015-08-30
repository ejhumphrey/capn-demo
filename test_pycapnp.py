import capnp
import test_capnp
import numpy as np

FNAME = "data/tmp.cpn"
DTYPE = np.int32
POWOF2 = 12
NUM_ELEMENTS = 2**POWOF2


def test_reading():
    ndarray = test_capnp.MultiArray.read_packed(open(FNAME, 'r'))
    assert ndarray, "Failed reading {}".format(FNAME)
    x = ndarray.rows[0]
    assert x, "Doesn't exist!"
    np.testing.assert_equal(
        np.asarray(x.values, dtype=DTYPE),
        np.arange(NUM_ELEMENTS))
