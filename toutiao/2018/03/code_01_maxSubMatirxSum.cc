 1//�����Ͼ����ȼ����0���n��m�о��� Ȼ��ÿ��ÿ�����������ƶ� ����ȫ������ 
 int maxSubmatrixSum(std::vector<std::vector<int>> matrix,
 2                     int n, int m) 
 {
	 int base_sum = 0; //base_sum��ʼ��
 4   for (int i = 0; i < n && n <= matrix.size(); i++){             //n���ܴ��������������
 5     for (int j = 0; j < m && m <= matrix.front().size(); j++){	//m���ܴ��������������
 6       base_sum += matrix[i][j];
 7     }
 8   }
 9   int result = base_sum;	//result��ʼ��Ϊbase
10   for (int i = 0; i + n < matrix.size(); i++) {
		int real_sum = base_sum; //real_sum������ǰbase_sumֵ
		for (int y = 0; y < m; y++){
13         base_sum += matrix[i + n][y] - matrix[i][y];//��i �����i-1�ᶪ����һ��
14       }
17      if (base_sum  > result) {
18       result = base_sum;
19      }
20     for (int j = 0; j + m < matrix.size(); j++) {
21       for (int x = i; x < i + n; x++) { //x��i��ʼ���� i�ǻ��߶�����0 xС��i+n ���������ƶ���һ��
22         real_sum += matrix[x][j + m] - matrix[x][j]; //��j ��j-1��core
23       }
24       if (real_sum > result) {
25         result = real_sum;
26       }
27     }
28   }
29   return result;
30 }