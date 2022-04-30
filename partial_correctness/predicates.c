/* PiVC allows you to define and use your own predicates. */

/*@
  predicate contains(int* arr, int l, int u, int e) = \exists int ix; (l <= ix && ix <= u && arr[ix] == e);
 */

/*@
  requires \valid(a+(0..n-1));
  requires n >= 0;
  requires 0 <= l && l <= u && u < n && n >= 0;
  ensures \result <==> contains(a, l, u, e);
 */
int LinearSearch(int a[], int n, int l, int u, int e) {
    /*@
      loop invariant 0 <= l && l <= i && i <= u + 1 && u < n && !contains(a, l, (int)(i - 1), e);
    */
	for
		(int i = l; i <= u; i = i + 1)
	{
		if (a[i] == e)
			return 1;
	}
	return 0;
}
