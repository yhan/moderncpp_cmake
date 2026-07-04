template<typename TSource, typename TDest>
TDest copy_array(TSource begin, TSource end, TDest dest) {
    while (begin != end) {
        *dest++ = *begin++;
    }
    return dest;
}

/*
 *
 * Explicit pointer syntax — same logic as copy_array
 *
* The parameters are pointers, but they're passed by value.
* Inside, dest is a local copy of the pointer. When dest++ happens, only the local copy increments.
Caller's dest unchanged ? still points to first element. ?
 */
template<typename TSource, typename TDest>
void copy_array2(TSource* begin, TSource* end, TDest* dest) { //
    while (begin != end) {
        *dest++ = *begin++; // will run dest++ first, then dereference the old value of dest
    }
}


template<typename TSource, typename TDest>
void copy_array3(TSource& begin, TSource& end, TDest& dest) {
    while (begin != end) {
        *dest++ = *begin++;
    }
}