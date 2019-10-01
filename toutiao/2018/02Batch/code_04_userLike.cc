#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

struct UserLike
{
	int like;
	int userId;
	
	UserLike() {}
	UserLike(int l, int id)
		: like(l), userId(id)
	{}
};

int LikeUserNum(const vector<UserLike>& values, int l, int r, int target)
{
	assert(l >= 0 && r < values.size());
	while (l <= r)
	{
		int m = (l + r) / 2;
    std::cout << "l=" << l << " m=" << m << " m.userId=" << values[m].userId  << " target=" << target << " r=" << r << std::endl;
    if (values[m].userId == target)
		{
			return values[m].userId;
		}
		else if (values[m].userId < target)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return -1;
}

vector<int> CurLikeUsers(const vector<UserLike>& values, int target)
{
  //std::cout << "values size=" << values.size() << " target=" << target << std::endl;
  int l = 0;
	int r = values.size() - 1;
	int lFirst = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
    //std::cout << "l=" << l << " m=" << m  << " m.like=" << values[m].like << " r=" << r << std::endl;
		if (values[m].like >= target)
		{
      //std::cout << "2--l=" << l << " m=" << m  << " m.like=" << values[m].like << " r=" << r << std::endl;
			
      if (values[m].like == target && (m == 0 || values[m - 1].like != target))
			{
				lFirst = m;
				break;
			}
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	
	l = 0;
	r = values.size() - 1;
	int rFirst = -1; 
	while (l <= r)
	{
		int m = (l + r) / 2;
    //std::cout << "l=" << l << " m=" << m  << " m.like=" << values[m].like  << " target=" << target << " r=" << r << std::endl;
		if (values[m].like <= target)
		{
			if (values[m].like == target && (m + 1 == values.size() || values[m + 1].like != target))
			{
				rFirst = m;
				break;
			}
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
  //std::cout << "lFirst=" << lFirst << " rFirst=" << rFirst << std::endl;
	if (lFirst == -1 || rFirst == -1)
  {
    return vector<int>();
  }
  return {lFirst, rFirst};
}

void Dump(vector<UserLike>& vals)
{
  int i = 0;
  for (const auto& val : vals)
  {
    std::cout << "i=" << i << " like=" << val.like << " userId=" << val.userId << std::endl;
    ++i;
  }
  std::cout << std::endl;
}

void UserLikeVal(vector<vector<int>>& reqs, vector<int> like)
{
	if (reqs.empty() || like.empty())
	{
		return;
	}
	vector<UserLike> usersLike(like.size());
	for (int i = 0; i < like.size(); ++i)
	{
		usersLike[i] = UserLike(like[i], i);
	}
	std::sort(usersLike.begin(), usersLike.end(),
		[](const UserLike& lhs, const UserLike& rhs)
		{
			if (lhs.like != rhs.like)
			{
				return lhs.like < rhs.like;
			}
			return lhs.userId < rhs.userId;
		});
  Dump(usersLike);
	for (const auto& req : reqs)
	{
		assert(req.size() == 3);
        //查喜好值位req[2]的这段区间
		vector<int> lr = CurLikeUsers(usersLike, req[2]);
    std::cout << "lr=" << lr[0] << " " << lr[1] << std::endl;
		if (lr.empty())
		{
      std::cout << "F1" << std::endl;
			continue;
		}
	//在查完喜好值的这段区间 找用户的id的区间 然后做减法就是答案
    int lIdx = LikeUserNum(usersLike, lr[0], lr[1], req[0] - 1);
    int rIdx = LikeUserNum(usersLike, lr[0], lr[1], req[1] - 1);
    
    //按照找完的关系划分区间
    int luserId = usersLike[lr[0]].userId;
    int ruserId = usersLike[lr[1]].userId;
    if (luserId <= req[0] - 1 && ruserId >= req[0] - 1)
    {
      printf("%d\n", req[1] - req[0]);
    }
    else if (ruserId >= req[0] - 1)
    {
      printf("%d\n", req[1] - lIdx);
    }
    else if (luserId <= req[0] - 1)
    {
      printf("%d\n", rIdx - req[0]); 
    }
    else
    {
      printf("%d\n", rIdx - lIdx + 1);
    }
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> like(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &like[i]);
	}
	int q;
	scanf("%d", &q);
	vector<vector<int>> reqs(q, vector<int>(3));
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d%d", &reqs[i][0], &reqs[i][1], &reqs[i][2]);
	}
	UserLikeVal(reqs, like);

	return 0;
}
