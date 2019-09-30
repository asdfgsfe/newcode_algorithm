#include <iostream>
#include <vector>

using std::vector;

vector<long long> Scores(long long maxScore, long long k, long long d1, long long d2)
{
	vector<long long> score(3);//��x1 x2 x3�õ÷�
	long long s = k + 2 * d1 + d2; // ����x1 > x2 && x2 > x3 ����µ�3x1ȡֵ
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
        if (score[0] <= maxScore && score[1] <= maxScore && score[2] <= maxScore) //x1 x2 x3��С��n/3
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

//һ����ѧ�� ��2����������
//x1, x2, x3��С�ڵ���n/3 ��Ϊ�ܹ�n�� ���Ҫ����� ��Ȼÿ���˵�n/3�� ���Ե�ĿǰΪֹÿ�����������n/3��
//ʣ��n-k�� ���x1��s1�� x2��s2�� x3��s3�� ���Ȼs1 + s2 + s3 == n - k
//��ʼ���� |x1 - x2| = d1 |x2 - x3| = d2 x1 + x2 + x3 = n - k�ⷽ�̳�������
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