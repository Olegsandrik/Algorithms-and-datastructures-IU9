unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    int right = nel - 1, left = 0, middle;
    while (right-left>1) {
        middle = (right + left) / 2;
        if (compare(middle) == 1) {
            right = middle;
        } else if (compare(middle) == -1) {
            left = middle;
        } else {
            return middle;
        }
    }
    if (compare(right) == 0) {
        return right;
    } else if (compare(left) == 0) {
        return left;
    } else {
        return nel;
    }
}
