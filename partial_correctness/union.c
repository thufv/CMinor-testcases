/*@
  predicate inRange(integer target, integer[] arr, integer n, integer low, integer high) =
    ((low <= high && 0 <= low && high <= n - 1) ==>
    (\exists integer ix; (low <= ix && ix <= high && arr[ix] == target)));

  predicate in(integer target, integer[] arr, integer n ) =
    inRange(target, arr, 0, n - 1 );
 */

/*@
  requires \valid(a+(0..n-1));
  requires \valid(b+(0..m-1));
  requires n > 0 && m > 0;
  ensures \valid(\result+(0..n+m-1));
  ensures ((\exists integer ix; (0 <= ix && ix <= n - 1 && a[ix] == 1)
        || \exists integer ix; (0 <= ix && ix <= m - 1 && b[ix] == 1))
          <==> \exists integer ix; (0 <= ix && ix <= n + m - 1 && \result[ix] == 1))
 */
int* unio(int a[], int n, int b[], int m) {
    int[] u = new int[n+m];
    int j = 0;

    /*@ 
      loop invariant n >= 0 && m >= 0 && j >= 0 &&
            (i > 0 && j > 0 && a[i-1] == u[j-1]
            ==> (\exists integer ix; (0 <= ix && ix <= i - 1 && a[ix] == 1)
                <==> \exists integer ix; (0 <= ix && ix <= j - 1 && u[ix] == 1)))
    */
    for
            (int i = 0; i < |a|; i = i + 1)
    {
            u[j] = a[i];
            j = j + 1;
    }
    for
            @ |a| >= 0 && |b| >= 0 && (in(1,a) || in(1,b) <-> in(1,u))
            (int i = 0; i < |b|; i = i + 1)
    {
            u[j] = b[i];
            j = j + 1;
    }

    return u;
}
