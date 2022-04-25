/*@
 * predicate a() = \true;
 * predicate b() = a();
 */

/*@
 * requires \true;
 * ensures b();
 */
void main() {}
