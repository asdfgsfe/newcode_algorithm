��Ʒ����(PM)�кܶ�õ�idea������Щidea��Ҫ����Աʵ�֡�
������N��PM����ĳ��ʱ������һ�� idea��ÿ�� idea �����ʱ�䡢����ʱ������ȵȼ���
����һ��PM��˵������ʵ�ֵ�idea���ȿ������ȵȼ��ߵģ���ͬ���������������ʱ����С�ģ�
����ͬ�������ѡ����������ģ�û�� PM ����ͬһʱ��������� idea��

ͬʱ��M������Ա��ÿ������Ա���е�ʱ��ͻ�鿴ÿ��PM��δִ�в���������ɵ�һ��idea,
Ȼ�������ѡ������ʱ����С��һ��idea����ʵ�֣��������ʱ����ͬ��ѡ��PM�����С�ġ�
ֱ�������idea�Ż��ظ���������������ж��ͬʱ���ڿ���״̬�ĳ���Ա����ô���ǻ����ν��в鿴idea�Ĳ�����

��ÿ��ideaʵ�ֵ�ʱ�䡣

�����һ��������N��M��P���ֱ��ʾ��N��PM��M������Ա��P��idea��
�����P�У�ÿ����4�����֣��ֱ���PM��š����ʱ�䡢���ȵȼ�������ʱ�䡣���P�У��ֱ��ʾÿ��ideaʵ�ֵ�ʱ��㡣


��������:
�����һ��������N��M��P���ֱ��ʾ��N��PM��M������Ա��P��idea��
�����P�У�ÿ����4�����֣��ֱ���PM��š����ʱ�䡢���ȵȼ�������ʱ�䡣ȫ�����ݷ�Χ [1, 3000]��

�������:
���P�У��ֱ��ʾÿ��ideaʵ�ֵ�ʱ��㡣

��������1:
2 2 5
1 1 1 2
1 2 1 1
1 3 2 2
2 1 1 2
2 3 5 5

�������1:
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
 
int proid = 1; //ȫ�ֵ�ʱ��
struct Programer
{
    Programer()
        : t(0), id(proid++) //������ûɶ��
    {
    }
    int t;//��ǰ��ʱ��
    int id;
    int doTask(vector<vector<Task>>& pmtasks, map<int, int>& result)
    {
        vector<Task>::iterator findT;
        int index = -1;
		//p*k(�����Ŀ����)
        for (size_t i = 0; i < pmtasks.size(); i++)
        {
            auto& tasks = pmtasks[i];
            if (tasks.empty()) continue;
            auto it = tasks.begin();
			//ѡ�������������� ѡ��ÿ��pm��ʱ��С ��pmid��С�� ��
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
    
	//����id�ĵ�ǰʱ�佨���� �Ϳ�����rd�Լ�ȥ����Ŀzuo
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
 
//��ԭ���ߵ� �о�doTask()�ط������ö� ʱ�临�Ӷ�log(m)
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
    for (size_t i = 0; i < pmtasks.size(); i++) //����pm
    {
        auto& tasks = pmtasks[i];
        if (tasks.size() == 0) continue;
        sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2); //��ͬһ��pm��idea����
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
    map<int, int> result; //��¼��Ŀ��id�����ʱ��
    vector<Programer> pros(m);
    for (int i = pros.size() / 2; i >= 0; --i)
	{
		Programer::PercDown(pros, i, pros.size());
	}
    while (p > 0)
    {
		//�Ѳ���ûɶ��
        p -= pros.begin()->doTask(pmtasks, result); 
		//ֻ��rd��ʱ����ö� log(m)
        Programer::PercDown(pros, 0, pros.size());
    }
    for (auto &it : result)
        cout << it.second << endl;
    return 0;
}
