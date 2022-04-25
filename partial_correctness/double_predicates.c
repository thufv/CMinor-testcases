/* This is Joel testing his fix */


/*@
 * predicate a() = \true;
 * predicate b() = a() <==> a();
 */

/*@
 * requires \true;
 * ensures a();
 */
void main() {}
