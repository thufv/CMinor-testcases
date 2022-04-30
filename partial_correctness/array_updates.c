/*
 * If you put in a lot more of these lines, we slot down a lot.
 */

/*@
  requires \valid(x+(0..0));
  ensures \result[0] == 20;
 */
int* foo(int x[]) {
    x[0] = 0;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	x[0] = x[0] + 1;
	return x;
}
