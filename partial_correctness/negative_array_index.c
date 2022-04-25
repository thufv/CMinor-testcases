/*@
 * predicate sorted(int[] arr, int low, int high) = 
  (forall sorted_a,sorted_b. ((low <= sorted_a && sorted_a <= sorted_b && sorted_b <= high) ==> arr[sorted_a]<=arr[sorted_b]));
 */

/*@
 * requires \valid(a_0+(0..n-1));
 * requires n >= 0;
 * ensures \valid(\result+(0..n-1));
 * ensures sorted(\result, 0, n-1);
 */
int[] InsertionSort(int[] a, int n) {
	for
        /*@
         * loop invariant sorted(a, 0, i - 1) && 1 <= i && i <= n + 1;
         */
		(int i = 1; i < n; i = i + 1)
	{
		int t = a[i];
		int j;
		for
        /*@
         * loop invariant sorted(a, 0, i - 1)
			  && \forall integer ix. (j < ix && ix < i -> a[ix] > t)
			  && (j < i - 1 ==> sorted(a, 0, i))
			  && j < i
			  && 1 <= i && i < n && j >= -1;
         */
			(j = i - 1; j >= 0; j = j - 1)
		{
			if (a[j] <= t) break;
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
	return a;
}
