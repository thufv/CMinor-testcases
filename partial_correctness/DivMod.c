// all specifications should hold

/*@
 * requires x_0 >= 0 && x_0 % 2 = 0;
 * ensures rv == x_0 /2 + y_0;
 */
int twoxy(int x_0, int y_0) {
	int x = x_0;
	int y = y_0;
	while
    /*@
     * loop invariant x >= 0 && x % 2 == 0
     *  && y == (x_0 - x) / 2 + y_0
     */
	(x > 0)
	{
		x = x - 2;
		y = y + 1;
	}
	return y;
}
