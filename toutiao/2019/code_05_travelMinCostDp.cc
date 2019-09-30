
//������������λ��������¼�м�״̬��dp���� ���൱�ڵݹ��е�path��λ������������
//����������������¼�������ĳ����������� ��ֻ��visitedֻ��֪����ʱ���� ������������û������
//�ݹ�ת��̬�滮 dpһ��Ҫ�����������ֳ��ݹ��ȫ������
int getAns(vector<vector<int>> &nums){
    const int MAX = 0x0fffffff;
    int n = nums.size();
    int stateNum = 1 << n;
    // dp[i][j]�е�i��һ����������ʽ��������ʾ�������еļ��ϣ���0111��ʾ�����˳���0,1,2
    // dp[i][j]��ʾ������i�еĳ��У�������j��β��·������
    vector<vector<int> > dp(stateNum,vector<int>(n,MAX));
    dp[1][0] = 0; //�ӳ���0���������Ծ�������0���Գ���0��β��·��Ϊ0
    //�ӳ���0���������º��������еľ���
    for(int i=1;i<stateNum;i++)
	{
        for(int j=0;j<n;j++)
		{
            if(dp[i][j] != MAX)
			{ //����Ѿ����ʹ�
                for(int k=0;k<n;k++)
				{
                    //������л�û��ȥ��
					if( (i & (1 << k) ) == 0)
					{ 
                        //û�з��ʹ�k���Ҵ����ﵽk�ľ���С��ԭ���ľ��룬�����
						//��j������k
						//dp[i][j]��ʾ������i�Ĺ��̵�j��β �˿�Ҫ��j�ߵ�kȥ
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k],dp[i][j] + nums[j][k]);
                    }
                }
            }
        }
    }
	//�����dpΪ��¼�ص�ԭ������� �����￪ʼ�ӽ�ȥ�ص�ԭ�������
    int res = MAX;
    for(int i=1;i<n;i++){
        res = min(res,dp[stateNum-1][i] + nums[i][0]);
    }
    return res;
}




public class Main{
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] map = new int[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                map[i][j] = in.nextInt();
            }
        }
        //dp[i][j]��ʾ��i����������j����������нڵ�һ�λص�0�����СС��
        int V = 1<<(n-1);  //
        int[][] dp = new int[n][V];
        for(int i=0;i<n;i++) 
		{     // ����dp���һ��
            dp[i][0] = map[i][0];   //ÿ�����лص����ľ���
        }
 
        for(int j=1;j<V;j++) 
		{                  // ����������
            for(int i=0;i<n;i++) 
			{              //��i������Ҫȥ����j = {010101} �ĳ���
//                dp[i][j] = 100000;               //������ 0x7ffff��ʾ�����
                dp[i][j] = 0x7ffff; //��ط�����ֱ����dp��ʼ��ʼ��
                //���ܲ����ȵ�k����
				for(int k=1;k<n;k++) 
				{
					//�ܵ� (k-1)�����ڴ�0���г��� �˿�0����һ���߹���
					if(((j >> (k-1)) & 1) == 1) 
					{
						//��ط���������ȡ�� ������ĵ���1����ʹ��
                        dp[i][j] = Math.min(dp[i][j], map[i][k] + dp[k][j ^ (1 << (k-1))]); 
                    }
                }
            }
        }
        System.out.println(dp[0][(1 << (n-1))-1]); //������Ϸ����
 
        /*
         *����Ϊ��ӡdp��
         */
        System.out.printf("%10d",0);
        for(int j = 0;j < 1 << (n - 1) ;j++){
            System.out.printf("%10d",j);
        }
        System.out.println();
        for(int i = 0;i < n;i++){
            System.out.printf("%10d",i);
            for(int j = 0;j < 1 << (n - 1) ;j++){
                if(dp[i][j] == 0x7ffff) dp[i][j] = -1;
                System.out.printf("%10d",dp[i][j]);
            }
            System.out.println();
        }
 
    }
}