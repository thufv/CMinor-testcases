/*@
 predicate sorted(int* arr, int low, int high) = 
  (\forall int sorted_a,sorted_b; ((low <= sorted_a && sorted_a <= sorted_b && sorted_b <= high) ==> arr[sorted_a]<=arr[sorted_b]));
 predicate partitioned(int* arr, int low1, int high1, int low2, int high2) =
  (\forall int partitioned_a, partitioned_b; ((low1 <= partitioned_a && partitioned_a <= high1 && low2 <= partitioned_b && partitioned_b <= high2) ==> arr[partitioned_a]<=arr[partitioned_b]));
*/

/*@
  requires \valid(arr_0+(0..n-1));
  requires n >= 1;
 */
void BubbleSort(int arr_0[], int n) {
	/*@
      loop invariant
        sorted(arr_0, i, n - 1) &&
        1 <= i && i < n &&
        partitioned(arr_0, 0, i, i+1, n-1);
      loop variant i + 1;
     */
	for
        (int i = n - 1; i > 0; i = i - 1)
	{
        /*@
            loop invariant
                partitioned(arr_0, 0, i, i + 1, n - 1) &&
                    1 <= i && i < n && 0 <= j && j <= i &&
                sorted(arr_0, i, n - 1) &&
                partitioned(arr_0, 0, j - 1, j, j);
            loop variant i - j;
        */
		for
            (int j = 0; j < i; j = j + 1)
		{
			if (arr_0[j] > arr_0[j + 1]) {
				int temp = arr_0[j];
				arr_0[j] = arr_0[j + 1];
				arr_0[j + 1] = temp;
			}
		}
	}
   //@ assert \valid(a_0+(0..n-1));
   //@ assert sorted(arr_0, 0, n-1) ;
	return arr_0;
}
