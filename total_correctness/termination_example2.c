/* From email with Aaron 6/01/2008. */

/*@
    requires n >= 0;
    ensures  \true;
 */
void foo(int n) {
    /*@
      loop invariant n >= 0 && i >= 0 && i <= n;
      loop variant n - i;
     */
	for (int i = 0; i < n; i = i + 1)
		{
			foo(n-1);
		}
}