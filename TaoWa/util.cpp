#include <iostream> 
#include <vector>
#include <ctime>

using namespace std;

const static int MAXLEN = 2000;

struct Unit {  //���޸���
    float w, h;
    inline bool operator == (const Unit& rhs); //���ز�����"=="
};

bool Unit::operator == (const Unit& rhs)
{
    return ((w == rhs.w) && (h == rhs.h));
}

struct cmp_lower	//lower_bound�Զ���ȽϹ���
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
        cout << "��" << i + 1 << "�����ޣ�";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << '(' << ans[i][j].w << ',' << ans[i][j].h << ')' << ' ';
        }
        cout << endl << endl;
    }
}

inline vector<Unit> readData()  // ���ļ��ж�ȡ����
{
    vector<Unit> v;
    float a[MAXLEN][2];//����Ŀ������

    FILE* file;
    //CHISQUARE�����ֲ���EXPONENTָ���ֲ���NORMAL��̬�ֲ���POISSON���ɷֲ�
    fopen_s(&file, "E:\\sfData\\EXPONENT2000.csv", "r");
    fseek(file, 0L, SEEK_SET);   // ���ļ��ڶ��п�ʼ��ȡ

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < 2; j++)
        {
            fscanf_s(file, "%f", &a[i][j]);
            fseek(file, 1L, SEEK_CUR);   /*fpָ��ӵ�ǰλ������ƶ�*/
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

    startTime = clock();//��ʱ��ʼ

    vector<Unit> v = readData();

    cout << endl << "ԭ���޸���v��";
    printData(v);
    auto ans = fun(v);
    printResult(ans);

    endTime = clock();//��ʱ����

    cout << endl << "������������" << ans.size() << endl;
    cout << "��������ʱ�䣺 " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl << endl;
}