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
//	//�ȶ����޸����������
//	sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
//		return e1.w < e2.w || (e1.w == e2.w && e1.h > e2.h);
//		});
//	cout << "�����v��";
//	printData(v);
//
//	while (!v.empty())
//	{
//		int size = v.size();
//
//		vector<Unit> t;  //��ʱ���������ڱ��浥��ѭ���õ�����ʱ������
//		vector<Unit> f(1); //����һ�����޹��̵õ����������
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
//		//���������޹��̵õ���������f���뵽�������ɾ�����ݼ�v�ж�Ӧ����
//		res.push_back(f);
//		for (int i = 0;i < f.size();++i)
//		{
//			Unit unit = f[i];
//			v.erase(remove_if(v.begin(), v.end(), [&](Unit x) {return x == unit;}), v.end());
//		}
//		f.clear();
//
//		cout << "��" << ++n << "�˺�v��";
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