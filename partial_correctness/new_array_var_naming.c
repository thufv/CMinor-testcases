/*@
 * requires \true;
 * ensures \true;
 */
void foo() {
	int[42] new_array;
	int[42] new_array2;
	//@ assert new_array[0] == new_array2[0];
}
