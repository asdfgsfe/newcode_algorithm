#include <iostream>
#include <vector>

using std::vector;

vector<long long> Scores(long long maxScore, long long k, long long d1, long long d2)
{
	vector<long long> score(3);//存x1 x2 x3得得分
	long long s = k + 2 * d1 + d2; // 满足x1 > x2 && x2 > x3 情况下的3x1取值
	if (s >= 0 && s % 3 == 0)
	{
		score[0] = s / 3;
		score[1] = score[0] - d1;
		score[2] = score[1] - d2;
        if (score[0] <= maxScore && score[1] <= maxScore && score[2] <= maxScore)
		    return score;
	}
	s = k + 2 * d1 - d2;// x1 > x2 x3 > x2
	if (s >= 0 && s % 3 == 0)
	{
		score[0] = s / 3;
		score[1] = score[0] - d1;
		score[2] = score[1] + d2;
        if (score[0] <= maxScore && score[1] <= maxScore && score[2] <= maxScore) //x1 x2 x3均小于n/3
		    return score;
	}
	s = k - 2 * d1 + d2;//x1 < x2 x2 > x3
	if (s >= 0 && s % 3 == 0)
	{
		score[0] = s / 3;
		score[1] = score[0] + d1;
		score[2] = score[1] - d2;
        if (score[0] <= maxScore && score[1] <= maxScore && score[2] <= maxScore)
		    return score;
	}
	s = k - 2 * d1 - d2;//x1 < x2 x2 > x3
	if (s >= 0 && s % 3 == 0)
	{
		score[0] = s / 3;
		score[1] = score[0] + d1;
		score[2] = score[1] + d2;
        if (score[0] <= maxScore && score[1] <= maxScore && score[2] <= maxScore)
		    return score;
	}
	return vector<long long>();
}

void IsEqual(const vector<vector<long long>>& infos)
{
    int i = 0;
    bool isEqual = false;
    for (auto info : infos)
    {
        long long rest = info[0] - info[1]; //n - k
	    long long maxScore = info[0] / 3; //n/3
		vector<long long> scores = Scores(maxScore, info[1], info[2], info[3]);
		if (scores.size() != 3)
        {
            std::cout << "no" << std::endl;
        }
        else
        {
            isEqual = rest == (maxScore - scores[0]) + (maxScore - scores[1]) + (maxScore - scores[2]);
		    std::cout << (isEqual ? "yes" : "no") << std::endl;
        }
		isEqual = false;
    }
}

//一道数学题 有2个限制条件
//x1, x2, x3均小于等于n/3 因为总共n分 最后要是相等 必然每个人得n/3分 所以到目前为止每个人最多能拿n/3分
//剩余n-k分 设给x1补s1分 x2补s2分 x3补s3分 则必然s1 + s2 + s3 == n - k
//初始条件 |x1 - x2| = d1 |x2 - x3| = d2 x1 + x2 + x3 = k解方程出来就行
int main(void)
{
    int t;
    std::cin >> t;
    vector<vector<long long>> infos(t, vector<long long>(4));
    for (int i = 0; i < t; ++i)
    {
        std::cin >> infos[i][0] >> infos[i][1] >> infos[i][2] >> infos[i][3];
    }
    IsEqual(infos);
    return 0;
}
