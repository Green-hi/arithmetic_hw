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
//
//		vector<Unit> t;  //临时向量，用于保存单次循环得到的临时套娃组
//		vector<Unit> f(1); //保存一次套娃过程得到的最长套娃组
//		for (int i = 0; i < size; ++i)
//		{
//			t.push_back(v[i]);
//			for (int j = i + 1; j < size; ++j)
//			{
//				if (v[j].h > t.back().h)
//				{
//					t.push_back(v[j]);
//				}
//			}
//			f = t.size() >= f.size() ? t : f;
//			t.clear();
//		}
//
//		//将本次套娃过程得到的套娃组f加入到结果集并删除数据集v中对应个体
//		res.push_back(f);
//		for (int i = 0;i < f.size();++i)
//		{
//			Unit unit = f[i];
//			v.erase(remove_if(v.begin(), v.end(), [&](Unit x) {return x == unit;}), v.end());
//		}
//		f.clear();
//
//		cout << "第" << ++n << "趟后v：";
//		printData(v);
//	}
//
//	return res;
//}
//
//int main()
//{
//	execute(getMaxSubs);
//
//	return 0;
//}