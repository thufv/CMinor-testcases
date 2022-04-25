/*@
 * predicate sorted(integer[] arr, integer low, integer high) = (\forall integer sorted_a,sorted_b; ((low <= sorted_a && sorted_a <= sorted_b && sorted_b <= high) ==> arr[sorted_a]<=arr[sorted_b]));
 */

/*@
 * requires \valid(a_0+(0..n-1));
 * requires 0 <= l && u < n && sorted(a, 0, n - 1)
 * ensures \result <==> \exists integer ix. (l <= ix && ix <= u && a[ix] = e)
 */
bool BinarySearch(int[] a, int n, int l, int u, int e) {
	if (l > u)
		return false;
	else {
		int m = (l + u) / 2;
		if (a[m] == e)
			return true;
		else if (a[m] < e)
			return BinarySearch(a, m + 1, u, e);
		else
			return BinarySearch(a, l, m - 1, e);
	}
}
