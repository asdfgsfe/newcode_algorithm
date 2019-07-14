 1//本质上就是先计算从0点的n行m列矩阵 然后每行每列向下向右移动 遍历全部矩阵 
 int maxSubmatrixSum(std::vector<std::vector<int>> matrix,
 2                     int n, int m) 
 {
	 int base_sum = 0; //base_sum初始化
 4   for (int i = 0; i < n && n <= matrix.size(); i++){             //n可能大于数组矩阵行数
 5     for (int j = 0; j < m && m <= matrix.front().size(); j++){	//m可能大于数组矩阵列数
 6       base_sum += matrix[i][j];
 7     }
 8   }
 9   int result = base_sum;	//result初始化为base
10   for (int i = 0; i + n < matrix.size(); i++) {
		int real_sum = base_sum; //real_sum保留当前base_sum值
		for (int y = 0; y < m; y++){
13         base_sum += matrix[i + n][y] - matrix[i][y];//用i 如果用i-1会丢掉第一行
14       }
17      if (base_sum  > result) {
18       result = base_sum;
19      }
20     for (int j = 0; j + m < matrix.size(); j++) {
21       for (int x = i; x < i + n; x++) { //x从i开始遍历 i是基线而不是0 x小于i+n 等于向下移动了一行
22         real_sum += matrix[x][j + m] - matrix[x][j]; //用j 用j-1会core
23       }
24       if (real_sum > result) {
25         result = real_sum;
26       }
27     }
28   }
29   return result;
30 }