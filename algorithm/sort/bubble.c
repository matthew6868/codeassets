/**
 * 冒泡算法
 * @param set 
 * @param size 
 */
void bubble_sort(int set[], int size) {
    for (int i = 0; i < size; ++i) {
        int swap_flag = 0;
        for (int j = 0; j < size - i - 1; ++j) {
            if (set[j] > set[j + 1]) {
                int temp = set[j];
                set[j] = set[j + 1];
                set[j + 1] = temp;
                swap_flag = 1;
            }
        }

        if (!swap_flag)
            break;
    }
}