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
//		vector<int> len(size, 1);//��¼�Ե�i��Ԫ�ؽ�β�ĳ���
//		vector<int> pos(size);//��¼��������ǰ��Ԫ��λ��
//
//		//����len
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
//		//��������г���max����lastPos��ֵ
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
//		//���������޹��̵õ���������f���뵽�������ɾ�����ݼ�v�ж�Ӧ����
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
//		cout << "��" << ++n << "�˺�v��";
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