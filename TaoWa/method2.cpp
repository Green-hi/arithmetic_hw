//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include "util.cpp"
//
//using namespace std;
//
//vector<vector<Unit>> getMaxSubs(vector<Unit> v)
//{
//	int n = 0;
//	
//	vector<vector<Unit>> res;
//
//	//先对套娃个体进行排序
//	sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
//		return e1.w < e2.w || (e1.w == e2.w && e1.h > e2.h);
//		});
//	cout << "排序后v：";
//	printData(v);
//
//	while (!v.empty())
//	{
//		int size = v.size();
//		vector<int> len(size, 1);//记录以第i个元素结尾的长度
//		vector<int> pos(size);//记录子序列中前驱元素位置
//
//		//计算len
//		for (int i = 0; i < size; ++i)
//		{
//			for (int j = 0; j < i; ++j)
//			{
//				if (v[j].h < v[i].h && len[i] < len[j] + 1)
//				{
//					len[i] = len[j] + 1;
//					pos[i] = j;
//				}
//			}
//		}
//
//		//给最长子序列长度max及其lastPos赋值
//		int max = -1;
//		int lastPos = -1;
//		for (int i = 0; i < len.size(); ++i)
//		{
//			if (max < len[i])
//			{
//				max = len[i];
//				lastPos = i;
//			}
//		}
//
//		//将本次套娃过程得到的套娃组f加入到结果集并删除数据集v中对应个体
//		for (int i = 0; i < max; ++i)
//		{
//			res.resize(n+1);
//			res[n].push_back(v[lastPos]);
//			vector<Unit>::iterator it = v.begin() + lastPos;
//			v.erase(it);
//			lastPos = pos[lastPos];
//		}
//		reverse(res[n].begin(), res[n].end());
//
//		cout << "第" << ++n << "趟后v：";
//		printData(v);
//	}
//	return res;
//}
//
//int main()
//{
//	execute(getMaxSubs);
//
//	return 0;
//}