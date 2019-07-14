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
 
int proid = 1;
struct Programer
{
    Programer()
        : t(0), id(proid++)
    {
    }
    int t;//当前的时间
    int id;
    int doTask(vector<vector<Task>>& pmtasks, map<int, int>& result)
    {
        vector<Task>::iterator findT;
        int index = -1;
        for (size_t i = 0; i < pmtasks.size(); i++)
        {
            auto& tasks = pmtasks[i];
            if (tasks.empty()) continue;
            auto it = tasks.begin();
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
    for (size_t i = 0; i < pmtasks.size(); i++)
    {
        auto& tasks = pmtasks[i];
        if (tasks.size() == 0) continue;
        sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2)
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
    map<int, int> result;
    vector<Programer> pros(m);
    for (int i = pros.size() / 2; i >= 0; --i)
	{
		Programer::PercDown(pros, i, pros.size());
	}
    while (p > 0)
    {
        //这个地方可以用堆 log(m)
        p -= pros.begin()->doTask(pmtasks, result);
        Programer::PercDown(pros, 0, pros.size());
    }
    for (auto &it : result)
        cout << it.second << endl;
    return 0;
}