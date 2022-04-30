/*@
  predicate sorted(int* arr, integer low, integer high) = 
  (\forall int sorted_a,sorted_b; ((low <= sorted_a && sorted_a <= sorted_b && sorted_b <= high) ==> arr[sorted_a]<=arr[sorted_b]));
  */

/*@
 requires sorted(a, 0, n - 1)
      && sorted(b, 0, m - 1)
	  && n >= 0 && m >= 0;
      decreases n + m + 1;
 ensures sorted(rv, 0, n + m - 1)
      && ((\exists int ix; (0 <= ix && ix <= n - 1 && a[ix] == 1)
           || \exists int ix; (0 <= ix && ix <= m - 1 && b[ix] == 1))
          <==> \exists int ix; (0 <= ix && ix <= u - 1 && rv[ix] == 1));
*/
void uni(int a[], int b[], int n, int m, int u[]) {
	int i = 0;
	int j = 0;

    /*@
      loop invariant i+j==k && i>=0 && j>=0 && i<=n && j<=m && k<=n+m &&
			sorted(a, 0, n - 1) && sorted(b, 0, m - 1) && sorted(u,0,k-1) &&
			(k>0 ==> (i<n ==>u[k-1]<=a[i]) && (j<m ==>u[k-1]<=b[j])) &&
			((\exists int ix; (0 <= ix && ix < i && a[ix] == 1)
				|| \exists int ix; (0 <= ix && ix < j && b[ix] == 1))
				<==> \exists int ix; (0 <= ix && ix < k && u[ix] == 1));
        loop variant n + m - k;
     */
	for (int k = 0; k < n+m; k = k + 1)
	{
		if (i >= n) {
			u[k] = b[j];
			j = j + 1;
		}
		else if (j >= m) {
			u[k] = a[i];
			i = i + 1;
		}
		else if (a[i] <= b[j]) {
			u[k] = a[i];
			i = i + 1;
		}
		else {
			u[k] = b[j];
			j = j + 1;
		}
	}

	return;
}
