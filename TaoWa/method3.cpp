#include <iostream>
#include <algorithm>
#include <vector>
#include "util.cpp"

using namespace std;

vector<vector<Unit>> getMaxSubs(vector<Unit> v) {

    int n = 0;

    vector<vector<Unit>> res;

    //先对套娃个体进行排序
    sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
        return e1.w < e2.w || (e1.w == e2.w && e1.h > e2.h);
        });

    cout << "排序后v：";
    printData(v);

    while (!v.empty())
    {
        int size = v.size();
        //f中保存的是构成的上升子序列
        vector<Unit> f = { v[0] };
        for (int i = 1; i < size; ++i) {
            Unit obj = v[i];
            if (obj.h > f.back().h) {
                //如果f为空，我们直接把obj加进去。如果f的最后一个元素小于obj，
                //说明obj加入到list的末尾可以构成一个更长的上升子序列，就把obj
                //加入到f的末尾
                f.push_back(obj);
            }
            else {
                //否则就把f中第一个不小于obj的元素替换
                //lower_bound()函数用于在指定区域内查找不小于目标值的第一个元素
                //其底层实现采用的是二分查找的方式,效率更高
                auto it = lower_bound(f.begin(), f.end(), obj, cmp_lower());
                *it = obj;
            }
        }

        //将本次套娃过程得到的套娃组f加入到结果集并删除数据集v中对应个体
        res.push_back(f);
        for (int i = 0;i < f.size();++i)
        {
            Unit unit = f[i];
            v.erase(remove_if(v.begin(), v.end(), [&](Unit x) {return x == unit;}), v.end());
        }
        f.clear();

        cout << "第" << ++n << "趟后v：";
        printData(v);
    }

    return res;
}

int main()
{
    execute(getMaxSubs);

    return 0;
}