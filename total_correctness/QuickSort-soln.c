/*@
  predicate sorted(int* arr, integer low, integer high) = 
  (\forall int sorted_a,sorted_b; ((low <= sorted_a && sorted_a <= sorted_b && sorted_b <= high) ==> arr[sorted_a]<=arr[sorted_b]));

predicate partitioned(int* arr, integer low1, integer high1, integer low2, integer high2) =
  (\forall int partitioned_a, partitioned_b; ((low1 <= partitioned_a && partitioned_a <= high1 && low2 <= partitioned_b && partitioned_b <= high2) ==> arr[partitioned_a]<=arr[partitioned_b]));
  */

/*@
  requires l <= u;
  ensures l <= \result && \result <= u;
  decreases u + 1;
 */
int random(int l, int u)
{
	/* a placeholder: only the @post is important */
	return u;
}

/*@
  requires  l<=u && l>=0 && u<n && n >= 0 &&
      partitioned(a, 0, l - 1, l, u) &&
      partitioned(a, l, u, u + 1, n - 1);
  requires \valid(a+(0..n-1));
  decreases n + 1;
  ensures
      \result >=l && \result <=u &&
      partitioned(a, l, \result - 1, \result, \result) &&
      partitioned(a, \result, \result, \result + 1, u) &&
      partitioned(a, 0, l - 1, l, u) &&
      partitioned(a, l, u, u + 1, n - 1);
  ensures \valid(a+(0..n-1));
*/
int partition(int a[], int n, int l, int u) {
	int pi = random(l, u);

	//swap a[u] and a[pi]	
	int pv = a[pi];
	a[pi] = a[u];
	a[u] = pv;

	int i = l - 1;
    /*@
      loop invariant \forall int x; ((x>=l && x<=i) ==> a[x]<=pv) &&
		\forall int x; ((x>i && x<j) ==> a[x]>=pv) &&
 		j>i && i>=l-1 && j<=u && a[u]==pv && i>=-1 && l<=u && l>=0 &&
		partitioned(a, 0, l - 1, l, u) &&
        partitioned(a, l, u, u + 1, n - 1) &&
        u < n;
     loop variant u - j;
    */
	for
		(int j = l; j < u; j = j + 1)
	{
		if (a[j] <= pv) {
			i = i + 1;
			
			//swap a[i] and a[j]
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	//swap a[i+1] and a[u]
	int t = a[i + 1];
	a[i + 1] = a[u];
	a[u] = t;
	
	return i+1;
}

/*@
  requires l>=0 && u < n && n >= 0 &&
    partitioned(a_0, 0, l - 1, l, u) &&
    partitioned(a_0, l, u, u + 1, n - 1) &&
    l <= u + 1;
  requires \valid(a_0+(0..n-1));
  decreases n + u - l;
  ensures sorted(a_0,l,u) &&
        partitioned(a_0, 0, l - 1, l, u) &&
        partitioned(a_0, l, u, u + 1, n - 1);
  ensures \valid(a_0+(0..n-1));
*/
void qsort(int a_0[], int n, int l, int u) {
	if (l >= u)
		return;
	else {
		int p = partition(a_0, n, l, u);
		qsort(a_0, n, l, p - 1);
		qsort(a_0, n, p + 1, u);
		return;
  }
}

/*@
  requires n >= 0;
  requires \valid(a+(0..n-1));
  decreases 2 * n + 1;
  ensures sorted(a, 0, n - 1);
  ensures \valid(a+(0..n-1));
 */
void QuickSort(int a[], int n)
{
	qsort(a, n, 0, n - 1);
}
