/**
 * 顺序查找
 * 时间复杂度：O（N）
 * @param set
 * @param size
 * @param target
 * @return
 */
int sequence_search(int set[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (set[i] == target) {
            return i;
        }
    }

    return -1;
}