产品经理(PM)有很多好的idea，而这些idea需要程序员实现。
现在有N个PM，在某个时间会想出一个 idea，每个 idea 有提出时间、所需时间和优先等级。
对于一个PM来说，最想实现的idea首先考虑优先等级高的，相同的情况下优先所需时间最小的，
还相同的情况下选择最早想出的，没有 PM 会在同一时刻提出两个 idea。

同时有M个程序员，每个程序员空闲的时候就会查看每个PM尚未执行并且最想完成的一个idea,
然后从中挑选出所需时间最小的一个idea独立实现，如果所需时间相同则选择PM序号最小的。
直到完成了idea才会重复上述操作。如果有多个同时处于空闲状态的程序员，那么他们会依次进行查看idea的操作。

求每个idea实现的时间。

输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。
随后有P行，每行有4个数字，分别是PM序号、提出时间、优先等级和所需时间。输出P行，分别表示每个idea实现的时间点。


输入描述:
输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。
随后有P行，每行有4个数字，分别是PM序号、提出时间、优先等级和所需时间。全部数据范围 [1, 3000]。

输出描述:
输出P行，分别表示每个idea实现的时间点。

输入例子1:
2 2 5
1 1 1 2
1 2 1 1
1 3 2 2
2 1 1 2
2 3 5 5

输出例子1:
3
4
5
3
9


#include <bits/stdc++.h>
using namespace std;
struct Task
{
    int id;
    int pm;
    int time;
    int pri;
    int dur;
};
 
int proid = 1; //全局的时间
struct Programer
{
    Programer()
        : t(0), id(proid++) //这玩意没啥用
    {
    }
    int t;//当前的时间
    int id;
    int doTask(vector<vector<Task>>& pmtasks, map<int, int>& result)
    {
        vector<Task>::iterator findT;
        int index = -1;
		//p*k(最长的项目个数)
        for (size_t i = 0; i < pmtasks.size(); i++)
        {
            auto& tasks = pmtasks[i];
            if (tasks.empty()) continue;
            auto it = tasks.begin();
			//选出最想做的事情 选出每个pm耗时最小 且pmid最小的 做
            while (it!= tasks.end() && it->time > t)
                it++;
            if (it == tasks.end()) continue;
            if (index == -1 
               || (it->dur < findT->dur)
               || (it->dur == findT->dur && it->pm < findT->pm))
            {
                findT = it;
                index = i;
            }
        }
        if (index != -1)
        {
            t += findT->dur;
            result[findT->id] = t;
            pmtasks[index].erase(findT);
            return 1;
        }
         t++;
        return 0;
    }
    
	//按照id的当前时间建立堆 就可以让rd自己去拿项目zuo
    static void PercDown(vector<Programer>& rds, int i, int n) 
	{
		int child = 2 * i + 1;
		while (child < n)
		{
			if (child + 1 < n && rds[child + 1].t < rds[child].t)
			{
				++child;
			}
			if (rds[child].t >= rds[i].t)
			{
				break;
			}
			std::swap(rds[child], rds[i]);
			i = child;
			child = 2 * i + 1;
		}
	}
};
 
//抄原作者的 感觉doTask()地方可以用堆 时间复杂度log(m)
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<Task>> pmtasks;
    pmtasks.resize(n);
    for (size_t i = 0; i < p; i++)
    {
        Task task;
        cin >> task.pm >> task.time >> task.pri >> task.dur;
        task.id = i;
        pmtasks[task.pm - 1].push_back(task);
    }
    for (size_t i = 0; i < pmtasks.size(); i++) //遍历pm
    {
        auto& tasks = pmtasks[i];
        if (tasks.size() == 0) continue;
        sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2); //对同一个pm的idea排序
        {
            if (t1.pri == t2.pri)
            {
                if (t1.dur == t2.dur)
                {
                    return t1.time < t2.time;
                }
                else return t1.dur < t2.dur;
            }
            else return t1.pri > t2.pri;
        });
    }
    map<int, int> result; //记录项目的id和完成时间
    vector<Programer> pros(m);
    for (int i = pros.size() / 2; i >= 0; --i)
	{
		Programer::PercDown(pros, i, pros.size());
	}
    while (p > 0)
    {
		//堆操作没啥用
        p -= pros.begin()->doTask(pmtasks, result); 
		//只对rd的时间采用堆 log(m)
        Programer::PercDown(pros, 0, pros.size());
    }
    for (auto &it : result)
        cout << it.second << endl;
    return 0;
}
