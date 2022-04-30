/*@
  requires \valid(a+(0..n-1));
  requires \valid(b+(0..m-1));
  requires n >= 0 && m >= 0;
  ensures \valid(u+(0..n+m-1));
  ensures ((\exists int ix; (0 <= ix && ix <= n - 1 && a[ix] == 1)
           || \exists int ix; (0 <= ix && ix <= m - 1 && b[ix] == 1))
          <==> \exists int ix; (0 <= ix && ix <= n + m - 1 && u[ix] == 1));
*/
void uni(int a[], int b[], int n, int m, int u[]) {
    int j = 0;

    /*@
        loop invariant j==i && i<=n && n >= 0 && m >= 0 &&
        ((\exists int ix; (0 <= ix && ix <= i - 1 && a[ix] == 1)
        <==> \exists int ix; (0 <= ix && ix <= i - 1 && u[ix] == 1))) &&
        i >= 0;
        loop variant n - i;
    */
	for (int i = 0; i < n; i = i + 1)
	{
		u[j] = a[i];
		j = j + 1;
	}
    /*@
        loop invariant j==i+n && i <= m && i>=0 && n >= 0 && m >= 0 &&
			(((\exists int ix; (0 <= ix && ix <= n - 1 && a[ix] == 1) ||
			(\exists int ix; (0 <= ix && ix <= i - 1 && b[ix] == 1)))
          <==> \exists int ix; (0 <= ix && ix <= n + i - 1 && u[ix] == 1)));
        loop variant m - i;
    */
	for (int i = 0; i < m; i = i + 1)
	{
		u[j] = b[i];
		j = j + 1;
	}

	return;
}
