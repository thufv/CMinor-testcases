/*@
 * requires \true;
 * ensures \true;
 */
int fun()
{
	int sum = 0;
	for
    /*@
     * loop invariant 0 <= i && i <= 9;
     */
	  (int i = 0; i < 10; i = i + 1)
	{
		sum = sum + i;
		if (i = 9) break;
  }
	return sum;
}