/*@
    requires n >= 0 && 0 <= l && u < n;
    ensures \result <==> \exists int ix; (l <= ix && ix <= u && a[ix] == e);
*/
int LinearSearch(int a[], int n, int l, int u, int e) {
    /*@
     loop invariant n >= 0 && l <= i && 0 <= l && u < n && (i <= u + 1 || i <= l)
        && \forall int ix; (l <= ix && ix < i ==> a[ix] != e);
     loop variant n + l + 1 - i;
     */
	for
		(int i = l; i <= u; i = i + 1)
	{
		if (a[i] = e)
			return 1;
	}
	return 0;
}
