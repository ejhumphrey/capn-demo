import argparse
import capnp
import numpy as np
import test_capnp

FNAME = "data/tmp.cpn"
DTYPE = np.int32


def test_reading(num_elements):
    ndarray = test_capnp.MultiArray.read_packed(open(FNAME, 'r'))
    assert ndarray, "Failed reading {}".format(FNAME)
    x = ndarray.rows[0]
    assert x, "Doesn't exist!"
    np.testing.assert_equal(
        np.asarray(x.values, dtype=DTYPE),
        np.arange(num_elements))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("num_elements",
                        metavar="num_elements", type=int,
                        help="Number of expected elements in the protobuff.")
    args = parser.parse_args()
    test_reading(args.num_elements)
