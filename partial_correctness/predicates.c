/* PiVC allows you to define and use your own predicates. */

/*@
 * predicate contains(int[] arr, int l, int u, int e) = \exists int ix. (l <= ix && ix <= u && arr[ix] == e);
 */

@pre  0 <= l && l <= u && u < |a| && |a| >= 0
@post rv <-> contains(a, l, u, e)
/*@
 * requires \valid(a_0+(0..n-1));
 * requires n >= 0;
 * requires 0 <= l && l <= u && u < n && n >= 0;
 * ensures \result <==> contains(a, l, u, e);
 */
bool LinearSearch(int[] a, int n, int l, int u, int e) {
	for
        /*@
         * loop invariant 0 <= l && l <= i && i <= u + 1 && u < n && !contains(a, l, i - 1, e);
         */
		(int i = l; i <= u; i = i + 1)
	{
		if (a[i] = e)
			return true;
	}
	return false;
}
