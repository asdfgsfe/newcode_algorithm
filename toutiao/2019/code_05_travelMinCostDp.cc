
//掌握这种利用位操作来记录中间状态的dp方法 就相当于递归中的path被位操作给代替了
//这种做法不仅仅记录了完整的尝试完整过程 而只用visited只能知道何时结束 但是完整过程没法复现
//递归转动态规划 dp一定要能完整的体现出递归的全部过程
int getAns(vector<vector<int>> &nums){
    const int MAX = 0x0fffffff;
    int n = nums.size();
    int stateNum = 1 << n;
    // dp[i][j]中的i是一个二进制形式的数，表示经过城市的集合，如0111表示经过了城市0,1,2
    // dp[i][j]表示经过了i中的城市，并且以j结尾的路径长度
    vector<vector<int> > dp(stateNum,vector<int>(n,MAX));
    dp[1][0] = 0; //从城市0出发，所以经过城市0，以城市0结尾的路径为0
    //从城市0出发，更新和其他城市的距离
    for(int i=1;i<stateNum;i++)
	{
        for(int j=0;j<n;j++)
		{
            if(dp[i][j] != MAX)
			{ //如果已经访问过
                for(int k=0;k<n;k++)
				{
                    //这个城市还没有去过
					if( (i & (1 << k) ) == 0)
					{ 
                        //没有访问过k，且从这里到k的距离小于原来的距离，则更新
						//从j出发到k
						//dp[i][j]表示经过了i的过程到j结尾 此刻要从j走到k去
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k],dp[i][j] + nums[j][k]);
                    }
                }
            }
        }
    }
	//上面的dp为记录回到原点的消费 从这里开始加进去回到原点的消费
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
        //dp[i][j]表示从i出发，经过j集合里的所有节点一次回到0点的最小小费
        int V = 1<<(n-1);  //
        int[][] dp = new int[n][V];
        for(int i=0;i<n;i++) 
		{     // 先求dp表第一列
            dp[i][0] = map[i][0];   //每个城市回到起点的距离
        }
 
        for(int j=1;j<V;j++) 
		{                  // 再求其他列
            for(int i=0;i<n;i++) 
			{              //从i出发，要去包含j = {010101} 的城市
//                dp[i][j] = 100000;               //或者用 0x7ffff表示无穷大
                dp[i][j] = 0x7ffff; //这地方可以直接在dp开始初始化
                //看能不能先到k城市
				for(int k=1;k<n;k++) 
				{
					//能到 (k-1)是由于从0城市出发 此刻0城市一定走过了
					if(((j >> (k-1)) & 1) == 1) 
					{
						//这地方异或仅仅是取反 和上面的等于1搭配使用
                        dp[i][j] = Math.min(dp[i][j], map[i][k] + dp[k][j ^ (1 << (k-1))]); 
                    }
                }
            }
        }
        System.out.println(dp[0][(1 << (n-1))-1]); //到此游戏结束
 
        /*
         *以下为打印dp表
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