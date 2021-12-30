#include <iostream> 
#include <vector>
#include <ctime>

using namespace std;

const static int MAXLEN = 2000;

struct Unit {  //套娃个体
    float w, h;
    inline bool operator == (const Unit& rhs); //重载操作符"=="
};

bool Unit::operator == (const Unit& rhs)
{
    return ((w == rhs.w) && (h == rhs.h));
}

struct cmp_lower	//lower_bound自定义比较规则
{
    bool operator  () (Unit e1, Unit e2)
    {
        return e1.h < e2.h;
    }
};

inline void printData(vector<Unit> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << '(' << v[i].w << ',' << v[i].h << ')' << ' ';
    }
    cout << endl << endl;
}

inline void printResult(vector<vector<Unit>> ans)
{
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "第" << i + 1 << "组套娃：";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << '(' << ans[i][j].w << ',' << ans[i][j].h << ')' << ' ';
        }
        cout << endl << endl;
    }
}

inline vector<Unit> readData()  // 从文件中读取数据
{
    vector<Unit> v;
    float a[MAXLEN][2];//保存目标数组

    FILE* file;
    //CHISQUARE卡方分布；EXPONENT指数分布；NORMAL正态分布；POISSON泊松分布
    fopen_s(&file, "E:\\sfData\\EXPONENT2000.csv", "r");
    fseek(file, 0L, SEEK_SET);   // 从文件第二行开始读取

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < 2; j++)
        {
            fscanf_s(file, "%f", &a[i][j]);
            fseek(file, 1L, SEEK_CUR);   /*fp指针从当前位置向后移动*/
        }
    }

    for (int m = 0;m < MAXLEN; m++)
    {
        Unit unit = { a[m][0] ,a[m][1] };
        v.push_back(unit);
    }

    return v;
}

typedef vector<vector<Unit>> FuncType(vector<Unit> v);

inline void execute(FuncType fun)
{
    clock_t startTime, endTime;

    startTime = clock();//计时开始

    vector<Unit> v = readData();

    cout << endl << "原套娃个体v：";
    printData(v);
    auto ans = fun(v);
    printResult(ans);

    endTime = clock();//计时结束

    cout << endl << "套娃组总数：" << ans.size() << endl;
    cout << "程序运行时间： " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl << endl;
}