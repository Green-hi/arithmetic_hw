#include <iostream>
#include <algorithm>
#include <vector>
#include "util.cpp"

using namespace std;

vector<vector<Unit>> getMaxSubs(vector<Unit> v) {

    int n = 0;

    vector<vector<Unit>> res;

    //�ȶ����޸����������
    sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
        return e1.w < e2.w || (e1.w == e2.w && e1.h > e2.h);
        });

    cout << "�����v��";
    printData(v);

    while (!v.empty())
    {
        int size = v.size();
        //f�б�����ǹ��ɵ�����������
        vector<Unit> f = { v[0] };
        for (int i = 1; i < size; ++i) {
            Unit obj = v[i];
            if (obj.h > f.back().h) {
                //���fΪ�գ�����ֱ�Ӱ�obj�ӽ�ȥ�����f�����һ��Ԫ��С��obj��
                //˵��obj���뵽list��ĩβ���Թ���һ�����������������У��Ͱ�obj
                //���뵽f��ĩβ
                f.push_back(obj);
            }
            else {
                //����Ͱ�f�е�һ����С��obj��Ԫ���滻
                //lower_bound()����������ָ�������ڲ��Ҳ�С��Ŀ��ֵ�ĵ�һ��Ԫ��
                //��ײ�ʵ�ֲ��õ��Ƕ��ֲ��ҵķ�ʽ,Ч�ʸ���
                auto it = lower_bound(f.begin(), f.end(), obj, cmp_lower());
                *it = obj;
            }
        }

        //���������޹��̵õ���������f���뵽�������ɾ�����ݼ�v�ж�Ӧ����
        res.push_back(f);
        for (int i = 0;i < f.size();++i)
        {
            Unit unit = f[i];
            v.erase(remove_if(v.begin(), v.end(), [&](Unit x) {return x == unit;}), v.end());
        }
        f.clear();

        cout << "��" << ++n << "�˺�v��";
        printData(v);
    }

    return res;
}

int main()
{
    execute(getMaxSubs);

    return 0;
}