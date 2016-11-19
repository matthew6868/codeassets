/*
 *	Author: matthew6868（mxu.public@outlook.com）
 *	Date: 2016-10-20
 *	Corporation:  Zoom Video Communication, Inc, 软视（杭州）有限公司
 */
void makeOddNumberFisrt(std::vector<int> &data) {
	//std::partition(v.begin(), v.end(), [v](int i) {return v[i] % 2 == 1; });
	if (data.size() > 1) {
		int left = 0, right = data.size() -1 ;
		// left 指向左边的奇数索引，right 指向右边的奇数索引。
		while (left < right) {
			// 如果头尾索引都是偶数，则左移右边的索引
			if (data[left] % 2 == 0 && data[right] % 2 == 0) {
				right--;
			}
			else if (data[left] % 2 != 0 && data[right] % 2 != 0) {
				// 如果头尾索引都是奇数数，则右移左边的索引
				left++;
			} else if (data[left] % 2 == 0 && data[right] % 2 != 0) {
				// 如果左侧是偶数，右侧是奇数，则交换位置，并同时移动左右索引
				int temp = data[left];
				data[left] = data[right];
				data[right] = temp;
				left++;
				right--;
			}
			else {
				left++;
				right++;
			}
		}
	}
}