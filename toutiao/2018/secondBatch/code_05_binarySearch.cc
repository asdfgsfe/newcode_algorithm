//���º���ʹ�ö��ֲ�������һ����������飬���ж��Ԫ��ֵ��Ŀ��Ԫ�����ʱ��
//�������һ��Ԫ�ص��±꣬Ŀ��Ԫ�ز�����ʱ����-1��
//��ָ����������д���򲻷����ʵ���ĵط������ⲻֹһ�����뾡���ҳ���������Ϊ������ĵط���

//error
int BinarySearchMax(const std::vector<int>& data, int target)

{
   int left = 0;
   int right = data.size();
   while (left < right) {
       int mid = (left + right) / 2;
       if (data[mid] <= target)
           left = mid + 1;
       else
           right = mid - 1;
   }
   if (data[right] == target)
       return right;
   return -1;
}

//ok
int BinarySearchMax(const std::vector<int>& data, int target)

{
   int left = 0;
   int right = data.size() - 1;
   int idx = -1;
   while (left <= right) {
       int mid = (left + right) / 2;
       if (data[mid] <= target) {
			idx = data[mid] == target ? mid : idx;
			left = mid + 1;
		} else
           right = mid - 1;
   }
   return idx;
}