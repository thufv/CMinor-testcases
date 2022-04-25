/*@
 * requires \true;
 * ensures \result == x;
 */
int fun1(int x) {
	return x;
}

/*@
 * requires \true;
 * ensures \result == x;
 */
int fun(int x) {
	if (true) x = 2;
	return fun1(fun1(fun1(x)));
}
